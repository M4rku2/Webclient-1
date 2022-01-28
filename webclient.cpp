#include "webclient.h"
#include <thread>


Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(textinput, &QLineEdit::returnPressed, this, &Webclient::clicked_button);

    m_sock = new QTcpSocket(this);
    connect(m_sock, &QTcpSocket::connected, this, &Webclient::socket_connect);
    connect(m_sock, &QTcpSocket::readyRead, this, &Webclient::print_text);
    connect(pushButton, &QPushButton::clicked, this, &Webclient::clicked_button); // In Stunde gemacht!

}


void Webclient::textoutput(QString message)
{
    output_text->clear();
    output_text->setText(message);
}


void Webclient::socket_connect()
{
    m_sock->write(QString("GET / HTTP/1.1\r\nHost:" + m_search + "\r\n\r\n").toLocal8Bit());
}


void Webclient::print_text()
{
    textoutput(m_sock->readAll());
    m_sock->disconnectFromHost();
}


void Webclient::clicked_button()
{
    m_sock->reset();
    if(!textinput->text().isEmpty())
    {
        m_sock->connectToHost(textinput->text(), m_port);
    }
    else
    {
        textoutput("Empty");
    }

}
