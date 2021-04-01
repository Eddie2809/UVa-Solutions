#include <bits/stdc++.h>
using namespace std;

int t,ans,l,cm,n,cap;
bool posLeft;
string s;
queue<int> righ,lef;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;

    while(t--){
        cin>>l>>n;
        cap = 0;
        l *= 100;
        ans = 0;
        posLeft = true;
        while(n--){
            cin>>cm;
            cin.ignore();
            cin>>s;
            if(s[0]=='l') lef.push(cm);
            else righ.push(cm);
        }
        while(!righ.empty()||!lef.empty()){
            if(posLeft){
                while(!lef.empty()&&(cap+lef.front())<l){
                    cap+=lef.front();
                    lef.pop();
                }
            }
            else{
                while(!righ.empty()&&(cap+righ.front())<l){
                    cap+=righ.front();
                    righ.pop();
                }
            }
            ans++;
            cap = 0;
            posLeft = !posLeft;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
