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
private slots:
    // Botones de Uso
    void on_pb_Campos_clicked();
    void on_pb_Registros_clicked();
    void on_pb_Indices_clicked();

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

private:
    Ui::MainWindow *ui;
    QFile file;

};
#endif // MAINWINDOW_H
