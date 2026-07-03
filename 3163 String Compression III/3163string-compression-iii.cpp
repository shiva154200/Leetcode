class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int ct = 0;
        char ch = word[0];
        for (int i = 0 ; i < word.size(); i++) {
            if (word[i] == ch)
                ct++;
            else {
                while (ct > 9) {
                    ans.push_back('9');
                    ans.push_back(ch);
                    ct -= 9;
                }
                if (ct) {
                    ans += to_string(ct);
                    ans.push_back(ch);
                }
                ct = 1;
                ch = word[i];
            }
        }
        while (ct > 9) {
            ans.push_back('9');
            ans.push_back(ch);
            ct -= 9;
        }
        if (ct) {
            ans += to_string(ct);
            ans.push_back(ch);
        }

        return ans;
    }
};

