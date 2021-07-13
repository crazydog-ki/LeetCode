// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>

/**字符串转换整数 (atoi)
请你来实现一个myAtoi(string s)函数，使其能将字符串转换成一个32位有符号整数（类似C/C++ 中的atoi函数）。

函数myAtoi(string s)的算法如下：
1. 读入字符串并丢弃无用的前导空格
2. 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。如果两者都不存在，则假定结果为正。
3. 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
4. 将前面步骤读入的这些数字转换为整数（即，"123" -> 123，"0032" ->      32）。如果没有读入数字，则整数为0。必要时更改符号（从步骤2开始）。
5. 如果整数数超过32位有符号整数范围[−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于−2^31的整数应该被固定为−2^31 ，大于2^31 − 1 的整数应该被固定为2^31 − 1 。
6. 返回整数作为最终结果。
 
注意：
1. 本题中的空白字符只包括空格字符' ' 。
2. 除前导空格或数字后的其余字符串外，请勿忽略任何其他字符。
 */
int myAtoi(string s) {
    int len = (int)s.length();
    int idx = 0;
    
    // 前导空格
    while (idx<len && s[idx]==' ') idx++;
    
    // 正负号
    int flag = 1;
    if (s[idx] == '+') {
        idx++;
    } else if (s[idx] == '-') {
        idx++;
        flag = -1;
    }
    
    // 数字
    long ret = 0;
    while (idx < len && isdigit(s[idx])) {
        ret = ret*10+(s[idx]-'0');
        // 处理临界
        if (flag*ret<=INT_MIN || INT_MAX<=flag*ret) return 0<flag ? INT_MAX : INT_MIN;
        idx++;
    }
    return (int)flag*ret;
}

