class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int common=0;
        if(ax1<bx2&&ax2>bx1&&ay1<by2&&ay2>by1){
            vector<int>x={ax1,bx1,ax2,bx2};
            vector<int>y={ay1,by1,ay2,by2};
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());

            common=(x[2]-x[1])*(y[2]-y[1]);
           
            



        }
        
        int ar1=(ax2-ax1)*(ay2-ay1);
        int ar2=(bx2-bx1)*(by2-by1);

        int total=ar1+ar2-common;
        return total;
    }
};