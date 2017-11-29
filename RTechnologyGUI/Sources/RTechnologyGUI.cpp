#include "RTechnologyGUI.h"
#include <Raytracer/Raytracer.h>

RTechnologyGUI::RTechnologyGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	std::string str = entry_point();
	
	ui.textBrowser->insertHtml(str.c_str());
}
