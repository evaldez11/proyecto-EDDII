#ifndef CAMPOS_H
#define CAMPOS_H
#include <QString>
class Campos
{
public:
    Campos();
    Campos(QString nombreCampo, QString tipoDato,int longitud, QString tipoLlave);
    QString getnombreCampo() const;
    QString gettipoDato() const;
    int getlongitud() const;
    QString gettipoLlave() const;
    void setnombreCampo(QString) ;
    void settipoDato(QString) ;
    void setlongitud(int) ;
    void settipoLlave(QString) ;
    QString toString() ;

private:
    QString nombreCampo;
    QString tipoDato;
    int longitud;
    QString tipoLlave;

};

#endif // CAMPOS_H
