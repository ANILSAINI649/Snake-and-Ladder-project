#include <bits/stdc++.h>
using namespace std;

extern int bfs_min_moves(vector<pair<int,int>>, vector<pair<int,int>>);

int main() {
    vector<pair<int,int>> ladders = {{3, 90}, {56, 76}};
    vector<pair<int,int>> snakes = {{99, 10}, {30, 5}};

    int moves = bfs_min_moves(ladders, snakes);
    cout << "Test Case 1: " << (moves == 3 ? "PASS" : "FAIL") << "\n";
}
