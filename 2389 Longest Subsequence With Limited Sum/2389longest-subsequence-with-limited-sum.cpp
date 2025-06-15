class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>answer(queries.size());
        sort(nums.begin(),nums.end());
      
      
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        
        for(int i=0;i<queries.size();i++){
          int l=0;
          int h=nums.size()-1;
          int f=1;
          while(l<=h){
              int mid=(l+h)/2;
              if(queries[i]==nums[mid]){
                answer[i]=mid+1;
                f=0;
                break;
              }
             else if(queries[i]>nums[mid]) l=mid+1;
             else h=mid-1;
          }
            if(f)  answer[i]=h+1;

        
        }
        return answer;
    }
};