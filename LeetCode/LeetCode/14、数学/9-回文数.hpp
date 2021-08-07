// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>

/**回文数
给你一个整数x，如果x是一个回文整数，返回 true；否则，返回false。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121是回文，而123不是。
 */

#pragma mark - 方法1-整数转字符串
bool isPalindrome1(int x) {
    string s = to_string(x);
    int len = (int)s.length();
    int i = 0, j = len-1;
    while (i < j) {
        if (s[i++] == s[j--]) continue;
        return false;
    }
    return true;
}

#pragma mark - 方法2-反转所有数字
bool isPalindrome2(int x) {
    if (x < 0) return false;
    
    int y = x;
    long ret = 0;
    while (x) {
        ret = ret*10+x%10;
        x = x / 10;
    }
    if (ret == y) return true;
    else return false;
}

#pragma mark - 方法3-反转一半数字
bool isPalindrome3(int x) {
    /// 处理临界情况
    if (x<0 || (0<x && x%10==0)) return false;
    
    int ret = 0;
    while (ret < x) {
        ret = ret*10 + x%10;
        x /= 10;
    }
    
    return x==ret || x==ret/10;
}

#pragma mark - 方法4-首尾成对去除
bool isPalindrome(int x) {
    if (x<0 || (0<x && x%10==0)) return false;
    
    int maxTen = 1;
    while (10 <= x/maxTen) maxTen *= 10;
    while (x) {
        int left = x/maxTen;
        int right = x%10;
        if (left != right) return false;
        x = (x%maxTen) / 10; /// 首尾相等，需去除
        maxTen /= 100;
    }
    return true;
}
