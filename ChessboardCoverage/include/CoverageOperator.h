#ifndef COVERAGEOPERATOR_H_
#define CEVERAGEOPERATOR_H_

#include<vector>

using Chessboard = std::vector<std::vector<int>>;

class CoverageOperator {
private:
    Chessboard m_Chessboard;

public:
    CoverageOperator() {}

    ~CoverageOperator() {}

public:
    void setChessboard(Chessboard  chessBoard);

    Chessboard  getChessboard();

    bool run();


};


#endif // !COVERAGEOPERATOR_H_
