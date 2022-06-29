#ifndef CALCQLABEL_H
#define CALCQLABEL_H

#include "LabelObserver.h"
#include <QLabel>

class CalcQLabel : public LabelObserver
{
public:
  CalcQLabel();
  CalcQLabel(QString text);
  CalcQLabel(QLabel* label);
  ~CalcQLabel() override;

  void Update(QString text) override;
  QLabel* GetLabel() const;

private:
  QLabel* m_Label;
};

#endif // CALCQLABEL_H
