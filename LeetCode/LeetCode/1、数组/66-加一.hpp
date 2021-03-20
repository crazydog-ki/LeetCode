// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 对方法一的优化
vector<int> plusOne2(vector<int> &digits)  {
    int count = (int)digits.size();
    for (int i = count-1; 0 <= i; i--) {
        if (digits[i] != 9) { // 当前位不是9, 该位加1, 该位后面的位全部置为0
            digits[i]++;
            for (int j = i+1; j <= count-1; j++) {
                digits[j] = 0;
            }
            return digits;
        } else {  // 当前位是9
            continue;
        }
    }
    
    // 来到这里, 说明是999...这种形式, 在index==0插入1, 其他位全部置为0
    digits.insert(digits.begin(), 1);
    for (int i = 1; i <= count; i++) {
        digits[i] = 0;
    }
    return digits;
}

#pragma mark - 方法一: 逆序常规操作
vector<int> plusOne(vector<int> &digits) {
    int count = (int)digits.size();
    if (count == 1) digits[0]++;
    
    // 处理index: 1~count-1
    for (int i = count-1; 0 < i; i--) {
        if (digits[i] == 10) { // 当前位为10, 当前位置1, 前一位加1
            digits[i] = 0;
            digits[i-1]++;
        } else if (digits[i] == 9 && i == count-1) { // 当前位为9, 并且是最后一位 => 当前位置0, 前一位加1
            digits[i] = 0;
            digits[i-1]++;
        } else {
            if (i == count-1) digits[i]++;
            return digits;
        }
    }
    
    // 处理index: 0
    if (digits[0] == 10) {
        digits[0] = 0;
        digits.insert(digits.begin(), 1);
    }
    
    return digits;
}


void test() {
    // vector<int> digits = {2, 4, 9, 9, 9};
    vector<int> digits = {9};
    plusOne2(digits);
    printVectors(digits);
}
