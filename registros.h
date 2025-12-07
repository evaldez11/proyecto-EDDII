#ifndef REGISTROS_H
#define REGISTROS_H
#include <QVector>
#include "campos.h"
class Registros
{
public:
    Registros();
    Registros(QVector<Campos> campos, QString registro);
    QVector<Campos> getVectorCampos();
    void setSectorCampos(QVector<Campos>);
    QString getRegistro();
    void setRegistro(QString);


private:
    QVector<Campos> campos;
    QString registro;
};

#endif // REGISTROS_H
