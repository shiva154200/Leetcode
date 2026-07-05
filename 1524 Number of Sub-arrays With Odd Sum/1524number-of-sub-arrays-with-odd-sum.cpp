class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;

        int n=arr.size();
        int nz=1;
        int ons=0;

       int sum=0;
       long long ans=0;

       for(int i=0;i<n;i++){
        sum+=arr[i];
        sum%=2;
        if(sum){
            ons++;
            ans+=nz;

        }
        else{
            nz++;
            ans+=ons;
        }
        ans%=mod;

       }

return ans;
        
    }
};