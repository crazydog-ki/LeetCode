// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <string>
#include <stack>

#pragma mark - 方法二: 优化, 字符串从后往前一遍遍历, 维护#的个数count
bool isValidSerialization(string preorder) {
    int count = 0;
    int length = (int)preorder.length();
    for (int i = length-1; 0 <= i; i--) {
        if (preorder[i] == ',') continue;
        else if (preorder[i] == '#') count++;
        else {
            while (0<=i && preorder[i]!=',') i--;
            if (2 <= count) count--;
            else return false;
        }
    }
    return count==1;
}

#pragma mark - 方法一: 栈
bool isValidSerialization1(string preorder) {
    stack<char> S;
    for (int i = 0; i < preorder.size(); i++) {
        if (preorder[i] == ',') continue; // 逗号
        else if (isdigit(preorder[i])) { // 数字, 可能是多位数 => 这里只需要把多位数第一位入栈即可
            S.push(preorder[i]);
            while (isdigit(preorder[i])) i++; // 跳过多位数
        }
        else { // #号
            if (S.empty() || S.top() != '#') S.push(preorder[i]); // 栈顶是数字
            else if (S.top() == '#') { // 连续两个#号
                while (!S.empty() && S.top() == '#') {
                    S.pop(); // #出栈
                    if (S.empty()) return false;
                    S.pop(); // 数字出栈
                }
                S.push('#');
            }
        }
    }
    return S.size()==1 && S.top() == '#';
}

void test() {
    cout << isValidSerialization("#") << endl;
    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
}
