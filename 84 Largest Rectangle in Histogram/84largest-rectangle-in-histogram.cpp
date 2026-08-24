class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      
        // previous smallest index array psi
        stack<int>st;
        int n= heights.size();
        vector<int>psi;
        psi.push_back(-1);
        st.push(0);
        for(int i=1;i<heights.size();i++){
            while(st.size()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.size()==0){
                psi.push_back(-1);
            }
            else  psi.push_back(st.top());

            st.push(i);
        }

        // next smallest index array:-
        stack<int>st1;
        vector<int>nsi(n);
        nsi[n-1]=n;
    
        st1.push(n-1);
        for(int i=heights.size()-2;i>=0;i--){
            while(st1.size()&&heights[i]<=heights[st1.top()]){
                st1.pop();
            }
            if(st1.size()==0){
                nsi[i]=heights.size();
            }
            else nsi[i]=st1.top();

            st1.push(i);
        }

        int maxarea=0;
        for(int i=0;i<n;i++){
            int l=nsi[i]-psi[i]-1;
            int area=l*heights[i];
            maxarea=max(area,maxarea);
            
        }

        return maxarea;

    }
};