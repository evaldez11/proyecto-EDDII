#include "key.h"
Key::Key() {
    llave = 0;
    Resto = "";
    posicion = 0;
}

Key::Key(long long llave,string Resto, int posicion){
    this->llave = llave;
    this->Resto = Resto;
    this->posicion = posicion;
}

long long Key::getllave(){
    return llave;
}
string Key::getResto(){
    return Resto;
}
int Key::getPosicion() {
    return posicion;
}
void Key::setllave(int llave){
    this->llave = llave;
}
void Key::setResto(string Resto){
    this->Resto = Resto;
}
void Key::setPosicion(int posicion){
    this->posicion = posicion;
}
