#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
public:
    MyHashMap() {
        this->map = new vector<int>(1000001,-1);
    }
    
    void put(int key, int value) {
        (*map)[key] = value;
    }
    
    int get(int key) {
        return (*map)[key];
    }
    
    void remove(int key) {
        (*map)[key] = -1;
    }
private:
    vector<int> *map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

