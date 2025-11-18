#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QAbstractAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Campos
void MainWindow::on_pb_Campos_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pg_Campos);
}

// Registros
void MainWindow::on_pb_Registros_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pg_Registros);
}

// Índices
void MainWindow::on_pb_Indices_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pg_Indices);
}

// Animacion de Desplace del Menu Izquierdo
void MainWindow::on_pb_Desplace_clicked()
{
    // Ancho actual del menú
    int anchoActual = ui->menuIzquierdo->width();

    int nuevoAncho;
    if (anchoActual == 50) {
        // Menú está colapsado → expandir
        nuevoAncho = 180;
        ui->pb_Campos->setText("Campos");
        ui->pb_Registros->setText("Registros");
        ui->pb_Indices->setText("Índices");
    } else {
        // Menú está expandido → colapsar
        nuevoAncho = 50;
        // Solo iconos (ocultamos el texto)
        ui->pb_Campos->setText("");
        ui->pb_Registros->setText("");
        ui->pb_Indices->setText("");
    }

    // Animación del ancho mínimo (puede ser maximumWidth también)
    QPropertyAnimation *animacion =
        new QPropertyAnimation(ui->menuIzquierdo, "minimumWidth");

    animacion->setDuration(350);                    // ms
    animacion->setStartValue(anchoActual);
    animacion->setEndValue(nuevoAncho);
    animacion->setEasingCurve(QEasingCurve::InOutCubic);

    // Se borra sola al terminar
    animacion->start(QAbstractAnimation::DeleteWhenStopped);
}

// Botones de Accion de Archivo
void MainWindow::on_actionNuevoArchivo_triggered()
{
    // Aquí limpias todo lo necesario para empezar un archivo nuevo
    // Ejemplo:
    // limpiarCampos();
    // currentFilePath.clear();
}

void MainWindow::on_actionAbrirArchivo_triggered()
{

    // Aquí llamas a tu FileManager para abrir el archivo
    // fileManager.abrirArchivo(fileName);
}

void MainWindow::on_actionGuardarArchivo_triggered()
{
    // Si ya tienes ruta guardada:
    // fileManager.guardarArchivo();

    // Si quieres “Guardar como…”:
    // QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), ...);
}

void MainWindow::on_actionCerrarArchivo_triggered()
{
    // Cerrar archivo actual, limpiar índices, etc.
    // fileManager.cerrarArchivo();
    // limpiarCampos();
}
