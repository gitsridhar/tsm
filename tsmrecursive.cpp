#include <iostream>

#import <vector>

using namespace std;

#define V 4

void tsm(int graph[][V], vector<bool> &v, int currPos, int n, int count,
         int cost, int &ans) {
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }

    for(int i=0; i<n; i++) {
        if(!v[i] && graph[currPos][i]) {
            v[i] = true;
            tsm(graph, v, i, n, count+1,
                cost+graph[currPos][i], ans);

            v[i] = false;
        }
    }
}
int main() {
    int graph[][V] = {{ 0, 10, 15, 20 },
        {10,  0, 35, 25 },
        {15, 35,  0, 30 },
        {20, 25, 30,  0 }};

    vector<bool> v(V);

    for(int i=0; i<V; i++) {
        v[i] = false;
    } 
    
    v[0] = true;
    int ans = INT_MAX;

    tsm(graph, v, 0, V, 1, 0, ans);

    cout << ans << endl;

    return 0;
}

