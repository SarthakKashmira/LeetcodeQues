
struct Node{
    int key;int val;int count;
    Node* next;
    Node* prev;
    Node(int key_,int val_)
    {
        key=key_;val=val_;count=1;next=NULL;prev=NULL;
    }
};

struct dlist{
    int siz;
    Node* head; 
    Node* tail;
    dlist()
    {
        head=new Node(0,0);
        tail=new Node(0,0);
        siz=0;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node* node)
    {
        siz++;
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    void deletenode(Node* node)
    {
        node->next->prev=node->prev;
        node->prev->next=node->next;
        siz--;
    }
};
class LFUCache {
public:
    int cap;
    unordered_map<int,dlist*> freqList;
    unordered_map<int,Node*> keyNode;
    int minFreq;
    int curSize;
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
        curSize=0;
    }

    void updateLists(Node* node)
    {
        keyNode.erase(node->key);
        freqList[node->count]->deletenode(node);
        if(node->count==minFreq && freqList[node->count]->siz==0)
        {minFreq++;}
        dlist* highFreq=new dlist();
        if(freqList.find(node->count+1)!=freqList.end())
        {
            highFreq=freqList[node->count+1];
        }
        node->count+=1;
        highFreq->addnode(node);
        freqList[node->count]=highFreq;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
        Node* node=keyNode[key];
        int val=node->val;
        updateLists(node);
        return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return;

        if(keyNode.find(key)!=keyNode.end())
        {
            Node* node=keyNode[key];
            node->val=value;
            updateLists(node);
        }
        else{
            if(curSize==cap)
            {
                dlist* newList=freqList[minFreq];
                keyNode.erase(newList->tail->prev->key);
                freqList[minFreq]->deletenode(newList->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            dlist* freq=new dlist();
            if(freqList.find(minFreq)!=freqList.end())
            {
                freq=freqList[minFreq];
            }
            Node* node=new Node(key,value);
            freq->addnode(node);
            keyNode[key]=node;
            freqList[minFreq]=freq;

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */