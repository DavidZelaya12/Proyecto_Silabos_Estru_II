#include "cframe.h"
#include "ui_cframe.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <QSqlError>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
    //CantInventario = obtenerPrimaryKey();
    setupDatabase();
    //createTable();
    //insertValues();
    //queryTable();
    // ActualizarTablas();
    ui->tabCentral->setTabEnabled(1, false);
    std::cout<<"adios";
}


cframe::~cframe()
{
    delete ui;
}



void cframe::setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString serverName = "unitecsilabos.database.windows.net";
    QString dbName = "silabos";
    QString username = "AdminSilabos";
    QString password = "Silabos123";

    QString connectionString = QString("Driver={ODBC Driver 18 for SQL Server};Server=tcp:%1,1433;Database=%2;Uid=%3;"
                                       "Pwd=%4;Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;")
            .arg(serverName).arg(dbName).arg(username).arg(password);
    db.setDatabaseName(connectionString);

    if (!db.open()) {
        QMessageBox::critical(this, "Database Connection Error", db.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Successfully connected to the database!");
    }
}
/*
void cframe::createTable()
{
    QSqlQuery query;
    QString createTableSql = R"(
        CREATE TABLE personas(
            ID NVARCHAR(13) PRIMARY KEY,
            nombre NVARCHAR(50),
            contra NVARCHAR(15),
            puesto NVARCHAR(15),
        )
    )";

    if (!query.exec(createTableSql)) {
        QMessageBox::critical(this, "Table Creation Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Table Creation", "Table 'personas' created successfully.");
    }
}
*/
