#include <iostream>
#include "AdjacencyList.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    ostringstream result;

    int totalPages = pages.size();
    for (const string& page : pages) {
        ranks[page] = 1.0 / totalPages;  // initial rank for each page
    }

    for(int i = 1; i < n; i++){
        map<string, double> newRanks;

        for(const auto& rank : ranks){
            const string& page = rank.first;
            double rankSum = 0.0; // sum of ranks from incoming links
            
            for(const string& incoming : inDegree[page]){
                if(outDegree[incoming] > 0){ // avoid division by zero
                    rankSum += ranks[incoming] / outDegree[incoming];
                }
            }
            newRanks[page] = rankSum;  // update rank for the page
        }
        ranks = newRanks; // update all ranks
    }

    vector<string> sortedPages(pages.begin(), pages.end()); // copy pages to vector
    sort(sortedPages.begin(), sortedPages.end());  // sort pages

    result << fixed << setprecision(2);  
    for(const string& page : sortedPages){
        result << page << " " << ranks[page] << "\n"; // print page and its rank
    }

    cout << result.str();
    return result.str();
}

void AdjacencyList::addEdge(const string& from, const string& to){
    if(from == to){
        return; // avoid self-loops
    }
    for(vector<pair<string, double>>::const_iterator it = graph[from].begin(); it != graph[from].end(); ++it){
        if(it->first == to){  
            return;  // avoid adding duplicate edges
        }
    }
    graph[from].emplace_back(to, 0.0); // add edge with initial rank 0.0
    outDegree[from]++;
    inDegree[to].insert(from);  

    ranks[from] = 0.0;  // initialize rank for the new edge
    ranks[to] = 0.0;

    pages.insert(from);  // add pages
    pages.insert(to);
}

map<string, vector<pair<string, double>>> AdjacencyList::getGraph() const{
    return graph;
}

map<string, int> AdjacencyList::getOutDegree() const{
    return outDegree;
}

map<string, set<string>> AdjacencyList::getInDegree() const{
    return inDegree;
}