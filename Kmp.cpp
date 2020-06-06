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

vector<int> createLps(string pat){
    int n=pat.length();
    vector<int> lps(n,0);
    int i=1,j=0;
    while(i<n){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            ++i;++j;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                ++i;
            }
        }
    }
    return lps;
}

vector<int> kmpSearch(string txt,string pat,vector<int> & lps){
    vector<int> ans;
    int m=pat.length();
    int n=txt.length();
    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==m){
            ans.push_back(i-j); //j is the length of pattern so -j will give start of the string
            j=lps[j-1]; //very similar to lps calculation consider this as a mismatch and go back 
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return ans;

}

void printVector(vector<int> &index){
    int n=index.size();
    fori(i,0,n){
        cout<<index[i]<<" ";
    }
    cout<<endl;

}


//to read strings with whitespace string s,getline(cin,s);
int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    string txt,pat;
    cin>>txt>>pat;
    vector<int> lps=createLps(pat);
    printVector(lps);
    vector<int> index=kmpSearch(txt,pat,lps);
    cout<<"index"<<endl;
    printVector(index);
    return 0;

}



