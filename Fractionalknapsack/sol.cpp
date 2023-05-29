vector<pair<double, int>> v;
        // Traverse the array
        for(int i=0;i<n;i++){
            // Calculate the value of the item
            double value = (double)arr[i].value/(double)arr[i].weight;
            // Push the value and weight of the item in the vector
            v.push_back({value, arr[i].weight});
        }
        // Sort the vector in descending order
        sort(v.begin(), v.end(), greater<pair<double, int>>());
        // Initialize the profit to 0
        double profit = 0;
        // Traverse the vector
        for(int i=0;i<n;i++){
            // If the weight of the item is less than or equal to the remaining weight
            if(v[i].second<=W){
                // Add the value of the item to the profit
                profit += v[i].first*v[i].second;
                // Subtract the weight of the item from the remaining weight
                W -= v[i].second;
            }
            // If the weight of the item is greater than the remaining weight
            else{
                // Add the value of the item to the profit
                profit += v[i].first*W;
                // Break the loop
                break;
            }
        }
        // Return the profit
        return profit;
        