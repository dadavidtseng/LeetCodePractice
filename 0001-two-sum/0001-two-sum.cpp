class Solution {
public:
    vector<int> twoSum(vector<int> const& nums, int const target) {
        unordered_map<int, int> numIndexMap;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int difference = target - nums[i];

            if (numIndexMap.find(difference) != numIndexMap.end()) {
                return {numIndexMap[difference], i};
            }

            numIndexMap[nums[i]] = i;
        }

        return {};
    }
};