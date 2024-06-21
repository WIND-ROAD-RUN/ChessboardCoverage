#include"PaintOperator.h"
#include <unordered_map>
#include <map>

PaintHistoryList PaintOperator::colorPaint(const Chessboard& chessboard)
{
    PaintHistoryList result{};
    PaintHistoryList singleBlock{};

    auto boardSize = chessboard.size();
    for (int i = 0;i<boardSize;i+=2) {
        for (int j = 0; j < boardSize; j += 2) {

            int item{};
            BlockItem blockItem1{}, blockItem2{};
            item = chessboard[i][j];
            blockItem1.first.push_back({ i,j });
            blockItem1.second = item;

            for (int block_i = i; block_i < i + 2;block_i++) {
                for (int block_j = j; block_j < j + 2; block_j++) {
                    if (block_i ==i&&block_j ==j) {
                        continue;
                    }
                    if (item !=chessboard[block_i][block_j]) {
                        blockItem2.first.push_back({ block_i ,block_j });
                        blockItem2.second = chessboard[block_i][block_j];
                    }
                    else {
                        blockItem1.first.push_back({ block_i ,block_j });
                        blockItem1.second = item;
                    }
                }
            }

            if (blockItem1.first.size()>blockItem2.first.size()) {
                result.push_back(blockItem1);
                singleBlock.push_back(blockItem2);
            }
            else {
                result.push_back(blockItem2);
                singleBlock.push_back(blockItem1);
            }

        }
    }

  
    singleBlock.erase(
        std::remove_if(singleBlock.begin(), singleBlock.end(),
            [](const BlockItem& item) {
                return item.second == 0;
            }),
        singleBlock.end());



    // 使用unordered_map来合并相同int值的数据项的vector部分
    std::unordered_map<int, std::vector<BlockLocate>> merged_map;

    for (const auto& item : singleBlock) {
        merged_map[item.second].insert(merged_map[item.second].end(), item.first.begin(), item.first.end());
    }

    // 将结果存回容器
    PaintHistoryList merged_list;
    for (const auto& entry : merged_map) {
        merged_list.emplace_back(entry.second, entry.first);
    }

    

    return result;
}
