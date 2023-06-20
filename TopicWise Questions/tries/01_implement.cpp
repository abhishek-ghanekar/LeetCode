/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node {
     Node* links[26];
     bool flag;
     bool containsKey(char ch) {
         return links[ch-'a'] != NULL;
     }
     void put(char ch,Node *node) {
         links[ch-'a'] = node;
     }
     Node* get(char ch) {
         return links[ch-'a'];
     }
     void setEnd() {
         flag = true;
     }
     bool isEnd() {
         return flag;
     }
};
class Trie {
private:
   Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
       root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++) {
           if(!node->containsKey(word[i])) {
               // it doesnt contain the key
               node->put(word[i], new Node());
           }
           //move to the reference node
           node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
       // we need to search the word
       Node* node = root;
       for(int i=0;i<word.size();i++) {
           if(!node->containsKey(word[i])) {
               return false;
           }
           node = node->get(word[i]);
       }
       // we need to return the flags value
       return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       Node* node = root;
       for(int i=0;i<prefix.size();i++) {
           if(!node->containsKey(prefix[i])) {
               return false;
           }
           node = node->get(prefix[i]);
       }
       // we need to return the flags value
       return true;
    }
};