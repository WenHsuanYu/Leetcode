//This can not work now (TLE)
//Implement LRU cache with hash table
//TC: O(1) means that `get` and `put` functions run in average time complexity
//SC: O(n), where n is the number of key-value pairs
struct Node{
    int val;
    int key;
    struct Node* prev;
    struct Node* next;
    
    Node(){
        
    }
    Node(int key, int value): key(key), val(value){
        this->prev = nullptr;
        this->next = nullptr;
    }
    
};


class LRUCache {

    struct Node* head = new Node();
    struct Node* tail = new Node();
    unordered_map<int, Node*> umap;
    int capacity;
    int size;
public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        this->head = NULL;
        this->tail = NULL;
    }
    
    void delete_node(Node* node) {
        //prev:
        if (node->prev != nullptr) {    
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        
        //next:
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
               
        node->prev = nullptr;
        node->next = nullptr;
    }
    
    void insert_node(Node* node) {
        //only one node
        if (head == nullptr) {
            head = tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }
    
    
    int get(int key) {
        if(umap.find(key) != umap.end()) {
            Node* target = umap[key];
            delete_node(target);
            insert_node(target);
            return target->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* node = new Node(key, value);
        //found key
        if (umap.find(key) != umap.end()) {
            umap[key]->val = value;
            delete_node(umap[key]);
            insert_node(umap[key]);
        // not found key
        } else {
            umap[key] = node;
            //Cache is full  
            if (size == capacity) {
                umap.erase(tail->key);
                delete_node(tail);
                insert_node(node);
            } else {
                size++;
                insert_node(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */