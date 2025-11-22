/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo_Archivo;
    QAction *actionAbrir_Archivo;
    QAction *actionGuardar_Archivo;
    QAction *actionCerrar_Archivo;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *menuIzquierdo;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_5;
    QPushButton *pb_Desplace;
    QFrame *SubmenuIzquierdo;
    QPushButton *pb_Campos;
    QPushButton *pb_Registros;
    QPushButton *pb_Indices;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *pg_Indices;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QWidget *pg_Registros;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QWidget *pg_Campos;
    QFrame *frame_3;
    QTableWidget *tableWidget;
    QFrame *frame_7;
    QGridLayout *gridLayout;
    QRadioButton *radioButtonLlavePrimaria;
    QComboBox *comboBoxTipoDato;
    QLineEdit *lineEditCampos;
    QRadioButton *radioButtonLlaveSecundaria;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_2;
    QSpinBox *spinBoxLongitud;
    QLabel *label_5;
    QFrame *frame_6;
    QPushButton *pushButtonCrearCampo;
    QPushButton *pushButtonModificarCampo;
    QPushButton *pushButtonBorrarCampo;
    QPushButton *pushButtonConfirmar;
    QMenuBar *menuBar;
    QMenu *menuArchivo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1090, 591);
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        MainWindow->setFont(font);
        actionNuevo_Archivo = new QAction(MainWindow);
        actionNuevo_Archivo->setObjectName("actionNuevo_Archivo");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        actionNuevo_Archivo->setIcon(icon);
        actionAbrir_Archivo = new QAction(MainWindow);
        actionAbrir_Archivo->setObjectName("actionAbrir_Archivo");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionAbrir_Archivo->setIcon(icon1);
        actionGuardar_Archivo = new QAction(MainWindow);
        actionGuardar_Archivo->setObjectName("actionGuardar_Archivo");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        actionGuardar_Archivo->setIcon(icon2);
        actionCerrar_Archivo = new QAction(MainWindow);
        actionCerrar_Archivo->setObjectName("actionCerrar_Archivo");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        actionCerrar_Archivo->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        menuIzquierdo = new QFrame(frame_2);
        menuIzquierdo->setObjectName("menuIzquierdo");
        menuIzquierdo->setMinimumSize(QSize(180, 0));
        menuIzquierdo->setMaximumSize(QSize(50, 16777215));
        menuIzquierdo->setFrameShape(QFrame::Shape::NoFrame);
        menuIzquierdo->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(menuIzquierdo);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(menuIzquierdo);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(16777215, 50));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #00A2E8;\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        pb_Desplace = new QPushButton(frame_5);
        pb_Desplace->setObjectName("pb_Desplace");
        pb_Desplace->setGeometry(QRect(0, 0, 180, 50));
        pb_Desplace->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pb_Desplace->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyCenter));
        pb_Desplace->setIcon(icon4);
        pb_Desplace->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(frame_5);

        SubmenuIzquierdo = new QFrame(menuIzquierdo);
        SubmenuIzquierdo->setObjectName("SubmenuIzquierdo");
        SubmenuIzquierdo->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #00A2E8;\n"
