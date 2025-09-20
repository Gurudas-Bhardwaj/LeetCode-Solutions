#include <iostream>
#include <list>
#include <queue>
#include<vector>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int V)
    {
        this->v = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);//uncomment it if this is undirected graph
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " : " << " ";
            for (int j : l[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void BFS(){
        queue<int> q;
        vector<bool> visited(v, false);

        q.push(0);
        visited[0] = true;

        cout<<"BFS Traversal : ";

        while(q.size()>0){
            int a = q.front();
            q.pop();

            cout<<a<<"<--->";

            for(int u : l[a]){
                if(visited[u] == false){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }   
        cout<<"END"<<endl;
    }

    void dfsHelper(int str, vector<bool>& visited){
        visited[str] = true;

        cout<<str<<"<-->";

        for(int a : l[str]){
            if(visited[a] == false)
                dfsHelper(a, visited);
        }
    }

    void DFS(int str){
        vector<bool> visited(v, false);
        
        cout<<"DFS Travesal : ";
        dfsHelper(str, visited);

        cout<<"END"<<endl;
    }


    bool detectCycleUsingBFS(int start){
        queue<pair<int, int>> q;
        vector<bool> visited(v, false);

        q.push({start, -1});
        visited[start] = true;

        while(q.size() > 0){
            auto [node, parent] = q.front();
            q.pop();

            for(auto neigh : l[node]){
                if(!visited[neigh]){
                    q.push({neigh, node});
                    visited[neigh] = false;
                }
                else if(parent != neigh)
                    return true;
            }

        }
        return false;
    }

    bool helperCycleDFS(int node, int parent, vector<bool>& visited){

        for(int neigh : l[node]){
            if(!visited[neigh]){
                visited[neigh] = true;
                if(helperCycleDFS(neigh, node, visited))
                    return true;
            }
            else if(neigh != parent)
                return true;
        }
        return false;
    }

    bool detectCycleUsingDFS(int start){
        vector<bool> visited(v, false);
        visited[start] = true;

        return helperCycleDFS(start, -1, visited);
    }

    bool helper(int node, vector<bool>& visited, vector<bool>& pathVisited){
        visited[node] = true;
        pathVisited[node] = true;

        for(int i : l[node]){
            if(visited[i] == false){
                if(helper(i, visited, pathVisited))
                    return true;
            }
            else if(visited[i] == true && pathVisited[i] == true)
                return true;
        }
        pathVisited[node] = false;
        return false;
    }       

    bool detectCycledirectedDFS(int start){
        vector<bool> visited(v, false);
        vector<bool> pathVisited(v, false);
        
        for(int i=0; i<v; i++){
            if(visited[i] == false)
                if(helper(i, visited, pathVisited))
                    return true;
        }

        return false;
    }
};

int main()
{

     Graph g(5);

   g.addEdge(0, 1);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(3, 4);
//    g.addEdge(4, 2);
   

    g.print(); 
    
    // bool ans = g.detectCycleUsingBFS(0);
    bool ans = g.detectCycledirectedDFS(0);

    cout<<ans<<endl;


    return 0;
}


