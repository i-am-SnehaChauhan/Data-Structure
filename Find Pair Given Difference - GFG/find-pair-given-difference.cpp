//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


#include <unordered_set>

bool findPair(int arr[], int size, int n){
    std::unordered_set<int> numSet; // Create a hash set to store numbers
    
    for(int i = 0; i < size; i++){
        // Check if (arr[i] - n) or (arr[i] + n) exists in the set
        if(numSet.count(arr[i] - n) || numSet.count(arr[i] + n)){
            return true;
        }
        
        // Insert current element into the set
        numSet.insert(arr[i]);
    }
    
    return false;
}
