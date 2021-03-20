// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <queue>
#include <vector>

#pragma mark - 方法一: 贪心
int leastInterval(vector<char> &tasks, int n) {
    int size = (int)tasks.size();
    int count[26];
    memset(count, 0, sizeof(int)*26);
    // 1. 计数
    for (int i = 0; i < size; i++) count[tasks[i]-'A']++;
    int maxCount = count[0];
    // 2. 确定maxCount
    for (int i = 1; i < 26; i++)
        if (maxCount < count[i]) maxCount = count[i];
    // 3. 确定extraCount
    int extraCount = 0;
    for (int i = 0; i < 26; i++)
        if (count[i] == maxCount) extraCount++;
    return max((maxCount-1)*(n+1)+extraCount, size);
    // res大于size是其他非maxCount对应的字母可以填充空隙; res小于size说明字符数量很多, 更利于冷却时间n的实现
}

void test() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << leastInterval(tasks, 2) << endl;
}
