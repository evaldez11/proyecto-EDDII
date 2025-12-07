#include "registros.h"


Registros::Registros(){

}
Registros::Registros(QVector<Campos> campos, QString registro){
    this->campos = campos;
    this->registro = registro;
}
QVector<Campos>Registros:: getVectorCampos(){
    return campos;
}
void Registros:: setSectorCampos(QVector<Campos> nuevosCampos){
    campos = nuevosCampos;
}
QString Registros:: getRegistro(){
    return registro;
}
void Registros:: setRegistro(QString r){
    registro = r;
}
