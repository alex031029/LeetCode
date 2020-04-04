// a LFU implementation based on unordered_map and set (i.e., binary search tree)
// both get and put operation is logarithm time complexity
// thus, it is a slow but straightforward implementation


struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    // overload < operator 
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
public:
    // time is to store when the node is updated 
    int cp;
    int time = 0;
    set<Node> st;
    unordered_map<int,Node> mp;

    LFUCache(int capacity):cp(capacity){}
    
    // log(n) time due to inserting in set
    int get(int key) {
        if (cp == 0) 
            return -1;
        auto it = mp.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == mp.end()) 
            return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        st.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        st.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    // log(n) time due to inserting in set
    void put(int key, int value) {
        if (cp == 0) 
            return;
        auto it = mp.find(key);
        if (it == mp.end()) {
            // 如果到达缓存容量上限
            if (mp.size() == cp) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                mp.erase(st.begin() -> key);
                st.erase(st.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            mp.emplace(key, cache);
            st.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            st.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            st.insert(cache);
            it -> second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
