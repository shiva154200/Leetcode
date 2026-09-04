class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.length();
        int i = 0;
        
        while (i < n) {
          
            while (i < n && path[i] == '/') {
                i++;
            }
            
            if (i >= n) break;
            
            
            string token;
            while (i < n && path[i] != '/') {
                token += path[i];
                i++;
            }
            
           
            if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (token != ".") {
                stack.push_back(token);
            }
        }
        
        string result;
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};