#ifdef COMPILE_WITH_QT
int main()
{
    return 0;
}
#else
  #include "Global.hpp"
  //#include "Test.hpp"
  //#include <QMainWindow>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Global::getSingleton().init();
  Global::getSingleton().mainWindow->show();

  auto ret = a.exec();
  Global::getSingleton().reset();
  return ret;
/*  QApplication a(argc, argv);
  QMainWindow *window = new QMainWindow;
  Controller *controller = new Controller(window);

//  controller->setGeometry(0, 0, window->width(), window->height());
  window->show();

  return a.exec();*/
}

#endif
