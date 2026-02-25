class Solution {
public:
    int number_of_bits(int k){
        int c=0;
        while(k){
            if(k&1) c++;
            k>>=1;
        }
        return c;
    }

    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(mp.count(arr[i])) continue;
            mp[arr[i]]=number_of_bits(arr[i]);
        }

        for(int i=1;i<n;i++){
            int k=i;
            while(k>0&&
            (mp[arr[k]]<mp[arr[k-1]]
            ||(mp[arr[k]]==mp[arr[k-1]]
            &&arr[k]<arr[k-1]))){
                swap(arr[k],arr[k-1]);
                k--;
            }

        }

        return arr;
        
    }
};