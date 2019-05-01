#include "alg.h"

// Eulerian path problem: use Hierholzer's algorithm
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78766/Share-my-solution
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B

map<string, priority_queue<string, vector<string>, greater<string>>> targets;
vector<string> route;

void visit(string airport) {
    while (targets[airport].size()) {
        string next = targets[airport].top();
        targets[airport].pop();
        visit(next);
    }
    route.push_back(airport);
}

vector<string> findItinerary(vector<vector<string>> tickets) {
    targets.clear();
    route.clear();
    for (auto ticket: tickets) {
        targets[ticket[0]].push(ticket[1]);
    }
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}


int main() {
    print_container(findItinerary({{"MUC", "JFK"},
                                   {"JFK", "MUC"}}));
    print_container(findItinerary({{"MUC", "LHR"},
                                   {"JFK", "MUC"},
                                   {"SFO", "SJC"},
                                   {"LHR", "SFO"}}));
    print_container(findItinerary({{"JFK", "SFO"},
                                   {"JFK", "ATL"},
                                   {"SFO", "ATL"},
                                   {"ATL", "JFK"},
                                   {"ATL", "SFO"}}));
    print_container(findItinerary({{"JFK", "A"},
                                   {"JFK", "D"},
                                   {"A", "C"},
                                   {"B", "C"},
                                   {"C", "D"},
                                   {"C", "JFK"},
                                   {"D", "B"},
                                   {"D", "A"},
                                  }));
}