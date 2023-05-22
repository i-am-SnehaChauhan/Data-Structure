# Scramble String
[Click here](https://leetcode.com/problems/scramble-string/)
## We can scramble a string s to get a string t using the following algorithm:

* If the length of the string is 1, stop.
* If the length of the string is > 1, do the following:
* Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
* Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
* Apply step 1 recursively on each of the two substrings x and y.
### Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

![image](https://user-images.githubusercontent.com/94298791/236491734-f7440c4d-aeb8-4092-942d-24ec755e55a1.png)
