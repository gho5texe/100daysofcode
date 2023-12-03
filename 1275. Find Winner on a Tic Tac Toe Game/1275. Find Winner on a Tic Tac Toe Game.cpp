class Solution {
public:

    bool check(vector<vector<char>>& grid, char c) {
        for(int i = 0 ; i < 3 ; i++) {
            if(grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) 
                return true;
            if(grid[0][i] == c && grid[1][i] == c && grid[2][i] == c) 
                return true;   
        }

        if(grid[1][1] == c && ((grid[0][0] == c && grid[2][2] == c) || 
            (grid[0][2] == c && grid[2][0] == c)))
            return true;
        
        return false;
        
    }
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<char > > grid(3, vector<char >(3, '.'));

        for(int i = 0 ; i < n ; i++) {
            if(i % 2 == 0)
                grid[moves[i][0]][moves[i][1]] = 'X';
            else
                grid[moves[i][0]][moves[i][1]] = 'O';
        }
        bool A = check(grid, 'X');
        bool B = check(grid, 'O');
        if(!A && !B && n == 9)
            return "Draw";
        else if(A)
            return "A";
        else if(B)
            return "B";
        else
            return "Pending";
    }
};