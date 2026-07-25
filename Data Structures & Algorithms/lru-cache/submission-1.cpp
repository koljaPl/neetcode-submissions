struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> our_cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev_node = node->prev;
        Node* next_node = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    void insert(Node* node) {
        Node* prev_node = right->prev;
        Node* next_node = right;
        
        prev_node->next = node;
        next_node->prev = node;
        
        node->next = next_node;
        node->prev = prev_node;
    }

    void clear() {
        Node* current = left;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        clear();
    }

    int get(int key) {
        if (our_cache.find(key) != our_cache.end()) {
            remove(our_cache[key]);
            insert(our_cache[key]);
            return our_cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (our_cache.find(key) != our_cache.end()) {
            remove(our_cache[key]);
            delete our_cache[key]; 
        }

        our_cache[key] = new Node(key, value);
        insert(our_cache[key]);

        if (our_cache.size() > capacity) {
            Node* lru = left->next;

            remove(lru);

            our_cache.erase(lru->key);

            delete lru;
        }
    }
};
