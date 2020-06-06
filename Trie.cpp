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


typedef struct TrieNode{

    TrieNode *children[26];

    bool isEndOfWord;
}TrieNode;

TrieNode *getNode(){
    TrieNode *n=new TrieNode();
    n->isEndOfWord=0;
    for (int i = 0; i < 26; i++) 
        n->children[i] = NULL; 
  
    return n;
}
void insert(TrieNode *root, string key) 
{ 
    TrieNode *curr = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!curr->children[index]) 
            curr->children[index] = getNode(); 
  
        curr = curr->children[index]; 
    } 
    curr->isEndOfWord = true; 
} 
bool search(TrieNode *root, string key) 
{ 
    TrieNode *curr = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!curr->children[index]) 
            return false; 
  
        curr = curr->children[index]; 
    } 
  
    return (curr != NULL && curr->isEndOfWord); 
} 


bool isLeafNode(TrieNode* root) 
{ 
    return root->isEndOfWord == 1; 
} 

void display(TrieNode* root, string &str) 
{ 
    if (isLeafNode(root))  
    { 
        cout << str << endl; 
    } 
  
    int i; 
    for (i = 0; i < 26; i++)  
    { 
        
        if (root->children[i])  
        { 
            str.push_back(i + 'a'); 
            display(root->children[i], str); 
            str.pop_back();
        } 
    } 
}

//to read strings with whitespace string s,getline(cin,s);
int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    cin>>t;
    TrieNode *root = getNode(); 
    while(t--){
        string s;
        cin>>s;
        insert(root,s);
    }
    cout<<search(root,"abc");
    string s="";
    display(root,s);
    return 0;

}



