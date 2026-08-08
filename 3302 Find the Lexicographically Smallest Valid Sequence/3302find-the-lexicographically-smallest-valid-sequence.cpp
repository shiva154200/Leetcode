class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();

        int i=0;
        int j=0;
       vector<int>left(n1,0);
         vector<int>right(n1,0);

        while(i<n1&&j<n2){
            if(word1[i]==word2[j]){
                j++;
            }
            left[i]=j;
            i++;
        }
          while(i<n1){
            left[i]=j;
            i++;
        }
        i=n1-1;
        j=n2-1;
          while(i>=0&&j>=0){
            if(word1[i]==word2[j]){
                j--;
            }
            right[i]=n2-j-1;
            i--;
        }

         while(i>=0){
            right[i]=n2-j-1;
            i--;
        }
        int k=0;
         if(right[1]+1>=n2){
            k=0;
         }
         else{
            
         i=0;
         j=2;
         while(j<n1){
            if(left[i]+right[j]+1>=n2 ) break;
            i++;j++;
         }
       
          k=left[i];
         }

         vector<int>ans;
         j=0;
         i=0;
        

        //  for(int x:left) cout<<x<<" ";
        //  cout<<endl;
        //   for(int x:right) cout<<x<<" ";

          while(i<n1&&j<n2){
            if(j==k){
                if(word1[i]==word2[j]){
                j++;
                k++;
                ans.push_back(i);
                i++;
                   
            }
            else{
                ans.push_back(i);
                j++;i++;
            }
            continue;
                
                
            }
            if(word1[i]==word2[j]){
                j++;
                ans.push_back(i);
            }
           
            i++;
        }
        if(ans.size()<n2) return {};
       

        return ans;

        
    }
};