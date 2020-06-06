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
    public:
        int V;
        vvi edges;//for bellman form we store array of edges
        Graph(int v,vvi& edgeList){
            V=v;
            edges=edgeList;

        } 
       vi bellmanFord(int src){
           vi dist(V,INT_MAX);
           dist[src]=0;
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

       void reWriteEdgeWeight(vi &dist){
           for(int i=0;i<edges.size();++i){
               edges[i][2]+=(dist[edges[i][0]]-dist[edges[i][1]]);
           }
       }
       

};

class GraphDijstraList{
    private:
        int V;
        vector<vpi> adjNodes;
    public:
        GraphDijstraList(int v,vvi& edgeList){
            V=v;
            vector<vpi> temp(V);
            for(int i=0;i<edgeList.size();++i){
                temp[edgeList[i][0]].push_back(make_pair(edgeList[i][1],edgeList[i][2]));//edge from 1th index to 0th index
            }
            adjNodes=temp;
        } 
        vector<int> dijkstra(int src){
            
            vector<int> dist(V,INT_MAX);
            vector<bool> inSP(V, 0);  
            set<pii> edges;
            edges.insert(make_pair(0,src));
            dist[src]=0;
            while(!edges.empty()){
                pii temp=*(edges.begin());
                edges.erase(edges.begin());
                int u=temp.second;
                vector<pii> li=adjNodes[u];
                for(int i=0;i<li.size();++i){
                    int v=li[i].first;
                    int w=li[i].second;
                    if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                        if(dist[v]!=INT_MAX ){
                            edges.erase(edges.find(make_pair(dist[v],v)));
                        }
                        dist[v]=dist[u]+w;
                        edges.insert(make_pair(dist[v],v));
                    }
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
    //we will add one node and create 
    Graph g(v,edges);
    //we will add one node and create edges to all nodes in a new graph
    for(int i=0;i<v;++i){
        vi temp(3);
        temp[0]=v;
        temp[1]=i;
        temp[2]=0;
        edges.push_back(temp);
    }
    Graph gT(v+1,edges);
    vector<int> distT=gT.bellmanFord(v);
    printVector(distT);
    vi d(distT.begin()+1,distT.end());
    g.reWriteEdgeWeight(d);
    //now will rewrite the weight of =edges of g
    // for(int i=0;i<v;++i){
    //     vector<int> dist=g.bellmanFord(i);
    //     printVector(dist);
    // }
    GraphDijstraList gD(v,g.edges);
    for(int i=0;i<v;++i){
        vector<int> dist=gD.dijkstra(i);
        printVector(dist);
    }


    
    return 0;

}



