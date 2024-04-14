#pragma once

#include <QDialog>
#include "ui_DlgSetChessboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DlgSetChessboardClass; };
QT_END_NAMESPACE

class DlgSetChessboard final : public QDialog
{
    Q_OBJECT
public:
    explicit DlgSetChessboard(QWidget *parent = nullptr);

    ~DlgSetChessboard() override;

    DlgSetChessboard(const DlgSetChessboard& c) = delete;

    DlgSetChessboard(const DlgSetChessboard&& c) = delete;

    DlgSetChessboard& operator=(DlgSetChessboard& c) = delete;

    DlgSetChessboard& operator=(DlgSetChessboard&& c) = delete;

private:
    void build_ui();

    void build_connect();

private:
    Ui::DlgSetChessboardClass *ui;
public:
    qint32 getX() const;
    qint32 getY() const;
    qint32 getSize() const;
private slots:
    void pbtn_ok_clicked();
    void pbtn_cancel_clicked();
};
