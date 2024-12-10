#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCostToReachCityN(vector<int>& costs) {
    int n = costs.size();
    
    // Create an array to store the minimum cost to reach each city.
    vector<int> dp(n, INT_MAX);
    
    // Base case: The minimum cost to reach the airport in city 1 is 0.
    dp[0] = 0;
    
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach city i from either city (i-1) or (i-3), if they exist.
        for (int j = 1; j <= 3 && i - j >= 0; j++) {
            int cost = dp[i - j] + abs(costs[i] - costs[i - j]);
            dp[i] = min(dp[i], cost);
        }
    }
    
    // The minimum cost to reach city N is stored in dp[N-1].
    return dp[n - 1];
}

int main() {
    vector<int> costs = {1,4,1};
    
    int minCost = minCostToReachCityN(costs);
    
    cout << "Minimum possible cost of flight ticket to reach city N: " << minCost << endl;
    
    return 0;
}
