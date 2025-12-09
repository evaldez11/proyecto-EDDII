#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "campos.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QAbstractAnimation>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <QVector>
#include "registros.h"
using namespace std;

QString archivo;
bool archivoGuardado = false;
QString metaData;
QVector<Campos> vectorCampos;
QVector<Registros> vectorRegitros;
bool campos = false;
bool modificar = false;
bool eliminar = false;
QVector<QString> vectorInfo;
QVector<Registros> vectorNuevosRegistros;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Font usado para mantener formato
    QFont fuente("Segoe UI", 10);
    QApplication::setFont(fuente);

    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pg_Home);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Deshabilitar boton de confirmar Campos
    ui->pushButtonConfirmar->setEnabled(false);

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);


    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->spinBoxLongitud->setMinimum(0);
    ui->frame_7->setVisible(false);
    ui->frame_10->setVisible(false);


    ui->tableWidgetRegistros->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetRegistros->setAlternatingRowColors(true);
    ui->tableWidgetRegistros->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetRegistros->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetRegistros->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetRegistros->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableWidgetRegistros->setEditTriggers(QAbstractItemView::NoEditTriggers);


    connect(ui->tableWidget, &QTableWidget::cellClicked,this, &MainWindow::onTablaCellClicked);
    connect(ui->comboBoxCampo,&QComboBox::currentIndexChanged,this,&::MainWindow::on_comboBoxTipoDato_currentIndexChanged);




}

MainWindow::~MainWindow()
{
    delete ui;
}

// Campos
void MainWindow::on_pb_Campos_clicked()
{
    if(archivo.isEmpty()){
        QMessageBox::information(this,"Error"," No hay ningun archivo abierto");
    }else{
        ui->stackedWidget->setCurrentWidget(ui->pg_Campos);
        //leerArchivo();
    }

}

// Registros
void MainWindow::on_pb_Registros_clicked()
{
    if(archivo.isEmpty()){
        QMessageBox::information(this,"Error"," No hay ningun archivo abierto");
    }else if(vectorCampos.isEmpty()){
         QMessageBox::information(this,"Error"," No hay campos registrados en el archivo");
    }else{

        ui->stackedWidget->setCurrentWidget(ui->pg_Registros);
    }

}

// Índices
void MainWindow::on_pb_Indices_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pg_Indices);
}

