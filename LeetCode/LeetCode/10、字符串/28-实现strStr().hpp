// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>

/**实现strStr()
实现strStr()函数。
给你两个字符串haystack和needle，请你在haystack字符串中找出needle 字符串出现的第一个位置（下标从0开始）。如果不存在，则返回-1。

说明：
1. 当needle是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
2. 对于本题而言，当needle是空字符串时我们应当返回0。这与C语言的strstr()以及Java 的indexOf()定义相符。
 
提示：
1. 0 <= haystack.length, needle.length <= 5*104
2. haystack和needle仅由小写英文字符组成
 */
#pragma mark - 方法1-暴力解法
int strStr1(string haystack, string needle) {
    int hLen = (int)haystack.size();
    int nLen = (int)needle.size();
    for (int i = 0; i <= hLen-nLen; i++) {
        int j = i, cur = 0;
        while (cur<nLen && haystack[j]==needle[cur]) {
            cur++;
            j++;
        }
        if (cur == nLen) return i;
    }
    return -1;
}

#pragma mark - 方法2-KMP算法
int strStr(string text, string pattern) {
    int tLen = (int)text.length();
    int pLen = (int)pattern.length();
    if (pLen == 0) return 0;
    
    vector<int> next(pLen, 0);
    // 构建next表，最长公共前后缀
    for (int i = 1, j = 0; i < pLen; i++) {
        while (0<j && pattern[i]!=pattern[j]) j = next[j-1];
        if (pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    
    // 匹配过程
    for (int i = 0, j = 0; i < tLen; i++) {
        while (0<j && text[i]!=pattern[j]) j = next[j-1];
        if (text[i] == pattern[j]) j++;
        if (j == pLen) {
            return i-pLen+1;
        }
    }
    return -1;
}
