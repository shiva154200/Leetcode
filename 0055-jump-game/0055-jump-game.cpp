class Solution {
public:
  //hello disty ka
  
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;  //denotes how long we can go
        for(int i=0;i<n;i++){
            
            if(i>farthest) return false;
            farthest=max(farthest,i+nums[i]);
        }
        
        return true;
        
        
    }
};


// Haa distay
// OKAY
//done
// Evdach Hota ??

//wait
// Submit karrrr