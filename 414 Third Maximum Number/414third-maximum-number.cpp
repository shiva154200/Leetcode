class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int>v(3,INT_MIN);
      bool f=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==INT_MIN) f=true;
            if(v[0]==nums[i]||v[1]==nums[i]||v[2]==nums[i]) continue;
            if(v[2]<nums[i]){
               v[0]=v[1];
               v[1]=v[2];
               v[2]=nums[i];
            }
            else if(v[1]<nums[i]){
                v[0]=v[1];
                v[1]=nums[i];
            }
            else if(v[0]<nums[i]){
                v[0]=nums[i];
            }
        }
         if ( v[0]==v[1]||v[1]==v[2] ) return v[2];
         else if(!f&&v[0]==INT_MIN) return v[2];
         return v[0];
    
        
    }

   
};