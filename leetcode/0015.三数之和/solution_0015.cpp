// 暴力解法：时间复杂度为O(n^3)，空间复杂度为O(1)。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 首先排除数组长度小于3的输入，包括空值
        if (nums.size() < 3) return {};
      
        // 正常情况下
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) ans.push_back({ nums[i], nums[j], nums[k] });
                }
            }
        }
      
        // 给每个子向量排序
        for (int i = 0; i < ans.size(); ++i) 
            sort(ans[i].begin(), ans[i].end());
      
        // 排序并去除重复元素
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// 排序+双指针：
