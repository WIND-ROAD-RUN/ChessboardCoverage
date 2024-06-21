#include"PaintOperator.h"

PaintHistoryList PaintOperator::colorPaint(const Chessboard& chessboard)
{
    PaintHistoryList result{};

    auto boardSize = chessboard.size();
    for (int i = 0;i<boardSize;i+=2) {
        for (int j = 0; j < boardSize; j += 2) {

            int item{};
            BlockItem blockItem1{}, blockItem2{};
            item = chessboard[i][j];
            blockItem1.push_back({i,j});

            for (int block_i = i; block_i < i + 2;block_i++) {
                for (int block_j = j; block_j < j + 2; block_j++) {
                    if (block_i ==i&&block_j ==j) {
                        continue;
                    }
                    if (item !=chessboard[block_i][block_j]) {
                        blockItem2.push_back({ block_i ,block_j });
                    }
                    else {
                        blockItem1.push_back({ block_i ,block_j });
                    }
                }
            }

            if (blockItem1.size()>blockItem2.size()) {
                result.push_back(blockItem1);
            }
            else {
                result.push_back(blockItem2);
            }

        }
    }

    return result;
}
