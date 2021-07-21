#include "config.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

config::config()
{

}

config& config::getConfig(){
    static config mConfig;
    return mConfig;
}

void config::readMainWindow(Ui::MainWindow *ui)
{
    searchName=ui->lineEditSearchName->text().trimmed();

    QButtonGroup *buttonGroupSeachType=new QButtonGroup;
    buttonGroupSeachType->addButton(ui->radioButtonDDA,1);
    buttonGroupSeachType->addButton(ui->radioButtonDIA,2);
    buttonGroupSeachType->addButton(ui->radioButtonSIP,3);
    buttonGroupSeachType->addButton(ui->radioButtonMutation,4);
    switch (buttonGroupSeachType->checkedId())
    {
        case 1: searchType="DDA";break;
        case 2: searchType="DIA";break;
        case 3: searchType="SIP";break;
        case 4: searchType="Mutation";break;
    };

    fastaDB.clear();
    QTableWidget *fasta=ui->tableWidgetFasta;
    int nFasta=fasta->rowCount();
    for (int i=0;i<nFasta;i++)
    {
        fastaDB.append(fasta->model()->index(i,0).data().toString());
    }

    rawFiles.clear();
    QTableWidget *raw=ui->tableWidgetRaw;
    int nRaw=raw->rowCount();
    for (int i=0;i<nRaw;i++)
    {
        rawFiles.append(raw->model()->index(i,0).data().toString());
    }

    QButtonGroup *buttonGroupFragmentationMethod=new QButtonGroup;
    buttonGroupFragmentationMethod->addButton(ui->radioButtonCID,1);
    buttonGroupFragmentationMethod->addButton(ui->radioButtonHCD,2);
    buttonGroupFragmentationMethod->addButton(ui->radioButtonETD,3);
    switch (buttonGroupFragmentationMethod->checkedId())
    {
        case 1: fragmentationMethod="CID";break;
        case 2: fragmentationMethod="HCD";break;
        case 3: fragmentationMethod="ETD";break;
    };

    parentMassWindows.clear();
    if(ui->checkBoxPminus1->isChecked()) parentMassWindows.append(-1);
    if(ui->checkBoxP0->isChecked()) parentMassWindows.append(0);
    if(ui->checkBoxP1->isChecked()) parentMassWindows.append(1);
    if(ui->checkBoxP2->isChecked()) parentMassWindows.append(2);
    if(ui->checkBoxP3->isChecked()) parentMassWindows.append(3);

    Minimum_Peptide_Length=ui->spinBoxPepLenMin->value();
    Maximum_Peptide_Length=ui->spinBoxPepLenMax->value();

    Search_Mass_Tolerance_Parent_Ion=ui->doubleSpinBoxPrecursorTolerance->value();
    Mass_Tolerance_Fragment_Ions=ui->doubleSpinBoxFragmentTolerance->value();

    Cleave_After_Residues=ui->lineEditCleaveAfterResidue->text().trimmed();
    Cleave_Before_Residues=ui->lineEditCleaveBeforeResidue->text().trimmed();


}






