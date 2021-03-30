#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,n,m;
    char c;

    cin>>a;

    while(a--){
        cin>>c>>n>>m;
        if(c=='r') cout<<min(n,m)<<"\n";
        else if(c=='k') cout<<((n*m)/2)+((n*m)%2)<<"\n";
        else if(c=='K') cout<<(((n/2)+(n%2))*((m/2)+(m%2)))<<"\n";
        else if(c=='Q'){
            if(n==4&&m==4) cout<<3<<"\n";
            else cout<<min(n,m)<<"\n";
        }

    }

    return 0;
}
