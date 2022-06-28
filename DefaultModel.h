#ifndef DEFAULTMODEL_H
#define DEFAULTMODEL_H

#include "IModel.h"

class DefaultModel : public IModel
{
public:
  DefaultModel();
  ~DefaultModel() override;

  void Calculate() override;
  void PushIntoInputLabel(std::string text) override;
  void Backspace() override;
  void Clean() override;

  void AddMainInputLabelObserver(LabelObserver* observer) override;
  void AddMainOutputLabelObserver(LabelObserver* observer) override;
  void RemoveMainInputLabelObserver(LabelObserver* observer) override;
  void RemoveMainOutputLabelObserver(LabelObserver* observer) override;
  void NotifyMainInputLabelObservers(std::string text) override;
  void NotifyMainOutputLabelObservers(std::string text) override;

private:
  std::string m_MainInputLabel;
  std::string m_MainOutputLabel;

  std::vector<LabelObserver*> m_MainInputLabelObservers;
  std::vector<LabelObserver*> m_MainOutputLabelObservers;
};

#endif // DEFAULTMODEL_H
