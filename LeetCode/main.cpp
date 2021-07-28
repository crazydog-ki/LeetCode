// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "26-删除有序数组中的重复项.hpp"

void test() {
    vector<int> nums = {0, 1, 1, 2, 3, 4, 4, 4};
    int ret = removeDuplicates(nums);
    printVectors(nums);
    cout << ret << endl;
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
