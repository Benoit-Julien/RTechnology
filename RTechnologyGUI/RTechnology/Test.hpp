/*
** Test.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  lun. mars 15:14 2018 benoit_g
** Last update lun. mars 15:14 2018 benoit_g
*/

#ifndef RTECHNOLOGY_TEST_HPP
#define RTECHNOLOGY_TEST_HPP

#include <QApplication>
#include <QThread>
#include <QOpenGLWidget>
#include <QOffscreenSurface>
#include <iostream>

class Worker2 : public QThread
{
 Q_OBJECT

 public:
  Worker2();
  ~Worker2();

  QOpenGLContext *context;
  QOffscreenSurface *offscrnsf;

 protected:
  void run();

 signals:
  void result();
};

class Controller : public QOpenGLWidget
{
 Q_OBJECT

  Worker2 *workerThread;

 public:
  Controller(QWidget *parent = nullptr);
  ~Controller();

 protected:
  virtual void initializeGL();
  virtual void resizeEvent(QResizeEvent *);
  virtual void resizeGL(int w, int h);
  virtual void paintEvent(QPaintEvent *);
  virtual void paintGL();
};

#endif /* !RTECHNOLOGY_TEST_HPP */
