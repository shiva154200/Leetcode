class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nextgrtElementIndex(nums2.size(),-1);
        unordered_map<int,int>mp;
        mp[nums2.back()]=-1;
            
        for(int i=nums2.size()-2;i>=0;i--){
            int j=i+1;
            while(1){
                if(nums2[j]>nums2[i]){                 
                   nextgrtElementIndex[i]=j;
                   mp[nums2[i]]=nums2[j];
                   break; 
                }
                else if(nextgrtElementIndex[j]==-1){
                     nextgrtElementIndex[i]=-1;
                      mp[nums2[i]]=-1;
                     break;
                }
                else j=nextgrtElementIndex[j];
            }

        }
        vector<int>ans;
         for(int x:nums1){
            ans.push_back(mp[x]);   
         }
      
        return ans;
        
    }
};