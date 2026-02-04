class Solution {
public:
    static bool isPalindrome(int x)
    {
        if (x == 0) return true;
        if (x < 0) return false;
        if (x % 10 == 0) return false;

        int reversed = 0;

        // reversed * 10 moves the number one digit left.
        // x % 10 gets the last digit.
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;

            x /= 10;    // Get rid of the last digit and move the number one digit right.
        }

        return x == reversed || x == reversed / 10;
    }
};