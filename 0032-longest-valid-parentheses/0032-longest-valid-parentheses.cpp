class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;

        // Left to right
        for (char ch : s) {
            if (ch == '(')
                left++;
            else
                right++;

            if (left == right)
                maxLength = max(maxLength, 2 * right);

            else if (right > left)
                left = right = 0;
        }

        // Right to left
        left = 0;
        right = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxLength = max(maxLength, 2 * left);

            else if (left > right)
                left = right = 0;
        }

        return maxLength;
    }
};