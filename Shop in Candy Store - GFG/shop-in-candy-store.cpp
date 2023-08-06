//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int maxAmt(int price[], int n, int k){
        sort(price, price+n, greater<int>());
        int res = 0;
        int a = n;
        for(int i=0; i<n-k; i++){
            if(a>0){
                res += price[i];
                a = a-k-1;
            }
        }
        
        return res;
    }
    int minAmt(int price[], int n, int k){
        sort(price, price+n);
        int res = 0;
        int a = n;
        for(int i=0; i<n-k; i++){
            if(a>0){
                res += price[i];
                a = a-k-1;
            }
        }
        
        return res;
    }
    vector<int> candyStore(int price[], int n, int k)
    {
       vector<int> ans(2);
       ans[0] = minAmt(price, n, k);
       ans[1] = maxAmt(price, n, k);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends