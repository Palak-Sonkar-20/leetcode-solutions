/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
public:
    static const int SIZE = 1000;
    vector<list<pair<int, int>>> table;
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int index = key % SIZE;
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = key % SIZE;
        for (const auto &pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % SIZE;
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                table[index].remove(pair);
                return;
            }
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
// @lc code=end

