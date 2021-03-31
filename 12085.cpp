#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull pn,ult,prim,numbers[100005];
int n;
bool range;

ull proc(){
    ull x = 0,mod;
    ull primCopy = prim;
    ull ultCopy = ult;

    while(primCopy!=ultCopy&&primCopy!=0&&ultCopy!=0){
        primCopy/=10;
        ultCopy/=10;
        x++;
    }

    mod = ult / (pow(10,x));
    mod *= (pow(10,x));
    if(mod==0) return ult;
    return ult%mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull caseNumber = 1;

    while(cin>>n){
        if(!n) break;
        for(int i=0;i<n;i++) cin>>numbers[i];
        cout<<"Case "<<caseNumber++<<":\n";
        numbers[n] = -1;
        range = false;
        for(int i=0;i<n;i++){
            if(numbers[i]==numbers[i+1]-1){
                if(!range) prim = numbers[i];
                range = true;
            }
            else{
                if(range){
                    ult = numbers[i];
                    cout<<"0"<<prim<<"-"<<proc()<<"\n";
                    range = false;
                }
                else{
                    cout<<"0"<<numbers[i]<<"\n";
                }
            }
        }
        cout<<"\n";
    }

    return 0;
}
