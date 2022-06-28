#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);



}

MainWindow::MainWindow(IModel* model, IController* controller)
  : m_Model(model), m_Controller(controller) {}

MainWindow::~MainWindow()
{
  delete ui;
  delete m_Model;
  delete m_Controller;
  delete m_MainInputLabel;
  delete m_MainOutputLabel;
}

void MainWindow::Initialize()
{

}
