// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "24-两两交换链表中的节点.hpp"

void test() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    ListNode* ret = swapPairs(l1);
    printNode(ret);
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
