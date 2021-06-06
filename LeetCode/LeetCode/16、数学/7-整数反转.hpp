// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

/**整数反转
 给你一个32位的有符号整数x，返回将x中的数字部分反转后的结果。
 如果反转后整数超过32位的有符号整数的范围[−2^31,  2^31 − 1] ，就返回0。
 */
int reverse(int x) {
    long ret = 0;
    while (x) {
        ret = ret*10+x%10;
        x /= 10;
    }
    // 处理临界情况
    if (ret<INT_MIN || INT_MAX<ret) ret = 0;
    return (int)ret;
}

void test() {
    cout << reverse(-12340) << endl;
}
