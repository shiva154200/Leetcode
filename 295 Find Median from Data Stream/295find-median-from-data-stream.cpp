class MedianFinder {
public:
priority_queue<double>mx;
priority_queue<double,vector<double>,greater<double>>mn;


   
    
    void addNum(int num) {
       if(mx.size()==0){
         mx.push(num);
       }
       else if(mx.top()<num){
        mn.push(num);
       }
       else   mx.push(num);

       if(mx.size()>mn.size()+1){
        mn.push(mx.top());
        mx.pop();
       }
       if(mn.size()>mx.size()+1){
        mx.push(mn.top());
        mn.pop();
       }
    
       
    }
    
    double findMedian() {
        if(mx.size()==mn.size()){
            return (mx.top()+mn.top())/2.0;
        } 
        if(mx.size()>mn.size()) return mx.top();
         else return mn.top();
        
           }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */