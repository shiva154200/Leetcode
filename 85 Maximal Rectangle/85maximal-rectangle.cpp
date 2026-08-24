class Solution {
public:
    int largestRectangle(vector<int>& h){
    stack<int> st;
    h.push_back(0);   
    int ans=0;

    for(int i=0;i<h.size();i++){
        while(!st.empty() && h[st.top()] > h[i]){
            int height = h[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    h.pop_back();
    return ans;
}

   int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> height(n, 0);
    int ans = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='1') height[j]++;
            else height[j]=0;
        }
        ans = max(ans, largestRectangle(height));
    }
    return ans;
}

};