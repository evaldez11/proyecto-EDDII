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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuArchivo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
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
        pb_Indices = new QPushButton(SubmenuIzquierdo);
        pb_Indices->setObjectName("pb_Indices");
        pb_Indices->setGeometry(QRect(0, 250, 180, 50));
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

        verticalLayout_2->addWidget(SubmenuIzquierdo);


        horizontalLayout_2->addWidget(menuIzquierdo);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
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
        verticalLayout_5 = new QVBoxLayout(pg_Campos);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(pg_Campos);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_2);

        stackedWidget->addWidget(pg_Campos);

        verticalLayout_3->addWidget(stackedWidget);


        horizontalLayout_2->addWidget(frame_4);


        verticalLayout->addWidget(frame_2);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 16));
        menuBar->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(7);
        menuBar->setFont(font2);
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName("menuArchivo");
        menuArchivo->setGeometry(QRect(356, 106, 110, 110));
        QFont font3;
        font3.setPointSize(10);
        menuArchivo->setFont(font3);
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Campos", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
