class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int k, int v) : key(k), val(v) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head = new Node(-1, -1); // Dummy head
    Node* tail = new Node(-1, -1); // Dummy tail

    // Helper: Remove a node from its current linked list position
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper: Insert a node right after the dummy head (Most Recently Used)
    void insertToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        remove(node);       // Remove from old position
        insertToHead(node); // Move to front (MRU)
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: update value and move to front
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insertToHead(node);
        } else {
            // Key is new: evict if full
            if (cache.size() == capacity) {
                Node* lru = tail->prev; // Node right before dummy tail
                cache.erase(lru->key);  // Remove from map
                remove(lru);            // Remove from list
                delete lru;             // Free memory
            }
            // Add new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertToHead(newNode);
        }
    }
    
    // Destructor to prevent memory leaks when cache is destroyed
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};