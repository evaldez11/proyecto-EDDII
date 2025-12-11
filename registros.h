#ifndef REGISTROS_H
#define REGISTROS_H
#include <QVector>
#include "campos.h"
class Registros
{
public:
    Registros();
    Registros(QVector<Campos> campos, QString registro, int RNN);
    QVector<Campos> getVectorCampos();
    void setSectorCampos(QVector<Campos>);
    QString getRegistro();
    void setRegistro(QString);
    int getRNN();
    void setRNN(int);


private:
    QVector<Campos> campos;
    QString registro;
    int RNN;
};

#endif // REGISTROS_H
