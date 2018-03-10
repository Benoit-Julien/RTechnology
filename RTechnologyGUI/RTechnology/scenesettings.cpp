#include "scenesettings.h"

SceneSettings::SceneSettings(QWidget *parent) :
	QDialog(parent), viewPlaneDistance(1), viewPlaneWidth(0.5), viewPlaneHeight(0.35)
{
  ui = std::make_shared<Ui::SceneSettings>();
  ui->setupUi(this);

  connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(handleValid()));
  connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(handleCancel()));
}

SceneSettings::~SceneSettings()
{}

void SceneSettings::setCameraPosition(const Vector3F &position)
{
  this->cameraPosition = position;
  ui->position_x_value->setValue(this->cameraPosition.x());
  ui->position_y_value->setValue(this->cameraPosition.y());
  ui->position_z_value->setValue(this->cameraPosition.z());
}

void SceneSettings::setCameraRotation(const Vector3F &rotation)
{
  this->cameraRotation = rotation;
  ui->position_x_value->setValue(this->cameraRotation.x());
  ui->position_y_value->setValue(this->cameraRotation.y());
  ui->position_z_value->setValue(this->cameraRotation.z());
}

void SceneSettings::setCameraViewPlaneDistance(const double &value)
{
  this->viewPlaneDistance = value;
  ui->viewPlaneDistance_value->setValue(value);
}

void SceneSettings::setCameraViewPlaneWidth(const double &value)
{
  this->viewPlaneWidth = value;
  ui->viewPlaneWidth_value->setValue(value);
}

void SceneSettings::setCameraViewPlaneHeight(const double &value)
{
  this->viewPlaneHeight = value;
  ui->viewPlaneHeight_value->setValue(value);
}

void SceneSettings::handleValid()
{
  float x, y, z;
  x = (float)ui->position_x_value->value();
  y = (float)ui->position_y_value->value();
  z = (float)ui->position_z_value->value();
  this->cameraPosition = Vector3F(x, y, z);

  x = (float)ui->rotation_x_value->value();
  y = (float)ui->rotation_y_value->value();
  z = (float)ui->rotation_z_value->value();
  this->cameraRotation = Vector3F(x, y, z);

  this->viewPlaneDistance = ui->viewPlaneDistance_value->value();
  this->viewPlaneWidth = ui->viewPlaneWidth_value->value();
  this->viewPlaneHeight = ui->viewPlaneHeight_value->value();
}

void SceneSettings::handleCancel()
{
  ui->position_x_value->setValue(this->cameraPosition.x());
  ui->position_y_value->setValue(this->cameraPosition.y());
  ui->position_z_value->setValue(this->cameraPosition.z());

  ui->position_x_value->setValue(this->cameraRotation.x());
  ui->position_y_value->setValue(this->cameraRotation.y());
  ui->position_z_value->setValue(this->cameraRotation.z());

  ui->viewPlaneDistance_value->setValue(this->viewPlaneDistance);
  ui->viewPlaneWidth_value->setValue(this->viewPlaneWidth);
  ui->viewPlaneHeight_value->setValue(this->viewPlaneHeight);
}