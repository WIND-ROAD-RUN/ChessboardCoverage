#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChessboardCoverage.h"
#include "CoverageOperator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChessboardCoverageClass; };
QT_END_NAMESPACE

class ChessboardCoverage : public QMainWindow
{
    Q_OBJECT
private:
    qint32 m_specialBlock_X{0};

    qint32 m_specialBlock_Y{ 0 };
private:
    CoverageOperator* m_coverageOperator{nullptr};
private:
    QVector<QColor> m_color
    {QColor(Qt::red),QColor(Qt::blue), QColor(Qt::yellow), QColor(Qt::green), QColor(Qt::cyan), QColor(Qt::magenta), QColor(Qt::gray), QColor(Qt::darkGray) , QColor(Qt::lightGray),QColor(Qt::transparent) };

public:
    ChessboardCoverage(QWidget *parent = nullptr);

    ~ChessboardCoverage();

private:
    void build_ui();

    void build_connect();

    QColor getColor(int value);

private:
    void drawChessboard(qint32 row,qint32 column);

    void paintChessboardItem(qint32 row, qint32 column, QBrush color);

    void paintChessboard(const Chessboard &  chessboard);

private:
    Ui::ChessboardCoverageClass *ui;

private slots:
    void pbtn_resetChessboard_clicked();

    void pbtn_CoverageOperate_clicked();

};