"}"));
        SubmenuIzquierdo->setFrameShape(QFrame::Shape::StyledPanel);
        SubmenuIzquierdo->setFrameShadow(QFrame::Shadow::Raised);
        pb_Campos = new QPushButton(SubmenuIzquierdo);
        pb_Campos->setObjectName("pb_Campos");
        pb_Campos->setGeometry(QRect(0, 110, 180, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(10);
        pb_Campos->setFont(font1);
        pb_Campos->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pb_Campos->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        pb_Campos->setIcon(icon5);
        pb_Campos->setIconSize(QSize(30, 30));
        pb_Campos->setCheckable(true);
        pb_Campos->setAutoExclusive(true);
        pb_Registros = new QPushButton(SubmenuIzquierdo);
        pb_Registros->setObjectName("pb_Registros");
        pb_Registros->setGeometry(QRect(0, 180, 180, 50));
        pb_Registros->setFont(font1);
        pb_Registros->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pb_Registros->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        pb_Registros->setIcon(icon6);
        pb_Registros->setIconSize(QSize(30, 30));
        pb_Registros->setCheckable(true);
        pb_Registros->setAutoExclusive(true);
        pb_Indices = new QPushButton(SubmenuIzquierdo);
        pb_Indices->setObjectName("pb_Indices");
        pb_Indices->setGeometry(QRect(0, 259, 180, 41));
        pb_Indices->setFont(font1);
        pb_Indices->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pb_Indices->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        pb_Indices->setIcon(icon7);
        pb_Indices->setIconSize(QSize(30, 30));
        pb_Indices->setCheckable(true);
        pb_Indices->setAutoExclusive(true);

        verticalLayout_2->addWidget(SubmenuIzquierdo);


        horizontalLayout_2->addWidget(menuIzquierdo);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName("frame_4");
        frame_4->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #FFFFFF;\n"
"}"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(frame_4);
        stackedWidget->setObjectName("stackedWidget");
        pg_Indices = new QWidget();
        pg_Indices->setObjectName("pg_Indices");
        verticalLayout_4 = new QVBoxLayout(pg_Indices);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(pg_Indices);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label);

        stackedWidget->addWidget(pg_Indices);
        pg_Registros = new QWidget();
        pg_Registros->setObjectName("pg_Registros");
        verticalLayout_6 = new QVBoxLayout(pg_Registros);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(pg_Registros);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_3);

        stackedWidget->addWidget(pg_Registros);
        pg_Campos = new QWidget();
        pg_Campos->setObjectName("pg_Campos");
        frame_3 = new QFrame(pg_Campos);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(9, 9, 731, 551));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        tableWidget = new QTableWidget(frame_3);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(1, 1, 721, 391));
        tableWidget->setMaximumSize(QSize(886, 536));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    border: none;\n"
"    gridline-color: #d0d0d0;\n"
"    font-size: 14px;\n"
"    color: #2f2f2f;\n"
"    selection-background-color: #009fe3;   /* azul corporativo */\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #009fe3;      /* azul */\n"
"    color: white;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #009fe3;\n"
"}\n"
"\n"
"QTableWidget QTableView {\n"
"    outline: 0; \n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 10px;\n"
"    background: #e0e0e0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #009fe3;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::add-line,\n"
"QScrollBar::sub-line {\n"
"    height: 0px;\n"
"}"));
        tableWidget->setFrameShape(QFrame::Shape::WinPanel);
        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(1, 405, 711, 151));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #00A2E8;\n"
"}"));
        frame_7->setFrameShape(QFrame::Shape::NoFrame);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame_7);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 14);
        radioButtonLlavePrimaria = new QRadioButton(frame_7);
        radioButtonLlavePrimaria->setObjectName("radioButtonLlavePrimaria");
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        QBrush brush1(QColor(31, 155, 93, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        radioButtonLlavePrimaria->setPalette(palette);
        radioButtonLlavePrimaria->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #003f5c;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color: #cfd9df;\n"
"    border: 2px solid #003f5c;\n"
"    border-radius: 6px;\n"
"}"));

        gridLayout->addWidget(radioButtonLlavePrimaria, 0, 3, 1, 1);

        comboBoxTipoDato = new QComboBox(frame_7);
        comboBoxTipoDato->addItem(QString());
        comboBoxTipoDato->addItem(QString());
        comboBoxTipoDato->addItem(QString());
        comboBoxTipoDato->addItem(QString());
        comboBoxTipoDato->setObjectName("comboBoxTipoDato");
        comboBoxTipoDato->setFont(font);
        comboBoxTipoDato->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background: #ffffff;\n"
"    border: 2px solid #0070A1;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"    color: #000000;           /* TEXTO NEGRO */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBoxTipoDato, 2, 1, 1, 1);

        lineEditCampos = new QLineEdit(frame_7);
        lineEditCampos->setObjectName("lineEditCampos");
        lineEditCampos->setFont(font);
        lineEditCampos->setStyleSheet(QString::fromUtf8("/* QLineEdit */\n"
"QLineEdit {\n"
"    background: #ffffff;\n"
"    border: 2px solid #0070A1;\n"
"    border-radius: 4px;\n"
"    padding: 4px 6px;\n"
"    color: #000000;           /* TEXTO NEGRO */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #ffffff;\n"
"    background: #ffffff;\n"
"}"));

        gridLayout->addWidget(lineEditCampos, 0, 1, 2, 1);

        radioButtonLlaveSecundaria = new QRadioButton(frame_7);
        radioButtonLlaveSecundaria->setObjectName("radioButtonLlaveSecundaria");
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        radioButtonLlaveSecundaria->setPalette(palette1);
        radioButtonLlaveSecundaria->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #003f5c;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color: #cfd9df;\n"
