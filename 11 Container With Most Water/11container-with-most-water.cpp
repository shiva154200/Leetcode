class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int r=0;
        int i=0;
        int j=n-1;
        int t=0;

        while(j>i){
         int m=min(height[i],height[j]);
         t=m*(j-i);
         if(r<t) r=t;
         if(height[i]<height[j]) i++;
         else j--;
        }
      return r;  
    }
};