class Solution {
public:
    int maxArea(vector<int>& height) {
        int const size = static_cast<int>(height.size());
        int result = 0;
        int left = 0;
        int right = size - 1;

        while (left < right) {
            int area = 0;

            if (height[left] < height[right]) {
                area = (right - left) * height[left];
                left++;
            } else if (height[left] > height[right]) {
                area = (right - left) * height[right];
                right--;
            } else {
                area = (right - left) * height[left];
                left++;
                right--;
            }

            result = max(result, area);
        }

        return result;
    }
};