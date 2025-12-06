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
#include <QMap>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

using namespace std;

QString archivo;
bool archivoGuardado = false;
QString metaData;
QVector<Campos> vectorCampos;
bool campos = false;
bool modificar = false;
bool eliminar = false;

// Registros global variables
QVector<QMap<QString, QString>> vectorRegistros;
bool crearRegistro = false;
bool modificarRegistro = false;
bool eliminarRegistro = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Font usado para mantener formato
    QFont fuente("Segoe UI", 10);
    QApplication::setFont(fuente);

    ui->setupUi(this);
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

    connect(ui->tableWidget, &QTableWidget::cellClicked,this, &MainWindow::onTablaCellClicked);

    // Configure tableWidgetRegistros
    ui->tableWidgetRegistros->setAlternatingRowColors(true);
    ui->tableWidgetRegistros->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetRegistros->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetRegistros->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetRegistros->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Initially hide input panel
    ui->frame_Registros->setVisible(false);

    // Disable confirm button initially
    ui->pushButtonConfirmarRegistro->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Campos
void MainWindow::on_pb_Campos_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pg_Campos);
    leerArchivo();
}

// Registros
void MainWindow::on_pb_Registros_clicked()
{
    // Validate that campos are defined before allowing navigation
    if (vectorCampos.isEmpty()) {
        QMessageBox::warning(this, "Error", "Primero debes definir campos en la página de Campos");
        return;
    }

    // Switch to Registros page and load the records
    ui->stackedWidget->setCurrentWidget(ui->pg_Registros);
    cargarRegistros();
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
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
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
            if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
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
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
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

    // Read registro lines
    vectorRegistros.clear();
    while (!in.atEnd()) {
        QString linea = in.readLine();
        if (linea.isEmpty()) continue;

        QStringList valores = linea.split('|', Qt::SkipEmptyParts);

        for (const QString &registroStr : valores) {
            QStringList cols = registroStr.split(QChar(0x0192)); // 'ƒ'

            if (cols.size() != vectorCampos.size()) continue;

            QMap<QString, QString> registro;
            for (int i = 0; i < vectorCampos.size(); i++) {
                QString campoNombre = vectorCampos[i].getnombreCampo();
                registro[campoNombre] = cols[i];
            }

            vectorRegistros.append(registro);
        }
    }
}

void MainWindow::on_actionGuardar_Archivo_triggered()
{
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

        // Build registros lines
        QString registrosData = "";
        for (const QMap<QString, QString> &registro : vectorRegistros) {
            for (const Campos &campo : vectorCampos) {
                QString valor = registro[campo.getnombreCampo()];
                registrosData += valor + "ƒ";
            }
            // Remove trailing 'ƒ', add '|'
            registrosData.chop(1);
            registrosData += "|\n";
        }

        file.resize(0);
        file.seek(0);
        QTextStream out(&file);
        out << metaData << "\n";
        out << registrosData;
        //metaData  = "";
        QMessageBox::information(this, "Guardado", "Los cambios se guardaron correctamente.");
        for(Campos c : vectorCampos){
            qDebug() << c.toString();
        }

        //file.close();

    }else{
         QMessageBox::information(this,"No Hay Llave Primaria","No hay ningun campo marcado como llave primaria, no puedes guardar asi el archivo");
    }

    archivoGuardado = true;
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

// Registros implementation stubs
void MainWindow::cargarRegistros() {
    // Clear table
    ui->tableWidgetRegistros->setRowCount(0);

    // Set column count from vectorCampos
    ui->tableWidgetRegistros->setColumnCount(vectorCampos.size());

    // Set column headers from campo names
    QStringList headers;
    for (const Campos &campo : vectorCampos) {
        headers << campo.getnombreCampo();
    }
    ui->tableWidgetRegistros->setHorizontalHeaderLabels(headers);

    // Iterate through vectorRegistros
    for (int row = 0; row < vectorRegistros.size(); ++row) {
        const QMap<QString, QString> &registro = vectorRegistros[row];

        // Insert new row
        ui->tableWidgetRegistros->insertRow(row);

        // For each campo in vectorCampos (iterate in order)
        for (int col = 0; col < vectorCampos.size(); ++col) {
            QString campoNombre = vectorCampos[col].getnombreCampo();

            // Get value from registro map using campo name as key
            QString valor = registro[campoNombre];

            // Create QTableWidgetItem with the value
            QTableWidgetItem *item = new QTableWidgetItem(valor);

            // Set item in table at [row, column]
            ui->tableWidgetRegistros->setItem(row, col, item);
        }
    }
}

