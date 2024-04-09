#include "ChessboardCoverage.h"
#include"DlgSetChessboard.h"

ChessboardCoverage::ChessboardCoverage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessboardCoverageClass())
{
    ui->setupUi(this);
    build_ui();
    build_connect();
}

ChessboardCoverage::~ChessboardCoverage()
{
    delete ui;
}

void ChessboardCoverage::build_ui()
{
    this->setWindowTitle("棋盘覆盖演示");
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    drawChessboard(5, 5);
    paintChessboardItem(0,0,Qt::black);
}

void ChessboardCoverage::build_connect()
{
    QObject::connect(ui->pbtn_resetChessboard,&QPushButton::clicked,
        this,&ChessboardCoverage::pbtn_resetChessboard_clicked);
}

void ChessboardCoverage::drawChessboard(qint32 row, qint32 column)
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);
    for (int i = 0;i<row;i++) {
        for (int j = 0; j < column; j++) {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem());
        }
    }
}

void ChessboardCoverage::paintChessboardItem(qint32 row, qint32 column, QBrush color)
{
    ui->tableWidget->item(row, column)->setBackground(color);
}

void ChessboardCoverage::pbtn_resetChessboard_clicked() {
    auto dlg = new DlgSetChessboard();
    auto result=dlg->exec();
    if (result==QDialog::Accepted) {
        drawChessboard(dlg->getRow(),dlg->getColumn());
        m_specialBlock_X = dlg->getX();
        m_specialBlock_Y = dlg->getY();
        paintChessboardItem(m_specialBlock_X, m_specialBlock_Y,Qt::black);
    }

    delete dlg;
}
