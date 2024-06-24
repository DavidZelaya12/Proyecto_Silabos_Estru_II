#include "cframe.h"
#include "ui_cframe.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <QSqlError>
#include <QFileDialog>
#include <qstandardpaths.h>
#include <QMap>

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
    mostrarDashboard();

    ui->tabCentral->setTabEnabled(1, false);
    std::cout<<"hola";
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
                    ui->LE_CambiarNombre->setText(QString::fromStdString(nombre));
                    ui->LE_nombre->setText(QString::fromStdString(nombre));
                    ui->LE_Cargo->setText(QString::fromStdString(query.value(3).toString().toStdString()).toUpper());
                    ActualizarTabla();
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

void cframe::descargarArchivo()
{
    QString classCode = ui->le_filepath->text(); // Obtén el código de clase de un QLineEdit, por ejemplo

    QSqlQuery query;
    query.prepare("SELECT archivo FROM silabos WHERE clase = :clase");
    query.bindValue(":clase", classCode);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    if (query.next()) {
        QByteArray fileData = query.value(0).toByteArray();

        // Define the file path where the PDF will be saved
        QString saveFilePath = QFileDialog::getSaveFileName(this, "Guardar archivo PDF", QDir::homePath(), "Archivos PDF (*.pdf)");
        if (saveFilePath.isEmpty()) {
            return; // El usuario canceló la operación
        }

        // Write the file data to the specified file path
        QFile file(saveFilePath);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, "Error", "No se pudo guardar el archivo.");
            return;
        }

        file.write(fileData);
        file.close();

        QMessageBox::information(this, "Éxito", "Archivo descargado exitosamente.");
    } else {
        QMessageBox::warning(this, "No encontrado", "No se encontró el archivo para la clase especificada.");
    }

}

void cframe::mostrarDashboard()
{

    QSqlQuery query;
    if (query.exec("SELECT * FROM silabos")) {
        ui->TablesEntradas_2->setRowCount(0);
        ui->TablesEntradas_2->setColumnCount(4);
        QStringList headers = {"Cargado por", "Facultad", "Clase", "Observacion", "Estado"};
        ui->TablesEntradas_2->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TablesEntradas_2->insertRow(row);

            QString carga = query.value(0).toString();
            QString clase = query.value(1).toString();
            QString observaciones = query.value(2).toString();
            QString facultad = query.value(3).toString();
            int revisiones = query.value(4).toInt();
            int lvl = query.value(5).toInt();
            QString estado;

            estado = (lvl==5) ? "Aprobado" :"En proceso" ;
            if(revisiones>2)
                estado = "Rechazado";

            ui->TablesEntradas_2->setItem(row, 0, new QTableWidgetItem(carga));
            ui->TablesEntradas_2->setItem(row, 1, new QTableWidgetItem(facultad));
            ui->TablesEntradas_2->setItem(row, 2, new QTableWidgetItem(clase));
            ui->TablesEntradas_2->setItem(row, 3, new QTableWidgetItem(observaciones));
            ui->TablesEntradas_2->setItem(row, 4, new QTableWidgetItem(estado));
            row++;
        }
    } else {
        QMessageBox::critical(this, "Query Execution Error", query.lastError().text());
    }

}

