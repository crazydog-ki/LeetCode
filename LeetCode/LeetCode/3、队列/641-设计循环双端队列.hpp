// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <queue>
#include <vector>


#pragma mark - 方法一: 循环数组
class MyCircularDeque {
private:
    vector<int> queue;
    int rear;
    int front;
    int size;
    int capacity;
public:
    /// 初始化数据机构, 设置队列长度为k
    MyCircularDeque(int k) {
        queue = vector<int>(k, -1);
        rear = front = 0;
        size = 0;
        capacity = k;
    }
    
    /// 头部插入元素
    bool insertFront(int value) {
        if (isFull()) return false;
        size++;
        front = (front-1+capacity) % capacity; // 队首插入, front==0 => front==capacity-1
        queue[front] = value;
        return true;
    }
    
    /// 尾部插入元素
    bool insertLast(int value) {
        if (isFull()) return false;
        size++;
        queue[rear] = value; // rear指向尾部待插入位置
        rear = (rear+1) % capacity;
        return true;
    }
    
    /// 头部删除元素
    bool deleteFront() {
        if (isEmpty()) return false;
        size--;
        front = (front+1) % capacity;
        return true;
    }
    
    /// 尾部删除元素
    bool deleteLast() {
        if (isEmpty()) return false;
        size--;
        rear = (rear-1+capacity) % capacity;
        return true;
    }
    
    /// 访问队列头部元素
    int getFront() {
        return  isEmpty() ? -1 : queue[front];
    }
    
    /// 访问队列尾部元素
    int getRear() {
        return isEmpty() ? -1 : queue[(rear-1+capacity) % capacity];
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

