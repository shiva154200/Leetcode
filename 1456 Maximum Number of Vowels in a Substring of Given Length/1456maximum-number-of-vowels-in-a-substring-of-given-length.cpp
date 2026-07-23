class Solution {
public:
    int maxVowels(string s, int k) {

        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int count=0;
        int maxcount=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(st.count(s[r])) count++;
            if(count==k) return k;
            if(r-l+1==k){
                maxcount=max(count,maxcount);
                if(count &&st.count(s[l])) count--;
                l++;

            }
            r++;

        }

        return maxcount;
        
    }
};