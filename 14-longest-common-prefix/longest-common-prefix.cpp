class Solution {
public:
    class TrieNode{
        public:
        char data;
        TrieNode* links[26];
        bool flag;
        int count;
        TrieNode(char ch){
            data=ch;
            flag=false;
            count=0;
            for(int i=0;i<26;i++)
            {links[i]=NULL;}
        }

    };
    class Trie{
        public:
        TrieNode* root;
        Trie(char ch)
        {
            root=new TrieNode(ch);
        }
        void insert(string word)
        {
            if(word.length()==0)
            {
                root->flag=true;
                return ;
            }
            TrieNode* node=root;
            for(auto c:word)
            {
                if(node->links[c-'a']==NULL)
                {
                    node->links[c-'a']=new TrieNode(c);
                    node->count++;
                }
                    node=node->links[c-'a'];
            }
            node->flag=true;
        }
        void lcp(string first,string &ans)
        {
            TrieNode* node=root;
            for(auto c:first)
            {
                if(node->count==1)
                {
                    ans.push_back(c);
                    node=node->links[c-'a'];
                }
                else{
                    break;
                }
                if(node->flag)
                {break;}
            }
            return ;
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t=new Trie('\0');
        for(auto i:strs)
        {
            if(i.size()==0) return "";
            t->insert(i);
        }
        string first=strs[0];
        string ans="";
        t->lcp(first,ans);
        return ans;
    }
};