"    border: 2px solid #003f5c;\n"
"    border-radius: 6px;\n"
"}"));

        gridLayout->addWidget(radioButtonLlaveSecundaria, 1, 3, 3, 1);

        label_6 = new QLabel(frame_7);
        label_6->setObjectName("label_6");
        QPalette palette2;
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush3(QColor(0, 162, 232, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush3);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush3);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush3);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush3);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush3);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush3);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        label_6->setPalette(palette2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setItalic(true);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("/* Etiquetas */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_4 = new QLabel(frame_7);
        label_4->setObjectName("label_4");
        QPalette palette3;
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush3);
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush3);
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush3);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush3);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush3);
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush3);
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        label_4->setPalette(palette3);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("/* Etiquetas */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(frame_7);
        label_2->setObjectName("label_2");
        QPalette palette4;
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush3);
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush3);
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush3);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush3);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush3);
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush3);
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        label_2->setPalette(palette4);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("/* Etiquetas */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}"));

        gridLayout->addWidget(label_2, 0, 0, 2, 1);

        spinBoxLongitud = new QSpinBox(frame_7);
        spinBoxLongitud->setObjectName("spinBoxLongitud");
        spinBoxLongitud->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background: #ffffff;\n"
"    border: 2px solid #0070A1;\n"
"    border-radius: 4px;\n"
"    padding: 4px 6px;\n"
"    color: #000000;           /* TEXTO NEGRO */\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 2px solid #ffffff;\n"
"}"));

        gridLayout->addWidget(spinBoxLongitud, 3, 1, 1, 1);

        label_5 = new QLabel(frame_7);
        label_5->setObjectName("label_5");
        QPalette palette5;
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush3);
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush3);
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush3);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush3);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush3);
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush3);
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush2);
#endif
        label_5->setPalette(palette5);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("/* Etiquetas */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        frame_6 = new QFrame(pg_Campos);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(734, 9, 171, 551));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #00A2E8;\n"
"}"));
        frame_6->setFrameShape(QFrame::Shape::NoFrame);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        pushButtonCrearCampo = new QPushButton(frame_6);
        pushButtonCrearCampo->setObjectName("pushButtonCrearCampo");
        pushButtonCrearCampo->setGeometry(QRect(9, 83, 151, 36));
        pushButtonCrearCampo->setFont(font1);
        pushButtonCrearCampo->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonCrearCampo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        pushButtonCrearCampo->setIcon(icon8);
        pushButtonCrearCampo->setCheckable(true);
        pushButtonCrearCampo->setChecked(true);
        pushButtonCrearCampo->setAutoExclusive(true);
        pushButtonCrearCampo->setFlat(false);
        pushButtonModificarCampo = new QPushButton(frame_6);
        pushButtonModificarCampo->setObjectName("pushButtonModificarCampo");
        pushButtonModificarCampo->setGeometry(QRect(9, 199, 148, 36));
        pushButtonModificarCampo->setFont(font1);
        pushButtonModificarCampo->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonModificarCampo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        pushButtonModificarCampo->setIcon(icon5);
        pushButtonModificarCampo->setCheckable(true);
        pushButtonModificarCampo->setChecked(false);
        pushButtonModificarCampo->setAutoExclusive(true);
        pushButtonModificarCampo->setFlat(false);
        pushButtonBorrarCampo = new QPushButton(frame_6);
        pushButtonBorrarCampo->setObjectName("pushButtonBorrarCampo");
        pushButtonBorrarCampo->setGeometry(QRect(9, 315, 141, 36));
        pushButtonBorrarCampo->setFont(font1);
        pushButtonBorrarCampo->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonBorrarCampo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        pushButtonBorrarCampo->setIcon(icon9);
        pushButtonBorrarCampo->setCheckable(true);
        pushButtonBorrarCampo->setChecked(false);
        pushButtonBorrarCampo->setAutoExclusive(true);
        pushButtonBorrarCampo->setFlat(false);
        pushButtonConfirmar = new QPushButton(frame_6);
        pushButtonConfirmar->setObjectName("pushButtonConfirmar");
        pushButtonConfirmar->setGeometry(QRect(9, 431, 151, 36));
        pushButtonConfirmar->setFont(font1);
        pushButtonConfirmar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonConfirmar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    padding: 10px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"/* Hover */\n"