void cframe::ActualizarTabla()
{

    QString  Cargos []= {"DOCENTE","COORDINADOR","IEDD","CONSULTOR"};
    QString CargoActual = ui->LE_Cargo->text();
    QMessageBox::information(this,"",CargoActual);
    QSqlQuery query;
    if (query.exec("SELECT * FROM silabos")) {
        ui->mostrar_revisiones->setRowCount(0);
        ui->mostrar_revisiones->setColumnCount(4);
        QStringList headers = {"Cargado por", "Facultad", "Clase", "Observacion"};
        ui->mostrar_revisiones->setHorizontalHeaderLabels(headers);

        int row = 0;

        while (query.next()) {
            ui->mostrar_revisiones->insertRow(row);
            QString carga = query.value(0).toString();
            QString clase = query.value(1).toString();
            QString observaciones = query.value(2).toString();
            QString facultad = query.value(3).toString();
            //int revisiones = query.value(4).toInt();
            int lvl = query.value(5).toInt();
            if(Cargos[lvl] == CargoActual){
                ui->mostrar_revisiones->setItem(row, 0, new QTableWidgetItem(carga));
                ui->mostrar_revisiones->setItem(row, 1, new QTableWidgetItem(facultad));
                ui->mostrar_revisiones->setItem(row, 2, new QTableWidgetItem(clase));
                ui->mostrar_revisiones->setItem(row, 3, new QTableWidgetItem(observaciones));
                row++;
            }
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

void cframe::createTable()
{
    QSqlQuery query;
    QString createTableSql = R"(
        CREATE TABLE silabos(
            ID INT PRIMARY KEY IDENTITY(1,1),
            cargado NVARCHAR(40),
            clase NVARCHAR(40),
            observaciones NVARCHAR(255),
            facultad NVARCHAR(50),
            numrevisiones INT,
            numlvl INT,
            archivo VARBINARY(MAX)
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


void cframe::on_botonlogearse_clicked()
{

    if(ui->txcontrasea->text()!="" && ui->txtusuario->text()!="")
        LogIn();
    else
        QMessageBox::critical(this, "Error", "Rellene todos los espacios");
    /*
    ui->tabCentral->setTabEnabled(1,true);
    ui->tabCentral->setCurrentIndex(1);
    ui->tabCentral->setTabEnabled(0,false);
    */
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


void cframe::on_cb_facultades_currentIndexChanged(int index)
{
    QStringList items;
    ui->cb_carreras->clear();
    if(index == 1){
        items<<"Biomedica"<<"Ciencia de datos e inteligencia artificial"<<"Civil"<<"Energia"<<"Industrial y de sistemas"<<"Mecatronica"<<"Sistemas Computacionales"<<"Telecomunicaciones y electronica";
        ui->cb_carreras->addItems(items);
    }else if(index == 2){
        items<<"Administracion de la hospitalidad y el tursimo"<<"Administracion industrial e inteligencia de negocios"<<"Administracion industrial y emprendimiento"<<"Industrial y operaciones"<<"Derecho"<<"Finanzas y Economia"<<"Mercadotecnia y negocios internacionales"<<"Relaciones internacionales";
        ui->cb_carreras->addItems(items);
    }else if(index == 3){
        items<<"Animacion digital y diseño interactivo"<<"Arquitectura"<<"Comunicacion audiovisual y publicitaria"<<"Diseno de modas"<<"Diseno Grafico"<<"Gastronomia";
        ui->cb_carreras->addItems(items);
    }
}


void cframe::on_btn_buscar_archivo_clicked()
{
    // Definir el mapa para los códigos de clase y sus nombres correspondientes
    QMap<QString, QString> classMap;
    classMap.insert("CCC104", "ProgramacionI");
    classMap.insert("CCC105", "ProgramacionII");
    classMap.insert("CCC208", "ProgramacionIII");
    classMap.insert("CCC210", "Ecologia");
    classMap.insert("CCC253", "Quimica");
    // Agregar más códigos de clase y nombres según sea necesario

    QString filePath = QFileDialog::getOpenFileName(this, "Seleccionar archivo PDF", QDir::homePath(), "Archivos PDF (*.pdf)");

    if (!filePath.isEmpty()) {
        // Obtener el nombre del archivo
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();

        // Definir la expresión regular para validar el nombre del archivo
        QRegularExpression rx("^([A-Za-z]+[IV]*)_?(CCC\\d{3})\\.pdf$", QRegularExpression::CaseInsensitiveOption); // Formato: NombreClase_CCC123.pdf

        // Validar el nombre del archivo según la expresión regular
        QRegularExpressionMatch match = rx.match(fileName);
        if (!match.hasMatch()) {
            QMessageBox::critical(this, "Error", "El nombre del archivo no cumple con el formato deseado (NombreClase_CCC###.pdf).");
            return;
        }

        // Obtener el nombre de la clase y el código del archivo
        QString className = match.captured(1).trimmed();
        QString classCode = match.captured(2);
        ui->falsedad->setText(classCode);

        // Verificar si el código de la clase existe en el mapa
        if (!classMap.contains(classCode)) {
            QMessageBox::critical(this, "Error", "Código de clase no válido.");
            return;
        }

        // Verificar si el nombre de la clase coincide con el nombre esperado
        if (classMap[classCode].compare(className, Qt::CaseInsensitive) != 0) {
            QMessageBox::critical(this, "Error", "El nombre del archivo no coincide con el código de clase.");
            return;
        }

        ui->le_filepath->setText(filePath);
    }
}



void cframe::on_AgregarProducto_clicked()
{
    // Leer el archivo PDF en formato binari
    QString filePath = ui->le_filepath->text();
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();

    QString classCode = ui->falsedad->text();
    QString cargado = ui->LE_CambiarNombre->text();
    QString facultad = ui->cb_facultades->currentText();
    QMessageBox::information(this,"",facultad);


    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo.");
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();

    // Preparar la consulta de inserción
    QSqlQuery query;
    query.prepare("INSERT INTO silabos (cargado, clase, observaciones, facultad, numrevisiones, numlvl, archivo) "
                  "VALUES (:cargado, :clase, :observaciones, :facultad, :numrevisiones, :numlvl, :archivo)");
    //query.bindValue(":ID", 1); // Debes proporcionar el ID correcto
    query.bindValue(":cargado", cargado); // Proporciona la fecha o información correcta
    query.bindValue(":clase", classCode);
    query.bindValue(":observaciones", ""); // Proporciona las observaciones correctas
    query.bindValue(":facultad", facultad); // Proporciona la facultad correcta
    query.bindValue(":numrevisiones", 0); // Proporciona el número de revisiones correcto
    query.bindValue(":numlvl", 1); // Proporciona el nivel correcto
    query.bindValue(":archivo", fileData);

    // Ejecutar la consulta
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    // Mostrar el nombre del archivo en el QLineEdit
    ui->le_filepath->setText(fileName);

    QMessageBox::information(this, "Éxito", "Archivo subido exitosamente.");
    ActualizarTabla();
}



void cframe::on_pushButton_clicked()
{
    QString classCode = ui->le_codigo_descargar->text(); // Obtén el código de clase de un QLineEdit, por ejemplo

    QSqlQuery query;
    query.prepare("SELECT archivo FROM silabos WHERE clase = :clase");
    query.bindValue(":clase", classCode);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    if (query.next()) {
        QByteArray fileData = query.value(0).toByteArray();

        // Define the file path where the PDF will be saved
        QString saveFilePath = QFileDialog::getSaveFileName(this, "Guardar archivo PDF", QDir::homePath(), "Archivos PDF (*.pdf)");
        if (saveFilePath.isEmpty()) {
            return; // El usuario canceló la operación
        }

        // Write the file data to the specified file path
        QFile file(saveFilePath);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, "Error", "No se pudo guardar el archivo.");
            return;
        }

        file.write(fileData);
        file.close();

        QMessageBox::information(this, "Éxito", "Archivo descargado exitosamente.");
    } else {
        QMessageBox::warning(this, "No encontrado", "No se encontró el archivo para la clase especificada.");
    }
}


void cframe::on_Enviar_clicked()
{
    // Obtener el índice seleccionado del combo box
            int index = ui->comboBox->currentIndex();
            QString clase = ui->le_codigo_descargar->text();  // Asegúrate de que tienes una manera de obtener la clase
            bool incrementar = (index == 0); // Supongamos que el índice 0 es para incrementar y el 1 es para decrementar

            // Preparar la consulta para obtener el valor actual de numlvl
            QSqlQuery query;
            query.prepare("SELECT numlvl FROM silabos WHERE clase = :clase");
            query.bindValue(":clase", clase);

            if (!query.exec()) {
                QMessageBox::critical(this, "Error", "Error al ejecutar la consulta de selección: " + query.lastError().text());
                return;
            }

            if (query.next()) {
                // Obtener el valor actual de numlvl
                int numlvlActual = query.value(0).toInt();

                // Calcular el nuevo valor de numlvl
                int nuevoNumlvl = incrementar ? numlvlActual + 1 : numlvlActual - 1;

                // Preparar la consulta para actualizar el valor de numlvl
                query.prepare("UPDATE silabos SET numlvl = :nuevoNumlvl WHERE clase = :clase");
                query.bindValue(":nuevoNumlvl", nuevoNumlvl);
                query.bindValue(":clase", clase);

                if (!query.exec()) {
                    QMessageBox::critical(this, "Error", "Error al ejecutar la consulta de actualización: " + query.lastError().text());
                    return;
                }

                QMessageBox::information(this, "Éxito", "El valor de numlvl se ha actualizado exitosamente.");
            } else {
                QMessageBox::warning(this, "No encontrado", "No se encontró la clase especificada.");
            }
}


void cframe::on_TabIngresar_tabBarClicked(int index)
{
    if(index==2) {
        mostrarDashboard();
    }
}

