#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>
#include<QString>
#include<iostream>

MainWindow::MainWindow(QWidget *parent,QString word)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), toGuss(word.toUpper())
{
    ui->setupUi(this);
    refreshWord();
    refreshNumberofFailures();
   // ui->Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/Hangman12.png")));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::refreshWord()
{
    QString output="";
    int numberOfFailures=getNumberofFailures();

    for (int i=0; i < toGuss.length() ;i++ ) {
        if(i != 0){
          output+=" ";
        }
        if(numberOfFailures == 11 || keyStrockes.contains(QString(toGuss[i]))){
            output+=toGuss[i];
        }
        else {
           output+="_";
        }
    }
    ui->Word->setText(output);

}
void MainWindow::keyPressEvent(QKeyEvent *event){
    int numberOfFailures=getNumberofFailures();
    if(numberOfFailures==11){
        return;
    }
    QString input = event->text().toUpper();
    if(!input.isEmpty()){
        keyStrockes.append(input);
        refreshWord();
        refreshNumberofFailures();
         std::cout<<"Taste wurde gedrueckt "
                  <<input.toStdString()
                  <<std::endl;
    }
}
int MainWindow::getNumberofFailures(){
    int numberofFail=0;
    for(QString key:keyStrockes){ // for(int i=0; i!=keyStrockes.size();i++) or Iterator
        if(!toGuss.contains(key.at(0))){
            numberofFail++;
        }
    }
    return numberofFail;
}
void MainWindow::refreshNumberofFailures(){
    //Fehler counter Aktualisieren
    int numberofFailures = getNumberofFailures();
    ui->numberofFailures->setText(QString::number(numberofFailures));
    //Galgen Aktualisieren
    ui->Background->setPixmap(QPixmap(images.at(numberofFailures)));
}

void MainWindow::on_resetButton_clicked()
{
    keyStrockes.clear();
    refreshWord();
    refreshNumberofFailures();
//    ui->Background->setPixmap(QPixmap(images.at(0)));

}

