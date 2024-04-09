#include "CoverageOperator.h"

void CoverageOperator::setChessboard(Chessboard chessBoard)
{
    m_Chessboard = chessBoard;
}

Chessboard CoverageOperator::getChessboard()
{
    return m_Chessboard;
}

bool CoverageOperator::run()
{
    chessBoard(0, 0, m_locateX,m_locateY,m_size);

    return true;
}

void CoverageOperator::chessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int s = size / 2;     //分割棋盘
    int t = ++m_num;      //L型骨牌号

    //覆盖左上角子棋盘
    if (dr < tr + s && dc < tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr, tc, dr, dc, s);
    }
    else            //此棋盘中无特殊方格
    {
        //用t号L型骨牌覆盖右下角
        m_Chessboard[tr + s - 1][tc + s - 1] = t;
        //覆盖其余方格
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    //覆盖右上角子棋盘
    if (dr < tr + s && dc >= tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr, tc + s, dr, dc, s);
    }
    else            //此棋盘中无特殊方格
    {
        //用t号L型骨牌覆盖左下角
        m_Chessboard[tr + s - 1][tc + s] = t;
        //覆盖其余方格
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    //覆盖左下角子棋盘
    if (dr >= tr + s && dc < tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr + s, tc, dr, dc, s);
    }
    else
    {
        //用t号L型骨牌覆盖右上角
        m_Chessboard[tr + s][tc + s - 1] = t;
        //覆盖其余方格
        chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    //覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        //用t号L型骨牌覆盖左上角
        m_Chessboard[tr + s][tc + s] = t;
        //覆盖其余方格
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }

}
