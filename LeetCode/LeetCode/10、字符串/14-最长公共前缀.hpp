// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <string>

/**最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串""。
 
提示：
1. 0 <= strs.length <= 200
2. 0 <= strs[i].length <= 200
3. strs[i]仅由小写英文字母组成
 */

#pragma mark - 方法1-横向扫描
string longestCommonPrefix1(vector<string>& strs) {
    int size = (int)strs.size();
    if(size == 0) return "";
    // ret取strs[0]作为原始的字符串，作为返回结果，对其进行删除尾部
    string ret = strs[0];
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < ret.size(); j++) {
            if(strs[i][j] != ret[j]) {
                ret.assign(ret, 0, j); // 这里可只记录索引
                break;
            }
        }
    }
    return ret;
}

#pragma mark - 方法2-纵向扫描
string longestCommonPrefix(vector<string>& strs) {
    int size = (int)strs.size();
    if(size == 0) return "";
    
    int count = (int)strs.size();
    int len = (int)strs[0].length();
    for (int i = 0; i < len; i++) {
        char ch = strs[0][i]; // 第0个字符串第i列
        // 遍历所有字符串的第i列
        for (int j = 1; j < count; j++) {
            if (i==strs[j].size() || strs[j][i] != ch) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}
