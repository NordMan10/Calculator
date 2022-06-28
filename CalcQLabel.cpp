#include "CalcQLabel.h"

CalcQLabel::CalcQLabel()
{
  m_Label = new QLabel();
}

CalcQLabel::CalcQLabel(std::string text)
{
  m_Label = new QLabel();
  m_Label->setText(QString::fromStdString(text));
}

CalcQLabel::~CalcQLabel()
{

}

QLabel* CalcQLabel::GetLabel() const
{
  return m_Label;
}

void CalcQLabel::Update(std::string text)
{
  m_Label->setText(QString::fromStdString(text));
}
