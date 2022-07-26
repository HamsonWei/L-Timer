#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer_sec = new QTimer(this);
    connect(Timer_sec, SIGNAL(timeout()), this, SLOT(update_timer_sec()));
    update_timer_sec();
    Timer_sec->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Timer_sec;
}


void MainWindow::on_infoBtn_clicked()
{
    QLocale myLocation;
    QMessageBox msgBox;
    msgBox.setIconPixmap(QPixmap(":/img/timer.png"));

    msgBox.setWindowTitle("About");
    msgBox.setText("L-Clock V1.0\n"
                   "Hamson@leee.tech\n"
                   "July 2, 2019\n\n"
                   "ICON: ICONS8(icons8.com)\n\n"
                   "Base on Qt.");
    msgBox.exec();
}

void MainWindow::update_timer_sec()
{
    QDateTime cDateTime = QDateTime::currentDateTime();
    QString myCTimeStr = cDateTime.toString("hh:mm:ss");
    QString myCDateStr = cDateTime.toString("ddd, MMMM dd, yyyy");
    ui->timeLabel->setText(myCTimeStr);
    ui->dateLabel->setText(myCDateStr);
}
