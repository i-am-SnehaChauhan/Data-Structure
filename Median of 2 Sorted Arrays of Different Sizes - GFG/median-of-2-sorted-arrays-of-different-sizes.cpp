//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a, vector<int>& b)
    {
        int n = a.size();
        int m = b.size();
        vector<int> ans(n+m);
        int i=0;
        int j=0; 
        int k=0;
        while(i<n && j<m){
            if(a[i]<b[j]){
            ans[k++] = a[i++];
            }
            else{
                ans[k++] = b[j++];
                }
        }
        while(i<n){
            ans[k++] = a[i++];
            
        }
        while(j<m){
            ans[k++]= b[j++];
        }
        int start = 0;
        int end = ans.size()-1;
        int med = start+(end-start)/2;  
        if(ans.size()%2==0){
        return (ans[med] + ans[med + 1]) / 2.0;      
        }
        else{
            return ans[med];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends