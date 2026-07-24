class MyHashSet {
private:
    static constexpr int MAX_KEY = 1'000'000;
    static constexpr int BITS_PER_WORD = 64;

    vector<uint64_t> bits;

    uint64_t getMask(int key) {
        int bitIdx = key % BITS_PER_WORD;
        return 1ULL << bitIdx;
    }

    int getBucket(int key) {
        return key / BITS_PER_WORD;
    }
public:
    MyHashSet() : bits(((MAX_KEY + BITS_PER_WORD) / BITS_PER_WORD), 0) {}
    
    void add(int key) {
        bits[getBucket(key)] |= getMask(key);
    }
    
    void remove(int key) {
        bits[getBucket(key)] &= ~getMask(key);
    }
    
    bool contains(int key) {
        return (bits[getBucket(key)] & getMask(key)) != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */