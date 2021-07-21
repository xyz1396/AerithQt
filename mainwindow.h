#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSave_triggered();

    void on_pushButtonFastaAdd_clicked();

    void on_pushButtonFastaDel_clicked();

    void on_pushButtonRawFileAdd_clicked();

    void on_pushButtonRawFileDel_clicked();

private:
    Ui::MainWindow *ui;
    void csvToTableWidget(QTableWidget *table, QString csvName);
};
#endif // MAINWINDOW_H
