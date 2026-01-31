class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
     if(target=='z') return letters[0];
    char ans= char(123);
     for(int i=0;i<n;i++){
        if( (letters[i]>target) && ans>letters[i]){
            ans=letters[i];
        }

     }

    return (ans==123)?letters[0]:ans;
        
    }
};