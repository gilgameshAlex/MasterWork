#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QFrame>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>



class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    FilterDialog();

    QString showDialog();

    void addItem(QString input);

    void applyList();

public slots:
    void on_addFilter_clicked();

    void on_apply_clicked();

private:
    QFrame *frame;
    QGridLayout *layout;
    QComboBox *combo;
    QComboBox *columnList;
    QLineEdit *valueLine;

    QLabel *conditionLabel;
    QLabel *columnLabel;
    QLabel *valueLabel;
    QLabel *selectLabel;
    QLabel *selectFilter;

    QPushButton *addFilter;
    QPushButton *apply;

    QStringList list;

    bool forAndSelect;

    QString resultFilter;
};

#endif // FILTERDIALOG_H
