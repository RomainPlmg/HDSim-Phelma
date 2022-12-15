#include <algorithm>
#include "defs.h"

int Node::detectCycle(vector<vector<Node*>> &cycles) {

    int flag = 0;
    vector<Node*> visited;
    vector<Node*> recStack;

    visited.push_back(this);
    recStack.push_back(this);

    for(size_t i = 0; i < children.size(); i++) {
        if(!(find(visited.begin(), visited.end(), children[i]) != visited.end())) {
            children[i]->recurCycle(flag, visited, recStack, cycles);
        }
    }
    return flag;
}

void Node::recurCycle(int &flag, vector<Node*> &visited, vector<Node*> &recStack, vector<vector<Node*>> &cycles) {

    visited.push_back(this);
    recStack.push_back(this);

    for(size_t i = 0; i < children.size(); i++) {
        if(!(find(visited.begin(), visited.end(), children[i]) != visited.end())) {
            children[i]->recurCycle(flag, visited, recStack, cycles);
        }
        if(find(recStack.begin(), recStack.end(), children[i]) != recStack.end()) {
            flag += 1;
            cout << "hello" << endl;
            cycles.push_back({this, children[i]});
        }
    }
    recStack.erase(find(recStack.begin(), recStack.end(), this));
}