//Iinicio
void MainWindow::on_pb_home_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->pg_Home);
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
        if (file.open(QIODevice::ReadWrite)) {
            //file.close();
            QMessageBox::information(this, "Archivo creado","Se creó correctamente el archivo:\n" + archivo);
        } else {
            QMessageBox::warning(this, "Error", "No se pudo crear el archivo .txt");
        }
    }
}
void MainWindow::vaciarPanelCampos(){
    ui->lineEditCampos->clear();
    ui->comboBoxTipoDato->setCurrentIndex(0);
    ui->spinBoxLongitud->setValue(0);
    ui->radioButtonLlavePrimaria->setChecked(false);
    ui->radioButtonLlaveSecundaria->setChecked(false);
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
            file.setFileName(archivo);
            if (file.open(QIODevice::ReadWrite)) {
                //file.close();
                leerArchivo();
                QMessageBox::information(this, "Archivo creado","Se creó correctamente el archivo:\n" + archivo);
            } else {
                QMessageBox::warning(this, "Error", "No se pudo abrir el archivo .txt");
            }
            QMessageBox::information(this,"Archivo seleccionado","Abriste el archivo:\n" + archivo);
        }

    }else{
         archivo = QFileDialog::getOpenFileName(this,"Seleccionar archivo", "", "Archivos de texto (*.txt)");

        if (archivo.isEmpty()){
            return; // si el usuario cancela
        }
        file.setFileName(archivo);
        if (file.open(QIODevice::ReadWrite)) {
            //file.close();
            QMessageBox::information(this, "Archivo creado","Se abrio correctamente el archivo:\n" + archivo);
            leerArchivo();
        } else {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo .txt");
        }
    }
}
void MainWindow::leerArchivo(){
    QTextStream in(&file);
    metaData = in.readLine();
    QString headLine = in.readLine();
    int headRNN = headLine.toInt();

    qDebug() << "Head del avail list:" << headRNN;
    avail.rebuildAvailList(headRNN);
    vectorCampos.clear();
    QStringList listaCampos = metaData.split('|', Qt::SkipEmptyParts);
    for(int i = 0; i<listaCampos.size();i++){
        Campos nuevoCampo;
        QStringList columnas = listaCampos[i].split(QChar(0x0192)); // 'ƒ'
        if (columnas.size() == 4) {
        nuevoCampo.setnombreCampo(columnas[0]);
        nuevoCampo.settipoDato(columnas[1]);
        nuevoCampo.setlongitud(columnas[2].toInt());
        nuevoCampo.settipoLlave(columnas[3]);
        vectorCampos.append(nuevoCampo);
        }
    }
    ui->tableWidget->setRowCount(listaCampos.size());


    for (int r = 0; r < listaCampos.size(); ++r) {
        QStringList cols = listaCampos[r].split(QChar(0x0192)); // 'ƒ'

        if (ui->tableWidget->columnCount() < cols.size())
            ui->tableWidget->setColumnCount(cols.size());

        for (int c = 0; c < cols.size(); ++c) {
            ui->tableWidget->setItem(r, c, new QTableWidgetItem(cols[c]));
        }
    }
    metaData = "";
    for(Campos c : vectorCampos){
        qDebug() << c.toString();
    }

    vectorRegitros.clear();
    QStringList listaRegistros;

    // Leer cada línea de registros
    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (!linea.isEmpty()){
            listaRegistros.append(linea);
        }
    }
    llenarPaginaRegistros(listaRegistros);
}
void MainWindow::guardarArchivo(){
    int filas = ui->tableWidget->rowCount();
    bool hayLlavePrimaria = false;
    for (int r = 0; r < filas; ++r) {
        QTableWidgetItem *it = ui->tableWidget->item(r, 3);
        if (!it) continue;
        QString texto = it->text();
        if (texto == "Primaria") {
            hayLlavePrimaria = true;
        }
    }

    if(hayLlavePrimaria){
        vectorCampos.clear();
        for(int r = 0; r < filas;r++){
            QTableWidgetItem *campoNombre = ui->tableWidget->item(r, 0);
            QTableWidgetItem *TipoDato = ui->tableWidget->item(r, 1);
            QTableWidgetItem *Longitud = ui->tableWidget->item(r, 2);
            QTableWidgetItem *TipoLlave = ui->tableWidget->item(r, 3);
            Campos nuevoCampo(campoNombre->text(),TipoDato->text(), Longitud->text().toInt(),TipoLlave->text());
            vectorCampos.append(nuevoCampo);
        }
        metaData = "";
        for(Campos c : vectorCampos){
            metaData += c.toString() + "|";
        }
        file.resize(0);
        file.seek(0);
        QTextStream out(&file);
        out << metaData;
        out.flush();
        metaData  = "";
    qint64 posDespuesDeMetadata = file.pos();

        if(avail.getHead()==nullptr){
            file.seek(posDespuesDeMetadata);

            // Escribir directamente para evitar problemas del QTextStream
            qDebug() << "Escribiendo -1...";
            file.write("\n-1\n");
            file.flush();
        }
    qint64 posDespuesDeHeadRNN = file.pos();
        agregarRegistros();
        //file.close();
        QMessageBox::information(this, "Guardado", "Los cambios se guardaron correctamente.");
        for(Campos c : vectorCampos){
            qDebug() << c.toString();
        }

    }else{
        QMessageBox::information(this,"No Hay Llave Primaria","No hay ningun campo marcado como llave primaria, no puedes guardar asi el archivo");
    }

    archivoGuardado = true;
}
void MainWindow::on_actionGuardar_Archivo_triggered()
{
    guardarArchivo();
}


void MainWindow::on_pushButtonCrearCampo_clicked()
{
    vaciarPanelCampos();
    QMessageBox::information(this,"Crear Campo","Llena la nueva fila al final de la tabla, con los datos requeridos, y luego darle al boton de confirmar");
    campos = true;
    modificar = false;
    eliminar = false;
    ui->frame_7->setVisible(true);
    ui->pushButtonConfirmar->setEnabled(true);
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
}

