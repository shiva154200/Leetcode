class Solution {
public:
    long long hourstoeat(vector<int>& piles,int speed){
        
        long long ct=0;
        for(int x:piles){
            ct+=x/speed;
            if(x%speed) ct+=1;
        }
        return ct;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=INT_MIN;
        for(int x:piles){
         hi=max(hi,x);
        }
       int mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;

            long long hr=hourstoeat(piles,mid);

            if(hr<=h){
                hi=mid-1;
            }
            else lo=mid+1;

        }

        return lo;



        
    }
};