/* Prob: Given two strings text1 and text2, return the length of their longest common subsequence. 
   If there is no common subsequence, return 0.*/

//Sol: 1.Recursion
/*We have two string a = "abcde" and b = "ace" 
BaseCase: Check if any one of them are empty then simply return 0
Now we start traversing two condition comes char at last equal or not
if equal then return 1 + function(a,b, n-1,n-1)
else return max(function(a,b, n-1, m),function(a,b, n, m-1))

Time Complexity: O(2^n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
class Solution {
public:
    int helper(string text1, string text2, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if(text1[n-1]==text2[m-1]){
            return 1 + helper(text1, text2, n-1, m-1);
        }
        else{
            return max(helper(text1, text2, n-1, m),helper(text1, text2, n, m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        return helper(text1, text2, n, m);
    }
};

//2.Memorisation 
/*Same as above but we store the value in a matrix and check if the value is already present or not"
  Time Complexity: O(m * n) where m and n are the string lengths.
  Auxiliary Space: O(m * n) */

class Solution {
public:
    int helper(string text1, string text2, int n, int m,vector<vector<int> >& dp){
        if(n==0 || m==0){
            return 0;
        }
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]= 1 + helper(text1, text2, n-1, m-1, dp);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        return  dp[n][m] = max(helper(text1, text2, n-1, m, dp),helper(text1, text2, n, m-1, dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        return helper(text1, text2, n, m, dp);
    }
};

//3.Dynamic Programming
/* */