class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    int cacheCapacity;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    // Always inserts at the right
    void insert(Node* node) {
        Node* prev = right->prev;

        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cache.clear();
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        // Find in the cache
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Move to right most by first removing then inserting to the rightmost
            remove(node);
            insert(node);

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // Check if key exists. If yes, remove existing node, create new one and insert updated at rightmost. If no, insert new node at rightmost
        if (cache.find(key) != cache.end()) {
            Node* oldNode = cache[key];
            remove(oldNode);
            delete(oldNode);
        }

        Node* updatedNode = new Node(key, value);
        cache[key] = updatedNode;
        insert(updatedNode);

        // check cache size. If > capacity, remove leftmost
        if (cache.size() > cacheCapacity) {
            Node* lruNode = left->next;
            remove(lruNode);
            cache.erase(lruNode->key);
            delete(lruNode);
        }
    }
};
