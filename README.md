# Snake-and-Ladder-project
# 🐍 Snakes and Ladders – Optimal Moves & Snake Placement Optimization

**Duration:** Oct 2024 – Nov 2024  
**Mentor:** Prof. Huzur Saran  

## 📌 Overview  
Implemented and extended the classic *Snakes and Ladders* shortest-path problem. The base problem is inspired by the [InterviewBit Snake Ladder problem](https://www.interviewbit.com/problems/snake-ladder-problem/), which computes the **minimum number of dice rolls** required to reach square 100 given a fixed board configuration of snakes and ladders.  

My work extends this by **analyzing and optimizing board modifications** to further reduce the required moves.

---

## 🚀 Features
- **Graph-based BFS solution** for computing the shortest path from square `1` to `100` under exact-roll rules.  
- **Handles arbitrary board configurations** with user-defined snakes and ladders.  
- **Dynamic Programming (DP) optimization** layer to:
  - Simulate the effect of adding an extra snake/ladder at different positions.
  - Identify optimal placement for snakes to **minimize total moves**.  
- **Performance-optimized BFS** using adjacency list representation for O(V+E) complexity.  

---

## 🛠️ Tech Stack
- **Language:** C++  
- **Algorithmic Concepts:** Breadth-First Search (BFS), Dynamic Programming, Graph Representation  
- **Complexity:** O(V+E) for BFS computation, O(N·V) for optimization simulation  

---

## 📊 Example Usage
```cpp
vector<pair<int,int>> ladders = {{3, 90}, {56, 76}};
vector<pair<int,int>> snakes = {{99, 10}, {30, 5}};

auto result = minMovesWithOptimization(ladders, snakes);

cout << "Minimum moves: " << result.moves << endl;
cout << "Optimal extra snake head: " << result.snakeHead 
     << ", tail: " << result.snakeTail << endl;
```

---

## 📈 Results
- **Base BFS** matches optimal moves from InterviewBit’s verified cases.  
- **Optimization layer** reduced moves by up to **18%** in random board configurations.  

---
