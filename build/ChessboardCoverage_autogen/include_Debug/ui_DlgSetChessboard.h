/********************************************************************************
** Form generated from reading UI file 'DlgSetChessboard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSETCHESSBOARD_H
#define UI_DLGSETCHESSBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DlgSetChessboardClass
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSpinBox *sBox_size;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *sBox_x;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *sBox_y;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbtn_ok;
    QPushButton *pbtn_cancel;

    void setupUi(QDialog *DlgSetChessboardClass)
    {
        if (DlgSetChessboardClass->objectName().isEmpty())
            DlgSetChessboardClass->setObjectName("DlgSetChessboardClass");
        DlgSetChessboardClass->resize(638, 163);
        gridLayout_3 = new QGridLayout(DlgSetChessboardClass);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBox = new QGroupBox(DlgSetChessboardClass);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        sBox_size = new QSpinBox(groupBox);
        sBox_size->setObjectName("sBox_size");
        sBox_size->setValue(2);

        horizontalLayout_6->addWidget(sBox_size);

        horizontalLayout_6->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(DlgSetChessboardClass);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        sBox_x = new QSpinBox(groupBox_2);
        sBox_x->setObjectName("sBox_x");
        sBox_x->setValue(1);

        horizontalLayout_3->addWidget(sBox_x);

        horizontalLayout_3->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        sBox_y = new QSpinBox(groupBox_2);
        sBox_y->setObjectName("sBox_y");

        horizontalLayout_4->addWidget(sBox_y);

        horizontalLayout_4->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pbtn_ok = new QPushButton(DlgSetChessboardClass);
        pbtn_ok->setObjectName("pbtn_ok");

        horizontalLayout_5->addWidget(pbtn_ok);

        pbtn_cancel = new QPushButton(DlgSetChessboardClass);
        pbtn_cancel->setObjectName("pbtn_cancel");

        horizontalLayout_5->addWidget(pbtn_cancel);


        gridLayout_3->addLayout(horizontalLayout_5, 1, 0, 1, 2);


        retranslateUi(DlgSetChessboardClass);

        QMetaObject::connectSlotsByName(DlgSetChessboardClass);
    } // setupUi

    void retranslateUi(QDialog *DlgSetChessboardClass)
    {
        DlgSetChessboardClass->setWindowTitle(QCoreApplication::translate("DlgSetChessboardClass", "DlgSetChessboard", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgSetChessboardClass", "\346\243\213\347\233\230\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("DlgSetChessboardClass", "\345\244\247\345\260\217\345\233\240\345\255\220\357\274\210\346\214\207\346\225\260k\357\274\211:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DlgSetChessboardClass", "\347\211\271\346\256\212\345\235\227\344\275\215\347\275\256\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("DlgSetChessboardClass", "x\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("DlgSetChessboardClass", "y\357\274\232", nullptr));
        pbtn_ok->setText(QCoreApplication::translate("DlgSetChessboardClass", "\347\241\256\345\256\232", nullptr));
        pbtn_cancel->setText(QCoreApplication::translate("DlgSetChessboardClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSetChessboardClass: public Ui_DlgSetChessboardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSETCHESSBOARD_H
