#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("Все файлы (*.*)"));
}

void MainWindow::on_actionExit_triggered()
{
   close();
}
