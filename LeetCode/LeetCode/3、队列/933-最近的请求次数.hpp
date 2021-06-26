// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <queue>

#pragma mark - 方法一: 队列
class RecentCounter {
private:
    queue<int> Q;
public:
    RecentCounter() { }
    
    int ping(int t) {
        Q.push(t);
        while (3000 < t-Q.front()) Q.pop();
        return (int)Q.size();
    }
};
