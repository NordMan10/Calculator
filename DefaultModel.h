#ifndef DEFAULTMODEL_H
#define DEFAULTMODEL_H

#include "IModel.h"

class DefaultModel : public IModel
{
public:
  DefaultModel();
  ~DefaultModel() override;

  void Calculate() override;
  void PushDigitIntoInputLabel(QString text) override;
  void PushOperationIntoInputLabel(QString text) override;
  void Backspace() override;
  void Clean() override;

  void AddMainInputLabelObserver(LabelObserver* observer) override;
  void AddMainOutputLabelObserver(LabelObserver* observer) override;
  void RemoveMainInputLabelObserver(LabelObserver* observer) override;
  void RemoveMainOutputLabelObserver(LabelObserver* observer) override;
  void NotifyMainInputLabelObservers(QString text) override;
  void NotifyMainOutputLabelObservers(QString text) override;

private:
  QString m_MainInputLabel;
  QString m_MainOutputLabel;

  std::vector<LabelObserver*> m_MainInputLabelObservers;
  std::vector<LabelObserver*> m_MainOutputLabelObservers;

  QList<QString> m_OperationList{"+", "-", "*", "/", "."};
};

#endif // DEFAULTMODEL_H
