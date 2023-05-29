#include < bits/stdc++.h>
using namespace std;

class Item{
    public:
    int value;
    int weight;
    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};


// Function to find the maximum profit
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Create a vector of pair of double and int
    vector<pair<double, int>> v;
    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Calculate the value of the item
        double value = (double)arr[i].value / (double)arr[i].weight;
        // Push the value and weight of the item in the vector
        v.push_back({value, arr[i].weight});
    }
    // Sort the vector in descending order
    sort(v.begin(), v.end(), greater<pair<double, int>>());
    // Initialize the profit to 0
    double profit = 0;
    // Traverse the vector
    for (int i = 0; i < n; i++)
    {
        // If the weight of the item is less than or equal to the remaining weight
        if (v[i].second <= W)
        {
            // Add the value of the item to the profit
            profit += v[i].first * v[i].second;
            // Subtract the weight of the item from the remaining weight
            W -= v[i].second;
        }
        // If the weight of the item is greater than the remaining weight
        else
        {
            // Add the value of the item to the profit
            profit += v[i].first * W;
            // Break the loop
            break;
        }
    }
    // Return the profit
    return profit;
}

int main()
{
    // Initialize the number of items
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    // Initialize the array of items
    Item arr[n];
    // Initialize the value and weight of the items
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value and weight of item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }
    // Initialize the capacity of the knapsack
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    // Call the function to find the maximum profit
    double profit = fractionalKnapsack(W, arr, n);
    // Print the maximum profit
    cout << "The maximum profit is: " << profit << endl;
    return 0;
}
