#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

int v, e;
vector<vector<int>> adjMatrix;


void showResults() {
    for(int i = 0; i < v; i++) {
		for(int j = 0; j < v; j++) {
			cout << "Distance from " << i << " to " << j << " is ";
            if(adjMatrix[i][j] != INF) {
                cout << adjMatrix[i][j] << endl;   
            }
            else {
                cout << "INF" << endl;   
            }
		}
	}
}

void initializeMatrix() {
    adjMatrix.resize(v);
	for(int i = 0; i < v; i++) {
        adjMatrix[i].resize(v);
		for(int j = 0; j < v; j++) {
            (i == j) ? adjMatrix[i][j] = 0 : adjMatrix[i][j] = INF;
		}
	}
}

void readEdges() {
    int v1, v2, edgeWeight;

    for(int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> edgeWeight;
        adjMatrix[v1][v2] = edgeWeight;
    }
}

void floydWarshall() {
	for(int k = 0; k < v; k++) {
		for(int i = 0; i < v; i++) {
			for(int j = 0; j < v; j++) {
				if(adjMatrix[k][j] != INF && adjMatrix[j][k] != INF && adjMatrix[i][k] != INF && adjMatrix[k][i] != INF) {
					adjMatrix[i][j] = min(adjMatrix[i][j], 0);
				}
				else if(adjMatrix[k][j] != INF && adjMatrix[j][k] != INF) {
					adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + 0);
				}
				else if(adjMatrix[i][k] != INF && adjMatrix[k][i] != INF) {
					adjMatrix[i][j] = min(adjMatrix[i][j], 0 + adjMatrix[k][j]);
				}
				else {
					adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
				}
			}
		}
	}	
}


int main() {
    cin >> v >> e;
    initializeMatrix();
    readEdges();
    floydWarshall();
    showResults();
    
	return 0;
}