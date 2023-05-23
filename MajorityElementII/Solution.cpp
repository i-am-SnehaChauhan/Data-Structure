// Prob : Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

/* Approach 1: Brute Force 
    At max 2 elements can be appear more than n/3 time in the n size array. Let take n = 8 and
    n/3 = 2 elements which are appear min 3 time will be the ans so 3+3+3 = 9 but no of should 
    be 8 so it is clear at max 2 elements will be there. 
    
    1 -> Take the ans vector.
    2 -> Start traversing the array and check if nums[i] == nums[j] then increment the count.
    3 -> If count > 3 then push the element int the ans vector. 
    
    Time Complexity : O(n^2)
    Space Complexity : O(n)
    
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

/*Approach 2: Using Sorting
    1 -> Sort the array.
    2 -> Take two variables and initialize them with 0 and 1.
    3 -> Start traversing the array and check if nums[i] == nums[0] then increment the count1
        else if nums[i] == nums[1] then increment the count2.
    4 -> If count1 == 0 then nums[i] will be the first element and increment the count1.
    5 -> If count2 == 0 then nums[i] will be the second element and increment the count2.
    6 -> If nums[i] != nums[0] && nums[i] != nums[1] then decrement the count1 and count2.
    7 -> Now we have two elements which are appear more than n/3 time in the array.
    8 -> Now we will check the count of both the elements in the array if it is greater than n/3
        then we will push it into the ans vector.
    
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
    */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int count1 = 0, count2 = 0, first = INT_MAX, second = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]==first){
                count1++;
            }
            else if(nums[i]==second){
                count2++;
            }
            else if(count1==0){
                first = nums[i];
                count1++;
            }
            else if(count2==0){
                second = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==first){
                count1++;
            }
            else if(nums[i]==second){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(first);
        }
        if(count2>n/3){
            ans.push_back(second);
        }
        return ans;
    }
};



/*Approach 3: Using Hash_Map
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

/*Approach 4: Using Moore Voting Algorithm
    1 -> Take two variables and initialize them with 0 and 1.
    2 -> Start traversing the array and check if nums[i] == nums[0] then increment the count1
        else if nums[i] == nums[1] then increment the count2.
    3 -> If count1 == 0 then nums[i] will be the first element and increment the count1.
    4 -> If count2 == 0 then nums[i] will be the second element and increment the count2.
    5 -> If nums[i] != nums[0] && nums[i] != nums[1] then decrement the count1 and count2.
    6 -> Now we have two elements which are appear more than n/3 time in the array.
    7 -> Now we will check the count of both the elements in the array if it is greater than n/3
        then we will push it into the ans vector.
    
    Time Complexity : O(n)
    Space Complexity : O(1)
    */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int count1 = 0, count2 = 0, first = INT_MAX, second = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]==first){
                count1++;
            }
            else if(nums[i]==second){
                count2++;
            }
            else if(count1==0){
                first = nums[i];
                count1++;
            }
            else if(count2==0){
                second = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==first){
                count1++;
            }
            else if(nums[i]==second){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(first);
        }
        if(count2>n/3){
            ans.push_back(second);
        }
        return ans;
    }
};

