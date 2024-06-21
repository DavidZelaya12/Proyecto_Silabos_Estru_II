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

    //RegistrarEmpleados();
    MostrarUsuarios();

    ui->tabCentral->setTabEnabled(1, false);
    std::cout<<"adios";
}


cframe::~cframe()
{
    delete ui;
}

void cframe::LogIn()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM personas")) {
        while (query.next()) {
            std::string contraDB, contraLog, tokencrip, contraingresada, nombre, nombreDB;
            QString tokenS;
            contraingresada = ui->txcontrasea->text().toStdString();
            contraDB = query.value(2).toString().toStdString();
            if(contraingresada.size()>7){
                nombre=ui->txtusuario->text().toStdString();
                nombreDB = query.value(1).toString().toStdString();
                contraLog = contraingresada.substr(0, contraingresada.size()-6);
                tokenS = QString::fromStdString(contraingresada.substr(contraingresada.size()-6, contraingresada.size()));
                tokencrip= a.EncriptarToken(tokenS.toLong());
                //QMessageBox::critical(this, "Error", QString::fromStdString(contraDB+" "+contraLog+" "+tokenS.toStdString()+" "+tokencrip+" "+LeerToken()+" "+nombre+" "+nombreDB));
                if(contraDB==contraLog && tokencrip==LeerToken() && nombre==nombreDB){
                    a.close();
                    ui->tabCentral->setTabEnabled(1,true);
                    ui->tabCentral->setCurrentIndex(1);
                    ui->tabCentral->setTabEnabled(0,false);
                    return;
                }
            }
        }
    }
    QMessageBox::critical(this, "Error", "Verifque sus credenciales de inicio de sesion");
}

void cframe::RegistrarEmpleados()
{
    QSqlQuery query;
    QStringList queries = {
        R"(
            INSERT INTO personas (id, nombre, contra, puesto) VALUES
            ('0501199067890', 'Virgilio Fuentes', 'docente123', 'docente')
        )",
        R"(
            INSERT INTO personas (id, nombre, contra, puesto) VALUES
            ('0501199012345', 'David Zelaya', 'coordinador123', 'coordinador')
        )",
        R"(
            INSERT INTO personas (id, nombre, contra, puesto) VALUES
            ('0401198098765', 'Daniel Lorenzo', 'iedd123', 'iedd')
        )",
        R"(
            INSERT INTO personas (id, nombre, contra, puesto) VALUES
            ('0501199045678', 'Abraham Reyes', 'consultor123', 'consultor')
        )"
    };

    for (const QString &insertValuesSql : queries) {
        if (!query.exec(insertValuesSql)) {
            QMessageBox::critical(this, "Insert Values Error", query.lastError().text());
            return;
        }
    }

    QMessageBox::information(this, "Insert Values", "Values inserted into 'personas' table successfully.");
}

void cframe::MostrarUsuarios()
{
    QSqlQuery query;
        if (query.exec("SELECT * FROM personas")) {
            while (query.next()) {
                QString ID = query.value(0).toString();
                QString nombre = query.value(1).toString();
                QString puesto = query.value(3).toString();

                qDebug() << "ID:" << ID << ", Nombre:" << nombre << ", Puesto:" << puesto;
            }
        } else {
            QMessageBox::critical(this, "Query Execution Error", query.lastError().text());
        }
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
            puesto NVARCHAR(15)
        )
    )";

    if (!query.exec(createTableSql)) {
        QMessageBox::critical(this, "Table Creation Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Table Creation", "Table 'personas' created successfully.");
    }
}

void cframe::insertValues()
{
    QSqlQuery query;
    QString insertValuesSql = R"(
        INSERT INTO personas (id, nombre, contra, puesto) VALUES
        ('0501199067890', 'Virgilio Fuentes', 'virgigod', 'Bodeguero')
    )";

    if (!query.exec(insertValuesSql)) {
        QMessageBox::critical(this, "Insert Values Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Insert Values", "Values inserted into 'personas' table successfully.");
    }
}
*/

void cframe::on_botonlogearse_clicked()
{
    if(ui->txcontrasea->text()!="" && ui->txtusuario->text()!="")
        LogIn();
    else
        QMessageBox::critical(this, "Error", "Rellene todos los espacios");
}


void cframe::on_TokenBtn_clicked()
{
    a.SetToken(a.GenerarToken());
    a.show();
}

std::string cframe::LeerToken()
{
    std::ifstream Archivo("token_cifrado.txt");
    if (Archivo.is_open())
    {
        std::string token;
        std::getline(Archivo, token);
        Archivo.close();
        return token;
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo token_cifrado.txt");
        return NULL;
    }
}

void cframe::on_CerrarSesion_clicked()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("Confirmar Cierre de Sesión");
    messageBox.setText("¿Estás seguro de que quieres cerrar sesión?");
    QPushButton *yesButton = messageBox.addButton(tr("Sí"), QMessageBox::YesRole);
    QPushButton *noButton = messageBox.addButton(tr("No"), QMessageBox::NoRole);
    messageBox.setIcon(QMessageBox::Question);

    messageBox.exec();

    if (messageBox.clickedButton() == yesButton) {
        ui->tabCentral->setTabEnabled(0,true);
        ui->tabCentral->setCurrentIndex(0);
        ui->tabCentral->setTabEnabled(1,false);
        //LimpiarEspacios();
    }
}


void cframe::on_CerrarSesion_2_clicked()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("Confirmar Cierre de Sesión");
    messageBox.setText("¿Estás seguro de que quieres cerrar sesión?");
    QPushButton *yesButton = messageBox.addButton(tr("Sí"), QMessageBox::YesRole);
    QPushButton *noButton = messageBox.addButton(tr("No"), QMessageBox::NoRole);
    messageBox.setIcon(QMessageBox::Question);

    messageBox.exec();

    if (messageBox.clickedButton() == yesButton) {
        ui->tabCentral->setTabEnabled(0,true);
        ui->tabCentral->setCurrentIndex(0);
        ui->tabCentral->setTabEnabled(1,false);
        //LimpiarEspacios();
    }
}

