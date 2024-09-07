#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>  // Include this for std::numeric_limits
#include <iomanip>

using namespace std;

typedef vector<vector<int>> Graph;

struct Train {
    int id;
    int arrival;
    int departure;
    int delay;
};

bool compareByArrival(const Train& a, const Train& b) {
    return a.arrival < b.arrival;
}

// Greedy TSP algorithm to find a path with minimal cost
vector<int> tspGreedy(const Graph& costMatrix, int start) {
    int n = costMatrix.size();
    vector<int> path;
    vector<bool> visited(n, false);
    int current = start;
    path.push_back(current);
    visited[current] = true;
    
    for (int i = 1; i < n; ++i) {
        int next = -1;
        int minCost = numeric_limits<int>::max();  // Use numeric_limits<int>::max()
        
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && costMatrix[current][j] < minCost) {
                minCost = costMatrix[current][j];
                next = j;
            }
        }
        
        path.push_back(next);
        visited[next] = true;
        current = next;
    }
    
    return path;
}

int main() {
    int numTrains;
    
    // Input number of trains
    cout << "Enter the total number of trains: ";
    cin >> numTrains;
    
    vector<Train> trains(numTrains);
    Graph costMatrix(numTrains, vector<int>(numTrains));
    
    // Input details for each train
    cout << "Enter train details (ID Arrival Departure Delay):" << endl;
    for (int i = 0; i < numTrains; ++i) {
        cout << "Train " << (i + 1) << ": ";
        cin >> trains[i].id >> trains[i].arrival >> trains[i].departure >> trains[i].delay;
    }
    
    // Input cost matrix (distances between stations)
    cout << "Enter the cost matrix (distances between stations):" << endl;
    for (int i = 0; i < numTrains; ++i) {
        for (int j = 0; j < numTrains; ++j) {
            cin >> costMatrix[i][j];
        }
    }
    
    int startCity;
    
    // Input starting city
    cout << "Enter the starting city (0-based index): ";
    cin >> startCity;
    
    // Compute optimal route using TSP
    vector<int> route = tspGreedy(costMatrix, startCity);
    
    cout << fixed << setprecision(2);
    cout << "\nOptimized Train Schedule:" << endl;
    
    for (int i = 0; i < numTrains; ++i) {
        int trainIndex = route[i];
        cout << "Train " << trains[trainIndex].id << " scheduled from " << trains[trainIndex].arrival << " to " << trains[trainIndex].departure << " with delay " << trains[trainIndex].delay << endl;
    }
    
    return 0;
}
