// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**加一
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 最高位数字存放在数组的首位，数组中每个元素只存储单个数字。
 你可以假设除了整数0之外，这个整数不会以零开头。
 **/
#pragma mark - 方法1-常规
vector<int> plusOne(vector<int>& digits) {
    int len = (int)digits.size();
    for (int i = len-1; 0 <= i; i--) {
        if (digits[i] != 9) {
            ++digits[i];
            for (int j = i+1; j < len; j++) {
                digits[j] = 0;
            }
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    //所有元素为9的情况
    digits.insert(digits.begin(), 1);
    return digits;
}
