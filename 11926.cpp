#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,n,m,o;
    bool conflict;
    bitset<1000001> bs;
    bs.reset();

    while(cin>>a>>b){
        if(!a&&!b) break;
        bs.reset();
        conflict = false;
        while(a--){
            cin>>n>>m;
            if(!conflict){
                for(int i = n; i<m;i++){
                    if(bs.test(i)) conflict = true;
                    bs.set(i);
                }
            }
        }
        while(b--){
            cin>>n>>m>>o;
            if(!conflict){
                while(n<=1000000){
                    for(int i = n; i<m&&i<1000000; i++){
                        if(bs.test(i)) conflict = true;
                        bs.set(i);
                    }
                    n+=o;
                    m+=o;
                }
            }
        }
        if(conflict) cout<<"CONFLICT\n";
        else cout<<"NO CONFLICT\n";
    }

    return 0;
}
