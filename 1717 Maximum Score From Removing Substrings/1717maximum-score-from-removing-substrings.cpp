class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper to remove all "first+second" patterns and get the gained score
        auto removePattern = [](string& str, char first, char second, int value) {
            string stack;
            int score = 0;
            for (char ch : str) {
                if (!stack.empty() && stack.back() == first && ch == second) {
                    stack.pop_back();  // remove the pattern
                    score += value;
                } else {
                    stack.push_back(ch);
                }
            }
            str = stack;  // update the string with remaining characters
            return score;
        };
        
        int total = 0;

        // Always remove the higher-scoring pattern first
        if (x > y) {
            total += removePattern(s, 'a', 'b', x);
            total += removePattern(s, 'b', 'a', y);
        } else {
            total += removePattern(s, 'b', 'a', y);
            total += removePattern(s, 'a', 'b', x);
        }

        return total;
    }
};



