/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isTerminal;
    
    Trienode(char ch){
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            
            /* code */
        }
        isTerminal = false;
        
    }
};

class Trie {

public:
    Trienode* root;

    Trie(){
        root = new Trienode('\0');
    }
    void insertUtil(Trienode* root,string word){
      //base case
      if (word.length() == 0)
      {
          root->isTerminal = true;
          return;
      }
      //index of array
      int index = word[0]-'a';
      Trienode* child;

      //present
      if (root->children[index] != NULL)
      {
        child = root->children[index];

      } else {
        // absent
        child = new Trienode(word[0]);
        root->children[index] = child;
      }

      // recursion
      insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
     insertUtil(root,word);
    }

    bool searchUtil(Trienode *root, string word){
       //base case
       if(word.length()==0){
        return root->isTerminal;
       }
       int index = word[0] - 'a';
       Trienode* child;

       //present
       if(root->children[index] != NULL){
        child = root->children[index];
       }
       else{
        //abseent
        return false;
       }
       //recursion
       return searchUtil(child,word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);
    }

    bool prefixUtil(Trienode *root, string word){
       //base case
       if(word.length()==0){
        return true;
       }
       int index = word[0] - 'a';
       Trienode* child;

       //present
       if(root->children[index] != NULL){
        child = root->children[index];
       }
       else{
        //abseent
        return false;
       }
       //recursion
       return prefixUtil(child,word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);

    }
};
