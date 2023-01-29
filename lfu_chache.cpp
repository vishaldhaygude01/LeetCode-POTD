class LFUCache
{
    int capacity;
    int size;
    unordered_map<int, pair<int, int>> key_val_freq;
    unordered_map<int, list<int>> freq_keys;
    unordered_map<int, list<int>::iterator> key_pos;
    int min_freq;

public:
    LFUCache(int capacity) : capacity(capacity), size(0), min_freq(0) {}

    int get(int key)
    {
        if (key_val_freq.find(key) == key_val_freq.end())
            return -1;
        auto [val, freq] = key_val_freq[key];
        freq_keys[freq].erase(key_pos[key]);
        if (freq == min_freq && freq_keys[freq].empty())
            min_freq++;
        key_val_freq[key] = {val, freq + 1};
        freq_keys[freq + 1].push_front(key);
        key_pos[key] = freq_keys[freq + 1].begin();
        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;
        if (get(key) != -1)
        {
            key_val_freq[key].first = value;
            return;
        }
        if (size == capacity)
        {
            int lfu = freq_keys[min_freq].back();
            freq_keys[min_freq].pop_back();
            key_val_freq.erase(lfu);
            key_pos.erase(lfu);
            size--;
        }
        key_val_freq[key] = {value, 1};
        freq_keys[1].push_front(key);
        key_pos[key] = freq_keys[1].begin();
        min_freq = 1;
        size++;
    }
};