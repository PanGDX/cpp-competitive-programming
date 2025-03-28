#include <bits/stdc++.h>
using namespace std;
#define int long long int 
//https://codebreaker.xyz/problem/segmenttree2
struct node{
    int s,e,m;
    int val, lazy;
    node *l = nullptr,*r = nullptr;
    
    
    node(int S, int E){//just creating
        s = S, e=E;
        m = (s+e)>>1;
        val = 0, lazy = 0;
        
        
    }
    
    void create(){
        if(s!=e){
            l = new node(s,m);
            r = new node(m+1,e);
        }
    }
    
    void propagation(){
        if(lazy == 0) return;
        
        val += (lazy * (e - s + 1));
        
        if(s != e){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        
        lazy =0;
    }
    
    void update(int S, int E, int increment){
        if(l == nullptr) create(); //lazily create children
            
            
        if(S == s && E == e) lazy += increment;
        else{
            if(E <= m) l->update(S, E, increment);
            else if(S > m) r -> update(S, E, increment);// [S,E] is in the right child
            else l-> update(S, m,increment), r->update(m+1, E, increment);
            
            l->propagation(), r->propagation();
            val = l->val + r->val;
        }
        
        
    }
    int query(int S, int E){
        if(l == nullptr) create();
        
        propagation();
        if(S == s && E == e) return val;
        else if(E <= m) return l->query(S, E );
        else if(S > m) return r->query(S, E);
        else return (l->query(S, m) + r->query(m+1,E));     
    }
};

signed main(){
    int n,m;
    cin >> n >> m;
    node *root = new node(1,n);
    
    for(int i =0;i<m;i++){
        int type;
        cin >> type;
        if(type == 1){
            int a,b,c;
            //a--;b--;
            
            cin >> a >> b >> c;
            
            root->update(a,b,c);
        }
        else{
            int a,b;
            //a--,b--;
            cin >> a >> b;
            
            cout << root->query(a,b) << "\n"; //inclusive
        }
    }
}