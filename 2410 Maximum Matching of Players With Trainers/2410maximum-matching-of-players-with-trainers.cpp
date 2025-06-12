class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) { 
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int c=0;
        for(int i=0,j=0;i<players.size()&&j<trainers.size();){
            if(players[i]<=trainers[j]){
                c+=1;
                i++;j++;
            }
            else j++;
        }
        return c;
    }
        
    
};