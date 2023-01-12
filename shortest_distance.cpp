#include <unordered_set>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<char,vector<char>> buildGraph(const vector<pair<char,char>>& edges) {
    unordered_map<char,vector<char>> graph;

    for (const auto& edge : edges) {
        char a,b;
        tie(a,b) = edge;
        if(!graph.count(a)) graph[a] = {};
        if(!graph.count(b)) graph[b] = {};
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}

int shortPath(const unordered_map<char,vector<char>>& graph, char nodeA, char nodeB) {
    unordered_set<char> visited = { nodeA };
    queue<pair<char, int>> queue;
    queue.push({nodeA, 0});
    

    while (!queue.empty()) {
        auto [node, distance] = queue.front();
        queue.pop();

        

        for (auto neighbour : graph.at(node)) {
            if (visited.count(neighbour) == 0) {
                visited.insert(neighbour);
                queue.push({ neighbour, distance + 1 });
            }
        }
        if (node == nodeB) return distance;
    }
    return -1;
}

int main(){

vector<pair<char,char>> edges;
edges.push_back({'w','y'});
edges.push_back({'x','z'});
edges.push_back({'z','y'});
edges.push_back({'z','v'});
edges.push_back({'w','v'});

auto graph = buildGraph(edges);
char nodeA = 'w',nodeB = 'z';
int distance = shortPath(graph, nodeA, nodeB);
cout<<"Shortest distance between node "<<nodeA<<" and node "<<nodeB<<" is: "<<distance<<endl;

return 0;
}
