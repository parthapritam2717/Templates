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
        vector<vector<pii>> adjNodes;
    public:
        Graph(int v,vvi& edgeList){
            V=v;
            vector<vector<pii>> temp(V);
            for(int i=0;i<edgeList.size();++i){
                temp[edgeList[i][0]].push_back(make_pair(edgeList[i][1],edgeList[i][2]));//edge from 1th index to 0th index
            }
            adjNodes=temp;
        } 
       

};



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
    return 0;

}



