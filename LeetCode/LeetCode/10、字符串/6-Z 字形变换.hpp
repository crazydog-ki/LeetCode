// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include <string>

/**Z 字形变换
 将一个给定字符串s根据给定的行数numRows，以从上往下、从左到右进行Z字形排列。
 */
#pragma mark - 方法1-按行排序
string convert1(string s, int numRows) {
    // 处理临界情况
    if (numRows == 1) return s;
    
    int len = (int)s.length();
    int curRow = 0, reversed = -1;
    vector<string> rowStrings(min(numRows, len)); // 存储每一行数据
    for (char ch : s) {
        if (curRow == 0 || curRow == numRows-1) reversed = -reversed;
        rowStrings[curRow] += ch; // 每个字符编上对应行号
        curRow += reversed;
    }
    
    string resString = "";
    for (string str : rowStrings) resString += str;
    return resString;
}

#pragma mark - 方法2-按行访问
string convert2(string s, int numRows) {
    if (numRows == 1) return s;
    
    int len = (int)s.length();
    int delta = 2*numRows-2;
    string ret = "";
    for (int i = 0; i < numRows; i++) {
        // 找某行对应的数学关系
        for (int j = 0; i+j < len; j += delta) {
            ret += s[i+j];
            // 中间行数
            if (i!=0 && i!=numRows-1 && j+delta-i<len) {
                ret += s[j+delta-i];
            }
        }
    }
    return ret;
}

void test() {
    cout << convert2("AB", 1) << endl;
    cout << convert2("PAYPALISHIRING", 3) << endl;
}
