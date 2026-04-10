#include <bits/stdc++.h>
#include <random>
using namespace std;

// Global Random Number Generator - A random number generator engine based on Mersenne Twister algorithm(new thing :))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double randDouble(double l, double r) {
    uniform_real_distribution<double> dist(l, r);
    return dist(rng);
}

int randInt(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int main() {
    ofstream out("input.txt");

    int N = randInt(2, 10);   // cars
    int M = randInt(2, 8);    // mechanics
    int K = randInt(1, 5);    // fatigue limit

    out << N << "\n";
    out << M << " " << K << "\n";

    int globalNode = 1;

    for (int car = 1; car <= N; car++) {

        int nodes = randInt(4, 8);

        int maxEdges = nodes * (nodes - 1) / 2;
        int E = randInt(1, maxEdges);

        out << E << "\n";

        vector<pair<int,int>> possible;

        // DAG edges (u < v)
        for (int i = 0; i < nodes; i++) {
            for (int j = i + 1; j < nodes; j++) {
                possible.push_back({i, j});
            }
        }

        shuffle(possible.begin(), possible.end(), rng);

        for (int i = 0; i < E; i++) {
            int u = globalNode + possible[i].first;
            int v = globalNode + possible[i].second;

            double p=randDouble(0.01, 0.99);

            out<<u<<" "<<v<<" "<<fixed<<setprecision(2)<<p<<"\n";
        }

        globalNode+=nodes;
    }

    out.close();

    return 0;
}