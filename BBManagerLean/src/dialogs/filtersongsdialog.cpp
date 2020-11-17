#include <QDebug>
#include <QSortFilterProxyModel>

#include "filtersongsdialog.h"
#include "ui_filtersongsdialog.h"
#include "mainwindow.h"

FilterSongsDialog::FilterSongsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterSongsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Filter songs..."));
    ui->caseSensitiveCB->setText(tr("Case sensitive"));
}


FilterSongsDialog::~FilterSongsDialog()
{
    delete ui;
}

void FilterSongsDialog::on_filterSongsEdit_textChanged(const QString &arg1)
{
    qDebug() << "Filtering songs using: " << arg1;
    QItemSelectionModel * selectionmodel = getSongsSelectionModel();
    debugModel(selectionmodel);
    SongFolderProxyModel* model = qobject_cast<SongFolderProxyModel *>(selectionmodel->model());
    model->setRecursiveFilteringEnabled(true);
    if (ui->caseSensitiveCB->isChecked()) {
        model->setFilterCaseSensitivity(Qt::CaseSensitivity::CaseSensitive);
    } else {
        model->setFilterCaseSensitivity(Qt::CaseSensitivity::CaseInsensitive);
    }
    model->setFilterFixedString(arg1);
}

void FilterSongsDialog::updateUI(const QString &arg1)
{
    if (arg1.isEmpty()) {

    }
}

void FilterSongsDialog::debugModel (QItemSelectionModel * selectionmodel)
{
    qDebug() << "hasSelection: " << selectionmodel->hasSelection();
    qDebug() << "model: " << selectionmodel->model();
}


QItemSelectionModel * FilterSongsDialog::getSongsSelectionModel()
{
    return qobject_cast<MainWindow *>(parent())->mp_ProjectExplorerPanel->beatsSelectionModel();
}


void FilterSongsDialog::on_caseSensitiveCB_stateChanged(int arg1)
{
    qDebug() << "Case sensitivity CB status: " << arg1;
    emit on_filterSongsEdit_textChanged(ui->filterSongsEdit->text());
}
