#include <QKeyEvent>
#include "Object/Sphere.hpp"
#include "Object/Cylinder.hpp"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), _previousClick(-1)
{
  ui = std::make_shared<Ui::MainWindow>();
  ui->setupUi(this);

  ui->attributes->layout()->setAlignment(Qt::AlignTop);

  connect(ui->actionSphere, SIGNAL(triggered()), this, SLOT(addSphere()));
  connect(ui->actionCylinder, SIGNAL(triggered()), this, SLOT(addCylinder()));

  connect(ui->object_list_view, SIGNAL(clicked(QModelIndex)), this, SLOT(itemClicked(QModelIndex)));
}

MainWindow::~MainWindow()
{}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  if (event->key() != Qt::Key_Delete)
    return;
  auto seletedItem = ui->object_list_view->currentItem();
  if (!seletedItem)
    return;
  auto index = ui->object_list_view->selectionModel()->selectedIndexes()[0].row();
  this->_objects.erase(this->_objects.begin() + index);
  ui->object_list_view->removeItemWidget(seletedItem);
  delete seletedItem;

  this->_previousClick = -1;
}

void MainWindow::addSphere()
{
  auto sphere = std::make_shared<Sphere>(ui->attributes);
  this->_objects.push_back(sphere);
  ui->object_list_view->addItem(QString::fromStdString(sphere->getName()));
}

void MainWindow::addCylinder()
{
  auto cylinder = std::make_shared<Cylinder>(ui->attributes);
  this->_objects.push_back(cylinder);
  ui->object_list_view->addItem(QString::fromStdString(cylinder->getName()));
}

void MainWindow::itemClicked(const QModelIndex &index)
{
  if (this->_previousClick != -1)
    this->_objects[this->_previousClick]->hide();

  this->_objects[index.row()]->show();
  this->_previousClick = index.row();
}

void MainWindow::itemNameUpdate(const QString &name)
{
  ui->object_list_view->currentItem()->setText(name);
}