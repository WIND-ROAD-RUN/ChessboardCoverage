#ifndef COVERAGEOPERATOR_H_
#define COVERAGEOPERATOR_H_

#include<vector>

using Chessboard = std::vector<std::vector<int>>;

class CoverageOperator {
public:
    using ChessboardHistoryTableIndex = std::vector<Chessboard>::size_type;
private:
    Chessboard m_chessboard;

    int m_num{ 0 };

    int m_locateX{ 0 };

    int m_locateY{ 0 };

    int m_size{ 0 };

    std::vector<Chessboard> m_chessboardHistoryTable{};

public:
    CoverageOperator() = default;

    ~CoverageOperator() = default;

    CoverageOperator(const CoverageOperator& c) = delete;

    CoverageOperator(const CoverageOperator&& c) = delete;

    CoverageOperator& operator=(CoverageOperator& c) = delete;

    CoverageOperator& operator=(CoverageOperator&& c) = delete;

public:
    void setChessboard(const Chessboard& chessBoard);

    Chessboard  getChessboard();

    void setNum(const int num) { m_num = num; }

    void setX(const int x) { m_locateX = x; }

    void setY(const int y) { m_locateY = y; }

    void setSize(const int size) { m_size = size; }

    bool run();

    void chessBoard(int tr, int tc, int dr, int dc, int size);

    const std::vector<Chessboard> & getChessboardHistoryTable()const;
};


#endif // !COVERAGEOPERATOR_H_
