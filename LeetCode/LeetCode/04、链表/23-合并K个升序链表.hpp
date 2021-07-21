// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"
#include <queue>

/**合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
 
提示：
1. k == lists.length
2. 0 <= k <= 10^4
3. 0 <= lists[i].length <= 500
4. -10^4 <= lists[i][j] <= 10^4
5. lists[i]按升序排列
6. lists[i].length的总和不超过10^4
 */

#pragma mark - 方法1-暴力法+两两合并
//ListNode* mergeTwoLists(ListNode* one, ListNode* two) {
//    ListNode* concat = new ListNode(-1);
//    ListNode* cur = concat;
//    while (one || two) {
//        if (!one) {
//            cur->next = two;
//            break;
//        }
//
//        if (!two) {
//            cur->next = one;
//            break;
//        }
//
//        if (one->val < two->val) {
//            cur->next = one;
//            one = one->next;
//        } else {
//            cur->next = two;
//            two = two->next;
//        }
//        cur = cur->next;
//    }
//    ListNode* ret = concat->next;
//    delete concat;
//    return ret;
//}

ListNode* mergeTwoLists(ListNode* one, ListNode* two) {
    if (!one) return two;
    if (!two) return one;
    
    if (one->val < two->val) {
        one->next = mergeTwoLists(one->next, two);
        return one;
    } else {
        two->next = mergeTwoLists(one, two->next);
        return two;
    }
}

ListNode* mergeKLists1(vector<ListNode*>& lists) {
    ListNode* ret = nullptr;
    for (ListNode* list: lists) {
        ret = mergeTwoLists(ret, list);
    }
    return ret;
}

#pragma mark - 方法2-分治+递归
ListNode* merge(vector<ListNode*>& lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = (l+r)>>1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
}

ListNode* mergeKLists2(vector<ListNode*>& lists) {
    return merge(lists, 0, (int)lists.size()-1);
}

#pragma mark - 方法3-队列
ListNode* mergeKLists3(vector<ListNode*>& lists) {
    int count = (int)lists.size();
    if (count == 0) return nullptr;
    if (count == 1) return lists[0];
    
    queue<ListNode*> Q;
    for (ListNode* list: lists) Q.push(list);

    while (1 < Q.size()) {
        ListNode* one = Q.front(); Q.pop();
        ListNode* two = Q.front(); Q.pop();
        Q.push(mergeTwoLists(one, two));
    }
    
    return Q.front();
}
