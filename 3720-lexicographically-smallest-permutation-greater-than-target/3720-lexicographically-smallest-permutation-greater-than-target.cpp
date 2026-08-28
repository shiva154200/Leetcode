class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[(c - 97)]++;
        }
        string ans = "";
        int i = 0;
        for (i; i < n; i++) {
            if (freq[target[i] - 97]) {
                freq[target[i] - 97]--;
                ans.push_back(target[i]);
            } else {
                int k = target[i] - 97;
                while (k < 26 && !freq[k]) {
                    k++;
                }
                int p=k;
                if (k == 26) {
                    cout << ans;

                    for (int j = 25; j >= 0; j--) {
                        for (int l = 0; l < freq[j]; l++) {
                            ans.push_back(char(j + 97));
                        }
                    }

                    int t = ans.size() - 2;
                    while (t >= 0) {
                        if (ans[t] < ans[t + 1])
                            break;
                        t--;
                    }
                    int k = t + 1;
                    if (t > -1) {
                        while (k < ans.size() && ans[t] < ans[k]) {
                            k++;
                        }
                        k--;
                        swap(ans[t], ans[k]);
                        sort(ans.begin() + t + 1, ans.end());

                       
                    }
                     if (ans > target)
                            return ans;

                        return "";
                }
               
                ans.push_back(char(k + 97));
                freq[k]--;
                for (int j = 0; j < 26; j++) {
                    for (int l = 0; l < freq[j]; l++) {
                        ans.push_back(char(j + 97));
                    }
                }
                return ans;
            }
        }
    
    if (i == n) {
        // next permutation of target
        int t = target.size() - 2;
        while (t >= 0) {
            if (target[t] < target[t + 1])
                break;
            t--;
        }
        int k = t + 1;
        if (t > -1) {
            while (k < target.size() && target[t] < target[k]) {
                k++;
            }
            k--;
            swap(target[t], target[k]);
            sort(target.begin() + t + 1, target.end());

            if (target == ans)
                return "";
            return target;
        }
    }
    return "";
}
}
;