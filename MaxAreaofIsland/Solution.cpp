/* Solution:
 
Approach:
  1- Using DFS.
  2- We will traverse the grid and if we find 1, we will call DFS on it.
  3- In DFS, we will check if the current cell is valid and is 1, we will mark it as 0 and increment area 
   call 4 directionally.
  4- We will return the max area. 

  Time Complexity: O(m*n)
    Space Complexity: O(m*n)
  
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;
        int area = 1;
        area += dfs(grid, i+1, j);
        area += dfs(grid, i-1, j);
        area += dfs(grid, i, j+1);
        area += dfs(grid, i, j-1);
        return area;
    }
};
