#include "DlgSetChessboard.h"

DlgSetChessboard::DlgSetChessboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DlgSetChessboardClass())
{
    ui->setupUi(this);
}

DlgSetChessboard::~DlgSetChessboard()
{
    delete ui;
}
