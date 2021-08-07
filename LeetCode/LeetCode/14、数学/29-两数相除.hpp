// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

/**两数相除
给定两个整数，被除数dividend和除数divisor。将两数相除，要求不使用乘法、除法和mod运算符。
返回被除数dividend除以除数divisor得到的商。
整数除法的结果应当截去（truncate）其小数部分，例如：
truncate(8.345) = 8
truncate(-2.7335) = -2
 
提示：
1. 被除数和除数均为32位有符号整数。
2. 除数不为0。
3. 假设我们的环境只能存储32位有符号整数，其数值范围是[−2^31, 2^31−1]。本题中，如果除法结果溢出，则返回2^31−1。
 */
#pragma mark - 方法1-位运算
int divide1(int dividend, int divisor) {
    long ret = 0, up = abs(dividend), down = abs(divisor);
    while (down <= up) {
        long count = 1, base = down;
        while((base<<1) < up) { /// 优化减法次数
            count <<= 1;
            base <<= 1;
        }
        ret += count;
        up -= base;
    }
    ret = ((dividend<0)^(divisor<0)) ? -ret : ret; /// ^异或
    return (INT_MAX<ret || ret<INT_MIN) ? INT_MAX : (int)ret;
}

#pragma mark - 方法2-递归
int minusCount(int a, int b) {
    if (a < b) return 0;
    int ret = 1;
    int val = b;
    while (val <= a-val) {
        ret += ret;
        val += val;
    }
    return ret + minusCount(a-val, b);
}

/// Note: INT_MIN = −2^31, INT_MAX = 2^31−1
int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    else if (divisor == 1) return dividend;
    else if (divisor == -1) return (dividend==INT_MIN) ? INT_MAX : -dividend;
    
    int a = dividend;
    int b = divisor;
    int ret = 0;
    bool isPositive = ((0<a && 0<b) || (a<0 && b<0));
    if (b == INT_MIN) return (a==INT_MIN) ? 1 : 0; /// "除数"特殊情况
    if (a == INT_MIN) { /// "被除数"特殊情况，能确保-b有意义
        a = (isPositive) ? a-b : a+b;
        ++ret;
    }
    /// -a及-b能确保有意义
    a = (0<a) ? a : -a;
    b = (0<b) ? b : -b;
    ret += minusCount(a, b);
    return isPositive ? ret : -ret;
}

