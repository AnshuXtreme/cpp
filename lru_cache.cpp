#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
    int cap;
    std::list<std::pair<int,int>> cache;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> map;
public:
    LRUCache(int c) : cap(c) {}
    int get(int key) {
        if (!map.count(key)) return -1;
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    void put(int key, int val) {
        if (map.count(key)) {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = val;
            return;
        }
        if ((int)cache.size() == cap) {
            map.erase(cache.back().first);
            cache.pop_back();
        }
        cache.emplace_front(key, val);
        map[key] = cache.begin();
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1,10); lru.put(2,20);
    std::cout << lru.get(1) << "\n"; // 10
    lru.put(3,30); // evicts key 2
    std::cout << lru.get(2) << "\n"; // -1
    return 0;
