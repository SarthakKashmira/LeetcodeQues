class LRUCache {
    struct Node
    {
     int val;
     int key;
     Node* back;
     Node* forth;
     Node(int num)
     {
        val=num;
        key=0;
        back=NULL;
        forth=NULL;
     }
    };
public:
    int siz;
    map<int,Node*> mp;
    Node* front=NULL;
    Node* last=NULL;
    LRUCache(int capacity) {
        front=new Node(-1);
        last=new Node(-1);
        front->forth=last;
        last->back=front;
        siz=capacity;
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end())
        {return -1;}
        else{
            Node* temp=mp[key];
                temp->forth->back=temp->back;
                temp->back->forth=temp->forth;
                temp->forth=front->forth;
                front->forth->back=temp;
                front->forth=temp;
                temp->back=front;
            return mp[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end() )
        {
            cout<<last->back->key<<siz<<" ";
            if(siz==0)
            {
                int num=last->back->key;
                mp.erase(num);
                last->back->back->forth=last;
                last->back=last->back->back;
                siz++;
            }

                Node* temp=new Node(value);
                temp->key=key;
                mp.insert({key,temp});
                siz--;
                temp->forth=front->forth;
                front->forth->back=temp;
                front->forth=temp;
                temp->back=front;
        }
        else{
            Node *temp=mp[key];
            temp->val=value;
            temp->back->forth=temp->forth;
            temp->forth->back=temp->back;
            temp->forth=front->forth;
            front->forth->back=temp;
            front->forth=temp;
            temp->back=front;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */