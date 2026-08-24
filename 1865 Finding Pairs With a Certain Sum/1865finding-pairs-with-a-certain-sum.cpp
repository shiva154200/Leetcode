class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int>mp,mp1;
     
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int x:nums1){
            mp[x]++;
        }
         for(int x:nums2){
            mp1[x]++;
        }
    }
    
    void add(int index, int val) {
    
        mp1[nums2[index]]--;
        if(mp1[nums2[index]]==0) mp1.erase(nums2[index]);
        nums2[index]+=val;
        mp1[nums2[index]]++;


       

    }
    
    int count(int tot) {
      int c=0;
      for(auto x:mp1)  {
       int r=x.first;
       int fre=x.second;
       if(mp.count(tot-r)){
        c+=(fre*mp[tot-r]);
       }
      }
      return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */