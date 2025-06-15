class Solution {
public:
    int maxSatisfied(vector<int>& customer, vector<int>& grumpy, int minutes) {
        int n=customer.size();
        int loss=0;
        for(int i=0;i<minutes;i++)
        {
           loss=loss+customer[i]*grumpy[i];
        }
        int maxloss=loss;
        int idx=0;
        for(int i=1,j=minutes;j<n;i++,j++){
            loss=loss-(customer[i-1]*grumpy[i-1])+(customer[j]*grumpy[j]);
            if(loss>maxloss){
                maxloss=loss;
                idx=i;
            } 
        }
        
        for(int i=idx;i<idx+minutes;i++){
            grumpy[i]=0;
        }
        int maxcustomer=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) maxcustomer+=customer[i];
        }
        return maxcustomer;
    }
};