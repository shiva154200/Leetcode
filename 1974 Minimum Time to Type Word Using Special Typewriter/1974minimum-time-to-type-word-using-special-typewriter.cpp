class Solution {
public:
    int minTimeToType(string word) {
        int n=word.size();
       
        int count=0;
        int i=0;
        int rt=97;

        while(i<n){
            int gap;
            gap=abs((int)word[i]-rt);
            if(gap<=13) gap=gap+1;
            else gap=(26-gap)+1;
            count+=gap;
            rt=int(word[i]);
            i++;
        }
        return count;
    }
};