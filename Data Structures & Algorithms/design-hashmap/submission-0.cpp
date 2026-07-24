class Node {
public:
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
    Node(int k, int v, Node* next) : key(k), value(v), next(next) {}
};

class MyHashMap {
private:
    int size = 100000;
    vector<Node*> map;
public:
    MyHashMap() : map(size, nullptr) {}
    
    void put(int key, int value) {
        int idx = key % size;
        Node* curr = map[idx];

        while(curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        map[idx] = new Node(key, value, map[idx]);
    }
    
    int get(int key) {
        int idx = key % size;

        Node* curr = map[idx];
        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = key % size;
        Node* curr = map[idx];
        Node* prev = nullptr;
        while(curr) {
            if (curr->key == key) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    map[idx] = curr->next;
                }
                curr->next = nullptr;
                delete(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */