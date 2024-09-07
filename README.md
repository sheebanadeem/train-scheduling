
# Train Scheduling with TSP and Greedy Approach

This C++ program solves a train scheduling problem using a combination of the Traveling Salesman Problem (TSP) and a greedy algorithm. The goal is to determine an optimized route for visiting stations and then schedule trains based on this route.

## Features

- **Input Number of Trains:** Specify the number of trains and their details.
- **Input Cost Matrix:** Define the distances or costs between stations.
- **Compute Optimal Route:** Use a greedy TSP approach to determine the best route.
- **Schedule Trains:** Output the optimized schedule for each train based on the TSP route.

## Requirements

- C++ compiler (e.g., g++, MinGW)
- Basic knowledge of C++ programming

## Compilation

To compile the program, use the following command:

```bash
g++ -o train_tsp_scheduling train_tsp_scheduling.cpp
