#include <bits/stdc++.h>
using namespace std;

int primes[] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int a,b,c,sum,aux,n,nos,cSize,aSize,bSize;
bool negative;

void gcd(){
    int pointer = 15;
    while(pointer!=0){
        while(b%primes[pointer]!=0||c%primes[pointer]!=0) pointer--;
        b/=primes[pointer];
        c/=primes[pointer];
    }
}

void proc(){
    if((b<0&&c>0)||(b>0&&c<0)) negative = true;
    a = b/n;
    b = b - (a*c);
    nos = 0;
    gcd();
    if(sum%n==0){
        if(a<0) cout<<"- ";
        cout<<abs(a)<<"\n";
        return;
    }
    else{
        a = abs(a); b = abs(b); c = abs(c);
        if(a!=0) aSize = static_cast<int>(log10(a))+1;
        bSize = static_cast<int>(log10(b))+1;
        cSize = static_cast<int>(log10(c))+1;
        nos += (cSize-1);
        if(a!=0) nos+=aSize;
        if(negative) nos+=2;
        nos-=(bSize-1);
        for(int i=0;i<nos;i++) cout<<" ";
        cout<<b<<"\n";
        if(negative) cout<<"- ";
        if(a!=0) cout<<a;
        for(int i=0;i<cSize;i++) cout<<"-";
        nos = 0;
        if(negative) nos+=2;
        if(a!=0) nos+=aSize;
        cout<<"\n";
        for(int i=0;i<nos;i++) cout<<" ";
        cout<<c<<"\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(cin>>n){
        if(!n) break;
        sum = 0;
        for(int i=0;i<n;i++){
            cin>>aux;
            sum+=aux;
        }
        cout<<"Case "<<t++<<":\n";
        if(sum==0){
            cout<<0<<"\n";
            continue;
        }
        negative = false;
        b = sum;
        c = n;
        proc();
    }

    return 0;
}
