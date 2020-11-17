#include <QDebug>
#include <QSortFilterProxyModel>

#include "searchsongdialog.h"
#include "ui_searchsongdialog.h"
#include "mainwindow.h"

SearchSongDialog::SearchSongDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchSongDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Search song..."));
    ui->caseSensitiveCB->setText(tr("Case sensitive"));
}


SearchSongDialog::~SearchSongDialog()
{
    delete ui;
}

void SearchSongDialog::on_songSearchEdit_textChanged(const QString &arg1)
{
    qDebug() << "Searching for song matching: " << arg1;
    QItemSelectionModel * selectionmodel = getSearchSelectionModel();
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

void SearchSongDialog::updateUI(const QString &arg1)
{
    if (arg1.isEmpty()) {

    }
}

void SearchSongDialog::debugModel (QItemSelectionModel * selectionmodel)
{
    qDebug() << "hasSelection: " << selectionmodel->hasSelection();
    qDebug() << "model: " << selectionmodel->model();
}


QItemSelectionModel * SearchSongDialog::getSearchSelectionModel()
{
    return qobject_cast<MainWindow *>(parent())->mp_ProjectExplorerPanel->beatsSelectionModel();
}


void SearchSongDialog::on_caseSensitiveCB_stateChanged(int arg1)
{
    qDebug() << "Case sensitivity CB status: " << arg1;
    emit on_songSearchEdit_textChanged(ui->songSearchEdit->text());
}
