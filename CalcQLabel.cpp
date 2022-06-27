#include "CalcQLabel.h"

CalcQLabel::CalcQLabel()
{
  m_Label = new QLabel();
}

CalcQLabel::CalcQLabel(std::string text)
{
  CalcQLabel();
  m_Label->setText(QString::fromStdString(text));
}

QLabel* CalcQLabel::GetLabel() const
{
  return m_Label;
}

void CalcQLabel::Update(std::string text)
{
  m_Label->setText(QString::fromStdString(text));
}
