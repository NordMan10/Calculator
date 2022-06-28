#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  Initialize();

}

MainWindow::MainWindow(IModel* model, IController* controller)
  : m_Model(model), m_Controller(controller)
{
  MainWindow();
}

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
  QSignalMapper* signalMapper = new QSignalMapper(this);

  QObject::connect(ui->one_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
  signalMapper->setMapping(ui->one_button, "1");
  connect(signalMapper, SIGNAL(mapped(std::string)), this, SLOT(ChangeInputButtonClicked(std::string)));
//  connect(ui->two_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked()));
//  connect(ui->three_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->four_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->five_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->six_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->seven_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->eight_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->nine_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->zero_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->double_zero_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->plus_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->minus_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->multiply_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->divide_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));
//  connect(ui->dot_button, SIGNAL(clicked()), this, SLOT(ChangeInputButtonClicked(std::string value)));

  connect(ui->equals_button, SIGNAL(clicked()), this, SLOT(GetResult()));
  connect(ui->backspace_button, SIGNAL(clicked()), this, SLOT(Backspace()));
  connect(ui->c_button, SIGNAL(clicked()), this, SLOT(Clean()));

  //
  m_Model->AddMainInputLabelObserver(m_MainInputLabel);
  m_Model->AddMainOutputLabelObserver(m_MainOutputLabel);
}

void MainWindow::ChangeInputButtonClicked(std::string value)
{
  m_Controller->ChangeInput(value);
}

void MainWindow::Clean()
{
  m_Controller->Clean();
}

void MainWindow::Backspace()
{
  m_Controller->Backspace();
}

void MainWindow::GetResult()
{
  m_Controller->CalculateResult();
}

