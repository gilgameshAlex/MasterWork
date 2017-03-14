#include "lookdatabase.h"
#include "ui_lookdatabase.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QStringListModel>
#include <QTextDocument>
#include <QTime>
#include "filterdialog.h"
#include <QHeaderView>

LookDataBase::LookDataBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LookDataBase)
{
    ui->setupUi(this);

    rowForDelete = -1;

    connect(ui->goMainMenu, SIGNAL(clicked()), this, SIGNAL(signalSettingToMainMenu()));
    QSettings settings("GatesB", "MakeMeSchedule");

    this->db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(settings.value("SETTING/ADDRESS_DB","").toString());
    db.setDatabaseName(settings.value("SETTING/NAME_DB","").toString());
    db.setUserName(settings.value("SETTING/USER_DB","").toString());
    db.setPassword(settings.value("SETTING/PASSWORD_DB","").toString());
    db.setPort(settings.value("SETTING/PORT_DB","").toInt());
    db.open();

    QStringList listTables;
    listTables = db.tables(QSql::Tables);
    if(listTables.isEmpty())
    {
        QMessageBox q;
        q.setText("WARNING:\ndata base is empty");
        q.exec();
    }
    else
    {
        //QButtonGroup bg;
        //bg.addButton(new QPushButton(listTables[0], ui->groupBox));
        //bg.setParent(ui->groupBox);
        //bg.setExclusive(false);

        //ui->comboBox->addItems(listTables);
        QStringListModel *qlm = new QStringListModel(russianListView(listTables,1));
        ui->listView->setModel(qlm);
        ui->listView->show();
        //on_listView_clicked(QModelIndex());
        //ui->listView->activated(qlm->index(0,0));
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(listTables[0]);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        ui->tableView->setModel(model);

    }
}

LookDataBase::~LookDataBase()
{
    delete ui;
}