bool  MainWindow::verificarCampos(int fila){
    if(ui->lineEditCampos->text().isEmpty()){
        QMessageBox::information(this,"Creacion de Campo Fallida","El apartado de Campo esta vacio");
        return false;
    }
    switch(ui->comboBoxTipoDato->currentIndex()){
    case 0:
        if(ui->spinBoxLongitud->value() == 0){
             QMessageBox::information(this,"Creacion de Campo Fallida","Si el tipo de dato es string, no puede tener longitud 0");
            return false;
        }
        break;
    case 1:
        if(ui->spinBoxLongitud->value() == 0){
            QMessageBox::information(this,"Creacion de Campo Fallida","Si el tipo de dato es int, no puede tener maximo de 0");
            return false;
        }
        break;
    case 2:
        break;
    case 3:
        if(ui->spinBoxLongitud->value() == 0){
            QMessageBox::information(this,"Creacion de Campo Fallida","Si el tipo de dato es float, no puede tener maximo de 0");
            return false;
        }
        break;
    }

    if(!ui->radioButtonLlavePrimaria->isChecked() && !ui->radioButtonLlaveSecundaria->isChecked() && !ui->radioButtonNinuna->isChecked()){
        QMessageBox::information(this,"Creacion de Campo Fallida","No has seleccionado el tipo de llave");
        return false;
    }
    if(ui->radioButtonLlavePrimaria->isChecked()){
        int filas = ui->tableWidget->rowCount();
        for (int r = 0; r < filas; ++r) {
            QTableWidgetItem *it = ui->tableWidget->item(r, 3);
            if (!it) continue;
            QString texto = it->text();
            if (texto == "Primaria" && r!=fila) {
                QMessageBox::information(this,"Creacion de Campo Fallida","Ya hay una llave primaria");
                return false;
            }
        }
    }


    return true;
}

void MainWindow::on_pushButtonConfirmar_clicked()
{
    if (campos){
        if(verificarCampos(ui->tableWidget->rowCount()-1)){
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(ui->lineEditCampos->text()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(ui->comboBoxTipoDato->currentText()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(ui->spinBoxLongitud->value())));
            if(ui->radioButtonLlavePrimaria->isChecked()){
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem("Primaria"));
            }else if (ui->radioButtonLlaveSecundaria->isChecked()){
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem("Secundaria"));
            }else if (ui->radioButtonNinuna->isChecked()){
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem("No es Llave"));
            }
            QMessageBox::information(this,"Creacion de Campo Existosa","El campo se creo correctamente");
            vaciarPanelCampos();
            ui->frame_7->setVisible(false);
            ui->pushButtonConfirmar->setEnabled(false);
        }
    }else if(modificar){
        if(verificarCampos(ui->tableWidget->currentRow())){
            ui->tableWidget->setItem(ui->tableWidget->currentRow(), 0, new QTableWidgetItem(ui->lineEditCampos->text()));
            ui->tableWidget->setItem(ui->tableWidget->currentRow(), 1, new QTableWidgetItem(ui->comboBoxTipoDato->currentText()));
            ui->tableWidget->setItem(ui->tableWidget->currentRow(), 2, new QTableWidgetItem(QString::number(ui->spinBoxLongitud->value())));
            if(ui->radioButtonLlavePrimaria->isChecked()){
                ui->tableWidget->setItem(ui->tableWidget->currentRow(), 3, new QTableWidgetItem("Primaria"));
            }else if (ui->radioButtonLlaveSecundaria->isChecked()){
                ui->tableWidget->setItem(ui->tableWidget->currentRow(), 3, new QTableWidgetItem("Secundaria"));
            }else if (ui->radioButtonNinuna->isChecked()){
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem("No es Llave"));
            }
            QMessageBox::information(this,"Modificacion de Campo Existosa","El campo se modifico correctamente");
            vaciarPanelCampos();
            ui->frame_7->setVisible(false);
            ui->pushButtonConfirmar->setEnabled(false);
        }
    }else if(eliminar){
        int fila = ui->tableWidget->currentRow();
        if (fila >= 0) {
            ui->tableWidget->removeRow(fila);
        }
        QMessageBox::information(this,"Eliminacion de Campo Existosa","El campo se elimino correctamente");
         ui->pushButtonConfirmar->setEnabled(false);
    }
}


