class Solution {
public:
    char slowestKey(const vector<int>& releaseTimes, const string& keysPressed) {
        pair<int, char> key = {releaseTimes[0], keysPressed[0]};
        for(int i = 1; i < keysPressed.size(); ++i) key = max(key, {releaseTimes[i] - releaseTimes[i - 1], keysPressed[i]});
        return key.second;
    }
};