#include "MainWindow.h"

#include <QApplication>
#include "MainWindow.h"
#include "DefaultModel.h"
#include "DefaultController.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  IModel* model = new DefaultModel();
  IController* controller = new DefaultController(model);

  MainWindow w(model, controller);

  w.show();
  return a.exec();
}
