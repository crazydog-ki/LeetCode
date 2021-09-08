// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**组合总和
给定一个无重复元素的正整数数组candidates和一个正整数target，找出candidates中所可以使数字和为目标数target的唯一组合。
 
candidates中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。
对于给定的输入，保证和为target的唯一组合数少于150个。

提示：
1. 1 <= candidates.length <= 30
2. 1 <= candidates[i] <= 200
3. candidate 中的每个元素都是独一无二的。
4. 1 <= target <= 500
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
        int num = candidates[i];
        /// 剪枝 已排序可直接跳出
        if (target < sum+num) break;
        path.push_back(num);
        sum += num;
        dfs(candidates, target, ret, path, i, sum);
        path.pop_back();
        sum -= num;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    
    vector<vector<int>> ret;
    vector<int> path;
    int idx = 0, sum = 0;
    dfs(candidates, target, ret, path, idx, sum);
    return ret;
}
