class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        int f=0;
        int s=0;
        int k=0;
        for(int i=0;i<n;i++,k++){
            if(nums[i]%2){
                flag=(flag)?false:true;
               
            }
            if(k==5){
                flag=(flag)?false:true;
                k=-1;
            }
            if(flag) f+=nums[i];
            else s+=nums[i];
            
        }
         return f-s;
        
        
    }
};