void MainWindow::generarInputsRegistros() {
    // Clear existing widgets from layout
    QLayoutItem *item;
    while ((item = ui->frame_Registros->layout()->takeAt(0))) {
        if (item->widget()) delete item->widget();
        delete item;
    }

    QFormLayout *formLayout = new QFormLayout();

    // Create input widget for each campo
    for (const Campos &campo : vectorCampos) {
        QString nombre = campo.getnombreCampo();
        QString tipo = campo.gettipoDato();
        int longitud = campo.getlongitud();

        QWidget *inputWidget = nullptr;

        if (tipo == "String") {
            QLineEdit *input = new QLineEdit();
            input->setObjectName("input_" + nombre);
            input->setMaxLength(longitud);
            inputWidget = input;

        } else if (tipo == "Int") {
            QSpinBox *input = new QSpinBox();
            input->setObjectName("input_" + nombre);
            input->setMaximum(longitud);
            input->setMinimum(0);
            inputWidget = input;

        } else if (tipo == "Char") {
            QLineEdit *input = new QLineEdit();
            input->setObjectName("input_" + nombre);
            input->setMaxLength(1);
            inputWidget = input;

        } else if (tipo == "Float") {
            QDoubleSpinBox *input = new QDoubleSpinBox();
            input->setObjectName("input_" + nombre);
            input->setMaximum(longitud);
            input->setMinimum(0.0);
            input->setDecimals(2);
            inputWidget = input;
        }

        if (inputWidget) formLayout->addRow(nombre + ":", inputWidget);
    }

    QLayout *oldLayout = ui->frame_Registros->layout();

    if (oldLayout) delete oldLayout;

    ui->frame_Registros->setLayout(formLayout);
}

void MainWindow::vaciarInputsRegistros() {
    for (const Campos &campo : vectorCampos) {
        QString nombre = campo.getnombreCampo();
        QString tipo = campo.gettipoDato();

        QWidget *widget = ui->frame_Registros->findChild<QWidget*>("input_" + nombre);

        if (tipo == "String" || tipo == "Char") {
            QLineEdit *input = qobject_cast<QLineEdit*>(widget);
            if (input) input->setText("");

        } else if (tipo == "Int") {
            QSpinBox *input = qobject_cast<QSpinBox*>(widget);
            if (input) input->setValue(0);

        } else if (tipo == "Float") {
            QDoubleSpinBox *input = qobject_cast<QDoubleSpinBox*>(widget);
            if (input) input->setValue(0.0);
        }
    }
}

void MainWindow::cargarInputsDesdeRegistro(int row) {
    // Get registro from vectorRegistros[row]
    const QMap<QString, QString> &registro = vectorRegistros[row];

    // For each campo, find corresponding input widget and set value
    for (const Campos &campo : vectorCampos) {
        QString nombre = campo.getnombreCampo();
        QString tipo = campo.gettipoDato();

        QWidget *widget = ui->frame_Registros->findChild<QWidget*>("input_" + nombre);
        QString valor = registro[nombre];

        if (tipo == "String" || tipo == "Char") {
            QLineEdit *input = qobject_cast<QLineEdit*>(widget);
            if (input) input->setText(valor);

        } else if (tipo == "Int") {
            QSpinBox *input = qobject_cast<QSpinBox*>(widget);
            if (input) input->setValue(valor.toInt());

        } else if (tipo == "Float") {
            QDoubleSpinBox *input = qobject_cast<QDoubleSpinBox*>(widget);
            if (input) input->setValue(valor.toDouble());
        }
    }
}

