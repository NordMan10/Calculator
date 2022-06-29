#ifndef LABELOBSERVER_H
#define LABELOBSERVER_H

#include <QString>

class LabelObserver
{
public:
  virtual ~LabelObserver() {};

  virtual void Update(QString) {};
};

#endif // LABELOBSERVER_H
