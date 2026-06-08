class LRUCache {
public:

    class Node{
    public:
        int val,key;
        Node* prev;
        Node* next;
        Node(int v , int k){
           this->key = k;
            this->val = v;
        }
    };
    unordered_map<int,Node*> mp;
    int cap;
    Node* head= new Node(0,0);
    Node* tail = new Node(0,0);
    void insert (Node* node){
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    void del (Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev; 
    }
    LRUCache(int capacity) {
        cap = capacity;

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        Node* res = mp[key];
        del(res);
        insert(res);
        return res->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            Node* node = new Node(value,key);
            mp[key] = node;
            insert(node);
        }
        else{
            Node* node = mp[key];
            node->val = value;
            del(node);
            insert(node);
        }

        if(mp.size()>cap){
            Node* dele = tail->prev;
            mp.erase(dele->key);
            del(dele);
            delete dele;
        }
    }
};
