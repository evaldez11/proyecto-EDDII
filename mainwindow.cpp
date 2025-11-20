#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QAbstractAnimation>
#include <QFileDialog>
#include <QMessageBox>

QString archivo;
bool archivoGuardado = false;
QString metaData;
bool campos = false;
bool modificar = false;
bool eliminar = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pushButtonConfirmar->setVisible(false);


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




void MainWindow::cerrarArchivo(){
    if (file.isOpen()){
        file.close();
    }
    archivoGuardado = false;
    archivo.clear();
    QMessageBox::information(this, "Archivo cerrado","Se cerro correctamente el archivo:\n" + archivo);
}
void MainWindow::on_actionNuevo_Archivo_triggered()
{

    if(!archivo.isEmpty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Archivo abierto","Ya tienes un archivo abierto\n""¿Deseas cerrarlo y crear uno nuevo?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::No){
            return;

        }else{
           cerrarArchivo();
        }

    }else{
        archivo = QFileDialog::getSaveFileName(this,"Crear archivo .txt", "","Archivo de texto (*.txt)");
        if (archivo.isEmpty()){
            return;
        }

        if (!archivo.endsWith(".txt")){
            archivo += ".txt";
        }

        file.setFileName(archivo);
        if (file.open(QIODevice::WriteOnly)) {
            file.close();
            QMessageBox::information(this, "Archivo creado","Se creó correctamente el archivo:\n" + archivo);
        } else {
            QMessageBox::warning(this, "Error", "No se pudo crear el archivo .txt");
        }
    }
}


void MainWindow::on_actionAbrir_Archivo_triggered()
{
    if(!archivo.isEmpty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Archivo abierto","Ya tienes un archivo abierto\n""¿Deseas cerrarlo y abrir otro?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::No){
            return;

        }else{
            cerrarArchivo();
            archivo = QFileDialog::getOpenFileName(this,"Seleccionar archivo", "", "Archivos de texto (*.txt)");

            if (archivo.isEmpty()){
                return; // si el usuario cancela
            }
            QMessageBox::information(this,"Archivo seleccionado","Abriste el archivo:\n" + archivo);
        }

    }else{
         archivo = QFileDialog::getOpenFileName(this,"Seleccionar archivo", "", "Archivos de texto (*.txt)");

        if (archivo.isEmpty()){
            return; // si el usuario cancela
        }
        QMessageBox::information(this,"Archivo seleccionado","AbristeS el archivo:\n" + archivo);
    }
}


void MainWindow::on_actionGuardar_Archivo_triggered()
{

    archivoGuardado = true;
    QMessageBox::information(this, "Guardado", "Los cambios se guardaron correctamente.");
}


void MainWindow::on_pushButtonCrearCampo_clicked()
{
    QMessageBox::information(this,"Crear Campo","Llena la nueva fila al final de la tabla, con los datos requeridos, y luego darle al boton de confirmar");
    ui->pushButtonConfirmar->setVisible(true);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

