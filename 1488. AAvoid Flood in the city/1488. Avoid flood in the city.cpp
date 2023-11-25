class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> memo; // (rains[i], i) where rains[i] != 0
        set<int> zeroes; // i where rains[i] == 0
        vector<int> ans(rains.size(), -1); // answer

        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                // store index in the zeroes list
                // or increment chain from previous zero
                zeroes.insert(i);
            } else if (!memo.count(rains[i])) {
                // store "lake" index in the hashmap
                memo.emplace(rains[i], i);
            } else {
                // search for zero index that can dry out the "lake"
                auto it = zeroes.upper_bound(memo.at(rains[i]));
                
                // return empty list if not found
                if (it == zeroes.end()) return vector<int>();

                // update answer, hashmp and zeroes
                ans.at(*it) = rains[i];
                memo.at(rains[i]) = i;
                zeroes.erase(it);
            }
        }

        // all unused zeroes will point to "lake" 1
        for (int i: zeroes) ans.at(i) = 1;

        return ans;
    }
};