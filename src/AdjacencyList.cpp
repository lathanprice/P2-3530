#include <iostream>
#include "AdjacencyList.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    string result;


    // do your page rank

    cout << result;
    return result;
}

void AdjacencyList::addEdge(const string& from, const string& to){
    for(const auto& neighbor : graph[from]){
        if(neighbor.first == to){
            return;
        }
    }
    graph[from].emplace_back(to, 1.0);
    outDegree[from]++;
    inDegree[to].insert(from);

    ranks[from] = 0.0;
    ranks[to] = 0.0;
}

map<string, vector<pair<string, double>>> AdjacencyList::getGraph(){
    return graph;
}
map<string, int> AdjacencyList::getOutDegree(){
    return outDegree;
}
map<string, set<string>> AdjacencyList::getInDegree(){
    return inDegree;
}
