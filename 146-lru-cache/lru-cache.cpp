class LRUCache {
   
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key_,int val_)
        {
            key=key_;
            val=val_;
            next=NULL;
            prev=NULL;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(node* resnode)
    {
        resnode->next->prev=resnode->prev;
        resnode->prev->next=resnode->next;
    }
    void addnode(node* newnode)
    {
        newnode->next=head->next;
        head->next->prev=newnode;
        head->next=newnode;
        newnode->prev=head;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node* resnode=mp[key];
            int res=resnode->val;
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node* existing=mp[key];
            deletenode(existing);
        }
        else if(mp.size()==cap){
            mp.erase(tail->prev->key); 
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */