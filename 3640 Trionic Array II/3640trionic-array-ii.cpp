class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=1;
     int si,p,q,r;

long long maxans=LLONG_MIN;

while(i<n){
       while(true){
        
        while(i<n&&nums[i]<=nums[i-1]) i++;
        if(i==n) break;

         si=i-1;
        while(i<n&&nums[i]>nums[i-1]) i++;
        if(i==n) break;
        if(nums[i]==nums[i-1]) continue;
         p=i-1;
         while(i<n&&nums[i]<nums[i-1]) i++;
        if(i==n) break;
        if(nums[i]==nums[i-1]) continue;
        q=i-1;
        while(i<n&&nums[i]>nums[i-1]) i++;
        r=i-1;
        break;

    }
if(q<=si ) break;

long long ans=0;

while(si<p-1&&nums[si]<0) si++;

while(r>q+1&&nums[r]<0) r--;
long long  s=0;
int z=r;
while(z>q+1){
    s+=nums[z];
    if(s<0) r=z-1;
    z--;
}
for(int j=si;j<=r;j++) ans+=nums[j]; 
maxans=max(maxans,ans);
if(i<n) i=q+1;

}
 

 return maxans;

    }
};