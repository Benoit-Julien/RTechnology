#ifndef SCENESETTINGS_H
#define SCENESETTINGS_H

#include <QDialog>
#include <memory>
#include <Raytracer/math/Vector3.hpp>
#include <rapidjson/document.h>
#include "ui_scenesettings.h"

class SceneSettings : public QDialog
{
 Q_OBJECT

 private:
  std::shared_ptr<Ui::SceneSettings> ui;

  rt::Vector3F _cameraPosition;
  rt::Vector3F _cameraRotation;
  double _viewPlaneDistance;
  double _viewPlaneWidth;
  double _viewPlaneHeight;

 public:
  explicit SceneSettings(QWidget *parent = nullptr);
  ~SceneSettings();

  void setCameraPosition(const rt::Vector3F &position);
  inline const rt::Vector3F &getCameraPosition() const
  { return this->_cameraPosition; }

  void setCameraRotation(const rt::Vector3F &rotation);
  inline const rt::Vector3F &getCameraRotation() const
  { return this->_cameraRotation; }

  void setCameraViewPlaneDistance(const double &value);
  inline const double &getCameraViewPlaneDistance() const
  { return this->_viewPlaneDistance; }

  void setCameraViewPlaneWidth(const double &value);
  inline const double &getCameraViewPlaneWidth() const
  { return this->_viewPlaneWidth; }

  void setCameraViewPlaneHeight(const double &value);
  inline const double &getCameraViewPlaneHeight() const
  { return this->_viewPlaneHeight; }

  void addToDocument(rapidjson::Document &doc);

 private slots:
  void handleCancel();
  void handleValid();

 private:
  static rapidjson::Value serializeVector(const rt::Vector3F &vec, rapidjson::Document::AllocatorType &allocator);
};

#endif // SCENESETTINGS_H
