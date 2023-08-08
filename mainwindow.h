#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,QString msg="Mephisto");
    ~MainWindow();
    void refreshWord();
    int getNumberofFailures();
    void refreshNumberofFailures();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    QString toGuss;
    QVector<QString> keyStrockes;
    QVector<QString>images={
        ":/backgrounds/Hangman01.png",
        ":/backgrounds/Hangman02.png",
        ":/backgrounds/Hangman03.png",
        ":/backgrounds/Hangman04.png",
        ":/backgrounds/Hangman05.png",
        ":/backgrounds/Hangman06.png",
        ":/backgrounds/Hangman07.png",
        ":/backgrounds/Hangman08.png",
        ":/backgrounds/Hangman09.png",
        ":/backgrounds/Hangman10.png",
        ":/backgrounds/Hangman11.png",
        ":/backgrounds/Hangman12.png"
    };
};
#endif // MAINWINDOW_H
