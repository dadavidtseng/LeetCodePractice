class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs{{'(', ')'}, {'[', ']'}, {'{', '}'}};

        stack<char> stack;

        for (char c : s) {
            if (pairs.find(c) != pairs.end())
                stack.push(pairs[c]);

            else {
                if (stack.empty() || stack.top() != c)
                    return false;

                stack.pop();
            }
        }

        return stack.empty();
    }
};