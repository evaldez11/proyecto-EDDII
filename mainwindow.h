#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "availlist.h"
#include "btree.h"
#include "key.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void cerrarArchivo();
    bool verificarCampos(int fila);
    void vaciarPanelCampos();
    void onTablaCellClicked(int row, int columna);
    void leerArchivo();
    void guardarArchivo();
    void llenarPaginaRegistros(QStringList);
    void agregarRegistros();
    void borrarRegistros(int rnnAEliminar);
    void limpiarFila(int);
    void llenarArbol();
    QString imprimirRegistro(Key k);
    long long stringToNumber(const QString &str);
private slots:
    // Botones de Uso
    void on_pb_Campos_clicked();
    void on_pb_Registros_clicked();
    void on_pb_Indices_clicked();
    void on_pb_home_clicked();

    // Boton de Desplace
    void on_pb_Desplace_clicked();


    void on_actionNuevo_Archivo_triggered();

    void on_actionAbrir_Archivo_triggered();

    void on_actionGuardar_Archivo_triggered();

    void on_pushButtonCrearCampo_clicked();

    void on_pushButtonConfirmar_clicked();

    void on_comboBoxTipoDato_currentIndexChanged(int index);

    void on_pushButtonModificarCampo_clicked();

    void on_pushButtonBorrarCampo_clicked();

    void on_actionCerrar_Archivo_triggered();
    void on_comboBoxCampo_currentIndexChanged(int index);



    void on_pushButtonAgregar_clicked();

    void on_pushButtonConfirmarRegistros_clicked();

    void on_pushButtonCrearRegistro_clicked();

    void on_pushButtonBorrarRegistro_clicked();

    void on_pushButtonModificarRegistro_clicked();

    void on_pushButtonBuscarRegistro_clicked();

    void on_pushButtonIndexar_clicked();

    void on_pushButtonBuscarInd_clicked();

private:
    Ui::MainWindow *ui;
    QFile file;
    QFile bin;
    availList avail;
    BTree arbolLlaveP;
    BTree arbolSec;

};
#endif // MAINWINDOW_H
