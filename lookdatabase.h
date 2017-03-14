#ifndef LOOKDATABASE_H
#define LOOKDATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class LookDataBase;
}

class LookDataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit LookDataBase(QWidget *parent = 0);
    ~LookDataBase();

    void russianColumn(QString input);

    QStringList russianListView(QStringList input, int mode);

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_goMainMenu_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_save_clicked();

    void on_add_clicked();

    void on_delete_2_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_exportCSV_clicked();

    void on_filter_clicked();

    void on_deleteFilter_clicked();

private:
    Ui::LookDataBase *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int rowForDelete;

signals:
    void signalSettingToMainMenu();
};

#endif // LOOKDATABASE_H
