class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
       int c=0;
       bool f=0;
       for(int i=0;i<n;i++) {
           f=1;
          for(int j=0;j<n;j++){
            if(fruits[i]<=baskets[j]){
                baskets[j]=0;
                f=0;
                break;} 
          }
          if(f) c++;
       }
       return c;
    }
};