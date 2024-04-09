#ifndef COVERAGEOPERATOR_H_
#define CEVERAGEOPERATOR_H_

#include<vector>

using Chessboard = std::vector<std::vector<int>>;

class CoverageOperator {
private:
    Chessboard m_Chessboard;

    int m_num{0};

    int m_locateX{ 0 };
    int m_locateY{ 0 };
    int m_size{0};


public:
    CoverageOperator() {}

    ~CoverageOperator() {}

public:
    void setChessboard(Chessboard  chessBoard);

    Chessboard  getChessboard();

    void setNum(int num) { m_num = num; }

    void setX(int x) { m_locateX = x; }
    void setY(int y) { m_locateY = y; }
    void setSize(int size) { m_size = size; }

    bool run();

    void chessBoard(int tr, int tc, int dr, int dc, int size);
};


#endif // !COVERAGEOPERATOR_H_
