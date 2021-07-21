#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "QtDebug"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetFasta->setColumnCount(1);
    ui->tableWidgetFasta->setHorizontalHeaderItem(0, new QTableWidgetItem("File Path"));
    ui->tableWidgetRaw->setColumnCount(1);
    ui->tableWidgetRaw->setHorizontalHeaderItem(0, new QTableWidgetItem("File Path"));
    csvToTableWidget(ui->tableWidgetPTM,":/Table/Table/PTM.csv");
    csvToTableWidget(ui->tableWidgetAmino,":/Table/Table/Element.csv");
    csvToTableWidget(ui->tableWidgetIsotope,":/Table/Table/Isotope.csv");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    config::getConfig().readMainWindow(ui);
    qInfo() << config::getConfig().searchType;
    qInfo() << config::getConfig().searchName;
    qInfo() << config::getConfig().fragmentationMethod;
    qInfo() << config::getConfig().parentMassWindows;
    qInfo() << config::getConfig().fastaDB;
    qInfo() << config::getConfig().rawFiles;
    qInfo() << config::getConfig().Minimum_Peptide_Length;
    qInfo() << config::getConfig().Maximum_Peptide_Length;
    qInfo() << config::getConfig().Search_Mass_Tolerance_Parent_Ion;
    qInfo() << config::getConfig().Mass_Tolerance_Fragment_Ions;
}

void MainWindow::on_pushButtonFastaAdd_clicked()
{
   QStringList fileNames=QFileDialog::getOpenFileNames(this,"Choose Fasta",
                                                 "/home","Fasta (*.fa *.fasta)");
   if (!fileNames.isEmpty())
   {
       QTableWidget *fasta=ui->tableWidgetFasta;
       int nFasta=fileNames.length();
       int nRow=fasta->rowCount();
       fasta->setRowCount(nRow+nFasta);
       for (auto r=0; r<nFasta; r++)
       {
           fasta->setItem(nRow+r-1,1, new QTableWidgetItem(fileNames[r]));
       }
       QHeaderView* header = fasta ->horizontalHeader();
       header->setSectionResizeMode(0,QHeaderView::Stretch);
   }
}

void MainWindow::on_pushButtonFastaDel_clicked()
{
    ui->tableWidgetFasta->setRowCount(0);
}

void MainWindow::on_pushButtonRawFileAdd_clicked()
{
   QStringList fileNames=QFileDialog::getOpenFileNames(this,"Choose MS File",
                                                 "/home","Raw (*.raw);;MS2 (*.ms2)");
   if (!fileNames.isEmpty())
   {
       QTableWidget *raw=ui->tableWidgetRaw;
       int nraw=fileNames.length();
       int nRow=raw->rowCount();
       raw->setRowCount(nRow+nraw);
       for (auto r=0; r<nraw; r++)
       {
           raw->setItem(nRow+r-1,1, new QTableWidgetItem(fileNames[r]));
       }
       QHeaderView* header = raw ->horizontalHeader();
       header->setSectionResizeMode(0,QHeaderView::Stretch);
   }
}

void MainWindow::on_pushButtonRawFileDel_clicked()
{
    ui->tableWidgetRaw->setRowCount(0);
}

void MainWindow::csvToTableWidget(QTableWidget *table, QString csvName)
{
    table->setRowCount(0);
    QFile csv(csvName);
    QString data;
    QStringList rowOfData;
    QStringList rowData;
    if (csv.open(QFile::ReadOnly))
    {
        QString data = csv.readAll();
        QStringList rowOfData = data.split("\n");
        csv.close();
        table->setRowCount(rowOfData.size());
        table->setColumnCount(10);
        for (int x = 0; x < rowOfData.size(); x++)
        {
            rowData = rowOfData.at(x).split(",");
            for (int y = 0; y < rowData.size(); y++)
            {
                //table->item(x,y)->setText(rowData[y]);
                QTableWidgetItem *Items= new QTableWidgetItem(rowData[y]);
                table->setItem(x,y,Items);
            }
        }
    }
}
