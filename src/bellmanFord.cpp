#include <bits/stdc++.h>
#define INF 1000000


using namespace std;

vector<vector<pair<int, int>>> adjList;
vector<int> bestDistance;
int v, e;

void showAllEdges() {
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << i << " " << adjList[i][j].first << " " << adjList[i][j].second << endl;
        }
    }
}

void showResults() {
    for(int i = 0; i < v; i++) {
        cout << "Vertice: " << i << " | Distance from root: " << bestDistance[i] << endl;
    }

    return;
}

void readEdges() {
    int v1, v2, edgeWeight;
    for(int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> edgeWeight;

        adjList[v1].push_back(make_pair(v2, edgeWeight));
    }

    return;
}

void bellmanFord() {
    int nextVertice, edgeDistance, currentDistance;

    for(int i = 0; i < v - 1; i++) {    
        for(int index = 0; index < adjList.size(); index++) {
            for(auto neighbor: adjList[index]) {
                nextVertice = neighbor.first;
                edgeDistance = neighbor.second;       
                currentDistance = bestDistance[index] + edgeDistance;

                if(currentDistance < bestDistance[nextVertice]) {
                    bestDistance[nextVertice] = currentDistance; // setting the best distance to this vertice
                } 
            }
        }
    }

    for(int index = 0; index < adjList.size(); index++) {
        for(auto neighbor: adjList[index]) {
            nextVertice = neighbor.first;
            edgeDistance = neighbor.second;       
            currentDistance = bestDistance[index] + edgeDistance;

            if(currentDistance < bestDistance[nextVertice]) {
                bestDistance[nextVertice] = -INF; // negative cycle
                cout << "Found a negative cycle" << endl;
            } 
        }
    }
    
    return;
}

int main() {
    cin >> v >> e;
    adjList.resize(v);
    bestDistance.resize(v);

    bestDistance[0] = 0;
    for(int i = 1; i < v; i++) {
        bestDistance[i] = INF;
    }

    readEdges();
    bellmanFord();
    showResults();
    return 0;
}