#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    M_Player = new QMediaPlayer();

    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    M_Player->setVolume(ui->horizontalSlider_Volume_Control->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_File_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"",tr("MP3 Files (*.MP3)"));
    M_Player->setMedia(QUrl("file://" + FileName));

    QFileInfo File(FileName);

    ui->lbl_Value_File_Name->setText(File.fileName());
}


void MainWindow::on_pushButton_Play_clicked()
{
    M_Player->play();
}


void MainWindow::on_pushButton_Pause_clicked()
{
    M_Player->stop();
}


void MainWindow::on_horizontalSlider_Volume_Control_valueChanged(int value)
{
    M_Player->setVolume(value);
}

