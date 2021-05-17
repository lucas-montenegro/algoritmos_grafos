#include <bits/stdc++.h>
#define INF 1000000


using namespace std;

vector<vector<pair<int, int>>> adjList;
vector<int> bestDistance;
vector<bool> verticesVisited;
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
        adjList[v2].push_back(make_pair(v1, edgeWeight));
    }

    return;
}

void dijkstra() {
    int currentVertice, currentDistance;
    pair<int, int> head;

    // need to invert the order of vertice to visit and edgeWeight because the pq orders by the first element in ascending order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push(make_pair(0, 0)); // inserting the distance to the root (0) and the root vertice (also 0)

    while(pq.size() > 0) {
        head = pq.top();
        currentVertice = head.second;
        currentDistance = head.first;        
        pq.pop();

        if(verticesVisited[currentVertice] == false) {
            verticesVisited[currentVertice] = true; // visiting a new vertice
            bestDistance[currentVertice] = currentDistance; // setting the best distance to this vertice

            for(int i = 0; i < adjList[currentVertice].size(); i++) {
                pq.push(make_pair(adjList[currentVertice][i].second + currentDistance, adjList[currentVertice][i].first));
            }
        }
    }
    
    return;
}

int main() {
    cin >> v >> e;
    adjList.resize(v);
    verticesVisited.resize(v);
    bestDistance.resize(v);

    for(int i = 0; i < v; i++) {
        bestDistance[i] = INF;
        verticesVisited[i] = false;
    }

    readEdges();
    dijkstra();
    showResults();
    return 0;
}