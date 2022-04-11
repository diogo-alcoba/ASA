#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Node{

    public:

    bool visited;
    int distance;

    //Constructor
    Node(){
        visited = false;
        distance = 1;
    }

};
class Graph{

    public:

    unsigned int number_nodes;
    int subgraphs;
    int longest_path;   
    vector<list<int>> adj ;              
    vector<Node> dominoes;   
    vector<int> topological_order;


    // Constructor
    Graph(int number_nodes);


    // Getter
    int getNumber_nodes();


    // Reset every node to unvisited
    void reset_dominoes();

    // function to add an edge to graph
    void addEdge(int node, int adjacent_node);
 
    void print_adjacency_list();

    void print_topological_order(); 

    void DFS(int node);

    void max_sequence();

    //void DFS();

    //int DFSVisit(int node, int time);
};

Graph::Graph(int number_nodesGraph){
    number_nodes = number_nodesGraph;
    subgraphs = 0;
    longest_path = 0;
    adj = vector<list<int>>(number_nodes + 1);
    dominoes = vector<Node>(number_nodes + 1, Node());
}

int Graph::getNumber_nodes(){
    return number_nodes;
}

void Graph::reset_dominoes(){
    for (unsigned int i = 1; i < number_nodes + 1; i++){
        dominoes[i].visited = false;
        dominoes[i].distance = 1;
    }
}

void Graph::addEdge(int node, int adjacent_node){   
    adj[node].push_back(adjacent_node); 
}

/* void Graph::print_adjacency_list(){
    cout << endl << "Adjacency List:" << endl;
    for(unsigned int i = 1; i < number_nodes + 1; i++){
        cout << i << " ->";
        for (int adjacent_node : adj[i]){
            cout << ", " << adjacent_node; 
        }
        cout << endl;
    } 

    cout << adj.size() << endl;
}

void Graph::print_topological_order(){
    assert(topological_order.size() == number_nodes);
    cout << endl << "Topological Order:" << endl;
    for (unsigned int i = 0; i < number_nodes; i++){
        cout << topological_order[i] << " ";
    }
    cout << endl;

}
 */
/* void Graph::DFS(){
    for (int node = 1; node < number_nodes + 1; node++){
        dominoes[node].color = WHITE;
        dominoes[node].parent = 0;
    }
    int time = 0;
    for (int node = 1; node < number_nodes + 1; node++){
        if (dominoes[node].color == WHITE)
            time = DFSVisit(node, time);
    }
}

int Graph::DFSVisit(int node, int time){
    assert(dominoes[node].color == WHITE);
    dominoes[node].color = GRAY;
    time++;
    dominoes[node].discover_time = time;
    for (int adjacent_node : adj[node]){
        if (dominoes[adjacent_node].color == WHITE){
            dominoes[adjacent_node].parent = node;
            time = DFSVisit(adjacent_node, time);
        }
    }
    dominoes[node].color = BLACK;
    time++;
    dominoes[node].finalize_time = time;
    cout << node << " ";
    return time;
}
 */

void Graph::DFS(int node){
    assert(dominoes[node].visited == false);
    dominoes[node].visited = true;
    for (int adjacent_node : adj[node]){
        if (dominoes[adjacent_node].visited == false){
            //dominoes[adjacent_node].parent = node;
            DFS(adjacent_node);
        }
        dominoes[node].distance = max(dominoes[node].distance, dominoes[adjacent_node].distance + 1);
    }
    if (topological_order.size() < number_nodes){
        topological_order.push_back(node);
    }
}

void Graph::max_sequence(){
    longest_path = dominoes[1].distance;
    for (unsigned int node = 2; node < number_nodes + 1; node++){
        if (dominoes[node].distance > longest_path){
            longest_path = dominoes[node].distance;
        }
    }
}

int main(){

    //Graph Creation
    int dominoes, connections;
    int node_a, node_b;
    cin >> dominoes >> connections;
    Graph g(dominoes);

    // Connecting the nodes
    for(int i = 0; i < connections ; i++){
        cin >> node_a >> node_b;
        g.addEdge(node_a, node_b);
    }

    // Printing the Graph
    //g.print_adjacency_list();
    
    // Knowing the Topological Order of the Graph
    for (int node = 1; node < g.getNumber_nodes() + 1; node++){
        if (g.dominoes[node].visited == false){
            g.DFS(node);
        }
    }
    reverse(g.topological_order.begin(), g.topological_order.end());
    //g.print_topological_order();

    // Knowing the number of subgraphs in the graph and longest path
    g.reset_dominoes();

    for (unsigned int i = 0; i < g.topological_order.size(); i++){
        if (g.dominoes[g.topological_order[i]].visited == false){
            g.DFS(g.topological_order[i]);
            g.subgraphs++;
        }
    }
    g.max_sequence();
    cout << g.subgraphs << " " << g.longest_path << endl;

    return 0;
}
