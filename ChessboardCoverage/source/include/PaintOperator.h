#ifndef PAINTOPERATOR_H_
#define PAINTOPERATOR_H_

#include<vector>

using Chessboard = std::vector<std::vector<int>>;
using BlockLocate = std::pair<int, int>;
using BlockItem = std::pair<std::vector<BlockLocate>,int>;
using PaintHistoryList = std::vector<BlockItem>;


class PaintOperator {
public: 
    static PaintHistoryList colorPaint(const Chessboard & chessboard);
    
};

#endif // !PAINTOPERATOR_H_
