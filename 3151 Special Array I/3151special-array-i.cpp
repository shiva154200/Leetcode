class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        int p=1;
        if(arr[0]%2==0) p=0;
        int i=1;
        while(i<arr.size()){
          if(arr[i]%2==p) return false;
          p=abs(p-1);
          i++;
        }
        return true;
    }
};