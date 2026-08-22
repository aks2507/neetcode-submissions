class Logger {
    unordered_map<string, int> mp;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!mp.count(message)) {
            mp[message] = timestamp + 10;
            return true;
        } else {
            if (timestamp >= mp[message]) {
                mp[message] = timestamp + 10;
                return true;
            }
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
