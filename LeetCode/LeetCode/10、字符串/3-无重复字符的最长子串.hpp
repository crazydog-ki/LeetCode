// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include "tools.h"

/**无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
 */
#pragma mark - 方法1-哈希+滑动窗口
int lengthOfLongestSubstring1(string s) {
    int len = (int)s.length();
    int left = 0, maxLen = 0;
    unordered_set<char> lookup;
    for (int i = 0; i < len; i++) {
        while (lookup.count(s[i])) { /// 循环去重
            lookup.erase(s[left]);
            left++;
        }
        lookup.insert(s[i]);
        maxLen = max(maxLen, i-left+1);
    }
    return maxLen;
}

#pragma mark - 方法2-哈希+滑动窗口优化
int lengthOfLongestSubstring2(string s) {
    int len = (int)s.length();
    int left = 0, maxLen = 0;
    map<char, int> myMap;
    for (int i = 0; i < len; i++) {
        if (myMap.count(s[i]) && left <= myMap[s[i]]) { /// 一步跳去重
            left = myMap[s[i]]+1;
        }
        myMap[s[i]] = i;
        maxLen = max(maxLen, i-left+1);
    }
    return maxLen;
}

#pragma mark - 方法3-桶数组
int lengthOfLongestSubstring3(string s) {
    int len = (int)s.length();
    int left = 0, maxLen = 0;
    int *lookup = new int[128];
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        left = max(left, lookup[ch]+1); /// 一步跳
        maxLen = max(maxLen, i-left+1);
        lookup[ch] = i;
    }
    return maxLen;
}
