#ifndef DEFAULTMODEL_H
#define DEFAULTMODEL_H

#include "IModel.h"

class DefaultModel : public IModel
{
public:
  DefaultModel();
  ~DefaultModel() override;

  void Calculate() override;
  void PushIntoInputLable(std::string text) override;
  void Backspace() override;

  void AddMainInputLabelObserver(LabelObserver* observer) override;
  void AddMainOutputLabelObserver(LabelObserver* observer) override;
  void RemoveLabelObserver(LabelObserver* observer) override;
  void NotifyMainInputLabelObservers(std::string text) override;
  void NotifyMainOutputLabelObservers(std::string text) override;

private:
  std::string m_MainInputString;
  std::string m_MainOutputString;
};

#endif // DEFAULTMODEL_H
