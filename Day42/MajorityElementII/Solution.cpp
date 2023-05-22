// Prob : Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

/* Approach 1: Brute Force 
    At max 2 elements can be appear more than n/3 time in the n size array. Let take n = 8 and
    n/3 = 2 elements which are appear min 3 time will be the ans so 3+3+3 = 9 but no of should 
    be 8 so it is clear at max 2 elements will be there. 
    
    So we will 
    1 -> take a vector ans and start traversing 
    2 -> check if it is empty or not if it is empty or ans.back() != nums[i] 
    3 -> then we will check the count of nums[i] in the array if it is greater
        than n/3 then we will push it into the ans vector.

    Time Complexity : O(n^2)
    Space Complexity : O(1)

    */ 
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || ans.back()!=nums[i]){
                int cnt = 0;
                for(int j=i; j<n; j++){
                    if(nums[i]==nums[j]){
                        cnt++;
                    }
                }
                if(cnt>n/3){
                    ans.push_back(nums[i]);
                }
                if(ans.size()==2){
                    break;
                }
            }
        }
        return ans;
    }
};

/*Approach 2: Using Hash_Map
    1 -> Take the ans vector and hash map.
    2 -> Start Traversing array increment the count of element in the map.
    3 -> If count > 3 then push the element int the ans vector. 
    
    Time Complexity : O(n)
    Space Complexity : O(n)
    */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==n/3+1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }