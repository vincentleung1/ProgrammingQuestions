/* 
 *   https://leetcode.com/problems/number-of-islands/description/
 *   Runtime of solution is O(n*m) where n is the width 
 *   of the 2D array and m is the length of the 2D array.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for ( int i = 0; i < grid.size(); i++){
            for ( int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1') {
                    count++;
                    recursiveDeleteIsland(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void recursiveDeleteIsland (vector<vector<char>>& grid, int x, int y) {
        // Delete myself 
        grid[x][y] = '0';
        if (grid.size()-1 > x && grid[x+1][y] == '1') {
            recursiveDeleteIsland(grid, x+1,y);
        } 
        if (x > 0 && grid[x-1][y] == '1') {
            recursiveDeleteIsland(grid, x-1,y);
        } 
        if (grid[x].size()-1 > y && grid[x][y+1] == '1') {
            recursiveDeleteIsland(grid, x, y+1);
        }
        if (y > 0 && grid[x][y-1] == '1') {
            recursiveDeleteIsland(grid, x, y-1);
        }
        
        return;
    }
};