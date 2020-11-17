#ifndef FILTERSONGSDIALOG_H
#define FILTERSONGSDIALOG_H

#include <QDialog>
#include <QItemSelectionModel>

namespace Ui {
class FilterSongsDialog;
}

class FilterSongsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterSongsDialog(QWidget *parent = nullptr);
    ~FilterSongsDialog();

private slots:
    void on_filterSongsEdit_textChanged(const QString &arg1);
    void on_caseSensitiveCB_stateChanged(int arg1);

private:
    Ui::FilterSongsDialog *ui;
    QItemSelectionModel *getSongsSelectionModel();
    void debugModel(QItemSelectionModel * model);
    void updateUI(const QString &arg1);
};

#endif // FILTERSONGSDIALOG_H
