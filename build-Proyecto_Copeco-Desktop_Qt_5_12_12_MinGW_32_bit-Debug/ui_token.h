/********************************************************************************
** Form generated from reading UI file 'token.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOKEN_H
#define UI_TOKEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Token
{
public:
    QLabel *lbl_TokenTitulo;
    QLabel *lbl_Token;
    QLabel *lbl_tiempo;
    QLabel *label;

    void setupUi(QWidget *Token)
    {
        if (Token->objectName().isEmpty())
            Token->setObjectName(QString::fromUtf8("Token"));
        Token->resize(396, 252);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Token->setPalette(palette);
        Token->setAutoFillBackground(false);
        lbl_TokenTitulo = new QLabel(Token);
        lbl_TokenTitulo->setObjectName(QString::fromUtf8("lbl_TokenTitulo"));
        lbl_TokenTitulo->setGeometry(QRect(0, 0, 391, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbl_TokenTitulo->setFont(font);
        lbl_TokenTitulo->setAlignment(Qt::AlignCenter);
        lbl_Token = new QLabel(Token);
        lbl_Token->setObjectName(QString::fromUtf8("lbl_Token"));
        lbl_Token->setGeometry(QRect(0, 100, 391, 51));
        QFont font1;
        font1.setPointSize(22);
        lbl_Token->setFont(font1);
        lbl_Token->setAlignment(Qt::AlignCenter);
        lbl_tiempo = new QLabel(Token);
        lbl_tiempo->setObjectName(QString::fromUtf8("lbl_tiempo"));
        lbl_tiempo->setGeometry(QRect(0, 160, 391, 21));
        QFont font2;
        font2.setPointSize(11);
        lbl_tiempo->setFont(font2);
        lbl_tiempo->setAlignment(Qt::AlignCenter);
        label = new QLabel(Token);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 401, 251));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Subheading.png")));
        label->raise();
        lbl_TokenTitulo->raise();
        lbl_Token->raise();
        lbl_tiempo->raise();

        retranslateUi(Token);

        QMetaObject::connectSlotsByName(Token);
    } // setupUi

    void retranslateUi(QWidget *Token)
    {
        Token->setWindowTitle(QString());
        lbl_TokenTitulo->setText(QApplication::translate("Token", "Token", nullptr));
        lbl_Token->setText(QApplication::translate("Token", "-", nullptr));
        lbl_tiempo->setText(QApplication::translate("Token", "-", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Token: public Ui_Token {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOKEN_H
