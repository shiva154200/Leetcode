class Node {
public:
    bool is_terminal;
    char data;
    unordered_map<char, Node*> child;
    Node(char data){
      this->data=data;
      is_terminal=false;
      
    }
};

class Trie {
public:
   Node*root;
    Trie() {
       root=new Node('\\');
    }

    void insert(string word) {
        Node *temp=root;
        
        for(int i=0;i<word.size();i++){
            if(temp->child.count(word[i])){
                temp=temp->child[word[i]];
            }
            else{
                Node *newNode=new Node(word[i]);
                temp->child[word[i]]=newNode;
                temp=newNode;
            }
           
        }
         temp->is_terminal=true;
    }

    bool search(string word) {
         Node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child.count(word[i])){
                temp=temp->child[word[i]];
            }
            else return false;

        }
        

        return (temp->is_terminal);
    }

    bool startsWith(string prefix) {
         Node *temp=root;
        for(int i=0;i<prefix.size();i++){
            if(temp->child.count(prefix[i])){
                temp=temp->child[prefix[i]];
            }
            else return false;

        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */