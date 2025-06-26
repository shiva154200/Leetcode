/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        Node*root=new Node(0);
        Node*t=root;
        while(temp){
           Node*N=new Node(temp->val);
           t->next=N;
           t=t->next;
           mp[temp]=N;
           temp=temp->next;
        }
        root=root->next;
        t=root;
        temp=head;
       
        while(temp){
            t->random=mp[temp->random];
             t=t->next;
            temp=temp->next;
        }

    return root;
        
    }
};