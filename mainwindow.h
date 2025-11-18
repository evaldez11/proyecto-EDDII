#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    // Botones de Uso
    void on_pb_Campos_clicked();
    void on_pb_Registros_clicked();
    void on_pb_Indices_clicked();

    // Boton de Desplace
    void on_pb_Desplace_clicked();

    // Botones de Acciones de Menu de Archivo
    void on_actionNuevoArchivo_triggered();
    void on_actionAbrirArchivo_triggered();
    void on_actionGuardarArchivo_triggered();
    void on_actionCerrarArchivo_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
