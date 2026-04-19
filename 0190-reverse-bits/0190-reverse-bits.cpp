class Solution {
public:
    int reverseBits(int n) {
        int result = 0;

        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1) {
                result |= (1 << (31 - i));
            }

            n = n >> 1;
        }

        return result;
    }
};