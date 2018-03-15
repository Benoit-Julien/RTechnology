/*
** MyGLWidget.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 16:47 2018 benoit_g
** Last update sam. mars 16:47 2018 benoit_g
*/

#ifndef RTECHNOLOGY_MYGLWIDGET_HPP
#define RTECHNOLOGY_MYGLWIDGET_HPP

#include <QOpenGLWidget>
#include <QThread>
#include <Raytracer/math/Vector2.hpp>
#include <Raytracer/Color.hpp>
#include <Raytracer/Raytracer.hpp>
#include <rapidjson/document.h>
#include <memory>
#include <mutex>

#include "QOpenGLPictureDraw.hpp"

class Worker : public QObject
{
 Q_OBJECT

 public slots:
  void doWork(const rapidjson::Document &doc);
};

class MyGLWidget : public QOpenGLWidget
{
 Q_OBJECT

 private:
  std::mutex _mutex;
  std::shared_ptr<QOpenGLPictureDraw> _pictureDraw;
  std::shared_ptr<rt::Raytracer> _raytracer;
  QThread _previewWorker;
  Worker *_worker;

 public:
  explicit MyGLWidget(QWidget *parent = nullptr);
  virtual ~MyGLWidget();

 protected:
  virtual void initializeGL();
  virtual void resizeGL(int w, int h);
  virtual void paintGL();

 signals:
  void updatePreview(const rapidjson::Document &doc);
  void initialized();
  void resized(int, int);

 public slots:
  void setPixel(const rt::Vector2I &pos, const rt::Color &color);
};

#endif /* !RTECHNOLOGY_MYGLWIDGET_HPP */
