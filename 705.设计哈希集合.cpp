/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int arraylist[1000001];    
    MyHashSet() {
        fill(arraylist,arraylist+1000001,0);
    }
    
    void add(int key) {
        arraylist[key]=1;
    }
    
    void remove(int key) {
        arraylist[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (arraylist[key]==1)
        {
            return true;
        }
        else return false;       
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

