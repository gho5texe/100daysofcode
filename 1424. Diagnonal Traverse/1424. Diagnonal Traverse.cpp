class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();
        vector<vector<int>> arr; // row+col,col,nums[row][col]

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                arr.push_back({i+j,j,nums[i][j]});
            }
        }
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for(auto x : arr)
        {
            ans.push_back(x[2]);
        }
        return ans;
    }
};
