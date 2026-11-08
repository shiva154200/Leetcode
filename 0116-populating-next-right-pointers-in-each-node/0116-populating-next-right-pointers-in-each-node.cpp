/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   
    Node* connect(Node* root) {
    if(!root) return root;
    Node* nxt=NULL;
    int c=0;
    int n=1;
    queue<Node*>q;
    q.push(root);
    while(q.size()){
    q.front()->next=nxt;
    c++;
    if(c==n){
        nxt=NULL;
          n=2*n;
          c=0;
    }
    else{
        nxt=q.front();
    }

    if(q.front()->left){
         q.push(q.front()->right);
    q.push(q.front()->left); 
    }
   q.pop();
    }
    
    return root;
    }
};