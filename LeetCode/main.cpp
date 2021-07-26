// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "25-K个一组翻转链表.hpp"

void test() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
//    ListNode* l6 = new ListNode(6);
//    ListNode* l7 = new ListNode(7);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
//    l5->next = l6;
//    l6->next = l7;
    ListNode* ret = reverseKGroup(l1, 3);
    printNode(ret);
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
