class MyHashSet {
public:
    static const int SIZE = 10007;
    vector<list<int>> buckets;
    MyHashSet() {
        buckets.resize(SIZE);    
    }
    
    void add(int key) {
        int idx = key % SIZE;
        for (int val : buckets[idx]) {
            if (val == key) return;
        }
        buckets[idx].push_back(key);
    }
    void remove(int key) {
        int idx = key % SIZE;
        buckets[idx].remove(key);
    }
    bool contains(int key) {
        int idx = key % SIZE;
        for (int val : buckets[idx]) {
            if (val == key) return true;
        }   
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */