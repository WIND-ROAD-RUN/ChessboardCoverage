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

public:
    ChessboardCoverage(QWidget *parent = nullptr);

    ~ChessboardCoverage();

private:
    void build_ui();

    void build_connect();

private:
    void drawChessboard(qint32 row,qint32 column);

    void paintChessboardItem(qint32 row, qint32 column, QBrush color);

    void paintChessboard(const Chessboard &  chessboard);

private:
    Ui::ChessboardCoverageClass *ui;

private slots:
    void pbtn_resetChessboard_clicked();

    void pbtn_pbtn_CoverageOperate_clicked();

};
