#include <QOpenGLContext>
#include <QKeyEvent>
#include <QFileDialog>
#include <fstream>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <Raytracer/math/Vector3.hpp>

#include "Object/Sphere.hpp"
#include "Object/Cylinder.hpp"

#include "Light/PointLight.hpp"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	  _previousClickObject(-1),
	  _previousClickLight(-1),
	  _selectedScene("")
{
  ui = std::make_shared<Ui::MainWindow>();
  ui->setupUi(this);

  ui->attributes->layout()->setAlignment(Qt::AlignTop);

  this->_sceneSettings = std::make_shared<SceneSettings>(this);

  connect(ui->actionSphere, &QAction::triggered, this, &MainWindow::addSphere);
  connect(ui->actionCylinder, &QAction::triggered, this, &MainWindow::addCylinder);

  connect(ui->actionPointLight, &QAction::triggered, this, &MainWindow::addPointLight);

  connect(ui->actionOptions_Scene, &QAction::triggered, this, &MainWindow::openSceneSettings);
  connect(ui->actionRendering, &QAction::triggered, this, &MainWindow::startRendering);

  connect(ui->object_list_view, &QListWidget::clicked, this, &MainWindow::itemObjectClicked);
  connect(ui->light_list_view, &QListWidget::clicked, this, &MainWindow::itemLightClicked);

  connect(ui->actionNouveau, &QAction::triggered, this, &MainWindow::newScene);
  connect(ui->actionOuvrir, &QAction::triggered, this, &MainWindow::openScene);
  connect(ui->actionEnregistrer, &QAction::triggered, this, &MainWindow::saveScene);
  connect(ui->actionEnregistrer_sous, &QAction::triggered, this, &MainWindow::saveAsScene);

  /*this->_openGLWidget = new MyGLWidget(this);
  delete ui->openGlPreview;
  ui->openGlPreview = this->_openGLWidget;
  this->_openGLWidget->setMinimumSize(400, 0);
  ui->horizontalLayout->addWidget(ui->openGlPreview);
  ui->horizontalLayout->removeWidget(ui->attributes);
  ui->horizontalLayout->addWidget(ui->attributes);*/

  this->_image = std::make_shared<QImage>(1280, 720, QImage::Format::Format_ARGB32);
  this->_draw = std::make_shared<QOpenGLPictureDraw>(this->_image);
  this->_raytracer = std::make_shared<rt::Raytracer>(this->_draw, false);
}

MainWindow::~MainWindow()
{}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  static int previousKey = -1;
  if (event->key() == Qt::Key_S && previousKey == Qt::Key_Control)
    this->saveScene();
  else if (event->key() == Qt::Key_O && previousKey == Qt::Key_Control)
    this->openScene();

  previousKey = event->key();
  if (event->key() != Qt::Key_Delete)
    return;

  QListWidgetItem * selectedItem = nullptr;
  if (this->_previousClickObject != -1)
    {
      auto selectedItem = ui->object_list_view->currentItem();

      auto index = ui->object_list_view->selectionModel()->selectedIndexes()[0].row();
      this->_objects.erase(this->_objects.begin() + index);
      ui->object_list_view->removeItemWidget(selectedItem);
      delete selectedItem;

      this->_previousClickObject = -1;
    }
  else if (this->_previousClickLight != -1)
    {
      selectedItem = ui->light_list_view->currentItem();

      auto index = ui->light_list_view->selectionModel()->selectedIndexes()[0].row();
      this->_lights.erase(this->_lights.begin() + index);
      ui->light_list_view->removeItemWidget(selectedItem);
      delete selectedItem;

      this->_previousClickLight = -1;
    }
}

void MainWindow::openSceneSettings()
{
  this->_sceneSettings->open();
}

