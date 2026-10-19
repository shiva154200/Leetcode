class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int c=0;//count of target elements;
        int tsi=0;//target starting index
        for(int &x:nums){
            if(x<target) tsi++;
            else if(x==target) c++;
        }

        if(c==0) return {};
        vector<int>ans;
        for(int i=tsi;i<tsi+c;i++) ans.push_back(i);

        return ans;
    }
};