// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 双指针
vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0;
    int j = (int)numbers.size() - 1;
    vector<int> res(2, -1);
    while (i < j) {
        if (numbers[i] + numbers[j] == target) {
            res[0] = i + 1;
            res[1] = j + 1;
            return res;
        }
        else if (numbers[i] + numbers[j] < target) i++;
        else j--;
    }
    return res;
}
