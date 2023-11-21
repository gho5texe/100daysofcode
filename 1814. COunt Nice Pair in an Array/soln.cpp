class Solution {
public:
    //helper function that reverse the integer
    int reverseInt(int num)
    {
        auto numString = to_string(num); //convert int to string
        reverse(numString.begin(), numString.end()); //reverse the string
        int reverseNum = stoi(numString); //convert back to int
        return reverseNum;
    }
    int countNicePairs(vector<int>& nums)
    {
        int result = 0, mod = 1e9 + 7; //initialize result and mod
        unordered_map<int, int> previousPairs = {}; //keep track of all previous pairs that have difference n-r 
        for (const int& currentNum : nums)
        {
            int reverseNum = reverseInt(currentNum); //find reverse of current number
            result = (result + previousPairs[currentNum - reverseNum]) % mod; //add the number of previous pairs 
            ++previousPairs[currentNum - reverseNum]; //increment the count of current pair's difference
        }
        return result;
    }
};