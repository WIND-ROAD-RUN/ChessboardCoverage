#include "DlgSetChessboard.h"

DlgSetChessboard::DlgSetChessboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DlgSetChessboardClass())
{
    ui->setupUi(this);
    build_ui();
    build_connect();
}

DlgSetChessboard::~DlgSetChessboard()
{
    delete ui;
}

void DlgSetChessboard::build_ui()
{
    this->setWindowTitle("棋盘设置");
}

void DlgSetChessboard::build_connect()
{
    QObject::connect(ui->pbtn_ok,&QPushButton::clicked,
        this,&DlgSetChessboard::pbtn_ok_clicked);
    QObject::connect(ui->pbtn_cancel, &QPushButton::clicked, 
        this, &DlgSetChessboard::pbtn_cancel_clicked);
}

qint32 DlgSetChessboard::getRow()
{
    return ui->sBox_row->value();
}

qint32 DlgSetChessboard::getColumn()
{
    return ui->sBox_column->value();
}

qint32 DlgSetChessboard::getX()
{
    return ui->sBox_x->value();
}

qint32 DlgSetChessboard::getY()
{
    return ui->sBox_y->value();
}

void DlgSetChessboard::pbtn_ok_clicked() {
    this->accept();
}
void DlgSetChessboard::pbtn_cancel_clicked() {
    this->reject();
}
