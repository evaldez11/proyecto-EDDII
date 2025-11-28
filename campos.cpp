#include "campos.h"

Campos::Campos()
{
    // Inicialización por defecto
    nombreCampo = "";
    tipoDato = "";
    longitud = 0;
    tipoLlave = "";
}
Campos::Campos(QString nombreCampo, QString tipoDato,int longitud, QString tipoLlave){
    this->nombreCampo = nombreCampo;
    this->tipoDato = tipoDato;
    this->longitud = longitud;
    this->tipoLlave = tipoLlave;
}
QString Campos::getnombreCampo()
{
    return nombreCampo;
}

QString Campos::gettipoDato()
{
    return tipoDato;
}

int Campos::getlongitud()
{
    return longitud;
}

QString Campos::gettipoLlave()
{
    return tipoLlave;
}

void Campos::setnombreCampo(QString nombre)
{
    nombreCampo = nombre;
}

void Campos::settipoDato(QString tipo)
{
    tipoDato = tipo;
}

void Campos::setlongitud(int lon)
{
    longitud = lon;
}

void Campos::settipoLlave(QString llave)
{
    tipoLlave = llave;
}

QString Campos::toString(){
    return nombreCampo + "ƒ" + tipoDato + "ƒ" + QString::number(longitud) + "ƒ" + tipoLlave;
}

