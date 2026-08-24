class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int r=0;
        int c=1;
        int l=n-1;
        int i=1;

       while(i<=l){
            if(nums[i]==nums[i-1]) {
                if(c<2) {c++;i++;}
                else{
                 int k=i+1;
                 r++;
                 while(k<=l){
                    swap(nums[k],nums[k-1]);
                    k++;
                 }
                 l--;
                }
            }
            else{
                c=1;i++;
            }
        }

        return n-r;
        
    }
};