class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int x:arr) sum+=x;
        if(sum%3) return false;
        int k=sum/3;
        int r=0;
        int s=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
          if(s==k){
            r+=1;
        
            s=0;
          } 

          if(r==2&&i<arr.size()-1) return true;
        }

       
        return false;
        

    }
};
