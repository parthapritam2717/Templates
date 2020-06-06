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

int constructSegmentTreeUtil(vi &arr,int l,int r,vi &tree,int treeIndex){
    if(l==r){
        tree[treeIndex]=arr[l];
        return arr[l];
    }
    int m=l+(r-l)/2;
    tree[treeIndex]=min(constructSegmentTreeUtil(arr,l,m,tree,treeIndex*2+1),constructSegmentTreeUtil(arr,m+1,r,tree,treeIndex*2+2));
    return tree[treeIndex];
}

vi constructSegmentTree(vi &arr,int n){
    int h=(int)ceil(log2(n));
    int sizeTree=2*pow(2,h)-1;
    vi segmentTree(sizeTree,INT_MAX);
    constructSegmentTreeUtil(arr,0,n-1,segmentTree,0);
    return segmentTree;
}


int getMinUtil(vi &tree,int sl,int sr,int ql,int qr,int treeIndex){
    if(ql<=sl && qr>=sr){
        return tree[treeIndex];
    }
    if(sr<ql || sl>qr){
        return INT_MAX;
    }
    int m=sl+(sr-sl)/2;
    return min(getMinUtil(tree,sl,m,ql,qr,treeIndex*2+1),getMinUtil(tree,m+1,sr,ql,qr,treeIndex*2+2));
}


int getMin(vi &tree,int n,int l,int r){
    if(r>=n || l<0){
        return INT_MAX;
    }
    return getMinUtil(tree,0,n-1,l,r,0);
}

int updateArrayUtil(vi &tree,int sl,int sr,int i,int newVal,int treeIndex){
    if(i<sl || i>sr)
        return INT_MAX;
    if(sl!=sr){
        int m=sl+(sr-sl)/2;
        tree[treeIndex]=min(
        updateArrayUtil(tree,sl,m,i,newVal,treeIndex*2+1),
        updateArrayUtil(tree,m+1,sr,i,newVal,treeIndex*2+2));
    }
    else{
        tree[treeIndex]=min(tree[treeIndex],newVal);
    }
    return tree[treeIndex];
    

}

void updateArray(vi & array,vi &tree,int n,int i,int newVal){
    if(i<0 || i>n-1){
        return ;
    }
    array[i]=newVal;
    updateArrayUtil(tree,0,n-1,i,newVal,0);
}

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
    int n;
    cin>>n;
    vi arr(n);
    fori(i,0,n){
        cin>>arr[i];
    }
    vi tree=constructSegmentTree(arr,n);
    
    printVector(tree);

    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<getMin(tree,n,l,r)<<endl;
    }

    int index,num;
    cin>>index>>num;
    updateArray(arr,tree,n,index,num);
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<getMin(tree,n,l,r)<<endl;
    }


}



