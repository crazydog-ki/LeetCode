// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>

/**括号生成
数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。
 
提示：
1. 1 <= n <= 8
 */

#pragma mark - 方法1-DFS
void dfs(vector<string>& ret,
         string& item,
         int left,
         int right,
         int n) {
    if (item.length() == 2*n) {
        ret.push_back(item);
        return;
    }
    
    if (left < n) {
        item.push_back('(');
        dfs(ret, item, left+1, right, n);
        item.pop_back();
    }
    
    if (right < left) {
        item.push_back(')');
        dfs(ret, item, left, right+1, n);
        item.pop_back();
    }
}

vector<string> generateParenthesis1(int n) {
    vector<string> ret;
    string item;
    int left = 0, right = 0;
    dfs(ret, item, left, right, n);
    return ret;
}

#pragma mark - 方法2-动态规划
/**状态方程
dp[i]表示i对括号所产生的有效组合
dp[i] = "("+dp[m]+")"+dp[k]，其中i=m+k+1
 */
vector<string> generateParenthesis2(int n) {
    vector<vector<string>> dp(n+1);
    vector<string> dp0;
    dp0.push_back("");
    dp[0] = dp0;
    for (int i = 1; i <= n; i++) { /// 求dp[n]
        vector<string> cur;
        for (int m = 0; m < i; m++) {
            int k = i-1-m;
            vector<string> str1 = dp[m];
            vector<string> str2 = dp[k];
            for (string& s1: str1) { /// 遍历dp[m]和dp[k]所有情况
                for (string& s2: str2) {
                    cur.push_back("("+s1+")"+s2);
                }
            }
        }
        dp[i] = cur;
    }
    return dp[n];
}

#pragma mark - 方法3-动态规划+递归
vector<string> generateParenthesis(int n) {
    vector<string> ret;
    if (n == 0) {
        ret.push_back("");
        return ret;
    }
    
    for (int m = 0; m < n; m++) {
        int k = n-m-1;
        vector<string> ll = generateParenthesis(m);
        vector<string> rr = generateParenthesis(k);
        for (string& l: ll) {
            for (string& r: rr) {
                ret.push_back("("+l+")"+r);
            }
        }
    }
    return ret;
}
