#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <string>

class IController
{
public:
  virtual ~IController() {};

  virtual void ChangeInput(std::string) {};
  virtual void Clean() {};
  virtual void CalculateResult() {};
  virtual void Backspace() {};
};

#endif // ICONTROLLER_H
