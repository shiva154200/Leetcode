// class Solution {
// public:
 
//     vector<string> removeSubfolders(vector<string>& arr) {
//         vector<string>ans;
//          int n=arr.size();
//        vector<bool>f(n,0);
       
//         for(int i=0;i<n;i++){
            
//             int l=arr[i].length();
//             for(int j=i+1;j<n;j++){

//                 int r=arr[j].length();
               
//                 if(r==l) continue;
//                 if(r<l){
//                     string substring=arr[i].substr(0,r);
//                     string substring2=arr[i].substr(l-r);
                    
                   
//                     if(arr[j]==substring) {
//                         if(arr[i][r]!='/') continue;
//                         f[i]=1;
                        
//                     }
                    
//                     else if(arr[j]==substring2) {
                       
//                           f[j]=1;
//                         continue;
//                     }
//                     else continue;

                    
//                 }

//                 else{
//                      string substring=arr[j].substr(0,l);
//                      string substring2=arr[j].substr(r-l);
                   
//                     if(arr[i]==substring) {
//                         if(arr[j][l]!='/') continue;
//                           f[j]=1;
//                     }
//                      else if(arr[i]==substring2) {
                    
//                          f[i]=1;
                    
//                     }
//                     else continue;
//                 }
//             }
       
//         }
//         for(int i=0;i<n;i++){
//             if(!f[i]) ans.push_back(arr[i]);
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        
        for (string& path : folder) {
            // If ans is empty or current path is NOT a subfolder of last added
            if (ans.empty() || path.find(ans.back() + "/") != 0) {
                ans.push_back(path);
            }
        }
        
        return ans;
    }
};

