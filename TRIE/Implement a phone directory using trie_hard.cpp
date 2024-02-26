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
class Trie{
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
        
      }
      else{
        //absent
        child = new Trienode(word[0]);
        root->children[index] = child;
      }

      //recursion
      insertUtil(child,word.substr(1));
      
    }

    void insertWord(string word){
       insertUtil(root,word);

    }
void printSuggestion(Trienode *curr,vector<string> &temp,string prefix){

    if(curr->isTerminal){
        temp.push_back(prefix);
    }

    for(char ch = 'a';ch <= 'z'; ch++){
        
        Trienode* next = curr->children[ch-'a'];
        
        if(next != NULL){
            prefix.push_back(ch);

            printSuggestion(next,temp,prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getsuggestion(string str){
    Trienode* prev = root;
    vector<vector<string> > output;
    string prefix = "";

    for(int i = 0; i<str.length();i++){
        char lastchar = str[i];
        prefix.push_back(lastchar);

        //check for lastchar
        Trienode* curr = prev->children[lastchar-'a'];

        //if not found
        if(curr == NULL){
            break;
        }

        //if found
        vector<string> temp;
        printSuggestion(curr,temp,prefix);

        output.push_back(temp);
        temp.clear();
        prev = curr;

    }
    return output;
}


};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie *t = new Trie();

    //inserting all contact in trie

    for(int i = 0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    //return ans
    return t->getsuggestion(queryStr);
}
