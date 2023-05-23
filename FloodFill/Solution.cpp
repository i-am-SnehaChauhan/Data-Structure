/*Sol: Flood Fill Algorithm

  Approach: 
  1- We will use DFS to solve this problem.
  2- We will check for the base cases first. 
  3- If the base cases are not satisfied, we will change the color of the current pixel 
    and call the dfs function for the adjacent pixels.
  4- We will keep on doing this until we reach the base case.

    Time Complexity: O(N*M)
    Space Complexity: O(N*M)
  
  */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,val,newColor);
        dfs(image,i+1,j,val,newColor);
        dfs(image,i,j-1,val,newColor);
        dfs(image,i,j+1,val,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,newColor);
        return image;
    }
};
