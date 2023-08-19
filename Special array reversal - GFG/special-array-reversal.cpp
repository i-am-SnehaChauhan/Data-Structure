//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    string reverse(string str)
    { 
        int n = str.size();
        stack<int>temp;
        for(int i=0; i<n; i++){
            if(str[i]>='a' && str[i]<='z' ||str[i]>='A' && str[i]<='Z'){
                temp.push(str[i]);
            }
        }
        
        
        for(int i=0; i<n; i++){
            if(!temp.empty()){
            if(str[i]>='a' && str[i]<='z' ||str[i]>='A' && str[i]<='Z'){
                str[i] = temp.top();
                temp.pop();
            }
            
            }
        }
        return str;
        
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends