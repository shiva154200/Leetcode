class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        if(num1=="0"||num2=="0") return "0";

        vector<int> nums1(n1);
        vector<int> nums2(n2);
         int t=0;
        for (int i = n1 - 1; i >= 0; i--) {
            nums1[t++] = num1[i] - 48;
        }
       t=0;
        for (int i = n2 - 1; i >= 0; i--) {
            nums2[t++] = num2[i] - 48;
        }



        vector<int> ans(n1 + n2, 0);

        for (int i = 0; i < n1; i++) {
            int c = 0; 
            int k = i;

            for (int j = 0; j < n2; j++) {

                int s = (ans[k] + nums1[i] * nums2[j] + c) / 10;
                ans[k] = (ans[k] + nums1[i] * nums2[j] + c) % 10;
                c=s;
                
                 
                k++;
            }
            ans[k]=c;
        }

        string r ="";
        for (int i = n1 + n2 - 1; i >= 0; i--) {
          char ch = '0' + ans[i];
            r.push_back(ch);
        
        }

        if (r[0] == '0')
            return r.substr(1);
        return r;
    }
};