void MainWindow::on_comboBoxTipoDato_currentIndexChanged(int index)
{
    if(index == 2){
        ui->spinBoxLongitud->setValue(1);
        ui->spinBoxLongitud->setEnabled(false);
    }else{
         ui->spinBoxLongitud->setEnabled(true);
    }

    if(index == 1 || index == 3){
        ui->label_5->setText("Maximo");
    }else{
        ui->label_5->setText("Longitud:");
    }
}
void MainWindow::onTablaCellClicked(int row, int columna)
{
    QTableWidgetItem *Campo   = ui->tableWidget->item(row, 0);
    QTableWidgetItem *TipoDato = ui->tableWidget->item(row, 1);
    QTableWidgetItem *Longitud = ui->tableWidget->item(row, 2);
    QTableWidgetItem *TipoLlave = ui->tableWidget->item(row, 3);


    // llenar los widgets del panel
    ui->lineEditCampos->setText(Campo->text());
    if(TipoDato->text() == "String"){
        ui->comboBoxTipoDato->setCurrentIndex(0);
    }else if(TipoDato->text() == "Int"){
        ui->comboBoxTipoDato->setCurrentIndex(1);
    }else if(TipoDato->text() == "Char"){
        ui->comboBoxTipoDato->setCurrentIndex(2);
    }else if(TipoDato->text() == "Float"){
        ui->comboBoxTipoDato->setCurrentIndex(3);
    }

    ui->spinBoxLongitud->setValue(Longitud->text().toInt());

    if(TipoLlave->text() == "Primaria"){
        ui->radioButtonLlavePrimaria->setChecked(true);
    }else if(TipoLlave->text() == "Secundaria"){
        ui->radioButtonLlaveSecundaria->setChecked(true);
    }
}

void MainWindow::on_pushButtonModificarCampo_clicked()
{
    vaciarPanelCampos();
    QMessageBox::information(this,"Modificar Campo","Modifica la fila seleccionada, con los datos requeridos, y luego darle al boton de confirmar");
    modificar = true;
    campos = false;
    eliminar = false;
    ui->pushButtonConfirmar->setEnabled(true);

    ui->frame_7->setVisible(true);

}


void MainWindow::on_pushButtonBorrarCampo_clicked()
{
    vaciarPanelCampos();
    QMessageBox::information(this,"Eliminar Campo"," Selecciona la fila que deseas eliminar y luego darle al boton de confirmar");
    modificar = false;
    campos = false;
    eliminar = true;
    ui->pushButtonConfirmar->setEnabled(true);
}


void MainWindow::on_actionCerrar_Archivo_triggered()
{
    if(archivo.isEmpty()){
        QMessageBox::information(this,"Error","No hay ningun archivo abierto");
    }else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Cerrar archivo","Estas cerrando el archivo\n¿Deseas guardar el archivo?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (reply == QMessageBox::Cancel){
            return;
        }else if (reply == QMessageBox::No){
            file.close();
            archivo.clear();
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);
            ui->stackedWidget->setCurrentWidget(ui->pg_Home);
            vectorCampos.clear();
        }else{
            guardarArchivo();
            file.close();
            archivo.clear();
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);
            ui->stackedWidget->setCurrentWidget(ui->pg_Home);
            vectorCampos.clear();
        }
    }

}
void MainWindow::llenarPaginaRegistros(QStringList cad){
    ui->tableWidgetRegistros->setColumnCount(0);
    ui->comboBoxCampo->clear();
    for(Campos c: vectorCampos){
        ui->comboBoxCampo->addItem(c.getnombreCampo());
        int col = ui->tableWidgetRegistros->columnCount();
        ui->tableWidgetRegistros->insertColumn(col);
        ui->tableWidgetRegistros->setHorizontalHeaderItem(col, new QTableWidgetItem(c.getnombreCampo()));
    }

    ui->tableWidgetRegistros->setRowCount(cad.size());

    // Llenar la tabla
    for (int i = 0; i < cad.size(); i++) {
        QStringList camposReg = cad[i].split(QChar(0x0192));
        for (int j = 0; j < camposReg.size(); j++) {
            // Crear QTableWidgetItem y ponerlo en la celda
            ui->tableWidgetRegistros->setItem(i, j, new QTableWidgetItem(camposReg[j].trimmed()));
        }
    }
    ui->tableWidgetRegistros->resizeColumnsToContents();
}
void MainWindow::on_comboBoxCampo_currentIndexChanged(int index){

    if (index >= 0 && index < vectorInfo.size()) {
        ui->lineEditInfo->setText(vectorInfo.at(index));
    } else {
        ui->lineEditInfo->clear(); // limpiar si no hay valor
    }


}


