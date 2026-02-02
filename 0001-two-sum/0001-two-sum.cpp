class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index_map;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            auto difference = target - nums[i];
            
            if (num_index_map.find(difference) != num_index_map.end())
                return {num_index_map[difference], i};

            num_index_map[nums[i]] = i;
        }

        throw invalid_argument("No two elements add up to the target.");
    }
};