#ifndef SCENESETTINGS_H
#define SCENESETTINGS_H

#include <QDialog>
#include <memory>
#include <Raytracer/math/Vector3.hpp>
#include "ui_scenesettings.h"

class SceneSettings : public QDialog
{
 Q_OBJECT

 private:
  Vector3F cameraPosition;
  Vector3F cameraRotation;
  double viewPlaneDistance;
  double viewPlaneWidth;
  double viewPlaneHeight;

 public:
  explicit SceneSettings(QWidget *parent = nullptr);
  ~SceneSettings();

  void setCameraPosition(const Vector3F &position);
  inline const Vector3F &getCameraPosition() const
  { return this->cameraPosition; }

  void setCameraRotation(const Vector3F &rotation);
  inline const Vector3F &getCameraRotation() const
  { return this->cameraRotation; }

  void setCameraViewPlaneDistance(const double &value);
  inline const double &getCameraViewPlaneDistance() const
  { return this->viewPlaneDistance; }

  void setCameraViewPlaneWidth(const double &value);
  inline const double &getCameraViewPlaneWidth() const
  { return this->viewPlaneWidth; }

  void setCameraViewPlaneHeight(const double &value);
  inline const double &getCameraViewPlaneHeight() const
  { return this->viewPlaneHeight; }

 private slots:
  void handleCancel();
  void handleValid();

 private:
  std::shared_ptr<Ui::SceneSettings> ui;
};

#endif // SCENESETTINGS_H
