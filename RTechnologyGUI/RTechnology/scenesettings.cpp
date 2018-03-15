#include "scenesettings.h"

SceneSettings::SceneSettings(QWidget *parent) :
	QDialog(parent),
	_viewPlaneDistance(1),
	_viewPlaneWidth(0.5),
	_viewPlaneHeight(0.35)
{
  ui = std::make_shared<Ui::SceneSettings>();
  ui->setupUi(this);

  connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(handleValid()));
  connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(handleCancel()));
}

SceneSettings::~SceneSettings()
{}

void SceneSettings::setCameraPosition(const rt::Vector3F &position)
{
  this->_cameraPosition = position;
  ui->position_x_value->setValue(this->_cameraPosition.x());
  ui->position_y_value->setValue(this->_cameraPosition.y());
  ui->position_z_value->setValue(this->_cameraPosition.z());
}

void SceneSettings::setCameraRotation(const rt::Vector3F &rotation)
{
  this->_cameraRotation = rotation;
  ui->position_x_value->setValue(this->_cameraRotation.x());
  ui->position_y_value->setValue(this->_cameraRotation.y());
  ui->position_z_value->setValue(this->_cameraRotation.z());
}

void SceneSettings::setCameraViewPlaneDistance(const double &value)
{
  this->_viewPlaneDistance = value;
  ui->viewPlaneDistance_value->setValue(value);
}

void SceneSettings::setCameraViewPlaneWidth(const double &value)
{
  this->_viewPlaneWidth = value;
  ui->viewPlaneWidth_value->setValue(value);
}

void SceneSettings::setCameraViewPlaneHeight(const double &value)
{
  this->_viewPlaneHeight = value;
  ui->viewPlaneHeight_value->setValue(value);
}

void SceneSettings::handleValid()
{
  float x, y, z;
  x = (float)ui->position_x_value->value();
  y = (float)ui->position_y_value->value();
  z = (float)ui->position_z_value->value();
  this->_cameraPosition = rt::Vector3F(x, y, z);

  x = (float)ui->rotation_x_value->value();
  y = (float)ui->rotation_y_value->value();
  z = (float)ui->rotation_z_value->value();
  this->_cameraRotation = rt::Vector3F(x, y, z);

  this->_viewPlaneDistance = ui->viewPlaneDistance_value->value();
  this->_viewPlaneWidth = ui->viewPlaneWidth_value->value();
  this->_viewPlaneHeight = ui->viewPlaneHeight_value->value();
}

void SceneSettings::handleCancel()
{
  ui->position_x_value->setValue(this->_cameraPosition.x());
  ui->position_y_value->setValue(this->_cameraPosition.y());
  ui->position_z_value->setValue(this->_cameraPosition.z());

  ui->rotation_x_value->setValue(this->_cameraRotation.x());
  ui->rotation_y_value->setValue(this->_cameraRotation.y());
  ui->rotation_z_value->setValue(this->_cameraRotation.z());

  ui->viewPlaneDistance_value->setValue(this->_viewPlaneDistance);
  ui->viewPlaneWidth_value->setValue(this->_viewPlaneWidth);
  ui->viewPlaneHeight_value->setValue(this->_viewPlaneHeight);
}

void SceneSettings::addToDocument(rapidjson::Document &doc)
{
  doc.AddMember("viewPlaneDistance", rapidjson::Value(this->_viewPlaneDistance), doc.GetAllocator());
  doc.AddMember("viewPlaneWidth", rapidjson::Value(this->_viewPlaneWidth), doc.GetAllocator());
  doc.AddMember("viewPlaneHeight", rapidjson::Value(this->_viewPlaneHeight), doc.GetAllocator());

  rapidjson::Value camObj;
  camObj.SetObject();

  if (this->_cameraPosition != rt::Vector3F())
    camObj.AddMember("position", SceneSettings::serializeVector(this->_cameraPosition, doc.GetAllocator()), doc.GetAllocator());
  if (this->_cameraRotation != rt::Vector3F())
    camObj.AddMember("rotation", SceneSettings::serializeVector(this->_cameraRotation, doc.GetAllocator()), doc.GetAllocator());

  doc.AddMember("camera", camObj, doc.GetAllocator());
}

rapidjson::Value SceneSettings::serializeVector(const rt::Vector3F &vec, rapidjson::Document::AllocatorType &allocator)
{
  rapidjson::Value obj;

  obj.SetObject();
  obj.AddMember("x", rapidjson::Value(vec.x()), allocator);
  obj.AddMember("y", rapidjson::Value(vec.y()), allocator);
  obj.AddMember("z", rapidjson::Value(vec.z()), allocator);
  return obj;
}