class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool bIsDuplicate = false;

        unordered_set<int> container;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {

            if (container.find(nums[i]) != container.end()) {
                bIsDuplicate = true;
                return bIsDuplicate;
            }

            container.insert(nums[i]);
        }

        return bIsDuplicate;
    }
};