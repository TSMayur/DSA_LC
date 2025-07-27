class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        const vector<pair<int, string>>& values = store.at(key);
        string result = "";
        
        int left = 0;
        int right = values.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};