bool MainWindow::validarInputsRegistros() {
    for (const Campos &campo : vectorCampos) {
        QString nombre = campo.getnombreCampo();
        QString tipo = campo.gettipoDato();
        int longitud = campo.getlongitud();

        QWidget *widget = ui->frame_Registros->findChild<QWidget*>("input_" + nombre);

        if (tipo == "String") {
            QLineEdit *input = qobject_cast<QLineEdit*>(widget);
            if (!input) continue;

            QString value = input->text();
            if (value.isEmpty()) {
                QMessageBox::warning(this, "Error", "El campo " + nombre + " no puede estar vacío");
                return false;
            }
            if (value.length() > longitud) {
                QMessageBox::warning(this, "Error", "El campo " + nombre + " excede la longitud máxima");
                return false;
            }

        } else if (tipo == "Int") {
            QSpinBox *input = qobject_cast<QSpinBox*>(widget);
            if (!input) continue;

            int value = input->value();
            if (value > longitud) {
                QMessageBox::warning(this, "Error", "El campo " + nombre + " excede el máximo permitido");
                return false;
            }

        } else if (tipo == "Char") {
            QLineEdit *input = qobject_cast<QLineEdit*>(widget);
            if (!input) continue;

            if (input->text().isEmpty()) {
                QMessageBox::warning(this, "Error", "El campo " + nombre + " requiere un carácter");
                return false;
            }

        } else if (tipo == "Float") {
            QDoubleSpinBox *input = qobject_cast<QDoubleSpinBox*>(widget);
            if (!input) continue;

            double value = input->value();
            if (value > longitud) {
                QMessageBox::warning(this, "Error", "El campo " + nombre + " excede el máximo permitido");
                return false;
            }
        }
    }

    return true;
}

void MainWindow::on_pushButtonCrearRegistro_clicked() {
    // Call generarInputsRegistros() to create fresh input widgets
    generarInputsRegistros();

    // Call vaciarInputsRegistros() to clear all inputs
    vaciarInputsRegistros();

    // Show success message
    QMessageBox::information(this, "Crear Registro", "Completa los campos y presiona Confirmar");

    // Set mode flags
    crearRegistro = true;
    modificarRegistro = false;
    eliminarRegistro = false;

    // Show input panel
    ui->frame_Registros->setVisible(true);

    // Enable confirm button
    ui->pushButtonConfirmarRegistro->setEnabled(true);
}

void MainWindow::on_pushButtonModificarRegistro_clicked() {
    // Get selected row
    int row = ui->tableWidgetRegistros->currentRow();

    // Check if a row is selected
    if (row < 0) {
        QMessageBox::warning(this, "Error", "Debes seleccionar un registro para modificar");
        return;
    }

    // Call generarInputsRegistros() to create input widgets
    generarInputsRegistros();

    // Call cargarInputsDesdeRegistro to populate inputs with current values
    cargarInputsDesdeRegistro(row);

    // Show info message
    QMessageBox::information(this, "Modificar Registro", "Modifica los campos y presiona Confirmar");

    // Set mode flags
    modificarRegistro = true;
    crearRegistro = false;
    eliminarRegistro = false;

    // Show input panel
    ui->frame_Registros->setVisible(true);

    // Enable confirm button
    ui->pushButtonConfirmarRegistro->setEnabled(true);
}

void MainWindow::on_pushButtonBorrarRegistro_clicked() {
    // Get selected row
    int row = ui->tableWidgetRegistros->currentRow();

    // Check if a row is selected
    if (row < 0) {
        QMessageBox::warning(this, "Error", "Debes seleccionar un registro para eliminar");
        return;
    }

    // Show confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmar Eliminación",
                                   "¿Estás seguro de eliminar este registro?",
                                   QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Set mode flags
        eliminarRegistro = true;
        crearRegistro = false;
        modificarRegistro = false;

        // Enable confirm button
        ui->pushButtonConfirmarRegistro->setEnabled(true);

        // Show message
        QMessageBox::information(this, "Eliminar Registro", "Presiona Confirmar para eliminar definitivamente");
    }
}

