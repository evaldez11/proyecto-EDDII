#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
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

    // Registros methods
    void cargarRegistros();
    void generarInputsRegistros();
    void vaciarInputsRegistros();
    void cargarInputsDesdeRegistro(int row);
    bool validarInputsRegistros();
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

    // Registros slots
    void on_pushButtonCrearRegistro_clicked();
    void on_pushButtonModificarRegistro_clicked();
    void on_pushButtonBorrarRegistro_clicked();
    void on_pushButtonConfirmarRegistro_clicked();
private:
    Ui::MainWindow *ui;
    QFile file;

};
#endif // MAINWINDOW_H
