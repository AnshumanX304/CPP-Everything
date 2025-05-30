#include <iostream>
using namespace std;

// class Node {
// public:
//     char data;
//     bool isend;
//     Node* config[26]; 

//     Node(char data) {
//         this->data = data;
//         this->isend = false;
//         for (int i = 0; i < 26; i++) {
//             config[i] = nullptr; 
//         }
//     }

//     void makeEnd() {
//         this->isend = true;
//     }

//     bool isEnd() {
//         return isend;
//     }
// };

// class Trie {
// public:
//     Node* root;

//     Trie() {
//         root = new Node('@'); 
//     }

//     void insert(string word) {
//         Node* curr = root;
//         for (char ch : word) {
//             int index = ch - 'a'; 
//             if (curr->config[index] == nullptr) {
//                 curr->config[index] = new Node(ch);
//             }
//             curr = curr->config[index];
//         }
//         curr->makeEnd();
//     }

//     bool search(string word) {
//         Node* curr = root;
//         for (char ch : word) {
//             int index = ch - 'a';
//             if (curr->config[index] == nullptr) {
//                 return false;
//             }
//             curr = curr->config[index];
//         }
//         return curr->isEnd();
//     }

//     bool startsWith(string prefix) {
//         Node* curr = root;
//         for (char ch : prefix) {
//             int index = ch - 'a';
//             if (curr->config[index] == nullptr) {
//                 return false;
//             }
//             curr = curr->config[index];
//         }
//         return true;
//     }
// };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


 class Node{
    public:
    char data;
    bool end;
    unordered_map<char,Node*> config;
    Node(char data){
        this->data=data;
        this->end=false;
    }

    void make_end(){
        end=true;
    }

    bool is_end(){
        return end;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node('@');
    }
    void insert(string word){
        
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->config.find(word[i])==curr->config.end()){
                Node* newnode=new Node(word[i]);
                curr->config[word[i]]=newnode;
            }
            curr=curr->config[word[i]];
        }
        curr->make_end();
    }

   
};
