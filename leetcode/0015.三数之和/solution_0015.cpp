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
                    if (nums[i] + nums[j] + nums[k] == 0)
                        ans.push_back({ nums[i], nums[j], nums[k] });
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

// 排序+双指针：时间复杂度为O(n^2)，排序的时间复杂度小于两层循环，故取大的时间复杂度
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 考虑特殊情况
        int length = nums.size();
        if(length < 3) return {};

        // 设置返回的结果数组
        vector<vector<int>> result;
        
        // 对原数组进行排序，使得每个子数组都是以由小至大的顺序压入的
        sort(nums.begin(), nums.end());
        // 进行第一层循环，确定第一位数字
        for(int index = 0; index < length - 2; ++index){
            // 剪枝：如果第一位数字与上次的数字相同，则直接跳过
            if(0 < index && nums[index] == nums[index-1])
                continue;
            // 双指针：根据和目标值的大小，调整指针的移动，需要遍历整个子数组，时间复杂度为O(n)
            int left = index + 1, right = length - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum + nums[index] == 0) result.push_back({nums[index],nums[left],nums[right]});
                if(sum + nums[index] < 0) ++left;
                else --right;
            }
        }
        // 由于第一位数字不会重复，只会后两个数字指针在运动，所以每个重复的子数组会跟在其数组之后，不需要再次进行排序（已完成排序）
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};
