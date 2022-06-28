#include "DefaultModel.h"

DefaultModel::DefaultModel()
{

}

DefaultModel::~DefaultModel()
{

}

void DefaultModel::Calculate()
{

}

void DefaultModel::PushIntoInputLabel(std::string text)
{
  m_MainInputLabel += text;
  NotifyMainInputLabelObservers(m_MainInputLabel);
}

void DefaultModel::Backspace()
{
  m_MainInputLabel = m_MainInputLabel.substr(m_MainInputLabel.length() - 2, 1);
}

void DefaultModel::Clean()
{
  m_MainInputLabel = "";
}

void DefaultModel::AddMainInputLabelObserver(LabelObserver* observer)
{
  m_MainInputLabelObservers.push_back(observer);
}

void DefaultModel::AddMainOutputLabelObserver(LabelObserver* observer)
{
  m_MainOutputLabelObservers.push_back(observer);
}

void DefaultModel::RemoveMainInputLabelObserver(LabelObserver* observer)
{
  m_MainInputLabelObservers.erase(std::remove(m_MainInputLabelObservers.begin(), m_MainInputLabelObservers.end(),
                                              observer), m_MainInputLabelObservers.end());
}

void DefaultModel::RemoveMainOutputLabelObserver(LabelObserver* observer)
{
  m_MainOutputLabelObservers.erase(std::remove(m_MainOutputLabelObservers.begin(), m_MainOutputLabelObservers.end(),
                                              observer), m_MainOutputLabelObservers.end());
}

void DefaultModel::NotifyMainInputLabelObservers(std::string text)
{
  for (auto observer : m_MainInputLabelObservers)
  {
    observer->Update(text);
  }
}

void DefaultModel::NotifyMainOutputLabelObservers(std::string text)
{
  for (auto observer : m_MainOutputLabelObservers)
  {
    observer->Update(text);
  }
}
