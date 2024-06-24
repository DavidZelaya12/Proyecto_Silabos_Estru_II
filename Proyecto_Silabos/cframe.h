#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <token.h>
#include <lista.h>

using std::string;


QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();
    void LogIn();
    void RegistrarEmpleados();
    std::string LeerToken();
    void MostrarUsuarios();
    void descargarArchivo();
    void mostrarDashboard();
    void ActualizarTabla();
    void ActualizarRevisiones(QString clase);
    void ActualizarObservacion(QString clase, QString nuevasObservaciones);

private slots:

    void on_botonlogearse_clicked();

    void on_TokenBtn_clicked();

    void on_CerrarSesion_clicked();

    void on_CerrarSesion_2_clicked();

    void on_cb_facultades_currentIndexChanged(int index);

    void on_btn_buscar_archivo_clicked();

    void on_AgregarProducto_clicked();

    void on_pushButton_clicked();

    void on_Enviar_clicked();

    void on_TabIngresar_tabBarClicked(int index);

    void on_mostrar_revisiones_cellClicked(int row, int column);

private:
    Ui::cframe *ui;
    void setupDatabase();
    void createTable();
    Token a;
    void insertValues();

};

#endif // CFRAME_H
