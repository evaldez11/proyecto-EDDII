#include "registros.h"


Registros::Registros(){

}
Registros::Registros(QVector<Campos> campos, QString registro, int RNN){
    this->campos = campos;
    this->registro = registro;
    this->RNN = RNN;
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
int Registros::getRNN(){
    return RNN;
}
void Registros::setRNN(int rnn){
    RNN = rnn;
}
