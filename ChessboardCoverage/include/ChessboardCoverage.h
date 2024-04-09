#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChessboardCoverage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChessboardCoverageClass; };
QT_END_NAMESPACE

class ChessboardCoverage : public QMainWindow
{
    Q_OBJECT

public:
    ChessboardCoverage(QWidget *parent = nullptr);
    ~ChessboardCoverage();
private:
    void build_ui();
    void build_connect();
private:
    Ui::ChessboardCoverageClass *ui;
};
