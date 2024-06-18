/********************************************************************************
** Form generated from reading UI file 'cframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFRAME_H
#define UI_CFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cframe
{
public:
    QWidget *centralwidget;
    QTabWidget *tabCentral;
    QWidget *InicioSesion_Tab;
    QLabel *imagenfondo;
    QLineEdit *txtusuario;
    QLineEdit *txcontrasea;
    QPushButton *botonlogearse;
    QPushButton *TokenBtn;
    QWidget *MenuPrin_Tab;
    QTabWidget *TabIngresar;
    QWidget *tab_4;
    QLineEdit *CodigoAgregar;
    QLineEdit *NombreAgregar;
    QPushButton *AgregarProducto;
    QLabel *label_2;
    QTableWidget *TableInventario;
    QPushButton *CerrarSesion;
    QWidget *tab_2;
    QLineEdit *NombreRemitente;
    QLineEdit *ResponsableEntrada;
    QSpinBox *cantidadentrada;
    QLabel *label_9;
    QLineEdit *CodigoEntrada;
    QPushButton *pushButton;
    QTableWidget *TablesEntradas;
    QLabel *label_3;
    QPushButton *CerrarSesion_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *cframe)
    {
        if (cframe->objectName().isEmpty())
            cframe->setObjectName(QString::fromUtf8("cframe"));
        cframe->resize(1036, 703);
        centralwidget = new QWidget(cframe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabCentral = new QTabWidget(centralwidget);
        tabCentral->setObjectName(QString::fromUtf8("tabCentral"));
        tabCentral->setGeometry(QRect(0, 0, 1021, 651));
        tabCentral->setMinimumSize(QSize(1011, 0));
        tabCentral->setLayoutDirection(Qt::LeftToRight);
        InicioSesion_Tab = new QWidget();
        InicioSesion_Tab->setObjectName(QString::fromUtf8("InicioSesion_Tab"));
        imagenfondo = new QLabel(InicioSesion_Tab);
        imagenfondo->setObjectName(QString::fromUtf8("imagenfondo"));
        imagenfondo->setGeometry(QRect(0, 0, 1001, 601));
        imagenfondo->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Black and Red Minimalist Modern Registration Gym Website Prototype (1).png")));
        imagenfondo->setScaledContents(true);
        txtusuario = new QLineEdit(InicioSesion_Tab);
        txtusuario->setObjectName(QString::fromUtf8("txtusuario"));
        txtusuario->setGeometry(QRect(120, 280, 251, 31));
        QPalette palette;
        QBrush brush(QColor(239, 239, 239, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        txtusuario->setPalette(palette);
        txtusuario->setAutoFillBackground(false);
        txtusuario->setFrame(false);
        txtusuario->setClearButtonEnabled(false);
        txcontrasea = new QLineEdit(InicioSesion_Tab);
        txcontrasea->setObjectName(QString::fromUtf8("txcontrasea"));
        txcontrasea->setGeometry(QRect(120, 360, 251, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        txcontrasea->setPalette(palette1);
        txcontrasea->setAutoFillBackground(false);
        txcontrasea->setFrame(false);
        txcontrasea->setEchoMode(QLineEdit::Password);
        txcontrasea->setClearButtonEnabled(false);
        botonlogearse = new QPushButton(InicioSesion_Tab);
        botonlogearse->setObjectName(QString::fromUtf8("botonlogearse"));
        botonlogearse->setGeometry(QRect(110, 460, 211, 41));
        botonlogearse->setFlat(true);
        TokenBtn = new QPushButton(InicioSesion_Tab);
        TokenBtn->setObjectName(QString::fromUtf8("TokenBtn"));
        TokenBtn->setGeometry(QRect(340, 460, 41, 41));
        TokenBtn->setFlat(true);
        tabCentral->addTab(InicioSesion_Tab, QString());
        MenuPrin_Tab = new QWidget();
        MenuPrin_Tab->setObjectName(QString::fromUtf8("MenuPrin_Tab"));
        TabIngresar = new QTabWidget(MenuPrin_Tab);
        TabIngresar->setObjectName(QString::fromUtf8("TabIngresar"));
        TabIngresar->setGeometry(QRect(0, 0, 1011, 631));
        TabIngresar->setFocusPolicy(Qt::TabFocus);
        TabIngresar->setLayoutDirection(Qt::LeftToRight);
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        CodigoAgregar = new QLineEdit(tab_4);
        CodigoAgregar->setObjectName(QString::fromUtf8("CodigoAgregar"));
        CodigoAgregar->setGeometry(QRect(90, 340, 271, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        CodigoAgregar->setPalette(palette2);
        CodigoAgregar->setFrame(false);
        NombreAgregar = new QLineEdit(tab_4);
        NombreAgregar->setObjectName(QString::fromUtf8("NombreAgregar"));
        NombreAgregar->setGeometry(QRect(100, 250, 261, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        NombreAgregar->setPalette(palette3);
        NombreAgregar->setFrame(false);
        AgregarProducto = new QPushButton(tab_4);
        AgregarProducto->setObjectName(QString::fromUtf8("AgregarProducto"));
        AgregarProducto->setGeometry(QRect(99, 430, 261, 41));
        AgregarProducto->setFlat(true);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 1001, 571));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/\303\255ewnr9n(1).png")));
        TableInventario = new QTableWidget(tab_4);
        TableInventario->setObjectName(QString::fromUtf8("TableInventario"));
        TableInventario->setGeometry(QRect(440, 70, 541, 481));
        TableInventario->setFrameShape(QFrame::NoFrame);
        CerrarSesion = new QPushButton(tab_4);
        CerrarSesion->setObjectName(QString::fromUtf8("CerrarSesion"));
        CerrarSesion->setGeometry(QRect(930, 10, 51, 41));
        CerrarSesion->setFlat(true);
        TabIngresar->addTab(tab_4, QString());
        label_2->raise();
        CodigoAgregar->raise();
        NombreAgregar->raise();
        AgregarProducto->raise();
        TableInventario->raise();
        CerrarSesion->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        NombreRemitente = new QLineEdit(tab_2);
        NombreRemitente->setObjectName(QString::fromUtf8("NombreRemitente"));
        NombreRemitente->setGeometry(QRect(80, 180, 291, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        NombreRemitente->setPalette(palette4);
        NombreRemitente->setFrame(false);
        ResponsableEntrada = new QLineEdit(tab_2);
        ResponsableEntrada->setObjectName(QString::fromUtf8("ResponsableEntrada"));
        ResponsableEntrada->setGeometry(QRect(80, 120, 291, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        ResponsableEntrada->setPalette(palette5);
        ResponsableEntrada->setFrame(false);
        cantidadentrada = new QSpinBox(tab_2);
        cantidadentrada->setObjectName(QString::fromUtf8("cantidadentrada"));
        cantidadentrada->setGeometry(QRect(430, 180, 71, 41));
        cantidadentrada->setMinimum(1);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(300, 10, 271, 16));
        CodigoEntrada = new QLineEdit(tab_2);
        CodigoEntrada->setObjectName(QString::fromUtf8("CodigoEntrada"));
        CodigoEntrada->setGeometry(QRect(440, 120, 281, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        CodigoEntrada->setPalette(palette6);
        CodigoEntrada->setFrame(false);
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(790, 110, 151, 91));
        pushButton->setFlat(true);
        TablesEntradas = new QTableWidget(tab_2);
        TablesEntradas->setObjectName(QString::fromUtf8("TablesEntradas"));
        TablesEntradas->setGeometry(QRect(50, 260, 921, 271));
        TablesEntradas->setFrameShape(QFrame::NoFrame);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 1001, 581));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/entradas.png")));
        CerrarSesion_2 = new QPushButton(tab_2);
        CerrarSesion_2->setObjectName(QString::fromUtf8("CerrarSesion_2"));
        CerrarSesion_2->setGeometry(QRect(930, 10, 51, 41));
        CerrarSesion_2->setFlat(true);
        TabIngresar->addTab(tab_2, QString());
        label_3->raise();
        NombreRemitente->raise();
        ResponsableEntrada->raise();
        cantidadentrada->raise();
        label_9->raise();
        CodigoEntrada->raise();
        TablesEntradas->raise();
        pushButton->raise();
        CerrarSesion_2->raise();
        tabCentral->addTab(MenuPrin_Tab, QString());
        cframe->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(cframe);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        cframe->setStatusBar(statusbar);
        menubar = new QMenuBar(cframe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1036, 25));
        cframe->setMenuBar(menubar);

        retranslateUi(cframe);

        tabCentral->setCurrentIndex(1);
        TabIngresar->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(cframe);
    } // setupUi

    void retranslateUi(QMainWindow *cframe)
    {
        cframe->setWindowTitle(QApplication::translate("cframe", "cframe", nullptr));
        imagenfondo->setText(QString());
        botonlogearse->setText(QString());
        TokenBtn->setText(QString());
        tabCentral->setTabText(tabCentral->indexOf(InicioSesion_Tab), QApplication::translate("cframe", "Inicio Sesion", nullptr));
        AgregarProducto->setText(QString());
        label_2->setText(QString());
        CerrarSesion->setText(QString());
        TabIngresar->setTabText(TabIngresar->indexOf(tab_4), QApplication::translate("cframe", "Carga ", nullptr));
        label_9->setText(QApplication::translate("cframe", "Codigo", nullptr));
        pushButton->setText(QString());
        label_3->setText(QString());
        CerrarSesion_2->setText(QString());
        TabIngresar->setTabText(TabIngresar->indexOf(tab_2), QApplication::translate("cframe", "Revision", nullptr));
        tabCentral->setTabText(tabCentral->indexOf(MenuPrin_Tab), QApplication::translate("cframe", "Menu Principal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cframe: public Ui_cframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFRAME_H
