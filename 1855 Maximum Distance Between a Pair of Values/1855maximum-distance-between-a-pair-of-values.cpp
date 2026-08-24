class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m =nums1.size();
        int n =nums2.size();
        int mx=0;
        int i=0;
        int j=0;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]) j++;
            else{
                if(i>=j){
                    i++;
                    j=i;
                }
                else{  
                    mx=max(mx,j-i-1);
                      i++;}
             
            }
        }
              mx=max(mx,j-i-1);

        return mx;
        
    }
};