#ifdef COMPILE_WITH_QT
int main()
{
    return 0;
}
#else
#include "Global.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Global::getSingleton().init();
  Global::getSingleton().mainWindow->showMaximized();

  auto ret = a.exec();
  Global::getSingleton().reset();
  return ret;
}
#endif
