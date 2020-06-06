#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include<math.h>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<string> vs;
typedef unordered_map<int,int> umap;
typedef map<long long,long long> omap;
typedef multimap<long long,long long> mmap;

#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)

class Graph{
    private:
        int V;
        vvi edges;//for bellman form we store array of edges
    public:
        Graph(int v,vvi& edgeList){
            V=v;
            edges=edgeList;

        } 
       vi bellmanFord(){
           vi dist(V,INT_MAX);
           dist[0]=0;
           for(int i=0;i<V-1;++i){
               for(int j=0;j<edges.size();++j){
                   int u=edges[j][0];
                   int v=edges[j][1];
                   int w=edges[j][2];
                   if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                       dist[v]=dist[u]+w;
                   }
               }
           }

           //check if we have negative edge cycle
           for(int j=0;j<edges.size();++j){
               int u=edges[j][0];
                   int v=edges[j][1];
                   int w=edges[j][2];
                   if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                       //negative edge cycle exists
                       vector<int> empty;
                       return empty;
                   }
           }
           return dist;
       }
       

};

void printVector(vector<int> &index){
    int n=index.size();
    fori(i,0,n){
        cout<<index[i]<<" ";
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int v;
    cin>>v;  
    int t;
    cin>>t;
    vvi edges;
    while(t--){
        vi temp(3);
        cin>>temp[0]; //u
        cin>>temp[1];//v
        cin>>temp[2];//weight
        edges.push_back(temp);
    }
    Graph g(v,edges);
    vi dist=g.bellmanFord();
    printVector(dist);
    return 0;

}



