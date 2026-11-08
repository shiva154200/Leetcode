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
    typedef pair<Node*,int>pr;
    Node* connect(Node* root) {
        if (!root)
            return root;
        pr nxt = {NULL,0};
        
        queue<pr> q;
        q.push({root,0});
        while (q.size()) {
            if(q.front().second==nxt.second){
                 q.front().first->next = nxt.first;
            }
           else q.front().first->next =NULL ;

           nxt=q.front();
            if (q.front().first->right) {
                q.push({q.front().first->right,q.front().second+1});
              
            }
           
            if (q.front().first->left) {
                q.push({q.front().first->left,q.front().second+1});
            }
            q.pop();
        }

        return root;
    }
};