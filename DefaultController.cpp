#include "DefaultController.h"

DefaultController::DefaultController() {}

DefaultController::DefaultController(IModel* model)
  : m_Model(model) {}

DefaultController::~DefaultController()
{
  delete m_Model;
}

void DefaultController::ChangeInput(std::string value)
{
  m_Model->PushIntoInputLabel(value);
}

void DefaultController::Clean()
{
  m_Model->Clean();
}

void DefaultController::CalculateResult()
{
  m_Model->Calculate();
}

void DefaultController::Backspace()
{
  m_Model->Backspace();
}
