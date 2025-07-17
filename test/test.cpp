#define CATCH_CONFIG_MAIN
#include "catch/catch_amalgamated.hpp"
#include <iostream>
#include <sstream>
#include <string>

#include "AdjacencyList.h"

using namespace std;

//test 1
TEST_CASE("adding edges and graph structure", "[structure]") {
  AdjacencyList aList;
  aList.addEdge("a.com", "b.com");
  aList.addEdge("a.com", "c.com"); //adding two edges

  auto graph = aList.getGraph();
  REQUIRE(graph["a.com"].size() == 2);  //checking size
  REQUIRE(graph["a.com"][0].first == "b.com");  //checking edge is correct
  REQUIRE(graph["a.com"][1].first == "c.com");  //checking edge is correct
}

//test 2
TEST_CASE("duplicate edges", "[structure]"){
  AdjacencyList aList;
  aList.addEdge("a.com", "b.com");
  aList.addEdge("a.com", "b.com"); //adding duplicate edge

  auto graph = aList.getGraph();
  REQUIRE(graph["a.com"].size() == 1);  //should only be one edge
}

//test 3
TEST_CASE("outdegree and indegree", "[degrees]"){
  AdjacencyList aList;
  aList.addEdge("a.com", "b.com");
  aList.addEdge("c.com", "b.com"); //adding edges

  auto out = aList.getOutDegree();
  auto in = aList.getInDegree();  //getting in and out degrees

  REQUIRE(out["a.com"] == 1); //checking a has one out degree
  REQUIRE(out["c.com"] == 1); //checking c has one out degree
  REQUIRE(in["b.com"].count("a.com") == 1); //checking b has one in degree from a
  REQUIRE(in["b.com"].count("c.com") == 1); //checking b has one in degree from c
}

//test 4
TEST_CASE("self loop", "[structure]"){
  AdjacencyList aList;
  aList.addEdge("a.com", "a.com");  //adding loop
  auto graph = aList.getGraph();
  REQUIRE(graph["a.com"].size() == 0);  //no loop allowed
}

//test 5
TEST_CASE("single edge added", "[structure]"){
  AdjacencyList aList;
  aList.addEdge("a.com", "b.com");  //adding edge

  auto graph = aList.getGraph();
  REQUIRE(graph["a.com"].size() == 1);  //check size
  REQUIRE(graph["a.com"][0].first == "b.com");  //check edge
}

// See the following for an example of how to easily test your output.
// This uses C++ "raw strings" and assumes your PageRank outputs a string with
//   the same thing you print.
TEST_CASE("Example PageRank Output Test", "[flag]") {
  // the following is a "raw string" - you can write the exact input (without
  //   any indentation!) and it should work as expected
  string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

  string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

  string actualOutput;

  // somehow pass your input into your AdjacencyList and parse it to call the
  // correct functions, for example:
  //  AdjacencyList g;
  //  g.parseInput(input)
  //  actualOutput = g.getStringRepresentation()

  REQUIRE(actualOutput == expectedOutput);
}
