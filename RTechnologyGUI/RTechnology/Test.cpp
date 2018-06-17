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

Controller::Controller(QWidget *parent) : QOpenGLWidget(parent)
{}

Controller::~Controller()
{}

void Controller::initializeGL()
{
  std::cout << "init" << std::endl;

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  auto f = this->context()->functions();
  f->glClearColor(0, 0, 0, 0);
  f->glClear(GL_COLOR_BUFFER_BIT);
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