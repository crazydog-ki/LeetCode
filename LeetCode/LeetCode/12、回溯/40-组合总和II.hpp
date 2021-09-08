// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**组合总和II
给定一个数组candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。
candidates中的每个数字在每个组合中只能使用一次。
注意：解集不能包含重复的组合。
 
提示:
1. 1 <= candidates.length <= 100
2.  1 <= candidates[i] <= 50
3. 1 <= target <= 30
 */

#pragma mark - 方法1-dfs回溯法
void dfs(vector<int> &candidates,
         int target,
         vector<vector<int>> &ret,
         vector<int> &path,
         int idx,
         int sum) {
    if (target < sum) return;
    else if (sum == target) {
        ret.push_back(path);
        return;
    }
    
    for (int i = idx; i < candidates.size(); i++) {
        /// 去重，多叉树同一层不重复
        if (idx<i && candidates[i]==candidates[i-1]) continue;
        
        int num = candidates[i];
        /// 剪枝，已排序可直接跳出
        if (target < sum+num) break;
        path.push_back(num);
        sum += num;
        dfs(candidates, target, ret, path, i+1, sum);
        path.pop_back();
        sum -= num;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    
    vector<vector<int>> ret;
    vector<int> path;
    int idx = 0, sum = 0;
    dfs(candidates, target, ret, path, idx, sum);
    return ret;
}
