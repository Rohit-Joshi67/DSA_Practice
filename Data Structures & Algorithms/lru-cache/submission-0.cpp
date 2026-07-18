class LRUCache {

    private : class Node {
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key =k;
            value=v;
            prev=NULL;
            next= NULL;
        }
    };

    int capacity;
    unordered_map<int,Node*>cache;

    Node* tail;
    Node* head;

    void remove(Node* node) {
        Node* left = node->prev;
        Node* right = node->next;
        left->next= right;
        right->prev=left;

    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev= head;
        head->next->prev = node;
        head->next= node;

    }

public:
    
    LRUCache(int capacity) {
        this-> capacity = capacity;
        head= new Node(-1,-1);
        tail= new Node(-1,-1);

        head->next = tail;
        tail->prev= head;
        
    }
    
    int get(int key) {
        if(cache.find(key)== cache.end()) {
            return -1;
        }

        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;

        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end()) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }

        if(cache.size()==capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

        Node* node= new Node(key,value);
        insert(node);
        cache[key]=node;
    }
};
