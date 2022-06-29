#include "CalcQLabel.h"

CalcQLabel::CalcQLabel()
{
  m_Label = new QLabel();
}

CalcQLabel::CalcQLabel(QString text)
{
  m_Label = new QLabel();
  m_Label->setText(text);
}

CalcQLabel::CalcQLabel(QLabel* label)
  : m_Label(label) {}

CalcQLabel::~CalcQLabel()
{
  delete m_Label;
}

QLabel* CalcQLabel::GetLabel() const
{
  return m_Label;
}

void CalcQLabel::Update(QString text)
{
  m_Label->setText(text);
}
