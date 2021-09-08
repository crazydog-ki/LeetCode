// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <unordered_map>

/**有效的数独
请你判断一个9x9的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
数字1-9在每一行只能出现一次。
数字1-9在每一列只能出现一次。
数字1-9在每一个以粗实线分隔的3x3宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用'.'表示。

注意：
1. 一个有效的数独（部分已被填充）不一定是可解的。
2. 只需要根据以上规则，验证已经填入的数字是否有效即可。

提示：
1. board.length == 9
2. board[i].length == 9
3. board[i][j]是一位数字或者'.'
 */

#pragma mark - 方法1-哈希1
bool isValidSudoku1(vector<vector<char>>& board) {
    int len = (int)board.size();
    /// 横向
    vector<unordered_map<char, bool>> rowM(len);
    /// 纵向
    vector<unordered_map<char, bool>> colM(len);
    /// 方格
    vector<unordered_map<char, bool>> boxM(len);
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            int k = 3*(j/3)+i/3;
            if (rowM[i].find(ch) != rowM[i].end() ||
                colM[j].find(ch) != colM[j].end() ||
                boxM[k].find(ch) != boxM[k].end()) {
                return false;
            }
            
            rowM[i][ch] = true;
            colM[j][ch] = true;
            boxM[k][ch] = true;
         }
    }
    return true;
}

#pragma mark - 方法2-哈希2
bool isValidSudoku(vector<vector<char>>& board) {
    int len = (int)board.size();
    vector<vector<int>> row(len, vector<int>(len+1, 0));
    vector<vector<int>> col(len, vector<int>(len+1, 0));
    vector<vector<int>> box(len, vector<int>(len+1, 0));
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            
            int k = 3*(j/3)+i/3;
            int key = ch-'0';
            if (row[i][key] != 0 ||
                col[j][key] != 0 ||
                box[k][key] != 0) {
                return false;
            }
            
            row[i][key]++;
            col[j][key]++;
            box[k][key]++;
        }
    }
    return true;
 }
