#include <bits/stdc++.h>
using namespace std;

int main(){

    string top[25],bottom[27];
    string aux;
    int apuntador,f,s,n,y,val;

    cin>>n;
    cin.ignore();
    for(int k = 1; k<=n; k++){
        apuntador = 26;
        y = 0;
        for(int i=0;i<27;i++){
            cin>>aux;
            bottom[i] = aux;
        }
        for(int i=0;i<25;i++){
            cin>>aux;
            top[i] = aux;
        }
        for(int i=0;i<3;i++){
            if(bottom[apuntador][0]=='A'||bottom[apuntador][0]=='K'||bottom[apuntador][0]=='Q'||bottom[apuntador][0]=='J'){
                val = 10;
                y+=val;
                apuntador--;
            }
            else{
                //val = static_cast<int>(bottom[apuntador][0])-48;
                switch(bottom[apuntador][0]){
                    case '2': val =2 ; break;
                    case '3': val =3 ; break;
                    case '4': val =4 ; break;
                    case '5': val =5 ; break;
                    case '6': val =6 ; break;
                    case '7': val =7 ; break;
                    case '8': val =8 ; break;
                    case '9': val =9; break;
                }
                y+=val;
                apuntador--;
                apuntador-=(10-val);
            }
        }
        y--;
        if(y>apuntador) cout<<"Case "<<k<<": "<<top[y-apuntador-1]<<"\n";
        else cout<<"Case "<<k<<": "<<bottom[y]<<"\n";
    }

    return 0;
}
