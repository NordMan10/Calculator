#include "DefaultController.h"

DefaultController::DefaultController() {}

DefaultController::DefaultController(IModel* model)
  : m_Model(model) {}

DefaultController::~DefaultController()
{
  delete m_Model;
}

void DefaultController::DigitButtonClicked(QString value)
{
  m_Model->PushDigitIntoInputLabel(value);
}

void DefaultController::OperationButtonClicked(QString value)
{
  m_Model->PushOperationIntoInputLabel(value);
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
