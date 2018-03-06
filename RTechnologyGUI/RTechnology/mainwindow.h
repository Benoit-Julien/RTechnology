#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "ui_mainwindow.h"
#include "Object/Object.hpp"

class MainWindow : public QMainWindow
{
 Q_OBJECT

  std::shared_ptr<Ui::MainWindow> ui;
  std::vector<std::shared_ptr<Object>> _objects;
  int _previousClick;

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void addSphere();
  void addCylinder();
  void itemClicked(const QModelIndex &index);

  void itemNameUpdate(const QString &name);

 private:
  virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
