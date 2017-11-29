#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RTechnologyGUI.h"

class RTechnologyGUI : public QMainWindow
{
	Q_OBJECT

public:
	RTechnologyGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::RTechnologyGUIClass ui;
};
