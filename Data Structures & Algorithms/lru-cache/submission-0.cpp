class LRUCache {
   private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int cap;

   public:
    LRUCache(int capacity) { cap = capacity; }
    int get(int key) {
        if (!cache.count(key)) return -1;
        order.splice(order.end(), order, cache[key].second);
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            order.splice(order.end(), order, cache[key].second);
            return;
        }

        if (cache.size() == cap) {
            cache.erase(order.front());
            order.pop_front();
        }

        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
