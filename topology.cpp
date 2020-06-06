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
        vector<vector<int>> adjNodes;
        bool detectCycle(){
            vector<bool> vis(V,0);
            vector<bool> recursiveStack(V,0);
            for(int i=0;i<V;++i){
                if(!vis[i] && detectCycleUtil(i,vis,recursiveStack)){
                    return 1;
                }
            }
            return 0;
        }
        bool detectCycleUtil(int v,vector<bool> &vis,vector<bool> &recursiveStack){
            if(!vis[v]){
                vis[v]=1;
                recursiveStack[v]=1;
                vector<int> l=adjNodes[v];
                for(int i=0;i<l.size();++i){
                    if(!vis[l[i]] && detectCycleUtil(l[i],vis,recursiveStack)){
                        return 1;
                    }  
                    else if(recursiveStack[l[i]]){
                        return 1;
                    }
                }
            }
            recursiveStack[v]=0;
            return 0;
        }
        void topologicalSortUtil(int v,vector<bool> &vis,stack<int> &s){
            vis[v]=1;
            vector<int> l=adjNodes[v];
            for(int i=0;i<l.size();++i){
                if(!vis[l[i]]){
                    topologicalSortUtil(l[i],vis,s);
                }
            }
            s.push(v);
        }
    public:
        Graph(int v,vector<vector<int>>& edgeList){
            V=v;
            vector<vector<int>> temp(V);
            for(int i=0;i<edgeList.size();++i){
                temp[edgeList[i][1]].push_back(edgeList[i][0]);//edge from 1th index to 0th index
            }
            adjNodes=temp;
        }
        vector<int> topologicalSort(){
            vector<int> sol;
            if(!detectCycle()){
                vector<bool> vis(V,0);
                stack<int> s;
                for(int i=0;i<V;++i){
                    if(!vis[i]){
                        topologicalSortUtil(i,vis,s);
                    }
                }
                while(!s.empty()){
                    sol.push_back(s.top());
                    s.pop();
                }
            }
            return sol;
        } 
};


//to read strings with whitespace string s,getline(cin,s);
int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    cin>>t;
    while(t--){
        Graph g(numCourses,prerequisites);
        return g.topologicalSort();
    }
    return 0;

}



