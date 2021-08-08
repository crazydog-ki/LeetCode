// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <stack>

/**最长有效括号
给你一个只包含'('和')'的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 
提示：
1. 0 <= s.length <= 3 * 104
2. s[i] 为 '(' 或 ')'
 */
#pragma mark - 方法1-栈
int longestValidParentheses1(string s) {
    int len = (int)s.length(), maxLen = 0;
    stack<int> S; S.push(-1); /// 哨兵
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') S.push(i);
        else {
            S.pop();
            if (S.empty()) S.push(i); /// 栈顶"-1"被")"匹配，开启下一轮
            else maxLen = max(maxLen, i-S.top());
        }
    }
    return maxLen;
}

#pragma mark - 方法2-动态规划
int longestValidParentheses2(string s) {
    int len = (int)s.length(), maxLen = 0;
    /// dp[i]代表以第i个字符结尾的最长有效括号
    vector<int> dp(len, 0);
    for (int i = 1; i < len; i++) { /// dp[0]恒为0
        if (s[i] == '(') continue;
        else if (s[i] == ')') {
            if (0<=i-dp[i-1]-1 && s[i-dp[i-1]-1] == '(')
                dp[i] = ((0<=i-dp[i-1]-2)?dp[i-dp[i-1]-2]:0) + dp[i-1] + 2;
            
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

#pragma mark - 方法3-正反逆序
int longestValidParentheses(string s) {
    int len = (int)s.length(), maxLen = 0;
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') leftCount++;
        else rightCount++;
        
        if (rightCount == leftCount) maxLen = max(maxLen, leftCount+rightCount);
        /// 中间被分隔，开启下一轮
        else if (leftCount < rightCount) leftCount = rightCount = 0;
    }
    
    leftCount = rightCount = 0;
    
    for (int i = len-1; 0 <= i; i--) {
        if (s[i] == ')') rightCount++;
        else leftCount++;
        
        if (leftCount == rightCount) maxLen = max(maxLen, leftCount+rightCount);
        else if (rightCount < leftCount) leftCount = rightCount = 0;
    }
    
    return maxLen;
}
