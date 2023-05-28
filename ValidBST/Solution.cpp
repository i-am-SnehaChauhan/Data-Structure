/* Solution:

Approach:
1- We have to find given tree is BST or not.
2- We will use recursion to solve this problem.
3- We will create a function isBST which will take the root node as an argument.
4- We will create a helper function isBSTUtil which will take the root node, 
   minimum value and maximum value as arguments.
5- We will check if the root node is NULL then we will return true.
6- We will check if the root node's data is less than the minimum value or greater
   than the maximum value then we will return false.
7- We will recursively call the isBSTUtil function for the left subtree and right subtree.
8- We will return the AND of the above two calls.
9- We will call the isBSTUtil function from the isBST function and pass the root node,
   INT_MIN and INT_MAX as arguments.

        Time Complexity: O(n)
        Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Helper function to check if the given tree is BST or not
    bool isBSTUtil(Node* root, int min, int max){
        // If the root node is NULL then return true
        if(root==NULL){
            return true;
        }
        // If the root node's data is less than the minimum value or greater than the maximum value
        // then return false
        if(root->data<min || root->data>max){
            return false;
        }
        // Recursively call the isBSTUtil function for the left subtree and right subtree
        return isBSTUtil(root->left, min, root->data-1) && isBSTUtil(root->right, root->data+1, max);
    }

    // Function to check if the given tree is BST or not
    bool isBST(Node* root){
        // Call the isBSTUtil function and pass the root node, INT_MIN and INT_MAX as arguments
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};
}