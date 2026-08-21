/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map< int , pair<int, int>> keyData;
    unordered_map<int ,  list<int>> freqList;
    unordered_map<int , list<int>::iterator> position;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        // this is used
    }
    
    int get(int key) {
        if(keyData.find(key) == keyData.end()) {
            return -1;
        }

        int freq = keyData[key].second;

        freqList[freq].erase(position[key]);

        if(freqList[freq].empty() && minFreq == freq){
            minFreq++;
        }

        keyData[key].second++;
        int newFreq = keyData[key].second;
        freqList[newFreq].push_back(key);
        position[key] = --freqList[newFreq].end();
        return keyData[key].first;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(keyData.find(key) != keyData.end()) {
            keyData[key].first = value;
            get(key);
            return;
        }

        if(keyData.size() == capacity) {
            int lfuKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyData.erase(lfuKey);
            position.erase(lfuKey);
        }

        keyData[key] = {value, 1};
        freqList[1].push_back(key);
        position[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

