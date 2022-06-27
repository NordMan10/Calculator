#ifndef IMODEL_H
#define IMODEL_H

#include <string>
#include "LabelObserver.h"

class IModel
{
public:
  virtual void Calculate() {};
  virtual void PushIntoInputLable(std::string) {};
  virtual void Backspace() {};

  virtual void AddMainInputLabelObserver(LabelObserver*) {};
  virtual void AddMainOutputLabelObserver(LabelObserver*) {};
  virtual void RemoveLabelObserver(LabelObserver*) {};
  virtual void NotifyMainInputLabelObservers(std::string) {};
  virtual void NotifyMainOutputLabelObservers(std::string) {};
};

#endif // IMODEL_H
