// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <map>

/**电话号码的字母组合
 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回。
 给出数字到字母的映射如下（与电话按键相同）。注意1不对应任何字母。
 
 提示：
 （1）0 <= digits.length <= 4
 （2）digits[i]是范围['2','9']的一个数字
 */

#pragma mark - 方法1-dfs+哈希
map<char, string> myMap;
void dfs(int depth,
         string& digits,
         string& item,
         vector<string> &ret) {
    if (item.length() == digits.length()) {
        ret.push_back(item);
        return;
    }
    
    for (auto &ch : myMap[digits[depth]]) {
        item.push_back(ch);
        dfs(depth+1, digits, item, ret);
        item.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    myMap['1'] = "";
    myMap['2'] = "abc";
    myMap['3'] = "def";
    myMap['4'] = "ghi";
    myMap['5'] = "jkl";
    myMap['6'] = "mno";
    myMap['7'] = "pqrs";
    myMap['8'] = "tuv";
    myMap['9'] = "wxyz";
    
    vector<string> ret = {};
    if (!digits.length()) return ret;
    string item;
    int depth = 0;
    dfs(depth, digits, item, ret);
    return ret;
}

void test() {
    
}
