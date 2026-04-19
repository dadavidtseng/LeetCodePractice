class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t n = nums.size(); // [0,n] range
        int result = n;
        for (size_t i = 0; i < n; i++) {
            result ^= i ^ nums[i];
        }

        return result;
    }
};