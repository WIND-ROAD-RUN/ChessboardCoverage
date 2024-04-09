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
    return false;
}
