class Solution {
public:
    static bool isPalindrome(int x)
    {
        if (x==0)return true;
        if (x < 0) return false;
        if (x % 10 == 0) return false;

        unordered_map<int, int> m;
        int                     mapIndex = 0;
        int                     temp    = x;


        while (temp > 0)
        {
            int digit = (temp % 10);
            m.insert({mapIndex, digit});

            temp /= 10;
            mapIndex++;
        }
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            printf("%d, %d\n", it->first, it->second);
        }



        for (int i = 0; i < (int)m.size() / 2; i++)
        {
            int a      = m[i];
            int b = m[(int)m.size() - i - 1];
            if (a != b)
            {
                return false;
            }
        }



        return true;
    }
};