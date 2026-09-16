class MyHashSet {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    static const int BUCKETS = 1009; // Prime number of buckets to minimize collisions
    Node* table[1009];

    int hash(int key) {
        return key % BUCKETS;
    }

public:
    MyHashSet() {
        for (int i = 0; i < BUCKETS; ++i) {
            table[i] = nullptr;
        }
    }
    
    void add(int key) {
        if (contains(key)) return;
        
        int idx = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[idx];
        table[idx] = newNode;
    }
    
    void remove(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->val == key) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    table[idx] = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        while (curr != nullptr) {
            if (curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }
};