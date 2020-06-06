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
    tree[treeIndex]=constructSegmentTreeUtil(arr,l,m,tree,treeIndex*2+1)+constructSegmentTreeUtil(arr,m+1,r,tree,treeIndex*2+2);
    return tree[treeIndex];
}

vi constructSegmentTree(vi &arr,int n){
    int h=(int)ceil(log2(n));
    int sizeTree=2*pow(2,h)-1;
    vi segmentTree(sizeTree,0);
    constructSegmentTreeUtil(arr,0,n-1,segmentTree,0);
    return segmentTree;
}


int getSumUtil(vi &tree,int sl,int sr,int ql,int qr,int treeIndex){
    if(ql<=sl && qr>=sr){
        return tree[treeIndex];
    }
    if(sr<ql || sl>qr){
        return 0;
    }
    int m=sl+(sr-sl)/2;
    return getSumUtil(tree,sl,m,ql,qr,treeIndex*2+1)+getSumUtil(tree,m+1,sr,ql,qr,treeIndex*2+2);
}


int getSum(vi &tree,int n,int l,int r){
    if(r>=n || l<0 ){
        return INT_MIN;
    }
    return getSumUtil(tree,0,n-1,l,r,0);
}

void updateArrayUtil(vi &tree,int sl,int sr,int i,int diff,int treeIndex){
    if(i<sl || i>sr)
        return;
    tree[treeIndex]+=diff;
    if(sl!=sr){
        int m=sl+(sr-sl)/2;
        updateArrayUtil(tree,sl,m,i,diff,treeIndex*2+1);
        updateArrayUtil(tree,m+1,sr,i,diff,treeIndex*2+2);
    }

}

void updateArray(vi & array,vi &tree,int n,int i,int newVal){
    if(i<0 || i>n-1){
        return ;
    }
    int diff=newVal-array[i];
    array[i]=newVal;
    updateArrayUtil(tree,0,n-1,i,diff,0);
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
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<getSum(tree,n,l,r)<<endl;
    }
    int index,num;
    cin>>index>>num;
    updateArray(arr,tree,n,index,num);
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<getSum(tree,n,l,r)<<endl;
        
    }


}



