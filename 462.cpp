#include <bits/stdc++.h>
using namespace std;

int suits[4];       //0:‘S’, 1:‘H’, 2:‘D’, 3:‘C’,
int score2,nMax,iMax;
bool stopped[4];
map<char,int> m;

int computeScore(char hand[]){

    int score = 0;
    suits[0] = 0; suits[1] = 0; suits[2] = 0; suits[3] = 0;
    stopped[0] = false; stopped[1] = false; stopped[2] = false; stopped[3] = false;
    score2 = 0;

    for(int i=1,j=0;i<strlen(hand);i+=3,j+=3){
        if(hand[i]=='S') suits[0]++;
        else if(hand[i]=='H') suits[1]++;
        else if(hand[i]=='D') suits[2]++;
        else if(hand[i]=='C') suits[3]++;

        if(hand[j]=='A') score+=4;
        else if(hand[j]=='K') score+=3;
        else if(hand[j]=='Q') score+=2;
        else if(hand[j]=='J') score+=1;
    }

    for(int i = 0; i<strlen(hand);i+=3){
        if(hand[i]=='K'&&suits[m[hand[i+1]]]<2) score--;
        else if(hand[i]=='Q'&&suits[m[hand[i+1]]]<3) score--;
        else if(hand[i]=='J'&&suits[m[hand[i+1]]]<4) score--;

        if(hand[i]=='A') stopped[m[hand[i+1]]]=true;
        else if(hand[i]=='K'&&suits[m[hand[i+1]]]>=2) stopped[m[hand[i+1]]]=true;
        else if(hand[i]=='Q'&&suits[m[hand[i+1]]]>=3) stopped[m[hand[i+1]]]=true;
    }

    for(int i=0;i<4;i++){
        if(suits[i]==0) score+=2,score2+=2;
        else if(suits[i]==1) score+=2,score2+=2;
        else if(suits[i]==2) score++,score2++;
    }

    return score;
}

void evaluateHand(char hand[]){
    int score = computeScore(hand);
    if(score<14) cout<<"PASS\n";
    else if((score-score2)>=16&&stopped[0]&&stopped[1]&&stopped[2]&&stopped[3]) cout<<"BID NO-TRUMP\n";
    else if(score>=14){
        cout<<"BID ";
        nMax = 0; iMax = 0;
        for(int i=3;i>=0;i--){
            if(suits[i]>=nMax){
                nMax = suits[i];
                iMax = i;
            }
        }
        if(iMax==0) cout<<"S\n";
        if(iMax==1) cout<<"H\n";
        if(iMax==2) cout<<"D\n";
        if(iMax==3) cout<<"C\n";
    }
}

int main(){

    char hand[40];
    m['S'] = 0; m['H'] = 1; m['D'] = 2; m['C'] = 3;
    while(cin.getline(hand,40,'\n')){
        evaluateHand(hand);
    }

    return 0;
}
