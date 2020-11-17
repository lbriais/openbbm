#ifndef SEARCHSONGDIALOG_H
#define SEARCHSONGDIALOG_H

#include <QDialog>
#include <QItemSelectionModel>

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
    void on_caseSensitiveCB_stateChanged(int arg1);

private:
    Ui::SearchSongDialog *ui;
    QItemSelectionModel *getSearchSelectionModel();
    void debugModel(QItemSelectionModel * model);
    void updateUI(const QString &arg1);
};

#endif // SEARCHSONGDIALOG_H
