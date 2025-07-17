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
        set<string> pages;
    public:
        string PageRank(int n);
        void addEdge(const string& from, const string& to);
        map<string, vector<pair<string, double>>> getGraph() const;
        map<string, int> getOutDegree() const;
        map<string, set<string>> getInDegree() const;
};

// This class and method are optional.
