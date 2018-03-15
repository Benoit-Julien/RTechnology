#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <memory>
#include <QProcess>
#include <Raytracer/Raytracer.hpp>

#include "scenesettings.h"
#include "Object/Object.hpp"
#include "Light/Light.hpp"
#include "ui_mainwindow.h"
#include "QOpenGLPictureDraw.hpp"
//#include "MyGLWidget.hpp"

class MainWindow : public QMainWindow
{
 Q_OBJECT

  std::shared_ptr<Ui::MainWindow> ui;
  std::shared_ptr<SceneSettings> _sceneSettings;
  std::vector<std::shared_ptr<Object>> _objects;
  std::vector<std::shared_ptr<Light>> _lights;
  int _previousClickObject;
  int _previousClickLight;

  //MyGLWidget *_openGLWidget;
  std::shared_ptr<rt::Raytracer> _raytracer;
  std::shared_ptr<QOpenGLPictureDraw> _draw;
  std::shared_ptr<QImage> _image;

  QString _selectedScene;

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void updatePreview();

 private slots:
  void openSceneSettings();
  void startRendering();

  void addSphere();
  void addCylinder();
  void addPointLight();

  void itemObjectClicked(const QModelIndex &index);
  void itemLightClicked(const QModelIndex &index);

  void itemNameUpdate(const QString &name);

  void newScene();
  void openScene();
  void saveScene();
  void saveAsScene();

 private:
  virtual void keyPressEvent(QKeyEvent *event);

  rapidjson::Document serializeScene();
};

#endif // MAINWINDOW_H
