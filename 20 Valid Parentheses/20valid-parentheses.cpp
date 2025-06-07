class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                v.push(s[i]);
            } 
            else {
                if (v.empty() || (s[i] == ')' && v.top() != '(') ||
                    (s[i] == ']' && v.top() != '[') ||
                    (s[i] == '}' && v.top() != '{')) {

                    return false;

                    
                }
                else v.pop();
            
            }
            i++;
            
        }
        if (v.empty())
                return true;
            else
                return false;
                }
    };