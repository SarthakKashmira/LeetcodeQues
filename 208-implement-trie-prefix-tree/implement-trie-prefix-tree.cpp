 class TrieNode{
        public:
        TrieNode* links[26];
        bool flag;
        TrieNode(){
            flag=false;
            for(int i=0;i<26;i++)
            {links[i]=NULL;}
        }
    };
class Trie {
    TrieNode* root;
public:
    Trie() {
       root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(auto c:word)
        {
            if(node->links[c-'a']==NULL)
            {
                node->links[c-'a']=new TrieNode();
            }
            node=node->links[c-'a'];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(auto c:word)
        {
            if(node->links[c-'a']==NULL)
            {return false;}
            node=node->links[c-'a'];
        }
        if(node->flag){return true;}
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(auto c:prefix)
        {
            if(node->links[c - 'a']==NULL)
            {return false;}
            node=node->links[c-'a'];
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