void MainWindow::startRendering()
{
  this->saveScene();

  QString imagePath = QFileDialog::getSaveFileName(this,
						   tr("Save File"),
						   QDir::homePath(),
						   tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

  this->_raytracer->reset();
  this->_raytracer->initialiseScene(this->serializeScene());
  this->_raytracer->start();
  this->_image->save(imagePath);
}

void MainWindow::addSphere()
{
  auto sphere = std::make_shared<Sphere>(ui->attributes);
  this->_objects.push_back(sphere);
  ui->object_list_view->addItem(QString::fromStdString(sphere->getName()));
  this->updatePreview();
}

void MainWindow::addCylinder()
{
  auto cylinder = std::make_shared<Cylinder>(ui->attributes);
  this->_objects.push_back(cylinder);
  ui->object_list_view->addItem(QString::fromStdString(cylinder->getName()));
  this->updatePreview();
}

void MainWindow::addPointLight()
{
  auto pointLight = std::make_shared<PointLight>(ui->attributes);
  this->_lights.push_back(pointLight);
  ui->light_list_view->addItem(QString::fromStdString(pointLight->getName()));
  this->updatePreview();
}

void MainWindow::itemObjectClicked(const QModelIndex &index)
{
  if (this->_previousClickObject != -1)
    this->_objects[this->_previousClickObject]->hide();
  if (this->_previousClickLight != -1)
    {
      this->_lights[this->_previousClickLight]->hide();
      ui->light_list_view->clearSelection();
    }

  this->_objects[index.row()]->show();
  this->_previousClickObject = index.row();
  this->_previousClickLight = -1;
}

void MainWindow::itemLightClicked(const QModelIndex &index)
{
  if (this->_previousClickLight != -1)
    this->_lights[this->_previousClickLight]->hide();
  if (this->_previousClickObject != -1)
    {
      this->_objects[this->_previousClickObject]->hide();
      ui->object_list_view->clearSelection();
    }

  this->_lights[index.row()]->show();
  this->_previousClickLight = index.row();
  this->_previousClickObject = -1;
}

void MainWindow::itemNameUpdate(const QString &name)
{
  ui->object_list_view->currentItem()->setText(name);
}

void MainWindow::newScene()
{
  this->saveScene();
  this->_selectedScene = "";

  ui->object_list_view->clear();
  ui->light_list_view->clear();
  this->_objects.clear();
  this->_lights.clear();
}

void MainWindow::openScene()
{
  static auto funcGetVec = [](rapidjson::Value value) -> rt::Vector3F
  {
    float x, y, z;
    assert(value.IsObject());
    assert(value.HasMember("x") && value["x"].IsNumber());
    assert(value.HasMember("y") && value["y"].IsNumber());
    assert(value.HasMember("z") && value["z"].IsNumber());

    x = value["x"].GetFloat();
    y = value["y"].GetFloat();
    z = value["z"].GetFloat();
    return rt::Vector3F(x, y, z);
  };

  QFileDialog dialog(this, tr("Save Scene"), QDir::homePath(), tr("Json Files (*.json)"));
  dialog.setAcceptMode(QFileDialog::AcceptOpen);
  if (dialog.exec())
    this->_selectedScene = dialog.selectedFiles()[0];
  else
    return;

  rapidjson::Document doc;

  std::ifstream ifs(this->_selectedScene.toStdString());
  rapidjson::IStreamWrapper isw(ifs);
  doc.ParseStream(isw);

  assert(doc.IsObject());
  assert(doc.HasMember("viewPlaneDistance") && doc["viewPlaneDistance"].IsNumber());
  assert(doc.HasMember("viewPlaneWidth") && doc["viewPlaneWidth"].IsNumber());
  assert(doc.HasMember("viewPlaneHeight") && doc["viewPlaneHeight"].IsNumber());
  assert(doc.HasMember("camera") && doc["camera"].IsObject());
  assert(doc.HasMember("objects") && doc["objects"].IsArray());
  assert(doc.HasMember("lights") && doc["lights"].IsArray());

  this->_sceneSettings->setCameraViewPlaneDistance(doc["viewPlaneDistance"].GetDouble());
  this->_sceneSettings->setCameraViewPlaneWidth(doc["viewPlaneWidth"].GetDouble());
  this->_sceneSettings->setCameraViewPlaneHeight(doc["viewPlaneHeight"].GetDouble());

  if (doc["camera"].HasMember("position"))
    this->_sceneSettings->setCameraPosition(funcGetVec(doc["camera"]["position"].GetObject()));
  if (doc["camera"].HasMember("rotation"))
    this->_sceneSettings->setCameraRotation(funcGetVec(doc["camera"]["rotation"].GetObject()));

  auto objects = doc["objects"].GetArray();
  auto lights = doc["lights"].GetArray();

  for (auto &obj : objects)
    {
      assert(obj.IsObject());
      assert(obj.HasMember("type") && obj["type"].IsString());

      std::shared_ptr<Object> object;
      if (std::string(obj["type"].GetString()) == "sphere")
	object = std::make_shared<Sphere>(ui->attributes);
      else if (std::string(obj["type"].GetString()) == "cylinder")
	object = std::make_shared<Cylinder>(ui->attributes);
      else
	return;

      if (obj.HasMember("position"))
	object->getDefaultAttribute()->setPosition(funcGetVec(obj["position"].GetObject()));
      else if (obj.HasMember("rotation"))
	object->getDefaultAttribute()->setRotation(funcGetVec(obj["rotation"].GetObject()));

      this->_objects.push_back(object);
      ui->object_list_view->addItem(QString::fromStdString(object->getName()));
    }
  for (auto &l : lights)
    {
      assert(l.IsObject());

      std::shared_ptr<Light> light;
      if (std::string(l["type"].GetString()) == "pointLight")
	light = std::make_shared<PointLight>(ui->attributes);
      else
	return;

      if (l.HasMember("position"))
	light->getDefaultAttribute()->setPosition(funcGetVec(l["position"].GetObject()));
      else if (l.HasMember("rotation"))
	light->getDefaultAttribute()->setRotation(funcGetVec(l["rotation"].GetObject()));

      this->_lights.push_back(light);
      ui->light_list_view->addItem(QString::fromStdString(light->getName()));
    }
}

void MainWindow::saveScene()
{
  if (this->_selectedScene.isEmpty())
    this->saveAsScene();

  std::ofstream file(this->_selectedScene.toStdString(), std::ofstream::out | std::ofstream::trunc);

  if (!file)
    return;

  auto doc = this->serializeScene();

  rapidjson::OStreamWrapper osw(file);
  rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
  doc.Accept(writer);
}

void MainWindow::saveAsScene()
{
  std::string file;
  QFileDialog dialog(this, tr("Save Scene"), QDir::homePath(), tr("Json Files (*.json)"));
  dialog.setAcceptMode(QFileDialog::AcceptSave);
  if (dialog.exec())
    file = dialog.selectedFiles()[0].toStdString();
  else
    return;

  if (file.find(".json") == std::string::npos)
    file += ".json";

  this->_selectedScene = QString::fromStdString(file);
  this->saveScene();
}

rapidjson::Document MainWindow::serializeScene()
{
  rapidjson::Document doc;
  doc.SetObject();

  this->_sceneSettings->addToDocument(doc);

  auto objects = rapidjson::Value();
  objects.SetArray();
  auto arrayObjects = objects.GetArray();
  for (auto &obj : this->_objects)
    arrayObjects.PushBack(obj->serialize(doc.GetAllocator()), doc.GetAllocator());
  doc.AddMember("objects", objects, doc.GetAllocator());

  auto lights = rapidjson::Value();
  lights.SetArray();
  auto arrayLights = lights.GetArray();

  for (auto &l : this->_lights)
    arrayLights.PushBack(l->serialize(doc.GetAllocator()), doc.GetAllocator());
  doc.AddMember("lights", lights, doc.GetAllocator());
  return doc;
}

void MainWindow::updatePreview()
{
//  emit this->_openGLWidget->updatePreview(this->serializeScene());
}