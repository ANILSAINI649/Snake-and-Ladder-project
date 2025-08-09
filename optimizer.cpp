#include <bits/stdc++.h>
using namespace std;

extern int bfs_min_moves(vector<pair<int,int>>, vector<pair<int,int>>);

struct Result {
    int moves;
    int snakeHead;
    int snakeTail;
};

Result minMovesWithOptimization(vector<pair<int,int>> ladders, vector<pair<int,int>> snakes) {
    int base_moves = bfs_min_moves(ladders, snakes);
    Result best = {base_moves, -1, -1};

    for (int head = 2; head <= 99; head++) {
        for (int tail = 1; tail < head; tail++) {
            auto new_snakes = snakes;
            new_snakes.push_back({head, tail});
            int moves = bfs_min_moves(ladders, new_snakes);
            if (moves != -1 && moves < best.moves) {
                best = {moves, head, tail};
            }
        }
    }
    return best;
}
