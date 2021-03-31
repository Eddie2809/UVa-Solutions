#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t,a,b;
    bool found;

    cin>>t;

    while(t--){
        cin>>a>>b;
        found = false;
        for(int i=0,j=a;i<=a;i++,j--){
            if(abs(i-j)==b){
                cout<<max(i,j)<<" "<<min(i,j)<<"\n";
                found = true;
                break;
            }
        }
        if(!found) cout<<"impossible\n";
    }

    return 0;
}
