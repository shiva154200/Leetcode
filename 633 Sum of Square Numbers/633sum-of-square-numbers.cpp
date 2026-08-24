class Solution {
public:
    bool isPerfectsqure(int x){
        if((int)sqrt(x)*(int)sqrt(x)==x) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfectsqure(x)&&isPerfectsqure(y)) return true;
            else if(!isPerfectsqure(x)){
                int n=sqrt(x)+1;
                x=n*n;
                y=c-x;
            }
            else{
                int n=sqrt(y);
                y=n*n;
                x=c-y;
            }
        }
        return false;
    }
};