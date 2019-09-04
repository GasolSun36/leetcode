/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
class MyHashMap
{
public:
    /** Initialize your data structure here. */
    int arraylist[1000001];
    MyHashMap()
    {
        fill(arraylist, arraylist + 1000001, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        arraylist[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        return arraylist[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        arraylist[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
