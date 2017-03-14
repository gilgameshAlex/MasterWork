#include "filterdialog.h"
#include "lookdatabase.h"

#include <QMessageBox>


FilterDialog::FilterDialog()
{
    this->setWindowTitle("Настройка фильтрации");
    forAndSelect = false;

    layout = new QGridLayout(this);

    combo = new QComboBox(this);
    combo->addItem("=", 1);
    combo->addItem(">", 2);
    combo->addItem("<", 3);
    combo->addItem("<>", 4);

    columnList = new QComboBox(this);

    valueLine = new QLineEdit(this);
    valueLine->setPlaceholderText("введите значение...");


    conditionLabel = new QLabel("Условие: ", this);
    columnLabel = new QLabel("Поля фильтрации: ", this);
    valueLabel = new QLabel("Значение: ", this);
    selectLabel = new QLabel("Выбранные фильтры: ", this);
    selectFilter = new QLabel(" ", this);

    addFilter = new QPushButton("Добавить", this);
    addFilter->setObjectName("addFilter");
    connect(addFilter, SIGNAL(clicked()), this, SLOT(on_addFilter_clicked()));
    apply = new QPushButton("Применить", this);
    apply->setObjectName("apply");
    connect(apply, SIGNAL(clicked()), this, SLOT(on_apply_clicked()));

    layout->addWidget(columnLabel, 0, 0);
    layout->addWidget(columnList, 0, 1);

    layout->addWidget(conditionLabel, 1, 0);
    layout->addWidget(combo, 1, 1);

    layout->addWidget(valueLabel, 2, 0);
    layout->addWidget(valueLine, 2, 1);

    layout->addWidget(selectLabel, 3, 0);
    layout->addWidget(selectFilter, 3, 1);

    layout->addWidget(addFilter, 4, 0);
    layout->addWidget(apply, 4, 1);
}

QString FilterDialog::showDialog()
{
    this->exec();
    return resultFilter;
}

void FilterDialog::addItem(QString input)
{
    list.append(input);
}

void FilterDialog::applyList()
{
    columnList->addItems(list);
}

void FilterDialog::on_addFilter_clicked()
{
    if(valueLine->text().isEmpty())
    {
        QMessageBox msg;
        msg.setText("Введите значение фильтра");
        msg.exec();
    }
    else
    {
        if(!forAndSelect)
        {
            selectFilter->setText(selectFilter->text() +
                              columnList->currentText() +
                              combo->currentText() +
                              "'" +
                              valueLine->text() +
                              "'" +
                              "\n");
            forAndSelect = true;
        }
        else
        {
            selectFilter->setText(selectFilter->text() +
                              "AND " +
                              columnList->currentText() +
                              combo->currentText() +
                              "'" +
                              valueLine->text() +
                              "'" +
                              "\n");
        }
    }

}

void FilterDialog::on_apply_clicked()
{
    resultFilter = selectFilter->text();
    resultFilter.replace("\n", " ");
    this->close();
}
