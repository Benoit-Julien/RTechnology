#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "scenesettings.h"
#include "Object/Object.hpp"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
 Q_OBJECT

  std::shared_ptr<Ui::MainWindow> ui;
  std::shared_ptr<SceneSettings> _sceneSettings;
  std::vector<std::shared_ptr<Object>> _objects;
  int _previousClick;

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void openSceneSettings();

  void addSphere();
  void addCylinder();
  void itemClicked(const QModelIndex &index);

  void itemNameUpdate(const QString &name);

 private:
  virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
