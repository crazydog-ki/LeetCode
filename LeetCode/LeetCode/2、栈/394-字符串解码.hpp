// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <string>
#include <stack>

#pragma mark - 方法一: 栈
string decodeString(string s) {
    stack<int> nums;
    stack<string> strs;
    int num = 0;
    string str = "";
    int times = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) num = 10*num+s[i]-'0'; // 数字
        else if (isalpha(s[i])) str += s[i]; // 字母
        else if (s[i] == '[') { // 左括号
            nums.push(num);
            num = 0;
            strs.push(str);
            str = "";
        }
        else { // 右括号
            times = nums.top();
            nums.pop();
            while (times--) strs.top() += str;
            str = strs.top();
            strs.pop();
        }
    }
    return str;
}

void test() {
    // cout << decodeString("") << endl;
    cout << decodeString("3[a2[c]]") << endl;
    // cout << decodeString("2[abc]3[cd]ef") << endl;
    // cout << decodeString("3[a]2[b4[F]c]") << endl;
}
