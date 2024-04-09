#include "ChessboardCoverage.h"
#include"DlgSetChessboard.h"

ChessboardCoverage::ChessboardCoverage(QWidget* parent)
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

    this->setWindowTitle(QString("棋盘覆盖演示"));
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(50);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    pbtn_resetChessboard_clicked();
}

void ChessboardCoverage::build_connect()
{
    QObject::connect(ui->pbtn_resetChessboard, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_resetChessboard_clicked);
    QObject::connect(ui->pbtn_CoverageOperate, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_CoverageOperate_clicked);
}

QColor ChessboardCoverage::getColor(const int value) const
{
    if (value == 0) {
        return QColor{Qt::black};
    }
    return m_color.at(value % m_color.size());
}

void ChessboardCoverage::drawChessboard(const qint32 row, const qint32 column) const
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            ui->tableWidget->setItem(i, j, new QTableWidgetItem());
        }
    }
}

void ChessboardCoverage::paintChessboardItem(const qint32 row, const qint32 column, const QBrush& color) const
{
    ui->tableWidget->item(row, column)->setBackground(color);
}

void ChessboardCoverage::paintChessboard(const Chessboard& chessboard) const
{
    for (int i = 0; i < chessboard.size(); i++) {
        for (int j = 0; j < chessboard[i].size(); j++) {
            paintChessboardItem(i, j, getColor(chessboard[i][j]));
            ui->tableWidget->item(i, j)->setText(QString::number(chessboard[i][j]));
        }
    }

}

void ChessboardCoverage::pbtn_CoverageOperate_clicked()
{
    m_coverageOperator->setNum(0);
    m_coverageOperator->run();
    const auto result = m_coverageOperator->getChessboard();

    paintChessboard(result);
}

void ChessboardCoverage::pbtn_resetChessboard_clicked() {
    const auto dlg = new DlgSetChessboard();

    if (const auto result = dlg->exec();
        result == QDialog::Accepted) {
        const auto size = dlg->getSize();

        const auto row = pow(2, size);

        drawChessboard(row, row);
        m_specialBlock_x = dlg->getX();
        m_specialBlock_y = dlg->getY();
        paintChessboardItem(m_specialBlock_x, m_specialBlock_y, Qt::black);

        Chessboard chessboard;
        for (int i = 0; i < row; i++) {
            std::vector<int> line;
            line.reserve(static_cast<std::vector<int>::size_type>(row));
            for (int j = 0; j < row; j++) {
                line.push_back(0);
            }
            chessboard.push_back(line);
        }

        chessboard[m_specialBlock_x][m_specialBlock_y] = 0;

        m_coverageOperator->setChessboard(chessboard);
        m_coverageOperator->setX(m_specialBlock_x);
        m_coverageOperator->setY(m_specialBlock_y);
        m_coverageOperator->setSize(row);
    }

    delete dlg;
}
