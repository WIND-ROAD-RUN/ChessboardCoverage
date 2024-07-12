#include "PaintOperator.h"
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>

PaintHistoryList *PaintOperator::m_LBlockPaintList = nullptr;
PaintHistoryList *PaintOperator::m_specailLBlockPaintList = nullptr;
PaintItemList *PaintOperator::m_paintItemList = nullptr;

PaintItemList PaintOperator::colorPaint(const Chessboard &chessboard, int size)
{
    getBlockList(chessboard);
    setBlockColor(size);
    sortPaintItemList();

    return *m_paintItemList;
}

void PaintOperator::getBlockList(const Chessboard &chessboard)
{
    delete m_LBlockPaintList;
    delete m_specailLBlockPaintList;

    PaintHistoryList lBlock{};
    PaintHistoryList specialBlock{};

    auto boardSize = chessboard.size();
    for (int i = 0; i < boardSize; i += 2)
    {
        for (int j = 0; j < boardSize; j += 2)
        {

            int item{};
            BlockItem blockItem1{}, blockItem2{};
            item = chessboard[i][j];
            blockItem1.first.push_back({i, j});
            blockItem1.second = item;

            for (int block_i = i; block_i < i + 2; block_i++)
            {
                for (int block_j = j; block_j < j + 2; block_j++)
                {
                    if (block_i == i && block_j == j)
                    {
                        continue;
                    }
                    if (item != chessboard[block_i][block_j])
                    {
                        blockItem2.first.push_back({block_i, block_j});
                        blockItem2.second = chessboard[block_i][block_j];
                    }
                    else
                    {
                        blockItem1.first.push_back({block_i, block_j});
                        blockItem1.second = item;
                    }
                }
            }

            if (blockItem1.first.size() > blockItem2.first.size())
            {
                lBlock.push_back(blockItem1);
                specialBlock.push_back(blockItem2);
            }
            else
            {
                lBlock.push_back(blockItem2);
                specialBlock.push_back(blockItem1);
            }
        }
    }

    specialBlock.erase(
        std::remove_if(specialBlock.begin(), specialBlock.end(),
                       [](const BlockItem &item)
                       {
                           return item.second == 0;
                       }),
        specialBlock.end());

    std::unordered_map<int, std::vector<BlockLocate>> merged_map;

    for (const auto &item : specialBlock)
    {
        merged_map[item.second].insert(merged_map[item.second].end(), item.first.begin(), item.first.end());
    }

    specialBlock.clear();

    PaintHistoryList merged_list;
    for (const auto &entry : merged_map)
    {
        specialBlock.emplace_back(entry.second, entry.first);
    }

    m_LBlockPaintList = new PaintHistoryList(lBlock);
    m_specailLBlockPaintList = new PaintHistoryList(specialBlock);
}

void PaintOperator::setBlockColor(int size)
{
    if (!m_paintItemList)
    {
        m_paintItemList = new PaintItemList;
    }
    else
    {
        m_paintItemList->clear();
    }
    size = std::pow(2, size);
    size = size / 2;

    PaintItem paintItem;
    for (int i = 0; i < m_LBlockPaintList->size(); ++i)
    {

        const auto &item = (*m_LBlockPaintList)[i];
        paintItem.index = item.second;
        paintItem.paintLocate = item.first;

        if ((i / size) % 2)
        {
            if (i % 2)
            {
                paintItem.color = 1;
                m_paintItemList->push_back(paintItem);
            }
            else
            {
                paintItem.color = 2;
                m_paintItemList->push_back(paintItem);
            }
        }
        else
        {
            if (i % 2)
            {
                paintItem.color = 2;
                m_paintItemList->push_back(paintItem);
            }
            else
            {
                paintItem.color = 1;
                m_paintItemList->push_back(paintItem);
            }
        }
    }

    for (const auto &item : *m_specailLBlockPaintList)
    {
        paintItem.color = 0;
        paintItem.index = item.second;
        paintItem.paintLocate = item.first;
        m_paintItemList->push_back(paintItem);
    }
}

void PaintOperator::sortPaintItemList()
{
    std::sort(m_paintItemList->begin(), m_paintItemList->end(), [](const PaintItem &a, const PaintItem &b)
              { return a.index < b.index; });
}
