class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        //mxchb=maximum consecutive horisontal bars;
        //chb=consecutive horizontal bars

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int mxchb=1;
        int chb=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1){
                chb++;
              
            }
            else{
                  if(chb>mxchb) mxchb=chb;
                chb=1;
            }
        }

          if(chb>mxchb) mxchb=chb;
         //mxcvb=maximum consecutive vertical bars;
        //cvb=consecutive vercital bars
        int mxcvb=1;
        int cvb=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1){
                cvb++;
                
            }
            else{
                if(cvb>mxcvb) mxcvb=cvb;
               
                cvb=1;
            }
        }

        if(cvb>mxcvb) mxcvb=cvb;
    int l=min(mxcvb,mxchb)+1;
    return l*l;

        
    }
};