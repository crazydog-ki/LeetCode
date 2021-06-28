// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <map>

/**整数转罗马数字
 罗马数字包含以下七种字符：I、V、X、L、C、D和M。
字符           数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 例如，罗马数字2写做II，即为两个并列的1；
      罗马数字12写做XII，即为X+II；
      罗马数字27写做XXVII，即为XX+V+II。

 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如4不写做IIII，而是IV。数字 1在数字5的左边，所表示的数等于大数5减小数1得到的数值4。同样地，数字9 表示为IX。这个特殊的规则只适用于以下六种情况：

 I可以放在V(5)和X(10)的左边，来表示4和9。
 X可以放在L(50)和C(100)的左边，来表示40和90。
 C可以放在D(500)和M(1000)的左边，来表示400和900。
 给你一个整数，将其转为罗马数字。
 
 提示：
 （1）1 <= num <= 3999
 */

#pragma mark - 方法1-硬编码数字
string intToRoman1(int num) {
    const string thousands[] = {"", "M", "MM", "MMM"};
    const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    return thousands[num/1000] + hundreds[num%1000/100] + tens[num%100/10] + ones[num%10];
}

#pragma mark - 方法2-哈希+贪心
// 注：这里之所以称之为贪心，是因为每次num每次都会减去最大的值，直至为0
string intToRoman(int num) {
    const pair<int, string> romanMap[] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
    };
    
    string ret = "";
    // 关键：遍历哈希表
    for (const auto &[val, symbol] : romanMap) {
        while (val <= num) {
            num -= val;
            ret += symbol;
        }
        if (num==0) break;
    }
    return ret;
}

void test() {
    cout << intToRoman(1994) << endl;
}
