// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>

/**最长回文子串
 给你一个字符串s，找到s中最长的回文子串。
 提示：
 （1）1 <= s.length <= 1000
 （2）s仅由数字和英文字母（大写和/或小写）组成
 */
#pragma mark - 方法1-中心扩散
string centerSpread(string s, int left, int right) {
    int len = (int)s.size();
    while (0<=left && right<=len-1) {
        if (s[left] == s[right]) {
            left--;
            right++;
        } else break;
    }
    // 跳出时，left多减1，right多加1
    return s.substr(left+1, right-left-1);
}

string longestPalindrome1(string s) {
    int len = (int)s.size();
    
    int maxLen = 1;
    string resStr = s.substr(0, 1);
    for (int i = 0; i < len; i++) {
        string oneMidStr = centerSpread(s, i, i);  // 一个数为中心点
        string twoMidStr = centerSpread(s, i, i+1);// 两个数为中心点
        string tmpMaxStr = oneMidStr.size() < twoMidStr.size() ?
                           twoMidStr : oneMidStr;
        if (maxLen < tmpMaxStr.size()) {
            maxLen = (int)tmpMaxStr.size();
            resStr = tmpMaxStr;
        }
    }
    
    return resStr;
}

#pragma mark - 方法2-中心扩散优化版
string longestPalindrome2(string s) {
    int len = (int)s.size();
    int maxLen = 1;
    string resStr = s.substr(0, 1);
    for (int i = 0; i < len; i++) {
        // 1个中心点
        int j = i, k = 1; // k代表距离中心点的距离
        while (j < len) {
            if (len-1<j+k || j-k<0 || s[j-k]!=s[j+k]) break;
            k++; // 继续探索
        }
        if (maxLen < 2*k-1) {
            maxLen = 2*k-1;
            resStr = s.substr(j-k+1, 2*k-1);
        }
        
        // 2个中心点
        k = 1;
        if (len-1<j+k || s[j]!=s[j+1]) continue;
        while (j < len) {
            if (len-1<j+k+1 || j-k<0 || s[j-k]!=s[j+1+k]) break;
            k++;
        }
        if (maxLen < 2*k) {
            maxLen = 2*k;
            resStr = s.substr(j-k+1, 2*k);
        }
    }
    
    return resStr;
}

#pragma mark - 方法3-动态规划
/*
 状态转移：在头尾字符相等的前提下，内部子串的回文性质就决定了整个串的回文性质
 状态转移方程：dp[i][j]表示s[i...j]是否为回文串，可得：
            dp[i][j] == (s[i]==s[j]) && dp[i+1][j-1]
 */
string longestPalindrome3(string s) {
    int len = (int)s.size();
    vector<vector<bool>> dp(len, vector<bool>(len));
    string resStr = s.substr(0, 1);
    for (int l = 0; l < len; l++) { // 截取长度
        for (int i = 0; i+l < len; i++) {
            int j = i+l;
            if (l==0) { // 单个字符
                dp[i][j] = true;
            } else if (l==1) { // 邻近两个字符
                dp[i][j] = (s[i]==s[j]);
            } else {
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
            }
            
            if (dp[i][j] && resStr.size() < l+1) {
                resStr = s.substr(i, l+1);
            }
        }
    }
    
    return resStr;
}

#pragma mark - 方法4-Manacher"马拉车"算法
int calculateRadius(string s, int left, int right) {
    while(0<=left && right<s.size() && s[left]==s[right]) {
        --left;
        ++right;
    }
    return (right-left-2) / 2;
}

string longestPalindrome4(string s) {
    // 对原始字符串做处理，将abc变成#a#b#c#
    string concatStr = "#";
    for(char c : s) {
        concatStr += c;
        concatStr += "#";
    }
    
    int len = (int)concatStr.size();
    // center中心对称点，right表示已探测的最右端位置
    int center = 0, right = 0;
    // 最长回文串的起始位置及长度
    int start = 0, maxLen = 0;
    // p数组记录所有已探测过的回文半径，后面我们再计算i时，根据p[i_mirror]计算i
    vector<int> p(len, 0);
    for(int i = 0; i < len; ++i) {
        /*根据i和right的位置分为两种情况：
         1、i<=right，利用已知的信息来计算i
         2、i>right，说明i的位置时未探测过的，只能用中心探测法
         */
        if(i <= right) {
            // 核心：减少不必要的探测，必须选择两者中的较小者作为左右探测起点
            int minExpandLen = min(right-i, p[2*center-i]);
            p[i] = calculateRadius(concatStr, i-minExpandLen, i+minExpandLen);
        } else {
            // i落在right右边，是没被探测过的，只能用中心探测法
            p[i] = calculateRadius(concatStr, i, i);
        }
        // 更新center、right
        if(right < i+p[i]) {
            center = i;
            right = i+p[i];
        }
        // 找到了一个更长的回文半径，更新原始字符串的start位置
        if(p[i] > maxLen) {
            maxLen = p[i];
            start = (i-p[i]) / 2;
        }
    }
    // 根据start和maxLen，从原始字符串中截取一段返回
    return s.substr(start, maxLen);
}

#pragma mark - 方法5-Manacher"马拉车"算法优化
string longestPalindrome5(string s) {
    // 字符串预处理，保证总长为奇数
    string concatStr;
    for (char ch : s) {
        concatStr += "#";
        concatStr += ch;
    }
    concatStr += "#";
    
    int len = (int)concatStr.length();
    
    // maxRight为当前访问到的所有回文子串，所能触及的最右一个字符的位置
    int center = 0, maxRight = 0;
    // 记录最长回文串的位置、长度
    int startIndex = 0, maxLen = 0;
    vector<int> p(len, 0);
    for (int i = 0; i < len; i++) {
        p[i] = i<maxRight ? min(p[2*center-i], maxRight-i) : 1;
        
        // 尝试扩展p[i]，注意处理边界
        while (0<=i-p[i] &&
               i+p[i]<len &&
               concatStr[i-p[i]]==concatStr[i+p[i]]) p[i]++;
        
        // 更新center、maxRight
        if (maxRight < i+p[i]-1) { // p[i]-1为回文半径
            center = i;
            maxRight = i+p[i]-1;
        }
        
        // 更新最长回文子串位置、长度
        if (maxLen <= p[i]-1) {
            maxLen = p[i]-1;
            startIndex = (i-maxLen)/2;
        }
    }
    
    return s.substr(startIndex, maxLen);
}

void test() {
    // 中心点为1个
    // cout << longestPalindrome("adbdl") << endl;
    // 中心点为2个
    cout << longestPalindrome5("cbbd") << endl;
}
