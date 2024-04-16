#include "ChessboardCoverage.h"
#include"DlgSetChessboard.h"
#include<QMessageBox>
#include<QThread>

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

    ini_chessboard();
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

    QObject::connect(ui->pbtn_autoDisplay, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_autoDisplay_clicked);
}

QColor ChessboardCoverage::getColor(const int value) const
{
    if (value == 0) {
        return QColor{ Qt::black };
    }
    if (value == -1)
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
    if (m_index == 0)
    {
        ui->pbtn_nextStep->setEnabled(true);
        ui->pbtn_lastStep->setEnabled(false);
    }
    else if (m_index == m_indexMaxsize)
    {
        ui->pbtn_nextStep->setEnabled(false);
        ui->pbtn_lastStep->setEnabled(true);
    }
    else
    {
        ui->pbtn_nextStep->setEnabled(true);
        ui->pbtn_lastStep->setEnabled(true);
    }
}

void ChessboardCoverage::ini_chessboard()
{
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

        ui->pbtn_nextStep->setEnabled(false);
        ui->pbtn_lastStep->setEnabled(false);
        ui->pbtn_skipToInitial->setEnabled(false);
        ui->pbtn_skipToFinal->setEnabled(false);
        ui->pbtn_autoDisplay->setEnabled(false);
        ui->pbtn_CoverageOperate->setEnabled(true);

        m_index = 0;
    }

    delete dlg;
}

void ChessboardCoverage::pbtn_CoverageOperate_clicked()
{
    m_coverageOperator->setNum(0);
    m_coverageOperator->run();

    QMessageBox::information(this, QString("加载"), QString("加载成功"));

    ui->pbtn_skipToInitial->setEnabled(true);
    ui->pbtn_skipToFinal->setEnabled(true);
    ui->pbtn_autoDisplay->setEnabled(true);

    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    m_indexMaxsize = table.size() - 1;

    check_index();

    ui->pbtn_CoverageOperate->setEnabled(false);

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
    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    m_index = table.size() - 1;


    paintChessboard(table.at(m_index));

    check_index();

}

void ChessboardCoverage::pbtn_lastStep_clicked()
{
    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    --m_index;

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

void ChessboardCoverage::pbtn_autoDisplay_clicked()
{
    const auto result = QMessageBox::question(this, QString("自动化展示"), QString("是否自动化展示"));
    if (result != QMessageBox::StandardButton::Yes)
    {
        return;
    }

    ui->pbtn_skipToInitial->setEnabled(false);
    ui->pbtn_skipToFinal->setEnabled(false);
    ui->pbtn_lastStep->setEnabled(false);
    ui->pbtn_nextStep->setEnabled(false);
    ui->pbtn_autoDisplay->setEnabled(false);
    ui->pbtn_resetChessboard->setEnabled(false);

    const auto& table = m_coverageOperator->getChessboardHistoryTable();

    const auto size = table.size() * table[0].size();
    const auto time = 50000 / size;

    m_index = 0;

    for (CoverageOperator::ChessboardHistoryTableIndex i = 0; i <= m_indexMaxsize; ++i, ++m_index)
    {
        paintChessboard(table.at(m_index));
        QApplication::processEvents();

        QThread::msleep(static_cast<unsigned long>(time));


    }
    --m_index;

    ui->pbtn_skipToInitial->setEnabled(true);
    ui->pbtn_skipToFinal->setEnabled(true);
    ui->pbtn_resetChessboard->setEnabled(true);
    ui->pbtn_autoDisplay->setEnabled(true);

    check_index();

}

void ChessboardCoverage::pbtn_resetChessboard_clicked() {

    const auto size = ui->sBox_sizeK->value();


    const auto row = pow(2, size);

    drawChessboard(row, row);
    m_specialBlock_x = ui->sBox_x->value();
    m_specialBlock_y = ui->sBox_y->value();
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

    ui->pbtn_nextStep->setEnabled(false);
    ui->pbtn_lastStep->setEnabled(false);
    ui->pbtn_skipToInitial->setEnabled(false);
    ui->pbtn_skipToFinal->setEnabled(false);
    ui->pbtn_autoDisplay->setEnabled(false);
    ui->pbtn_CoverageOperate->setEnabled(true);

    m_index = 0;



}
