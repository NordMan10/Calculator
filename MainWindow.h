#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IModel.h"
#include "IController.h"
#include "CalcQLabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  MainWindow(IModel* model, IController* controller);

  ~MainWindow();

private:
  Ui::MainWindow* ui;
  IModel* m_Model;
  IController* m_Controller;

  CalcQLabel* m_MainInputLabel;
  CalcQLabel* m_MainOutputLabel;
};
#endif // MAINWINDOW_H
