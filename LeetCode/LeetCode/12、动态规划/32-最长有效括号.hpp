// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <string>
#include <vector>

#pragma mark - 方法二: 动态规划, 改进版
int longestValidParentheses2(string s)  {
    int len = (int)s.length();
    vector<int> dp(len, 0);
    int maxLen = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') dp[i] = ((0<=i-2)?dp[i-2]:0) + 2;
            else if (1<=i-dp[i-1] && s[i-dp[i-1]-1]=='(') {
                dp[i] = dp[i-1] + ((0<=i-dp[i-1]-2)?dp[i-dp[i-1]-2]:0) + 2;
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    return maxLen;
}

#pragma mark - 方法一: 动态规划, 效率较低
int longestValidParentheses1(string s) {
    int len = (int)s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false));  // dp[i][j]: s[i~j]是否为有效括号
    vector<int> dpLen(len, 0); // dpLen[i]: 以结尾有效括号最大长度
    // dp初始化
    int maxLen = 0;
    for (int i = 0; i < len; i++)
        // dp[i][i] = false; 默认就是false
        if (i<=len-2 && s[i]=='(' && s[i+1]==')') {
            dp[i][i+1] = true;
            maxLen = 2;
            dpLen[i+1] = 2;
        }
    // dp状态转移
    for (int j = 2; j < len; j++) {
        for (int i = 0; i < j; i++) {
            if (s[i]=='('&&s[j]==')' && (dp[i+1][j-1]||j-i==1)) {
                dp[i][j] = true;
                if (0 <= i-1) {
                    dpLen[j] = j-i+1+dpLen[i-1];
                    dp[i-dpLen[i-1]][j] = true;
                }
                else dpLen[j] = j-i+1;
                if (maxLen < dpLen[j]) maxLen = dpLen[j];
            }
            
        }
    }
    return maxLen;
}

void test() {
    cout << longestValidParentheses2(")()()()") << endl;
    cout << longestValidParentheses2("(()())") << endl;
}
