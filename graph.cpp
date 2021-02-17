
#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
class Graph{
    vector<vector<pair<int,int>>> adjList;
    //Edges
    int n;

public:
    Graph(int N){
        n=N;
        adjList.resize(n,vector<pair<int,int>>());

    }
    void addNewEdge(int u, int v, int d=1){
        auto p1 = make_pair(v,d);
        auto p2 = make_pair(u,d);
        adjList[u].push_back(p1);
        adjList[v].push_back(p2);
    }
    void printAdjacencyList(){
        cout<<"Adjacency List of Graph\n";
        for(int i=0; i<n; i++){
            cout<<i<<"->";
            for(auto j: adjList[i]){
                cout<<"["<<j.first<<","<<j.second<<"]";
            }
            cout<<'\n';
        }
    }

    void breadthFirstTraversal(int src){
        cout<<"BFS traversal"<<endl;
        queue<int> q;

        int vis[n]={0};
        q.push(src);
        vis[src]=1;
        while(!q.empty()){

            int cur=q.front();
            cout<<cur<<",";
            q.pop();

            for(auto i:adjList[cur]){
                if(vis[i.first]==0)
                    q.push(i.first);
                vis[i.first]=1;
            }
        }


    }
    void dfshelper(int ele, unordered_map<int,bool> &vis){

        vis[ele]=true;
        cout<<ele<<",";

        for(auto i: adjList[ele]){

            if(!vis[i.first])
                dfshelper(i.first,vis);
        }
    }

    void dfs(){
        unordered_map<int,bool> vis;
        for(int i=0; i<n; i++)
            vis[i]=false;
        cout<<"DFS traversal"<<endl;
        dfshelper(0,vis);


    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    Graph obj(5);
    obj.addNewEdge(0,1);
    obj.addNewEdge(0,3);
    obj.addNewEdge(0,4);
    obj.addNewEdge(1,2);
    obj.addNewEdge(1,3);
    obj.addNewEdge(2,3);
    obj.addNewEdge(4,3);
    obj.printAdjacencyList();
    obj.breadthFirstTraversal(0);
    cout<<endl;
    obj.dfs();

    return 0;

}

