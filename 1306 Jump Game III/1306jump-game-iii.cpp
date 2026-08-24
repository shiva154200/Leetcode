class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0||start>=arr.size()||arr[start]<0) return false;

        if(arr[start]==0) return true;
        
        
        int val=abs(arr[start]);
        arr[start]=-1;

        bool r=(start+val<arr.size())?canReach(arr,start+val):false;
        bool l=(start-val>=0)?canReach(arr,start-val):false;

        return (l||r);


        
    }
};