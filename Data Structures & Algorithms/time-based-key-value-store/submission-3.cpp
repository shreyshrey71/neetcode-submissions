class TimeMap {
    unordered_map<string, vector<pair<int, string>>> tmi;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { tmi[key].emplace_back(timestamp, value); }

    string get(string key, int timestamp) {
        if (!tmi.contains(key)) return "";
        int l = 0, r = tmi[key].size() - 1, m = l;
        string result = "";
        while (l <= r) {
            m = l + (r - l) / 2;
            if (tmi[key][m].first <= timestamp) {
                result = tmi[key][m].second;
                l = m + 1;
            }
            else r = m - 1;
        }
        return result;
    }
};
