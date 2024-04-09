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
    delete m_coverageOperator;
    delete ui;
}

void ChessboardCoverage::build_ui()
{
    m_coverageOperator = new CoverageOperator;

    this->setWindowTitle("棋盘覆盖演示");
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    pbtn_resetChessboard_clicked();
}

void ChessboardCoverage::build_connect()
{
    QObject::connect(ui->pbtn_resetChessboard,&QPushButton::clicked,
        this,&ChessboardCoverage::pbtn_resetChessboard_clicked);
    QObject::connect(ui->pbtn_CoverageOperate, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_pbtn_CoverageOperate_clicked);
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

void ChessboardCoverage::paintChessboard(const Chessboard& chessboard)
{
    for (int i = 0;i<chessboard.size();i++) {
        for (int j = 0;j<chessboard[i].size();j++) {
            paintChessboardItem(i,j,QColor(chessboard[i][j]));
        }
    }

}

void ChessboardCoverage::pbtn_pbtn_CoverageOperate_clicked()
{
    m_coverageOperator->run();
    auto result = m_coverageOperator->getChessboard();

    paintChessboard(result);
}

void ChessboardCoverage::pbtn_resetChessboard_clicked() {
    auto dlg = new DlgSetChessboard();
    auto result=dlg->exec();

    if (result==QDialog::Accepted) {
        auto chessboardRow = dlg->getRow();
        auto chessboardColumn = dlg->getColumn();

        drawChessboard(chessboardRow,chessboardColumn);
        m_specialBlock_X = dlg->getX();
        m_specialBlock_Y = dlg->getY();
        paintChessboardItem(m_specialBlock_X, m_specialBlock_Y,Qt::black);

        Chessboard chessboard;
        for (int i = 0; i < chessboardRow; i++) {
            std::vector<int> line;
            for (int j = 0;j<chessboardColumn;j++) {
                line.push_back(0);
            }
            chessboard.push_back(line);
        }
        chessboard[m_specialBlock_X][m_specialBlock_Y] = -1;
        m_coverageOperator->setChessboard(chessboard);

    }

    delete dlg;
}
