#pragma once

#include <QDialog>
#include "ui_DlgSetChessboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DlgSetChessboardClass; };
QT_END_NAMESPACE

class DlgSetChessboard : public QDialog
{
    Q_OBJECT

public:
    DlgSetChessboard(QWidget *parent = nullptr);
    ~DlgSetChessboard();

private:
    Ui::DlgSetChessboardClass *ui;
};
