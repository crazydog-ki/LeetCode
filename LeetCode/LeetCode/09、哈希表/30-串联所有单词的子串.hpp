// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <unordered_map>

/**串联所有单词的子串
给定一个字符串s和一些长度相同的单词words。找出s中恰好可以由words中所有单词串联形成的子串的起始位置。
注意子串要与words中的单词完全匹配，中间不能有其他字符，但不需要考虑words中单词串联的顺序。

提示：
1. 1 <= s.length <= 104
2. s 由小写英文字母组成
3. 1 <= words.length <= 5000
4. 1 <= words[i].length <= 30
5. words[i] 由小写英文字母组成
 */
#pragma mark - 方法1-哈希+大串遍历截取
vector<int> findSubstring1(string s, vector<string>& words) {
    vector<int> ret;
    int wCount = (int)words.size();
    if (wCount == 0) return ret;
    
    /// 构建映射
    unordered_map<string, int> M, tmpM;
    for (string& word : words) M[word]++;

    int sLen = (int)s.length();
    int wordLen = (int)words[0].length();
    int totalLen = wordLen*wCount;
    
    for (int i = 0; i < sLen-totalLen+1; i++) {
        int j = i;
        while (j < i+totalLen) {
            string str = s.substr(j, wordLen);
            if (M.find(str) == M.end()) break; /// 不存在
            tmpM[str]++;
            j += wordLen;
        }
        if (M == tmpM) ret.push_back(i);
        tmpM.clear();
    }
    
    return ret;
}

#pragma mark - 方法2-哈希+双指针+滑动窗口
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    int wCount = (int)words.size();
    if (wCount == 0) return ret;
    
    /// 构建映射
    unordered_map<string, int> M, tmpM;
    for (string& word : words) M[word]++;

    int sLen = (int)s.length();
    int wordLen = (int)words[0].length();
    
    for (int i = 0; i < wordLen; i++) {
        int l = i, r = i, count = 0; /// 判定[l, r]滑动区间
        while (r+wordLen <= sLen) {
            string rStr = s.substr(r, wordLen);
            r += wordLen;
            if (M.find(rStr) == M.end()) { /// 剪枝
                count = 0;
                l = r;
                tmpM.clear();
                continue;
            }
            
            tmpM[rStr]++;
            count++;
            while (M[rStr] < tmpM[rStr]) { /// 移动左指针
                string lStr = s.substr(l, wordLen);
                tmpM[lStr]--;
                l += wordLen;
                count--;
            }
            if (count == wCount) ret.push_back(l);
        }
        tmpM.clear();
    }
    return ret;
}
