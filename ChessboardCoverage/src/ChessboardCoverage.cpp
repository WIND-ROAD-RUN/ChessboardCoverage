#include "ChessboardCoverage.h"
#include"DlgSetChessboard.h"
#include<QMessageBox>

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

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    pbtn_resetChessboard_clicked();
}

void ChessboardCoverage::build_connect()
{
    QObject::connect(ui->pbtn_resetChessboard, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_resetChessboard_clicked);
    QObject::connect(ui->pbtn_CoverageOperate, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_CoverageOperate_clicked);

    QObject::connect(ui->pbtn_lastStep, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_lastStep_clicked);
    QObject::connect(ui->pbtn_nextStep, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_nextStep_clicked);

    QObject::connect(ui->pbtn_skipToFinal, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_skipToFinal_clicked);
    QObject::connect(ui->pbtn_skipToInitial, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_skipToInitial_clicked);
}

QColor ChessboardCoverage::getColor(const int value) const
{
    if (value == 0) {
        return QColor{Qt::black};
    }
    if(value==-1)
    {
        return QColor{ Qt::white };
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

void ChessboardCoverage::check_index() const
{
    if(m_index==0)
    {
        ui->pbtn_nextStep->setEnabled(true);
        ui->pbtn_lastStep->setEnabled(false);
    }
    else if(m_index==m_indexMaxsize)
    {
        ui->pbtn_nextStep->setEnabled(false);
        ui->pbtn_lastStep->setEnabled(true);
    }
}

void ChessboardCoverage::pbtn_CoverageOperate_clicked()
{
    m_coverageOperator->setNum(0);
    m_coverageOperator->run();

    QMessageBox::information(this,QString("加载"), QString("加载成功"));

    ui->pbtn_skipToInitial->setEnabled(true);
    ui->pbtn_skipToFinal->setEnabled(true);

    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    m_indexMaxsize = table.size() - 1;

    check_index();
    
}

void ChessboardCoverage::pbtn_skipToInitial_clicked()
{
    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    m_index = 0;

    paintChessboard(table.at(m_index));

    check_index();
}

void ChessboardCoverage::pbtn_skipToFinal_clicked()
{
    const auto & table= m_coverageOperator->getChessboardHistoryTable();

    m_index = table.size()-1;


    paintChessboard(table.at(m_index));

    check_index();

}

void ChessboardCoverage::pbtn_lastStep_clicked()
{
    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    --m_index ;

    paintChessboard(table.at(m_index));

    check_index();
}

void ChessboardCoverage::pbtn_nextStep_clicked()
{
    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    ++m_index;

    paintChessboard(table.at(m_index));

    check_index();
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
                line.push_back(-1);
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

    ui->pbtn_nextStep->setEnabled(false);
    ui->pbtn_lastStep->setEnabled(false);
    ui->pbtn_skipToInitial->setEnabled(false);
    ui->pbtn_skipToFinal->setEnabled(false);

    m_index = 0;
}
