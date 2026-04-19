class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

for (int i = 0; i < n+1; i++)
{
    result.push_back(hammingWeight(i));
}

return result;
    }

    int hammingWeight(int n) {

        int count = 0;

        //for (int i = 0; i < 32; i++)
        //{
        //    if ((n & 1)  == 1)
        //    {
        //        count++;
        //    }

        //    n = n >> 1;
        //}

        while (n != 0)
        {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};