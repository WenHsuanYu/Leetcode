//TC: O(1)
//SC: O(n)
class LRUCache {
public:
    
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if (um.find(key) == um.end()) {
            return -1;
        } else {
            auto node = um[key];
            li.splice(li.begin(), li, um[key]);
            //three lines below can not work now (TLE), use list.splice instead
            //li.erase(um[key]);
            //li.insert(li.begin(), node);
            //um[key] = li.begin();
            return node->second;
        }
    }a
    
    void put(int key, int value) {
        if (get(key) != -1) {
            um[key]->second = value;
        } else {
            if (li.size() == capacity) {
                um.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key, value});
            um[key] = li.begin();
        }
    }
private:
    int capacity;   
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */