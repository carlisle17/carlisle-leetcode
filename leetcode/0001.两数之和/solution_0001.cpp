// 暴力解法：时间复杂度较高，两层循环。时间复杂度为O(n^2)，空间复杂度为O(1)。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
    }
};

// 哈希表：空间换时间。时间复杂度为O(n)，空间复杂度为O(n)。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> hashtable; // 采用键值对保存，key为数值，用以比较和是否为target；value为索引，用以返回题目要求的结果
        for (int i = 0; i < nums.size(); ++i){
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) // 如果查找成功，则返回该索引，与循环变量，即另一个数值
                return { it->second, i };
            hashtable[nums[i]] = i; // 如果查找不成功，则添加入哈希表
        }
        return {};
    }
};
