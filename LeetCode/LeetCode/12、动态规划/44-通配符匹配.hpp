// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <string>
#include <vector>

#pragma mark - 方法二: 双指针
bool isMatch(string s, string p) {
    int sLen = (int)s.length();
    int pLen = (int)p.length();
    int pFlag = -1, sFlag = -1;
    int i = 0, j = 0;
    while (i < sLen) {
        if (j<pLen && (s[i]==p[j]||p[j]=='?')) {
            i++;
            j++;
        } else if (j<pLen && p[j] == '*') {
            sFlag = i;
            pFlag = j;
            j++;
        } else if (pFlag != -1) { // 出现过'*'
            j = pFlag + 1;
            sFlag++;
            i = sFlag;
        } else return false;
    }
    while (j < pLen) {
        if (p[j] != '*') return false;
        j++;
    }
    return true;
}

#pragma mark - 方法一: 动态规划
bool isMatch1(string s, string p) {
    int sLen = (int)s.length();
    int pLen = (int)p.length();
    // dp[i][j]: s的前i个字符与p的前j个字符是否匹配
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));
    // dp状态初始化
    dp[0][0]= true;
    for (int j = 1; j <= pLen; j++) dp[0][j] = (dp[0][j-1] && p[j-1]=='*');
    // dp状态转移
    for (int i = 0; i < sLen; i++) {
        for (int j = 0; j < pLen; j++) {
            if (s[i]==p[j] || p[j]=='?') dp[i+1][j+1] = dp[i][j];
            else if (p[j] == '*')
                //           "adc"与"ad*" "adce"与"ad*"   "a"与"a*"
                dp[i+1][j+1] = dp[i][j] || dp[i][j+1] || dp[i+1][j];
        }
    }
    return dp[sLen][pLen];
}

void test() {
    cout << isMatch("adceb", "*a*b") << endl;
    cout << isMatch("a", "a*") << endl;
}
