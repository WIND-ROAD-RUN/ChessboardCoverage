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
    void build_ui();
    void build_connect();
private:
    Ui::DlgSetChessboardClass *ui;
public:
    qint32 getX();
    qint32 getY();
    qint32 getSize();
private slots:
    void pbtn_ok_clicked();
    void pbtn_cancel_clicked();
};
