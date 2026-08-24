class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& brr) {
        int m= brr.size();
        int n=brr[0].size();
        vector<int>v;
        
    int z=m*n;
    
    int k=0;
    int p=0,q=0;
    int a=m-1,b=n;
       
     while(k<z){
        for(int i=p,j=q,s=0;s<b;j++,s++){ 
            v.push_back(brr[i][j]) ;
               p=i+1;q=j;
               k++;
               
        }
        b--;
        if(k<z) 
        {
            for(int i=p,j=q,t=0;t<a;i++,t++){ 
             v.push_back(brr[i][j]) ;
             p=i;q=j-1; k++;  
        }
        
        
        a--;
        }
       if(k<z) { 
        for( int i=p,j=q,s=0;s<b;j--,s++){ 
             v.push_back(brr[i][j]) ; 
            p=i-1;q=j; k++;
        }
        b--;
         }
       if(k<z) { 
        for(int i=p,j=q,t=0;t<a;i--,t++){
             v.push_back(brr[i][j]) ;
            p=i;q=j+1;  k++;   
        }
        a--;}
    }
        
  return v;   }
};