/*
** Test.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  lun. mars 15:14 2018 benoit_g
** Last update lun. mars 15:14 2018 benoit_g
*/

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include "Test.hpp"

Worker2::Worker2()
{}

Worker2::~Worker2()
{}

void Worker2::run()
{
  std::cout << "run" << std::endl;

  this->context->makeCurrent(this->offscrnsf);
  //this->context->swapBuffers(this->offscrnsf);
  auto f = this->context->functions();

  f->glEnable(GL_SCISSOR_TEST);
  {
    f->glScissor(0, 0, 10, 10);
    f->glClearColor(1, 0, 0, 1);
    f->glClear(GL_COLOR_BUFFER_BIT);
  }
  f->glEnable(GL_SCISSOR_TEST);

  this->context->doneCurrent();
  std::cout << "ok" << std::endl;

  emit this->result();
}

Controller::Controller(QWidget *parent) : QOpenGLWidget(parent)
{}

Controller::~Controller()
{
  if (workerThread)
    {
      workerThread->quit();
      workerThread->wait();
    }
}

void Controller::initializeGL()
{
  std::cout << "init" << std::endl;

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  this->doneCurrent();

  /*this->workerThread = new Worker2;
  this->workerThread->context = new QGLContext(QGLFormat());
  this->workerThread->context->create(this->context());
  this->context()->moveToThread(this->workerThread);

  connect(this->workerThread, &Worker2::result, [this](){
    this->context()->moveToThread(qApp->thread());
    this->updateGL();
  });
  this->workerThread->start();
*/
  auto f = this->context()->functions();
  f->glClearColor(0, 0, 0, 0);
  f->glClear(GL_COLOR_BUFFER_BIT);

  this->workerThread = new Worker2;
  this->workerThread->offscrnsf = new QOffscreenSurface();
  this->workerThread->offscrnsf->create();
  if (!this->workerThread->offscrnsf->isValid()) {
      std::cerr << "Surface Failed" << std::endl;
      exit(1);
    }

  this->workerThread->context = new QOpenGLContext();
  this->workerThread->context->setShareContext(this->context()->globalShareContext());
  this->workerThread->context->create();

  if (!this->workerThread->context->isValid()) {
      std::cerr << "Context Failed" << std::endl;
      exit(1);
    }
  this->workerThread->context->moveToThread(this->workerThread);
  connect(this->workerThread, &Worker2::result, [this](){
    std::cout << "update" << std::endl;
    //this->update();
  });
  this->workerThread->start();
}

void Controller::resizeEvent(QResizeEvent *)
{
  std::cout << "resizeEvent" << std::endl;
}

void Controller::resizeGL(int w, int h)
{
  std::cout << "resizeGL" << std::endl;

  //this->makeCurrent();

  //glViewport(0, 0, w, h);

/*  f->glClearColor(1, 0, 0, 0);
  f->glEnable(GL_SCISSOR_TEST);
  {
    f->glScissor(0, 0, 10, 10);
    f->glClearColor(1, 0, 0, 1);
    f->glClear(GL_COLOR_BUFFER_BIT);
  }
  f->glEnable(GL_SCISSOR_TEST);*/
}

void Controller::paintEvent(QPaintEvent *)
{
  std::cout << "paintEvent" << std::endl;
}

void Controller::paintGL()
{
  std::cout << "paintGL" << std::endl;
}
/*
void Controller::paintEvent(QPaintEvent *)
{
  std::cout << "paint Event" << std::endl;
}*/