void MainWindow::on_pushButtonConfirmarRegistro_clicked() {
    // Branch based on mode flags
    if (crearRegistro) {
        // 1. Call validarInputsRegistros() - return if false
        if (!validarInputsRegistros()) return;

        // 2. Build new registro QMap from input widgets
        QMap<QString, QString> nuevoRegistro;

        for (const Campos &campo : vectorCampos) {
            QString nombre = campo.getnombreCampo();
            QString tipo = campo.gettipoDato();

            QWidget *widget = ui->frame_Registros->findChild<QWidget*>("input_" + nombre);

            QString valor;
            if (tipo == "String" || tipo == "Char") {
                QLineEdit *input = qobject_cast<QLineEdit*>(widget);
                if (input) valor = input->text();

            } else if (tipo == "Int") {
                QSpinBox *input = qobject_cast<QSpinBox*>(widget);
                if (input) valor = QString::number(input->value());

            } else if (tipo == "Float") {
                QDoubleSpinBox *input = qobject_cast<QDoubleSpinBox*>(widget);
                if (input) valor = QString::number(input->value());
            }

            nuevoRegistro[nombre] = valor;
        }

        // 3. Append to vectorRegistros
        vectorRegistros.append(nuevoRegistro);

        // 4. Call cargarRegistros() to refresh table
        cargarRegistros();

        // 5. Show success
        QMessageBox::information(this, "Éxito", "Registro creado correctamente");

        // 6. Hide input panel
        ui->frame_Registros->setVisible(false);

        // 7. Reset mode flags
        crearRegistro = false;
        modificarRegistro = false;
        eliminarRegistro = false;

    } else if (modificarRegistro) {
        // 1. Get current row index
        int row = ui->tableWidgetRegistros->currentRow();

        // 2. Call validarInputsRegistros() - return if false
        if (!validarInputsRegistros()) return;

        // 3. Build updated registro QMap from input widgets
        QMap<QString, QString> registroActualizado;

        for (const Campos &campo : vectorCampos) {
            QString nombre = campo.getnombreCampo();
            QString tipo = campo.gettipoDato();

            QWidget *widget = ui->frame_Registros->findChild<QWidget*>("input_" + nombre);

            QString valor;
            if (tipo == "String" || tipo == "Char") {
                QLineEdit *input = qobject_cast<QLineEdit*>(widget);
                if (input) valor = input->text();

            } else if (tipo == "Int") {
                QSpinBox *input = qobject_cast<QSpinBox*>(widget);
                if (input) valor = QString::number(input->value());

            } else if (tipo == "Float") {
                QDoubleSpinBox *input = qobject_cast<QDoubleSpinBox*>(widget);
                if (input) valor = QString::number(input->value());
            }

            registroActualizado[nombre] = valor;
        }

        // 4. Replace vectorRegistros[row] with updated map
        vectorRegistros[row] = registroActualizado;

        // 5. Call cargarRegistros() to refresh table
        cargarRegistros();

        // 6. Show success
        QMessageBox::information(this, "Éxito", "Registro modificado correctamente");

        // 7. Hide input panel
        ui->frame_Registros->setVisible(false);

        // 8. Reset mode flags
        crearRegistro = false;
        modificarRegistro = false;
        eliminarRegistro = false;

    } else if (eliminarRegistro) {
        // 1. Get current row index
        int row = ui->tableWidgetRegistros->currentRow();

        // 2. Remove from vector
        if (row >= 0 && row < vectorRegistros.size())
            vectorRegistros.removeAt(row);

        // 3. Call cargarRegistros() to refresh table
        cargarRegistros();

        // 4. Show success
        QMessageBox::information(this, "Éxito", "Registro eliminado correctamente");

        // 5. Reset mode flags
        crearRegistro = false;
        modificarRegistro = false;
        eliminarRegistro = false;
    }
}
