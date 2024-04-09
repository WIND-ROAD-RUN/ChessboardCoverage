#include "ChessboardCoverage.h"

ChessboardCoverage::ChessboardCoverage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessboardCoverageClass())
{
    ui->setupUi(this);
}

ChessboardCoverage::~ChessboardCoverage()
{
    delete ui;
}
