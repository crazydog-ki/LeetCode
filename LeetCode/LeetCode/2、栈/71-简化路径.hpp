// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <string>
#include <vector>

#pragma mark - 方法三: 版本三 => 最优空间复杂度
string simplifyPath3(string path) {
    string dirs;
    for (auto i = path.begin(); i != path.end();) {
        i++;
        auto j = find(i, path.end(), '/'); // 找到'/'对应的指针
        auto dir = string(i, j); // 截取两个'/'之间的内容
        if (!dir.empty() && dir != ".") { // 连续的///dir为空
            if (dir == ".." ) { // 删除前一个目录
                if (dirs.empty()) continue;
                while (dirs.back() != '/') dirs.pop_back();
                dirs.pop_back();
            } else { // dir追加到dirs后边
                dirs += "/";
                dirs += dir;
            };
        }
        i = j;
    }
    return dirs.empty() ? "/" : dirs;
}

#pragma mark - 方法二: 版本二
string simplifyPath2(string path) {
    // 1. 将目录拆分出来
    vector<string> dirs;
    for (auto i = path.begin(); i != path.end();) {
        i++;
        auto j = find(i, path.end(), '/'); // 找到'/'对应的指针
        auto dir = string(i, j); // 截取两个'/'之间的内容
        if (!dir.empty() && dir != ".") { // 连续的///dir为空
            if (dir == ".." ) {
                if (!dirs.empty()) dirs.pop_back();
            }
            else dirs.push_back(dir);
        }
        i = j;
    }
    
    // 2. 目录整合到字符串中, 返回
    string res;
    if (dirs.empty()) res += '/';
    else {
        for (auto dir: dirs) {
            res += '/';
            res += dir;
        }
    }
    return res;
}

#pragma mark - 方法一: 版本一
string readString(string str, int idx) {
    string res;
    for (int i = idx; i < str.length(); i++) {
        if (str[i]!='/' && str[i]!='.') res += str[i]; // 读取字母
        else if (str[i] == '.') res += str[i]; // 读取"."或者".."
        else break;
    }
    return res;
}

string simplifyPath1(string path) {
    string res;
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '/') continue; // 斜杠
        else if (path[i] == '.') { // 点
            int tmpLength = (int)readString(path, i).length();
            if (tmpLength == 1) continue; // 一个点
            else if (tmpLength == 2) { // 两个点
                if (res.length() == 0) continue;
                while (res.back() != '/') res.pop_back();
                res.pop_back();
                i += 1;
            } else if (2 < tmpLength) { // 大于两个点
                res += '/';
                res += readString(path, i);
                i += tmpLength;
            }
        }
        else { // 单词
            res += '/';
            res += readString(path, i);
            i += readString(path, i).length();
        }
    }
    if (res.front() != '/') res.insert(res.begin(), '/');
    return res;
}

void test() {
    // cout << readString("/usr/home//..//./my", 1) << endl;
    cout << simplifyPath3("/usr/home//..//./my") << endl;
}
