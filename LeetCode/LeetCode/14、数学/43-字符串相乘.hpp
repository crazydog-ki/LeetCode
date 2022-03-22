// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include <string>

/**字符串相乘
给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，它们的乘积也表示为字符串形式。
注意：不能使用任何内置的BigInteger库或直接将输入转换为整数。
 */
#pragma mark - 方法1-普通竖式
string addStrings(string &num1, string &num2) {
    int i = (int)num1.size()-1, j = (int)num2.size()-1, add = 0;
    string ret = "";
    while (0<=i || 0<=j || add!=0) {
        int x = 0<=i ? num1[i]-'0' : 0;
        int y = 0<=j ? num2[j]-'0' : 0;
        int tmp = x+y+add;
        ret.push_back(tmp%10);
        add = tmp/10;
        i--;
        j--;
    }
    reverse(ret.begin(), ret.end());
    for (auto &c : ret) c += '0';
    return ret;
}

string multiply1(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string ret = "";
    int m = (int)num1.size(), n = (int)num2.size();
    for (int i = n-1; 0 <= i; i--) {
        string curr;
        int add = 0;
        for (int j = n-1; i < j; j--) curr.push_back(0); /// 补0
        int y = num2[i] - '0';
        for (int j = m-1; 0 <= j; j--) {
            int x = num1[j]-'0';
            int product = x*y+add;
            curr.push_back(product%10);
            add = product/10;
        }
        while (add != 0) {
            curr.push_back(add%10);
            add /= 10;
        }
        reverse(curr.begin(), curr.end());
        for (auto &c : curr) c += '0'; /// 数字转字符串
        ret = addStrings(ret, curr);
    }
    return ret;
}

#pragma mark - 方法2-优化竖式
string multiply2(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int m = (int)num1.size(), n = (int)num2.size();
    vector<int> caches(m+n+1, 0);
    for (int j = n-1; 0 <= j; j--) {
        int v2 = num2[j]-'0';
        for (int i = m-1; 0 <= i; i--) {
            int v1 = num1[i]-'0';
            int idx = m+n-2-(j+i);
            caches[idx] += v1*v2;
        }
    }
    
    /// 寻找数组前面的'0'个数
    int zeroCount = 0;
    for (int p = m+n; 0 <= p; p--) {
        if (caches[p] == 0) zeroCount++;
        else break;
    }
    
    string ret = "";
    int add = 0;
    for (int k = 0; k < caches.size()-zeroCount; k++) {
        int v = caches[k]+add;
        ret.push_back(v%10);
        add = v/10;
    }
    while (add!=0) {
        ret.push_back(add%10);
        add = add/10;
    }
    reverse(ret.begin(), ret.end());
    for (auto &c : ret) c += '0'; /// 数字转字符串
    return ret;
}
