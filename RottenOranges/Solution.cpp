/* Solution:

Approach: 
1- We have to find the minimum time required to rot all oranges.
2- We can use BFS to solve this problem.
3- We will use a queue to store the rotten oranges and then we will traverse the queue 
   and rot the oranges.
4- We will also keep track of the time required to rot the oranges.
5- We will also keep track of the fresh oranges left in the grid.
6- If there are no fresh oranges left in the grid then we will return the time required
   to rot the oranges.

   Time Complexity: O(m*n)
   Space Complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    int orangesRotting(vector<vector<int>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<pair<int,int>,int>> q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(matrix[i][j]==1){
                    fresh++;
                }
            }
        }
        int time = 0;
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i=0;i<4;i++){
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]==1){
                    matrix[nr][nc] = 2;
                    q.push({{nr,nc},t+1});
                    fresh--;
                }
            }
        }
        if(fresh>0){
            return -1;
        }

        return time;
    }