#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

class AdjacencyList {
    private:
        map<string, vector<pair<string, double>>> graph;
        map<string, double> ranks;
        map<string, int> outDegree;
        map<string, set<string>> inDegree;
    public:
        string PageRank(int n);
        void addEdge(const string& from, const string& to);
        map<string, vector<pair<string, double>>> getGraph();
        map<string, int> getOutDegree();
        map<string, set<string>> getInDegree();
};

// This class and method are optional.
