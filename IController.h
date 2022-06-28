#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QObject>
#include <string>

class IController : public QObject
{
  Q_OBJECT

public:
  virtual ~IController() {};

public slots:
  virtual void ChangeInput(std::string) {};
  virtual void Clean() {};
  virtual void CalculateResult() {};
  virtual void Backspace() {};
};

#endif // ICONTROLLER_H
