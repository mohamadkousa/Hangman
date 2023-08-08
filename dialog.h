#ifndef DIALOG_H
#define DIALOG_H

#include "mainwindow.h"
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_lineEdit_returnPressed();

private:
    Ui::Dialog *ui;
    MainWindow *main;
};

#endif // DIALOG_H
