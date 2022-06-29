#ifndef IMODEL_H
#define IMODEL_H

#include <QObject>
#include <string>
#include "LabelObserver.h"

class IModel //: public QObject
{
  //Q_OBJECT
public:
  virtual ~IModel() {};

//public slots:
  virtual void Calculate() {};
  virtual void PushDigitIntoInputLabel(QString) {};
  virtual void PushOperationIntoInputLabel(QString) {};
  virtual void Backspace() {};
  virtual void Clean() {};

//public:
  virtual void AddMainInputLabelObserver(LabelObserver*) {};
  virtual void AddMainOutputLabelObserver(LabelObserver*) {};
  virtual void RemoveMainInputLabelObserver(LabelObserver*) {};
  virtual void RemoveMainOutputLabelObserver(LabelObserver*) {};
  virtual void NotifyMainInputLabelObservers(QString) {};
  virtual void NotifyMainOutputLabelObservers(QString) {};
};

#endif // IMODEL_H
