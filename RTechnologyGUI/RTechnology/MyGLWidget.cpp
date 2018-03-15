/*
** MyGLWidget.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 16:47 2018 benoit_g
** Last update sam. mars 16:47 2018 benoit_g
*/

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <iostream>
#include <rapidjson/document.h>
#include "MyGLWidget.hpp"

void Worker::doWork(const rapidjson::Document &doc)
{
  std::cout << "ok" << std::endl;
}

MyGLWidget::MyGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
  this->_pictureDraw = std::make_shared<QOpenGLPictureDraw>(this);
  this->_raytracer = std::make_shared<rt::Raytracer>(this->_pictureDraw, false);

  this->_worker = new Worker;
  this->_worker->moveToThread(&this->_previewWorker);
  connect(&this->_previewWorker, &QThread::finished, this->_worker, &QObject::deleteLater);
  connect(this, &MyGLWidget::updatePreview, this->_worker, &Worker::doWork);
  this->_previewWorker.start();
}

MyGLWidget::~MyGLWidget()
{
  this->_previewWorker.quit();
  this->_previewWorker.wait();
}

void MyGLWidget::setPixel(const rt::Vector2I &pos, const rt::Color &color)
{
  QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  f->glEnable(GL_SCISSOR_TEST);
  {
    f->glScissor(pos.x(), pos.y(), 1, 1);
    f->glClearColor((float)color.r / 255, (float)color.g / 255, (float)color.b / 255, (float)color.a / 255);
    f->glClear(GL_COLOR_BUFFER_BIT);
  }
  f->glEnable(GL_SCISSOR_TEST);
}

void MyGLWidget::initializeGL()
{
  //this->makeCurrent();

  QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  f->glClearColor(0, 0, 0, 0);
  f->glClear(GL_COLOR_BUFFER_BIT);
  emit this->initialized();

  //this->doneCurrent();
  this->context()->moveToThread(&this->_previewWorker);
}

void MyGLWidget::resizeGL(int w, int h)
{
  /*QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  f->glClearColor(0, 0, 0, 0);
  f->glClear(GL_COLOR_BUFFER_BIT);
  emit this->resized(w, h);
*/
  this->_pictureDraw->setWidth(w);
  this->_pictureDraw->setHeight(h);
}

void MyGLWidget::paintGL()
{}
