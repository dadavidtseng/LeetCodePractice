class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numIndexMap;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int difference = target - nums[i];

            if (numIndexMap.find(difference) != numIndexMap.end()) {
                return std::vector<int>{numIndexMap[difference], i};
            }

            numIndexMap[nums[i]] = i;
        }
        return {};
    }
};