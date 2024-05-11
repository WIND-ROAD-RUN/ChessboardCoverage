/********************************************************************************
** Form generated from reading UI file 'ChessboardCoverage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSBOARDCOVERAGE_H
#define UI_CHESSBOARDCOVERAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessboardCoverageClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *gBox_chessBoard;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QGroupBox *gBox_chessBoardSet;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QSpinBox *sBox_sizeK;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *sBox_x;
    QLabel *label_4;
    QSpinBox *sBox_y;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbtn_resetChessboard;
    QPushButton *pbtn_CoverageOperate;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *gBox_display;
    QGridLayout *gridLayout_3;
    QPushButton *pbtn_autoDisplay;
    QPushButton *pbtn_nextStep;
    QPushButton *pbtn_skipToInitial;
    QPushButton *pbtn_lastStep;
    QPushButton *pbtn_skipToFinal;
    QLabel *label_loadInfo;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *ChessboardCoverageClass)
    {
        if (ChessboardCoverageClass->objectName().isEmpty())
            ChessboardCoverageClass->setObjectName("ChessboardCoverageClass");
        ChessboardCoverageClass->resize(1186, 963);
        centralWidget = new QWidget(ChessboardCoverageClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        gBox_chessBoard = new QGroupBox(centralWidget);
        gBox_chessBoard->setObjectName("gBox_chessBoard");
        gridLayout_2 = new QGridLayout(gBox_chessBoard);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        tableWidget = new QTableWidget(gBox_chessBoard);
        tableWidget->setObjectName("tableWidget");

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(gBox_chessBoard);

        gBox_chessBoardSet = new QGroupBox(centralWidget);
        gBox_chessBoardSet->setObjectName("gBox_chessBoardSet");
        gridLayout = new QGridLayout(gBox_chessBoardSet);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(gBox_chessBoardSet);
        groupBox->setObjectName("groupBox");
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        sBox_sizeK = new QSpinBox(groupBox);
        sBox_sizeK->setObjectName("sBox_sizeK");

        gridLayout_4->addWidget(sBox_sizeK, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        sBox_x = new QSpinBox(groupBox);
        sBox_x->setObjectName("sBox_x");

        gridLayout_4->addWidget(sBox_x, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        sBox_y = new QSpinBox(groupBox);
        sBox_y->setObjectName("sBox_y");

        gridLayout_4->addWidget(sBox_y, 3, 1, 1, 1);

        gridLayout_4->setColumnStretch(1, 1);

        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        pbtn_resetChessboard = new QPushButton(gBox_chessBoardSet);
        pbtn_resetChessboard->setObjectName("pbtn_resetChessboard");

        horizontalLayout->addWidget(pbtn_resetChessboard);

        pbtn_CoverageOperate = new QPushButton(gBox_chessBoardSet);
        pbtn_CoverageOperate->setObjectName("pbtn_CoverageOperate");

        horizontalLayout->addWidget(pbtn_CoverageOperate);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        verticalLayout->addLayout(horizontalLayout_2);

        gBox_display = new QGroupBox(gBox_chessBoardSet);
        gBox_display->setObjectName("gBox_display");
        gridLayout_3 = new QGridLayout(gBox_display);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        pbtn_autoDisplay = new QPushButton(gBox_display);
        pbtn_autoDisplay->setObjectName("pbtn_autoDisplay");

        gridLayout_3->addWidget(pbtn_autoDisplay, 3, 0, 1, 2);

        pbtn_nextStep = new QPushButton(gBox_display);
        pbtn_nextStep->setObjectName("pbtn_nextStep");

        gridLayout_3->addWidget(pbtn_nextStep, 1, 1, 1, 1);

        pbtn_skipToInitial = new QPushButton(gBox_display);
        pbtn_skipToInitial->setObjectName("pbtn_skipToInitial");

        gridLayout_3->addWidget(pbtn_skipToInitial, 2, 0, 1, 1);

        pbtn_lastStep = new QPushButton(gBox_display);
        pbtn_lastStep->setObjectName("pbtn_lastStep");

        gridLayout_3->addWidget(pbtn_lastStep, 1, 0, 1, 1);

        pbtn_skipToFinal = new QPushButton(gBox_display);
        pbtn_skipToFinal->setObjectName("pbtn_skipToFinal");

        gridLayout_3->addWidget(pbtn_skipToFinal, 2, 1, 1, 1);

        label_loadInfo = new QLabel(gBox_display);
        label_loadInfo->setObjectName("label_loadInfo");

        gridLayout_3->addWidget(label_loadInfo, 0, 0, 1, 2);


        verticalLayout->addWidget(gBox_display);

        verticalSpacer = new QSpacerItem(20, 308, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(gBox_chessBoardSet);

        horizontalLayout_3->setStretch(0, 1);
        ChessboardCoverageClass->setCentralWidget(centralWidget);

        retranslateUi(ChessboardCoverageClass);

        QMetaObject::connectSlotsByName(ChessboardCoverageClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChessboardCoverageClass)
    {
        ChessboardCoverageClass->setWindowTitle(QCoreApplication::translate("ChessboardCoverageClass", "ChessboardCoverage", nullptr));
        gBox_chessBoard->setTitle(QCoreApplication::translate("ChessboardCoverageClass", "\346\243\213\347\233\230", nullptr));
        gBox_chessBoardSet->setTitle(QCoreApplication::translate("ChessboardCoverageClass", "\346\243\213\347\233\230\347\233\270\345\205\263\346\223\215\344\275\234", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ChessboardCoverageClass", "\346\243\213\347\233\230\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("ChessboardCoverageClass", "\345\244\247\345\260\217\345\233\240\345\255\220\357\274\210\346\214\207\346\225\260k\357\274\211\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ChessboardCoverageClass", "x:", nullptr));
        label_2->setText(QCoreApplication::translate("ChessboardCoverageClass", "\347\211\271\346\256\212\345\235\227\344\275\215\347\275\256\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ChessboardCoverageClass", "y:", nullptr));
        pbtn_resetChessboard->setText(QCoreApplication::translate("ChessboardCoverageClass", "\351\207\215\350\256\276\346\243\213\347\233\230", nullptr));
        pbtn_CoverageOperate->setText(QCoreApplication::translate("ChessboardCoverageClass", "\350\246\206\347\233\226\345\212\240\350\275\275", nullptr));
        gBox_display->setTitle(QCoreApplication::translate("ChessboardCoverageClass", "\345\261\225\347\244\272", nullptr));
        pbtn_autoDisplay->setText(QCoreApplication::translate("ChessboardCoverageClass", "\350\207\252\345\212\250\345\261\225\347\244\272\350\246\206\347\233\226\350\277\207\347\250\213", nullptr));
        pbtn_nextStep->setText(QCoreApplication::translate("ChessboardCoverageClass", "\344\270\213\344\270\200\346\255\245", nullptr));
        pbtn_skipToInitial->setText(QCoreApplication::translate("ChessboardCoverageClass", "\345\233\236\345\210\260\345\210\235\345\247\213\347\212\266\346\200\201", nullptr));
        pbtn_lastStep->setText(QCoreApplication::translate("ChessboardCoverageClass", "\344\270\212\344\270\200\346\255\245", nullptr));
        pbtn_skipToFinal->setText(QCoreApplication::translate("ChessboardCoverageClass", "\350\267\263\345\210\260\347\273\210\346\255\242\347\212\266\346\200\201", nullptr));
        label_loadInfo->setText(QCoreApplication::translate("ChessboardCoverageClass", "\350\277\230\346\234\252\345\212\240\350\275\275\357\274\214\345\212\240\350\275\275\345\220\216\345\217\257\344\273\245\346\223\215\344\275\234\357\274\201\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessboardCoverageClass: public Ui_ChessboardCoverageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSBOARDCOVERAGE_H
