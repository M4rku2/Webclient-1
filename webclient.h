#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"
#include <QDebug>
#include <QAbstractSocket>
#include <QTcpSocket>


class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT


public:
    explicit Webclient(QWidget *parent = nullptr);


private slots:
    void clicked_button();


    void on_pushButton_clicked();

private:
    void textoutput(QString message);
    void socket_connect();
    void print_text();


private:
    QTcpSocket *m_sock = nullptr;
    QString m_search;
    const short m_port = 80;
};

#endif // WEBCLIENT_H
