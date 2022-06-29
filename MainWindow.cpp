#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

}

MainWindow::MainWindow(IModel* model, IController* controller)
  : ui(new Ui::MainWindow), m_Model(model), m_Controller(controller)
{
  ui->setupUi(this);

  Initialize();
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
  m_MainInputLabel = new CalcQLabel(ui->input_label);
  m_MainOutputLabel = new CalcQLabel(ui->output_label);

  //m_SignalMapper = new QSignalMapper(this);

//  QObject::connect(ui->one_button, SIGNAL(clicked(bool)), m_SignalMapper, SLOT(map()));
//  m_SignalMapper->setMapping(ui->one_button, ui->one_button->text());
  connect(ui->one_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->one_button->text()); });
  connect(ui->two_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->two_button->text()); });
  connect(ui->three_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->three_button->text()); });
  connect(ui->four_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->four_button->text()); });
  connect(ui->five_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->five_button->text()); });
  connect(ui->six_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->six_button->text()); });
  connect(ui->seven_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->seven_button->text()); });
  connect(ui->eight_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->eight_button->text()); });
  connect(ui->nine_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->nine_button->text()); });
  connect(ui->zero_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->zero_button->text()); });
  connect(ui->double_zero_button, &QPushButton::clicked, this, [this](){ DigitButtonClicked(ui->double_zero_button->text()); });

  connect(ui->plus_button, &QPushButton::clicked, this, [this](){ OperationButtonClicked(ui->plus_button->text()); });
  connect(ui->minus_button, &QPushButton::clicked, this, [this](){ OperationButtonClicked(ui->minus_button->text()); });
  connect(ui->multiply_button, &QPushButton::clicked, this, [this](){ OperationButtonClicked(ui->multiply_button->text()); });
  connect(ui->divide_button, &QPushButton::clicked, this, [this](){ OperationButtonClicked(ui->divide_button->text()); });
  connect(ui->dot_button, &QPushButton::clicked, this, [this](){ OperationButtonClicked(ui->dot_button->text()); });

  connect(ui->equals_button, &QPushButton::clicked, this, [this](){ GetResult(); });
  connect(ui->backspace_button, &QPushButton::clicked, this, [this](){ Backspace(); });
  connect(ui->c_button, &QPushButton::clicked, this, [this](){ Clean(); });

  //
  m_Model->AddMainInputLabelObserver(m_MainInputLabel);
  m_Model->AddMainOutputLabelObserver(m_MainOutputLabel);
}

void MainWindow::DigitButtonClicked(QString value)
{
  m_Controller->DigitButtonClicked(value);
}

void MainWindow::OperationButtonClicked(QString value)
{
  m_Controller->OperationButtonClicked(value);
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

