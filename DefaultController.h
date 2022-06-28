#ifndef DEFAULTCONTROLLER_H
#define DEFAULTCONTROLLER_H

#include "IController.h"
#include "IModel.h"

class DefaultController : public IController
{
public:
  DefaultController();

  DefaultController(IModel* model);
  ~DefaultController() override;

  void ChangeInput(std::string value) override;
  void Clean() override;
  void CalculateResult() override;
  void Backspace() override;

private:
  IModel* m_Model;
};

#endif // DEFAULTCONTROLLER_H