void MainWindow::on_pushButtonAgregar_clicked()
{
    int pos = ui->comboBoxCampo->currentIndex();

    // Si no hay selección, agregamos al final
    if (pos < 0 || pos > vectorInfo.size()) {
        pos = vectorInfo.size();
    }
    if(ui->lineEditInfo->text().size() > vectorCampos[pos].getlongitud()){
         QMessageBox::information(this,"Error","La informacion que desea agregar excede la longitud establecida para el campo de:\n"+vectorCampos[pos].getnombreCampo()+" (Longitud: "+ QString::number(vectorCampos[pos].getlongitud()) +")");
    }else{
        vectorInfo[pos] = ui->lineEditInfo->text();
        QMessageBox::information(this,"Informacion","El campo "+vectorCampos[pos].getnombreCampo()+" se lleno correctamente");
    }

}


void MainWindow::on_pushButtonConfirmarRegistros_clicked()
{
    bool registroLleno = true;
    for(QString r : vectorInfo){
        if(r == ""){
            registroLleno = false;
        }
    }
    if(registroLleno){
        int row = ui->tableWidgetRegistros->rowCount();
        ui->tableWidgetRegistros->insertRow(row);
        for(int i = 0; i < vectorInfo.size();i++){
            ui->tableWidgetRegistros->setItem(row, i, new QTableWidgetItem(vectorInfo[i]));
        }
        ui->frame_10->setVisible(false);
        Registros nuevoRegistro;
        nuevoRegistro.setSectorCampos(vectorCampos);
        QString reg = "";
        for(int i = 0; i <vectorInfo.size();i++){
            int tamRestante = 0;
            if(vectorInfo[i].size() < vectorCampos[i].getlongitud()){
                tamRestante = vectorCampos[i].getlongitud() - vectorInfo[i].size();
            }
            QString cadenaEspacios;
            for(int j = 0; j < tamRestante; j++){
                cadenaEspacios +=" ";
            }
            if(i == vectorInfo.size() - 1 ){
                reg += vectorInfo[i] + cadenaEspacios;
            }else{
                reg += vectorInfo[i]+cadenaEspacios + "ƒ";
            }
        }
        nuevoRegistro.setRegistro(reg);
        qDebug() << nuevoRegistro.getRegistro();
        vectorNuevosRegistros.append(nuevoRegistro);
    }else{
         QMessageBox::information(this,"Error","No llenaste todos los campos");
    }


}


void MainWindow::on_pushButtonCrearRegistro_clicked()
{
    ui->lineEditInfo->setText("");
    vectorInfo.clear();
    for(int i = 0; i<vectorCampos.size();i++){
        vectorInfo.append("");
    }
    QMessageBox::information(this,"Informacion","1. Llena el apartado de informacion, segun el campo seleccionado\n2. Presiona el boton de agregar para llenar ese campo\n3. Al terminar de llenar todos los campos, presiona el boton de confirmar");
    ui->frame_10->setVisible(true);
}

void MainWindow::agregarRegistros(){
    if(vectorNuevosRegistros.isEmpty()){
        return;
    }
    if(avail.getHead() == nullptr){
        //qDebug() << "La avail list está vacía";
        file.seek(file.size());
        QTextStream out(&file);
        for(Registros s : vectorNuevosRegistros){
            out << s.getRegistro() << "\n";
        }
    }else{

    }
}
void MainWindow::borrarRegistros(){

}
