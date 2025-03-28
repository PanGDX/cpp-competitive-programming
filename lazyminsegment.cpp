
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
        if(l == nullptr) create();
 //need to have l==nullptr for every function lol
//or else the l->propagation() would result in the program propagating
//from l, for which l->l == nullptr, thus RTE(11)
        
        if(lazy == 0) return;
        
        val = min(lazy, val);
        
        
        if(s != e){
            l->lazy = min(lazy, l->lazy);
            r->lazy = min(lazy, r->lazy);
        }
        
        lazy =0;
    }
    
    void update(int pos, int new_val){
        if(l == nullptr) create(); //lazily create children
            
        if(s <= pos && pos <= e){
			lazy = min(lazy, new_val);
		}
		else{
			if(pos<=m){
				l->update(pos, new_val);
			}
			else{
				r->update(pos,new_val);
			}
			val = min(l->val, r->val);
		}
    }
    
    
    int query(int S, int E){
        if(l == nullptr) create();
        
        propagation();
        if(S == s && E == e) return val;
        else if(E <= m) return l->query(S, E );
        else if(S > m) return r->query(S, E);
        else return min(l->query(S, m), r->query(m+1,E));     
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
            int pos,c;
            //a--;b--;
            
            cin >> pos >> c;
            
            root->update(pos,c);
        }
        else{
            int a,b;
            //a--,b--;
            cin >> a >> b;
            
            cout << root->query(a,b) << "\n"; //inclusive
        }
    }
}
