#include "token.h"
#include "ui_token.h"
#include "cframe.h"

Token::Token(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Token)
{
    ui->setupUi(this);
    this->setFixedSize(400, 275);
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &Token::UpdateClock);
    connect(timer, &QTimer::timeout, this, &Token::update);
    timer->start(1000);
}

Token::~Token()
{
    delete ui;
}

string Token::EncriptarToken(long token)
{
       std::array<char, 36> cipher = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
       std::string tokenStr = std::to_string(token);
       std::string encryptedToken;

       // Añade ceros al inicio si el token tiene menos de 6 dígitos
       while (tokenStr.length() < 6) {
           tokenStr = "0" + tokenStr;
       }

       for (char c : tokenStr)
       {
           int digit = c - '0'; // Convierte el carácter a un dígito
           encryptedToken += cipher[digit]; // Reemplaza el dígito
       }

       // Añade ceros al inicio si el token cifrado tiene menos de 6 caracteres
       while (encryptedToken.length() < 6) {
           encryptedToken = "0" + encryptedToken;
       }

       return encryptedToken;
}

void Token::SetToken(long Token)
{
    // Muestra el token original
       ui->lbl_Token->setText(QString::number(Token));

       // Cifra el token
       std::string encryptedToken = EncriptarToken(Token);

       // Guarda el token cifrado en un archivo .txt
       std::ofstream outFile("token_cifrado.txt");
       if (outFile.is_open())
       {
           outFile << encryptedToken;
           outFile.close();
       }
       else
       {
           QMessageBox::critical(this, "Error", "No se pudo abrir el archivo token_cifrado.txt");
       }
}


long Token::GenerarToken()
{
    int Token = QRandomGenerator::global()->bounded(100000, 1000000);
    return Token;
}

void Token::UpdateClock()
{
    int secondsLeft = 60 - QDateTime::currentSecsSinceEpoch() % 60;
    ui->lbl_tiempo->setText(QString::number(secondsLeft) + " segundos restantes");
}

void Token::update()
{
    if(ui->lbl_tiempo->text().toStdString()=="60 segundos restantes"){
        int token = GenerarToken();
        ui->lbl_Token->setText(QString::number(token));
        SetToken(token);
    }
}
