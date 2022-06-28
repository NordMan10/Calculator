#ifndef LABELOBSERVER_H
#define LABELOBSERVER_H

#include <string>

class LabelObserver
{
public:
  virtual ~LabelObserver() {};

  virtual void Update(std::string) {};
};

#endif // LABELOBSERVER_H
