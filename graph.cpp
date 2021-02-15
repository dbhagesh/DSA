#include<list>
#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
class graph{
    vector<vector<int>> adjList;
public:
    void func(){
        adjList.push_back(1);
    }
    void printg(){
        for(auto i: adjList) cout<<i<<" ";
    }
};
int main()
{

    graph obj;
    obj.func();
    obj.printg();
}