"QPushButton:hover:enabled {\n"
"    background: #0070A1;\n"
"}\n"
"\n"
"/* Estado deshabilitado \342\200\224 elegante */\n"
"QPushButton:disabled {\n"
"    background:  #00A2E8;   /* un brillo leve */\n"
"    color: rgba(255, 255, 255, 120);         /* texto blanco apagado */\n"
"    border: none;\n"
"}"));
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::AppointmentNew));
        pushButtonConfirmar->setIcon(icon10);
        pushButtonConfirmar->setCheckable(true);
        pushButtonConfirmar->setAutoExclusive(true);
        pushButtonConfirmar->setFlat(false);
        stackedWidget->addWidget(pg_Campos);

        verticalLayout_3->addWidget(stackedWidget);


        horizontalLayout_2->addWidget(frame_4);


        verticalLayout->addWidget(frame_2);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1090, 16));
        menuBar->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Verdana")});
        font3.setPointSize(7);
        menuBar->setFont(font3);
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName("menuArchivo");
        menuArchivo->setGeometry(QRect(345, 102, 164, 146));
        menuArchivo->setFont(font1);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionNuevo_Archivo);
        menuArchivo->addAction(actionAbrir_Archivo);
        menuArchivo->addAction(actionGuardar_Archivo);
        menuArchivo->addAction(actionCerrar_Archivo);
        menuArchivo->addSeparator();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNuevo_Archivo->setText(QCoreApplication::translate("MainWindow", "Nuevo Archivo", nullptr));
        actionAbrir_Archivo->setText(QCoreApplication::translate("MainWindow", "Abrir Archivo", nullptr));
        actionGuardar_Archivo->setText(QCoreApplication::translate("MainWindow", "Guardar Archivo", nullptr));
        actionCerrar_Archivo->setText(QCoreApplication::translate("MainWindow", "Cerrar Archivo", nullptr));
        pb_Desplace->setText(QString());
        pb_Campos->setText(QCoreApplication::translate("MainWindow", "Campos", nullptr));
        pb_Registros->setText(QCoreApplication::translate("MainWindow", "Registros", nullptr));
        pb_Indices->setText(QCoreApplication::translate("MainWindow", "Indices", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Indices segundo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Registros", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Campo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Tipo de Dato", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Longitud Estimada", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Tipo de Llave", nullptr));
        radioButtonLlavePrimaria->setText(QCoreApplication::translate("MainWindow", "Llave Primaria", nullptr));
        comboBoxTipoDato->setItemText(0, QCoreApplication::translate("MainWindow", "String", nullptr));
        comboBoxTipoDato->setItemText(1, QCoreApplication::translate("MainWindow", "Int", nullptr));
        comboBoxTipoDato->setItemText(2, QCoreApplication::translate("MainWindow", "Char", nullptr));
        comboBoxTipoDato->setItemText(3, QCoreApplication::translate("MainWindow", "Float", nullptr));

        radioButtonLlaveSecundaria->setText(QCoreApplication::translate("MainWindow", "Llave Secundaria", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Tipo de Llave:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tipo de Dato:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Campo:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Longitud:", nullptr));
        pushButtonCrearCampo->setText(QCoreApplication::translate("MainWindow", "Crear Campo", nullptr));
        pushButtonModificarCampo->setText(QCoreApplication::translate("MainWindow", "Modificar Campo", nullptr));
        pushButtonBorrarCampo->setText(QCoreApplication::translate("MainWindow", "Borrar Campo", nullptr));
        pushButtonConfirmar->setText(QCoreApplication::translate("MainWindow", "Confirmar", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
