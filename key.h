#ifndef KEY_H
#define KEY_H
#include <string>
using namespace std;
class Key {
    long long llave;
    string Resto;
    int posicion;
public:
    Key();
    Key(long long llave,string Resto,int posicion);
    bool esTipoNumerico();
    int string_a_numero();
    long long getllave();
    string getResto();
    int getPosicion();
    void setllave(int llave);
    void setResto(string Resto);
    void setPosicion(int posicion);

};
#endif // KEY_H
