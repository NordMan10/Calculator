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
  virtual void DigitButtonClicked(QString) {};
  virtual void OperationButtonClicked(QString) {};
  virtual void Clean() {};
  virtual void CalculateResult() {};
  virtual void Backspace() {};
};

#endif // ICONTROLLER_H
