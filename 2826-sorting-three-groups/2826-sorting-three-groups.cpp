class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int mx1=0;
        int mx2=0;
        int mx3=0;
        int mxc=0;
        for(int i=0;i<n;i++){
            if(nums[i]==3){
                mx3=max(mx1+1,max(mx3+1,mx2+1));
                mxc=max(mxc,mx3);
            }
            else if(nums[i]==2){
                mx2=max(mx1+1,mx2+1);
              mxc=max(mxc,mx2);    
            }
            else{

                mx1=mx1+1;
                 mxc=max(mxc,mx1); 

            }

            // cout<<mx1<<" "<<mx2<<" "<<mx3<<endl;
           
        }
       

        return n-mxc;
        
    }
};