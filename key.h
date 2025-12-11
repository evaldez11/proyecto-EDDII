#ifndef KEY_H
#define KEY_H
#include <string>
using namespace std;
class Key {
    int llave;
    string Resto;
    int posicion;
public:
    Key();
    Key(int llave,string Resto,int posicion);
    bool esTipoNumerico();
    int string_a_numero();
    int getllave();
    string getResto();
    int getPosicion();
    void setllave(int llave);
    void setResto(string Resto);
    void setPosicion(int posicion);

};
#endif // KEY_H
