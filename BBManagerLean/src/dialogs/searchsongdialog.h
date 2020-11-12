#ifndef SEARCHSONGDIALOG_H
#define SEARCHSONGDIALOG_H

#include <QDialog>

namespace Ui {
class SearchSongDialog;
}

class SearchSongDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchSongDialog(QWidget *parent = nullptr);
    ~SearchSongDialog();

private slots:
    void on_songSearchEdit_textChanged(const QString &arg1);

private:
    Ui::SearchSongDialog *ui;
};

#endif // SEARCHSONGDIALOG_H
