class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int common=0;
        if(ax1<bx2&&ax2>bx1&&ay1<by2&&ay2>by1){
            
            int l=min(bx2,ax2)-max(ax1,bx1);
            int b=min(by2,ay2)-max(ay1,by1);

            common=abs(l*b);



        }
        
        int ar1=(ax2-ax1)*(ay2-ay1);
        int ar2=(bx2-bx1)*(by2-by1);

        int total=ar1+ar2-common;
        return total;
    }
};