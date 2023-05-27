/* Solution:

Approach:
  1. Similar problem as longest common subsequence.
  2. We will use dynamic programming to solve this problem.
  3. We will create a 2D array dp of size (n+1)*(n+1).
  4. We need to find the longest common subsequence of the string with itself with the 
     condition that the two characters shouldn't be at the same index.
  5. If the characters are same and the indices are not same then we will add 1 to the
     previous value.
  6. If the characters are not same then we will take the maximum of the previous values.
    7. We will return the last element of the dp array.
    
         Time Complexity: O(n^2)
         Space Complexity: O(n^2)
  */

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int longestRepeatingSubsequence(string str){
        int n = str.length();
        // Create dp array of size (n+1)*(n+1)
        int dp[n+1][n+1];
        // Initialize the dp array with 0
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }

        // Traverse the dp array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // If the characters are same and the indices are not same
                if(str[i-1]==str[j-1] && i!=j){
                    // Add 1 to the previous value
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                // If the characters are not same
                else{
                    // Take the maximum of the previous values
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // Return the last element of the dp array
        return dp[n][n];

    }