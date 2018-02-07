#include <QApplication>
#include <QtWidgets>
#include <modules/newForm/newForm.h>
#include <ClientRepository.h>
#include <modules/mainWindow/mainWindow.h>
#include <QObject>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    mainWindow* instance = mainWindow::GetInstance();
    instance->show();
    app.exec();
}
