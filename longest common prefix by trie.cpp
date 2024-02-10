class Trienode{
    public:
    char data;
    int childcount;
    Trienode* children[26];
    bool isTerminal;
    
    Trienode(char ch){
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            
            /* code */
        }
        childcount = 0;
        isTerminal = false;
        
    }
};

class Trie {

public:
    Trienode* root;

    Trie(char ch){
        root = new Trienode(ch);
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
        root->childcount++;
        root->children[index] = child;
      }

      // recursion
      insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
     insertUtil(root,word);
    }
    void lcp(string str,string &ans){
       for(int i = 0;i<str.length();i++){
           char ch = str[i];

           if(root->childcount == 1){
               ans.push_back(ch);
               int index = ch-'a';
               root = root->children[index];
           }
           else{
               break;
           }
           if (root->isTerminal) {
               break;
           }
       }
    }
};

string
longestCommonPrefix(vector<string> &arr, int n) {

    Trie *t = new Trie('\0');

    //inserting strings into trie
    for(int i = 0;i<n;i++){
        t->insert(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first,ans);
    return ans;
}
