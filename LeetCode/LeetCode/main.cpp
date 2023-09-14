// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#include "88-合并两个有序数组.hpp"

int main(int argc, const char * argv[]) {
//    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//    ListNode *l1 = new ListNode(1);
//    ListNode *l2 = new ListNode(2);
//    ListNode *l3 = new ListNode(2);
//    ListNode *l4 = new ListNode(3);
//    ListNode *l5 = new ListNode(4);
//    ListNode *l6 = new ListNode(4);
//    ListNode *l7 = new ListNode(5);
//    l1->next = l2;
//    l2->next = l3;
//    l3->next = l4;
//    l4->next = l5;
//    l5->next = l6;
//    l6->next = l7;
    
//    vector<int> nums1 = {1,2,3,4,5,-1,-1,-1,-1,-1};
//    vector<int> nums2 = {2,2,4,5,6};
    
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    
    merge(nums1, 1, nums2, 1);
    return 0;
}
