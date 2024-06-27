#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int srcNode, edgeWt, destNode;
    Edge(int a, int b, int c) {
        srcNode = a; edgeWt = b; destNode = c;
    } 
};
// WORKS FOR UNDIRECTED AS WELL AS DIRECTED GRAPHS
// WORKS WITH NEGATIVE EDGES
// DOES NOT WORK WITH NEGATIVE CYCLE
vector<int> bellmanFord(int src) {
    int n = 10;
    vector<Edge> edges;
    vector<int> dist(n+1, 1e17);
    dist[src] = 0;
    for (int i=1; i<=n-1; i++){
        for (auto e: edges) {
            if (dist[e.srcNode] + e.edgeWt < dist[e.destNode]) {
                dist[e.destNode] = dist[e.srcNode] + e.edgeWt;
            }
        }
    }
    bool negCycle = false;
    for (auto e: edges) {
        if (dist[e.srcNode] + e.edgeWt < dist[e.destNode]) {
            negCycle = true;
            break;
        }
    }
}