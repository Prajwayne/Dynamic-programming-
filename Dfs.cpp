// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

void depthfirstprint(const std::unordered_map<char, std::vector<char>>& graph, char source) {
  std::stack<char> stack;
  stack.push(source);
  while (!stack.empty()) {
    char current = stack.top();
     std::cout << current << std::endl;
    stack.pop();
    for (char neighbor : graph.at(current)) {
      stack.push(neighbor);
    }
  }
}

int main() {
  std::unordered_map<char, std::vector<char>> graph = {{'a', {'b', 'c'}},
                                                        {'b', {'d'}},
                                                        {'c', {'e'}},
                                                        {'d', {'f'}},
                                                        {'e', {}},
                                                        {'f', {}}};

  depthfirstprint(graph, 'a');
  return 0;
}
