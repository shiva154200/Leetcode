class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        int i = 0;
        int j = 0;
        int v1, v2;
        while (i < m || j < n) {

            if (i >= m)
                v1 = 0;
            else {
                string str = "";
                while (i < m && version1[i] != '.') {
                    str += version1[i];
                    i++;
                   
                }
                 v1 = stoi(str);
            }

            if (j >= n)
                v2 = 0;
            else {
                string str = "";
                while (j < n && version2[j] != '.') {
                    str += version2[j];
                    j++;
                   
                }
                 v2 = stoi(str);
            }

            if(v1>v2) return 1;
            if(v1<v2) return -1;

            i++;
            j++;
        }

        return 0;

    }
    };