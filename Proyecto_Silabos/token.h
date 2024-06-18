#ifndef TOKEN_H
#define TOKEN_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <fstream>
#include <QRandomGenerator>

namespace Ui {
class Token;
}

class MainWindow;

class Token : public QWidget
{
    Q_OBJECT

public:
    explicit Token(QWidget *parent = nullptr);
    ~Token();
    std::string EncriptarToken(long token);
    void SetToken(long Token);
    long SeedKey=736352;
    long GenerarToken();
    QTimer* timer;
    void UpdateClock();
private slots:

    void update();

private:
    Ui::Token *ui;
};

#endif // TOKEN_H
