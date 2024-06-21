#include "ChessboardCoverage.h"
#include"PaintOperator.h"
 
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

    ui->label_operateState->setVisible(false);

    ini_chessboard();
}

void ChessboardCoverage::build_connect()
{
    QObject::connect(ui->pbtn_resetChessboard, &QPushButton::clicked,
        this, &ChessboardCoverage::pbtn_resetChessboard_clicked);

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

QColor ChessboardCoverage::getColor(ChessboardColor color) const
{
    switch (color) {
        case ChessboardColor::WHITE:{
            return QColor{ Qt::white };
        }
        case ChessboardColor::BLACK: {
            return QColor{ Qt::black };
        }
        case ChessboardColor::GREEN:{
            return QColor{ Qt::green };
        }
        case ChessboardColor::RED: {
            return QColor{ Qt::red };
        }
        case ChessboardColor::YELLOW: {
            return QColor{ Qt::yellow };
        }
    }
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

void ChessboardCoverage::paintFromItem(const qint32 row, const qint32 column, const QBrush& color) const
{
    ui->tableWidget->item(row, column)->setBackground(color);
}

void ChessboardCoverage::paintChessboardItem(const PaintItem& paintItem)
{
    auto color = paintItem.color;
    for (const auto &item: paintItem.paintLocate) {
        if (color==1) {
            paintFromItem(item.first, item.second, getColor(ChessboardColor::RED));
        }
        else if(color == 2){
            paintFromItem(item.first, item.second, getColor(ChessboardColor::GREEN));
        }
        else {
            paintFromItem(item.first, item.second, getColor(ChessboardColor::YELLOW));
        }
    }
}

void ChessboardCoverage::paintChessboardItem(const PaintItem& paintItem, ChessboardColor color)
{
    for (const auto& item : paintItem.paintLocate) {
        paintFromItem(item.first, item.second, getColor(color));
    }
}

void ChessboardCoverage::check_index() const
{
    if (m_index == -1)
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
        const auto size = 2;

        const auto row = pow(2, size);

        drawChessboard(row, row);
        m_specialBlock_x = 0;
        m_specialBlock_y = 0;
        paintFromItem(m_specialBlock_x, m_specialBlock_y, Qt::black);

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

        m_index = -1;

        CoverageOperateLoad();
}

void ChessboardCoverage::CoverageOperateLoad()
{
    m_coverageOperator->setNum(0);
    m_coverageOperator->run();

    check_index();
    m_paintItemList= PaintOperator::colorPaint(m_coverageOperator->getChessboard(),ui->sBox_sizeK->value());
    m_indexMaxsize = m_paintItemList.size() - 1;
}

void ChessboardCoverage::pbtn_skipToInitial_clicked()
{
    m_index = 0;

    for (const auto& item : m_paintItemList) {
        paintChessboardItem(item,ChessboardColor::WHITE);
    }

    check_index();
}

void ChessboardCoverage::pbtn_skipToFinal_clicked()
{
    m_index = m_paintItemList.size() - 1;

    for (const auto & item: m_paintItemList) {
        paintChessboardItem(item);
    }

    check_index();

}

void ChessboardCoverage::pbtn_lastStep_clicked()
{
    const auto& table = m_paintItemList;
    paintChessboardItem(m_paintItemList.at(m_index), ChessboardColor::WHITE);
    --m_index;
    check_index();
}

void ChessboardCoverage::pbtn_nextStep_clicked()
{
    const auto& table = m_paintItemList;
    ++m_index;
    paintChessboardItem(m_paintItemList.at(m_index));
    check_index();
}

void ChessboardCoverage::pbtn_autoDisplay_clicked()
{
    pbtn_skipToInitial_clicked();
    ui->label_operateState->setVisible(true);

    ui->pbtn_skipToInitial->setEnabled(false);
    ui->pbtn_skipToFinal->setEnabled(false);
    ui->pbtn_lastStep->setEnabled(false);
    ui->pbtn_nextStep->setEnabled(false);
    ui->pbtn_autoDisplay->setEnabled(false);
    ui->pbtn_resetChessboard->setEnabled(false);

    const auto& table = m_paintItemList;

    const auto size = table.size();
    //const auto time = 50000 / size;
    const auto time = 50;

    m_index = 0;

    for (CoverageOperator::ChessboardHistoryTableIndex i = 0; i <= m_indexMaxsize; ++i, ++m_index)
    {
        paintChessboardItem(m_paintItemList.at(i));
        QApplication::processEvents();

        QThread::msleep(static_cast<unsigned long>(time));


    }
    --m_index;

    ui->pbtn_skipToInitial->setEnabled(true);
    ui->pbtn_skipToFinal->setEnabled(true);
    ui->pbtn_resetChessboard->setEnabled(true);
    ui->pbtn_autoDisplay->setEnabled(true);

    check_index();

    ui->label_operateState->setVisible(false);

}

void ChessboardCoverage::pbtn_resetChessboard_clicked() {

    const auto size = ui->sBox_sizeK->value();


    const auto row = pow(2, size);

    const auto locateX= ui->sBox_x->value();
    const auto locateY= ui->sBox_y->value();

    if(locateX>=row||locateY>=row)
    {
        QMessageBox::warning(this, "错误", "特殊块位置不在棋盘中");

        return;
    }

    m_specialBlock_x = locateX;
    m_specialBlock_y = locateY;


    drawChessboard(row, row);
    paintFromItem(m_specialBlock_x, m_specialBlock_y, Qt::black);

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

    m_index = 0;

    CoverageOperateLoad();

}
