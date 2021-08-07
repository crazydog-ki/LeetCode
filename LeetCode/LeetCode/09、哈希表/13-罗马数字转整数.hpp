// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <map>

/**罗马数字转整数
罗马数字包含以下七种字符：I、V、X、L、C、D和M。

 字符          数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
例如，罗马数字2写做II，即为两个并列的1。12写做XII，即为X+II。27写做XXVII，即为XX+V+II。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如4不写做IIII，而是IV。数字 1在数字5的左边，所表示的数等于大数5减小数1得到的数值4。同样地，数字9 表示为IX。这个特殊的规则只适用于以下六种情况：

I可以放在V(5)和X(10)的左边，来表示4和9。
X可以放在L(50)和C(100)的左边，来表示40和90。
C可以放在D(500)和M(1000)的左边，来表示400和900。
给定一个罗马数字，将其转换成整数。输入确保在1到3999的范围内。
 
提示：
1. 1 <= s.length <= 15
2. s仅含字符('I', 'V', 'X', 'L', 'C', 'D', 'M')
3. 题目数据保证s是一个有效的罗马数字，且表示整数在范围[1, 3999]内
4. 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
5. IL和IM这样的例子并不符合题目要求，49应该写作XLIX，999应该写作CMXCIX。
 */

#pragma mark - 方法1-哈希
int romanToInt1_1(string s) {
    map<char, int> romanMap = {
        {'M', 1000},
        {'D',  500},
        {'C',  100},
        {'L',   50},
        {'X',   10},
        {'V',    5},
        {'I',    1},
    };
    
    int sLen = (int)s.length(), ret = 0;
    int pre = romanMap[s[0]];
    for (int i = 1; i < sLen; i++) {
        int num = romanMap[s[i]];
        if (pre < num) {
            ret -= pre;
        } else {
            ret += pre;
        }
        pre = num;
    }
    ret += pre;
    return ret;
}

int romanToInt1_2(string s) {
    map<char, int> romanMap = {
        {'M', 1000},
        {'D',  500},
        {'C',  100},
        {'L',   50},
        {'X',   10},
        {'V',    5},
        {'I',    1},
        {'\0',   0} /// string数组越界会取该值
    };
    
    int sLen = (int)s.length(), ret = 0;
    for (int i = 0; i < sLen; i++) {
        int v1 = romanMap[s[i]];
        int v2 = romanMap[s[i+1]];
        if (v1 < v2) ret -= v1;
        else ret += v1;
    }
    return ret;
}

#pragma mark - 方法2-暴力法
int romanToInt(string s) {
    char ch = s[5];
    cout << ch << endl;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'M':sum += 1000; break;
            case 'D':sum += 500; break;
            case 'C': {
                if (s[i+1] == 'D'|| s[i+1] == 'M') {
                    sum -= 100;
                } else {
                    sum += 100;
                }
            } break;
            case 'L':sum += 50; break;
            case 'X': {
                if (s[i+1] == 'L' || s[i+1] == 'C') {
                    sum -= 10;
                } else {
                    sum += 10;
                }
            } break;
            case 'V':sum += 5; break;
            case 'I': {
                if (s[i+1]=='I' || i==s.length()-1) {
                    sum += 1;
                } else {
                    sum -= 1;
                }
            } break;
            default:
                break;
        }
    }
    return sum;
}
