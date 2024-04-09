#include "ChessboardCoverage.h"

ChessboardCoverage::ChessboardCoverage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessboardCoverageClass())
{
    ui->setupUi(this);
    build_ui();
}

ChessboardCoverage::~ChessboardCoverage()
{
    delete ui;
}

void ChessboardCoverage::build_ui()
{
    this->setWindowTitle("棋盘覆盖演示");
}
