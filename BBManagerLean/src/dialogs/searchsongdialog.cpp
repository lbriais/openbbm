#include <QDebug>

#include "searchsongdialog.h"
#include "ui_searchsongdialog.h"

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

}
