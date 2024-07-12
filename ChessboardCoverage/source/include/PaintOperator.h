#ifndef PAINTOPERATOR_H_
#define PAINTOPERATOR_H_

#include <vector>

using Chessboard = std::vector<std::vector<int>>;
using BlockLocate = std::pair<int, int>;
using BlockItem = std::pair<std::vector<BlockLocate>, int>;
using PaintHistoryList = std::vector<BlockItem>;

struct PaintItem
{
    int index{};
    std::vector<BlockLocate> paintLocate{};
    int color{};
};
using PaintItemList = std::vector<PaintItem>;

class PaintOperator
{
private:
    static PaintHistoryList *m_LBlockPaintList;
    static PaintHistoryList *m_specailLBlockPaintList;
    static PaintItemList *m_paintItemList;

public:
    static PaintItemList colorPaint(const Chessboard &chessboard, int size);

public:
    static void getBlockList(const Chessboard &chessboard);
    static void setBlockColor(int size);
    static void sortPaintItemList();
};

#endif // !PAINTOPERATOR_H_
