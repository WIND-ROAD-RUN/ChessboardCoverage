#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChessboardCoverage.h"
#include "CoverageOperator.h"
#include"PaintOperator.h"

enum ChessboardColor{
    WHITE=0,
    BLACK=1,
    RED=2,
    GREEN=3,
    YELLOW=4
};

QT_BEGIN_NAMESPACE
namespace Ui { class ChessboardCoverageClass; };
QT_END_NAMESPACE

class ChessboardCoverage final : public QMainWindow 
{
    Q_OBJECT
public:
    ChessboardCoverage(const ChessboardCoverage & c) = delete;

    ChessboardCoverage(const ChessboardCoverage&& c) = delete;

    ChessboardCoverage& operator=(ChessboardCoverage& c) = delete;

    ChessboardCoverage & operator=(ChessboardCoverage &&c)=delete;

public:
    explicit ChessboardCoverage(QWidget* parent = nullptr);

    ~ChessboardCoverage() override;

private:
    qint32 m_specialBlock_x{0};

    qint32 m_specialBlock_y{ 0 };

    CoverageOperator::ChessboardHistoryTableIndex m_index{ 0 };

    CoverageOperator::ChessboardHistoryTableIndex m_indexMaxsize{ 0 };

private:
    CoverageOperator* m_coverageOperator{nullptr};
    PaintItemList m_paintItemList{};
private:
    QVector<QColor> m_color

    { QColor(Qt::red),QColor(Qt::blue),
        QColor(Qt::yellow), QColor(Qt::green),
        QColor(Qt::cyan), QColor(Qt::magenta),
        QColor(Qt::gray), QColor(Qt::darkGray) ,
        QColor(Qt::lightGray),QColor(Qt::transparent)};

private:
    void build_ui();

    void build_connect();

    QColor getColor(int value) const;
    QColor getColor(ChessboardColor color) const;

private:
    void drawChessboard(qint32 row,qint32 column) const;

    void paintFromItem(qint32 row, qint32 column, const QBrush& color) const;
    void paintChessboardItem(const PaintItem& paintItem);
    void paintChessboardItem(const PaintItem& paintItem, ChessboardColor color);

private:
    Ui::ChessboardCoverageClass *ui;

private:
    void check_index() const;

    void ini_chessboard();

    void CoverageOperateLoad();

private slots:
    void pbtn_resetChessboard_clicked();

    void pbtn_skipToInitial_clicked();

    void pbtn_skipToFinal_clicked();

    void pbtn_lastStep_clicked();

    void pbtn_nextStep_clicked();

    void pbtn_autoDisplay_clicked();
};

