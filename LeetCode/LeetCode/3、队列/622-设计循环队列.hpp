// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <queue>
#include <vector>

#pragma mark - 方法一: 数组
class MyCircularQueue {
private:
    vector<int> queue;
    int size;
    int rear;
    int front;
public:
    /// 初始化数据机构, 设置队列长度为k
    MyCircularQueue(int k) {
        queue = vector<int>(k, -1);
        rear = front = -1;
        size = 0;
    }
    
    /// 插入
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear+1) % queue.size();
        queue[rear] = value;
        if (size == 0) front = rear;
        size++;
        return true;
    }
    
    /// 删除
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front+1) % queue.size();
        size--;
        return true;
    }
    
    /// 访问队首元素
    int Front() {
        return !isEmpty() ? queue[front] : -1;
    }
    
    /// 访问队尾元素
    int Rear() {
        return !isEmpty() ? queue[rear] : -1;
    }
    
    /// 判空
    bool isEmpty() {
        return size == 0;
    }
    
    /// 判满
    bool isFull() {
        return size == queue.size();
    }
};

void test() {
    MyCircularQueue *Q = new MyCircularQueue(3);
    Q->enQueue(1);
    Q->enQueue(2);
    cout << Q->enQueue(3) << endl;
    cout << Q->enQueue(4) << endl;
    cout << Q->Front() << endl;
    cout << Q->Rear() << endl;
    Q->deQueue();
    cout << Q->Front() << endl;
    cout << Q->Rear() << endl;
}

