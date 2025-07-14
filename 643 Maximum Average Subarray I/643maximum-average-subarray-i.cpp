class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
         double avg=0;
         double sum=0;
        for(int i=0;i<k;i++){
              sum+=nums[i];
        }
        avg=sum/( double)k;
         double maxavg=avg;
        int i=0;
        int j=k;
        while(j<n) {
            sum-=nums[i];
            sum+=nums[j];
             avg=sum/( double)k;
            if(avg>maxavg) maxavg=avg;
            i++;j++;
        } 

        return maxavg;      
    }
};