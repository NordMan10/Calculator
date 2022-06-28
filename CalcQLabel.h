#ifndef CALCQLABEL_H
#define CALCQLABEL_H

#include "LabelObserver.h"
#include <QLabel>

class CalcQLabel : public LabelObserver
{
public:
  CalcQLabel();
  CalcQLabel(std::string text);
  ~CalcQLabel() override;

  void Update(std::string text) override;
  QLabel* GetLabel() const;

private:
  QLabel* m_Label;
};

#endif // CALCQLABEL_H
