// class Solution {
// public:
//     int countCollisions(string s) {

//         int n=s.size();
//         int c=0;
//         for(int i=1;i<n;i++){
//             if(s[i]=='L'){
//                if(s[i-1]=='L') continue;
//              if(s[i-1]=='R') c+=2;
//             else c+=1;
//             s[i]='S';
//             }

//            else  if(s[i]=='S'&&s[i-1]=='R') c++;

//         }


     
      
        



//         return c;
        
//     }
// };


class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        // Remove cars that will never collide
        while (i < n && s[i] == 'L') i++;
        while (j >= 0 && s[j] == 'R') j--;

        int collisions = 0;
        for (int k = i; k <= j; k++) {
            if (s[k] != 'S') collisions++;
        }
        return collisions;
    }
};
