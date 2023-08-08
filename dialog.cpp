#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    hide();
    QString word=ui->lineEditWord->text();
    if(word.isEmpty()){
       main=new MainWindow(this);
    }else {
       main=new MainWindow(this,word.toUpper());
    }
    main->show();
}


void Dialog::on_lineEdit_returnPressed()
{
    on_buttonBox_accepted();
}

