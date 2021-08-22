// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**解数独
编写一个程序，通过填充空格来解决数独问题。
数独的解法需遵循如下规则：
1. 数字1-9在每一行只能出现一次。
2. 数字1-9在每一列只能出现一次。
3. 数字1-9在每一个以粗实线分隔的3x3宫内只能出现一次。（请参考示例图）
4. 数独部分空格内已填入了数字，空白格用'.'表示。
 
提示：
1. board.length == 9
2. board[i].length == 9
3. board[i][j]是一位数字或者'.'
4. 题目数据保证输入数独仅有一个解
 */

#pragma mark - 方法1-dfs深度优先搜索
bool dfs(vector<vector<char>>& board,
         int n,
         vector<vector<bool>> &row,
         vector<vector<bool>> &col,
         vector<vector<bool>> &box) {
    int i = n/9, j = n%9;
    if (n == 81) return true;
    if (board[i][j] != '.') return dfs(board, n+1, row, col, box);
    
    int k = 3*(i/3)+j/3;
    for (int num = 0; num < 9; num++) {
        if (row[i][num] || col[j][num] || box[k][num]) continue;
        board[i][j] = num+'1';
        row[i][num] = col[j][num] = box[k][num] = true;
        if (dfs(board, n+1, row, col, box)) return true;
        row[i][num] = col[j][num] = box[k][num] = false;
        board[i][j] = '.';
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    /// 构建状态表
    vector<vector<bool>> row(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> box(9, vector<bool>(9, false));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            int key = ch-'1', k = 3*(i/3)+j/3;
            row[i][key] = col[j][key] = box[k][key] = true;
        }
    }
    /// dfs深度优先搜索
    dfs(board, 0, row, col, box);
}
