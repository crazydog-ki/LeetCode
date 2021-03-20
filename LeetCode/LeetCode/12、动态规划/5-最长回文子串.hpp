// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <string>
#include <vector>

#pragma mark - 方法二: 动态规划
string longestPalindrome2(string s) {
    int length = (int)s.length();
    if (length <= 1) return s;
    // dp[i][j] => 子串s[i]~s[j]是否为回文串
    vector<vector<bool>> dp(length, vector<bool>(length, false));
    // dp初始状态
    int maxLength = 1;
    int start = 0;
    for (int i = 0; i < length; i++) {
        dp[i][i] = true; // 单个字符为回文串
        if (i<length-1 && s[i]==s[i+1]) {
            dp[i][i+1] = true; // 两个相等字符为回文串
            maxLength = 2;
            start = i;
        }
    }
    // dp递推
    for (int j = 1; j < length; j++) {
        for (int i = 0; i < j; i++) {
            if (1<j-i && s[i]==s[j] && dp[i+1][j-1]) { // 单个字符和两个相邻字符已处理
                dp[i][j] = true;
                if (maxLength < j-i+1) {
                    maxLength = j-i+1;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}

#pragma mark - 方法一: 中心扩散
void diffusion(string &s, int left, int right, string &res, int &maxLength) {
    while (0<=left && right<=s.size()-1 && s[left]==s[right]) {
        if (maxLength < right-left+1) {
            maxLength = right-left+1;
            res = s.substr(left, right-left+1);
        }
        left--;
        right++;
    }
}

string longestPalindrome(string s) {
    int length = (int)s.length();
    if (length <= 1) return s;
    
    int maxLength = 0;
    string res = "";
    for (int i = 0; i < length; i++) {
        diffusion(s, i, i, res, maxLength); // 一个字符中心扩散
        if (i<length-1 && s[i] == s[i+1]) diffusion(s, i, i+1, res, maxLength); // 两个相同字符中心扩散
    }
    return res;
}

void test() {
    cout << longestPalindrome2("abbac") << endl;
}
