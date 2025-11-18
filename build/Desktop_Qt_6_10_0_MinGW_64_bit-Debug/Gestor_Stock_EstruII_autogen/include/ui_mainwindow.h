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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_5;
    QPushButton *pushButton;
    QFrame *frame_6;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        MainWindow->setFont(font);
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
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(180, 0));
        frame_3->setMaximumSize(QSize(50, 16777215));
        frame_3->setFrameShape(QFrame::Shape::NoFrame);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(16777215, 50));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #00A2E8;\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(frame_5);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 180, 50));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: transparent;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;\n"
"text-align: left;\n"
"}\n"
"QPushButton:Hover{\n"
"background: #0070A1;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyCenter));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(frame_5);

        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName("frame_6");
        frame_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background: #00A2E8;\n"
"}"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        pb_Campos = new QPushButton(frame_6);
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
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        pb_Campos->setIcon(icon1);
        pb_Campos->setIconSize(QSize(30, 30));
        pb_Registros = new QPushButton(frame_6);
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
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        pb_Registros->setIcon(icon2);
        pb_Registros->setIconSize(QSize(30, 30));
        pb_Indices = new QPushButton(frame_6);
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        pb_Indices->setIcon(icon3);
        pb_Indices->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(frame_6);


        horizontalLayout_2->addWidget(frame_3);

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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
        pb_Campos->setText(QCoreApplication::translate("MainWindow", "Campos", nullptr));
        pb_Registros->setText(QCoreApplication::translate("MainWindow", "Registros", nullptr));
        pb_Indices->setText(QCoreApplication::translate("MainWindow", "Indices", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Indices", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Registros", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Campos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