void LookDataBase::on_comboBox_activated(const QString &arg1)
{
    /*!
      *Константа	Значение	Описание
      *QSqlTableModel::OnFieldChange	0	Все изменения модели будут применены непосредственно к БД
      *QSqlTableModel::OnRowChange	    1	Изменения строки будут применены, когда пользователь выберет другую строку.
      *QSqlTableModel::OnManualSubmit	2	Все изменения будут кэшироваться в модели пока не будут вызваны submitAll() или revertAll().
    */
    model = new QSqlTableModel;
    model->setTable(arg1);
    model->setSort(0,Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!model->select())
    {
        QMessageBox q;
        q.setText(model->lastError().text());
        q.exec();
    }
    russianColumn(arg1);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void LookDataBase::on_goMainMenu_clicked()
{
    this->db.close();
    this->setVisible(false);
}

void LookDataBase::on_tableView_clicked(const QModelIndex &index)
{
    ui->tableView->selectRow(index.row());
    rowForDelete = index.row();
}

void LookDataBase::on_save_clicked()
{
    if(!this->model->submitAll())
    {
        QMessageBox q;
        q.setText(model->lastError().text());
        q.exec();
    }
    ui->tableView->resizeColumnsToContents();
    ui->tableView->repaint();
}

void LookDataBase::on_add_clicked()
{
   int newRow = model->rowCount();
   if(!model->insertRow(newRow))
   {
       QMessageBox q;
       q.setText(model->lastError().text());
       q.exec();
   }
   model->setData(model->index(newRow,0), "");
   ui->tableView->resizeColumnsToContents();
   ui->tableView->repaint();
}

void LookDataBase::on_delete_2_clicked()
{
    if(rowForDelete != -1
            && !model->removeRow(this->rowForDelete))
    {
        QMessageBox q;
        q.setText(model->lastError().text());
        q.exec();
    }
    else
    {   model->submitAll();
        ui->tableView->resizeColumnsToContents();
        ui->tableView->repaint();
    }
}

QStringList LookDataBase::russianListView(QStringList input, int mode)
{
    QStringList output;
    if(mode == 1)
    {
        if(input.contains("groups"))
            output.append("Группы");
        if(input.contains("lecture_halls"))
            output.append("Аудиторный фонд");
        if(input.contains("faculty"))
            output.append("Факультеты");
        if(input.contains("subjects_teacher"))
            output.append("Преподаватели+предметы");
        if(input.contains("teachers"))
            output.append("Преподаватели");
        if(input.contains("wishes_teachers"))
            output.append("Ограничения преподавателей");
        if(input.contains("schedule_alarm"))
            output.append("Расписание звонков");
        if(input.contains("schedule"))
            output.append("Расписание");
        return input;
    }
    if(mode == 2)
    {
        if(input.contains("Группы"))
        {
            output.append("groups");
            return output;
        }
        if(input.contains("Аудиторный фонд"))
        {
            output.append("lecture_halls");
            return output;
        }
        if(input.contains("Факультеты"))
        {
            output.append("faculty");
            return output;
        }
        if(input.contains("Преподаватели+предметы"))
        {
            output.append("subjects_teacher");
            return output;
        }
        if(input.contains("Преподаватели"))
        {
            output.append("teachers");
            return output;
        }
        if(input.contains("Ограничения преподавателей"))
        {
            output.append("wishes_teachers");
            return output;
        }
        if(input.contains("Расписание звонков"))
        {
            output.append("schedule_alarm");
            return output;
        }
        if(input.contains("Расписание"))
        {
            output.append("schedule");
            return output;
        }
    }
    return input;
}

void LookDataBase::russianColumn(QString input)
{
    if(input == "groups")
    {
        model->setHeaderData(0,Qt::Horizontal, "Идентификатор\nфакультета");

        model->setHeaderData(1,Qt::Horizontal, "Код\nфакультета");

        model->setHeaderData(2,Qt::Horizontal, "Идентификатор\nгруппы");

        model->setHeaderData(3,Qt::Horizontal, "Номер\nгруппы");

        model->setHeaderData(4,Qt::Horizontal, "Количество\nстудентов");
        return;
    }

    if(input == "lecture_halls")
    {
        model->setHeaderData(0,Qt::Horizontal, "Идентификатор\nфакультета");

        model->setHeaderData(1,Qt::Horizontal, "Код\nфакультета");

        model->setHeaderData(2,Qt::Horizontal, "Идентификатор\nаудитории");

        model->setHeaderData(3,Qt::Horizontal, "Номер\nаудитории");

        model->setHeaderData(4,Qt::Horizontal, "Тип\nаудитории");

        model->setHeaderData(5,Qt::Horizontal, "Вместимость\nаудитории");

        model->setHeaderData(6,Qt::Horizontal, "Приоритет\nфакультета");

        model->setHeaderData(7,Qt::Horizontal, "Имеет\nдоску");

        model->setHeaderData(8,Qt::Horizontal, "Имеет\nпроектор");

        model->setHeaderData(9,Qt::Horizontal, "Имеет\nрозетки");

        model->setHeaderData(10,Qt::Horizontal, "Имеет\nокна");
        return;
    }

    if(input == "faculty")
    {
        model->setHeaderData(0,Qt::Horizontal, "Идентификатор\nфакультета");

        model->setHeaderData(1,Qt::Horizontal, "Название\nфакультета");

        model->setHeaderData(2,Qt::Horizontal, "Код\nфакультета");

        model->setHeaderData(3,Qt::Horizontal, "Декан\nфакультета");

        model->setHeaderData(4,Qt::Horizontal, "Адрес\nфакультета");
        return;
    }
}

void LookDataBase::on_listView_clicked(const QModelIndex &index)
{
    /*!
      *Константа	Значение	Описание
      *QSqlTableModel::OnFieldChange	0	Все изменения модели будут применены непосредственно к БД
      *QSqlTableModel::OnRowChange	    1	Изменения строки будут применены, когда пользователь выберет другую строку.
      *QSqlTableModel::OnManualSubmit	2	Все изменения будут кэшироваться в модели пока не будут вызваны submitAll() или revertAll().
    */
    model = new QSqlTableModel;
    QStringList translate;
    if (index.isValid())
        translate = russianListView(QStringList(index.data().toString()), 2);
    //else
    //    translate.append("groups");
    model->setTable(translate[0]);
    model->setSort(0,Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!model->select())
    {
        QMessageBox q;
        q.setText(model->lastError().text());
        q.exec();
    }
    //russianColumn(translate[0]);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void LookDataBase::on_exportCSV_clicked()
{
    QDateTime dt;
    QDir dir;
    QFile csvFile(dir.currentPath() + "/" + model->tableName() + "_" + dt.currentDateTime().toString("dd-MM-yyyy_hh-mm") + ".csv");
    // Открываем, или создаём файл, если он не существует
    if(csvFile.open(QIODevice::WriteOnly))
    {
        // Создаём текстовый поток, в который будем писать данные
        QTextStream textStream(&csvFile);
        QStringList stringList; // Вспомогательный объект QSqtringList, который сформирует строку
        // Проходимся по всем строкам ...
        for(int row = 0; row < model->rowCount(); row++)
        {
            stringList.clear(); // ... каждый раз очищая stringList
            /* Если обратить внимание в заголовочный файл, то
             * можно увидеть в перечислении Roles, что ролей модели всего 4
             * */
            for(int column = 0; column < model->columnCount(); column++)
            {
                // Записываем в stringList каждый элемент таблицы
                stringList << model->data(model->index(row,column)).toString();
            }
            /* После чего отправляем весь stringList в файл через текстовый поток
             * добавляя разделители в виде ";", а также поставив в конце символ окончания строки
             * */
            textStream << stringList.join(';')+"\n";
        }
        // Закрываем файл - готово
        csvFile.close();
        QMessageBox msg;
        msg.setText("Экспорт успешно завершен");
        msg.exec();
    }
}

void LookDataBase::on_filter_clicked()
{
    QHeaderView *q = new QHeaderView(Qt::Horizontal, this);
    q->setModel(model);
    FilterDialog *fd = new FilterDialog();
    for(int i = 0; i < q->count(); i++)
    {
        fd->addItem(model->headerData(i,Qt::Horizontal).toString());
    }
    fd->applyList();
    model->setFilter(fd->showDialog());
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void LookDataBase::on_deleteFilter_clicked()
{
    model->setFilter("");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
