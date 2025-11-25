// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//      int n=nums.size();

//      vector<bool>ans(n,false);
//      int i=0;
//      while(i<n&&nums[i]==0){
//         ans[i++]=true;
//      }
     
//     int j=i;
//      for(;i<n;i++){
//         long long m=1;
//         long long t=0;
//        for(int k=i;k>=j;k--){
//          if(nums[k]) t+=m;
//           m*=2;
//        }

//         if(t%5==0) ans[i]=true;
     
         
//        }

      

     

//        return ans;
//     }
// };

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        
        int num = 0;
        for(int i = 0; i < n; i++){
            num = ((num<<1)+ nums[i]) % 5;
            ans[i] = (num == 0);
        }
        
        return ans;
    }
};
