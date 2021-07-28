// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "27-移除元素.hpp"

void test() {
    vector<int> nums = {1, 1, 2, 3, 4, 4, 4};
    int ret = removeElement(nums, 1);
    printVectors(nums);
    cout << ret << endl;
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
