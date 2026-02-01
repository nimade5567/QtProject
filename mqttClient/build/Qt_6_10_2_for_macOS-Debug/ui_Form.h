/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *lineEditIp;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEditClientId;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditTopic;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *lineEditPassword;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonLink;
    QPushButton *pushButtonQuitLink;
    QPushButton *pushButtonExit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(548, 325);
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 40, 421, 241));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label);

        lineEditIp = new QLineEdit(widget);
        lineEditIp->setObjectName("lineEditIp");

        horizontalLayout_6->addWidget(lineEditIp);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_2);

        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName("lineEditPort");

        horizontalLayout_5->addWidget(lineEditPort);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        lineEditClientId = new QLineEdit(widget);
        lineEditClientId->setObjectName("lineEditClientId");

        horizontalLayout_4->addWidget(lineEditClientId);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        lineEditTopic = new QLineEdit(widget);
        lineEditTopic->setObjectName("lineEditTopic");

        horizontalLayout_3->addWidget(lineEditTopic);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        lineEditUsername = new QLineEdit(widget);
        lineEditUsername->setObjectName("lineEditUsername");

        horizontalLayout_2->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_6);

        lineEditPassword = new QLineEdit(widget);
        lineEditPassword->setObjectName("lineEditPassword");

        horizontalLayout->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButtonLink = new QPushButton(widget);
        pushButtonLink->setObjectName("pushButtonLink");

        verticalLayout_2->addWidget(pushButtonLink);

        pushButtonQuitLink = new QPushButton(widget);
        pushButtonQuitLink->setObjectName("pushButtonQuitLink");

        verticalLayout_2->addWidget(pushButtonQuitLink);

        pushButtonExit = new QPushButton(widget);
        pushButtonExit->setObjectName("pushButtonExit");

        verticalLayout_2->addWidget(pushButtonExit);


        horizontalLayout_7->addLayout(verticalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "IP              ", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Port          ", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "clientId     ", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Topic        ", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "username", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "password", nullptr));
        pushButtonLink->setText(QCoreApplication::translate("Form", "\350\277\236\346\216\245", nullptr));
        pushButtonQuitLink->setText(QCoreApplication::translate("Form", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("Form", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
