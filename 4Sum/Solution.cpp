/*Solution:
  
Approach 3:
 1- Using Unordered Map .
 2- first we will store the sum of all possible pairs in a map.
 3- Then we will traverse the array and check if the sum of current pair is present in 
    the map or not.
 4- If it is present, then check for all the indexes they are distict or not.
 5- If they are distinct, then we will push them in the result vector.
 6- We will return the result vector.

    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        if(nums.size()<4){
            return result;
        }
        unordered_map<int, vector<pair<int, int>>> map;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int sum = nums[i]+nums[j];
                if(map.find(target-sum)!=map.end()){
                    for(auto pair: map[target-sum]){
                        if(pair.first!=i && pair.first!=j && pair.second!=i && pair.second!=j){
                            vector<int> temp = {nums[i], nums[j], nums[pair.first], nums[pair.second]};
                            sort(temp.begin(), temp.end());
                            if(find(result.begin(), result.end(), temp)==result.end()){
                                result.push_back(temp);
                            }
                        }
                    }
                }
                map[sum].push_back({i, j});
            }
        }
        return result;
    }
};

/* 
Approach 2:
 1- Using Two Pointer.
 2- We will sort the array.
 3- Then we will traverse the array and for each element, we will call threeSum function.
 4- In threeSum function, we will use two pointer approach.
 5- We will check if the sum of current element and left and right pointer is equal to target or not.
 6- If it is equal, then we will push them in the result vector.
 7- If the sum is less than target, then we will increment left pointer.
 8- If the sum is greater than target, then we will decrement right pointer.
 9- We will return the result vector.

    Time Complexity: O(n^3)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        if(nums.size()<4){
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            threeSum(nums, target-nums[i], i+1, result);
        }
        return result;
    }
    
    void threeSum(vector<int>& nums, int target, int start, vector<vector<int>>& result){
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==target){
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
};