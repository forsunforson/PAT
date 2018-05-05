#include <iostream>
using namespace std;
//Win=0 Equal=1 Lose=2 B=3 C=4 J=5
int jia[6], yi[6];
char result[6]={' ',' ',' ','B','C','J'};
void check(char a, char b) {
    if(a==b) {
        jia[1]++;
        yi[1]++;
    }
    else if (a=='C') {
        if (b=='J') {
            jia[4]++;
            jia[0]++;
            yi[2]++;
        }
        else if (b=='B') {
            yi[0]++;
            yi[3]++;
            jia[2]++;
        }
    }
    else if (a=='J') {
        if (b=='C') {
            yi[0]++;
            yi[4]++;
            jia[2]++;
        }
        else if (b=='B') {
            jia[0]++;
            jia[5]++;
            yi[2]++;
        }
    }
    else if (a=='B') {
        if (b=='C') {
            jia[0]++;
            jia[3]++;
            yi[2]++;
        }
        else if (b=='J') {
            jia[2]++;
            yi[0]++;
            yi[5]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    char ip1,ip2;
    for(int i=0;i<n;++i) {
        cin >> ip1 >> ip2;
        check(ip1, ip2);
    }
    cout << jia[0] << " " << jia[1] << " " << jia[2] << endl;
    cout << yi[0] << " " << yi[1] << " " << yi[2] << endl;
    int maxidx=3,maxnum=0;
    for(int i=3;i<6;++i) {
        if(jia[i]>maxnum) {
            maxidx = i;
            maxnum = jia[i];
        }
    }
    cout << result[maxidx] << " ";
    maxidx=3,maxnum=0;
    for(int i=3;i<6;++i) {
        if(yi[i]>maxnum) {
            maxidx = i;
            maxnum = yi[i];
        }
    }
    cout << result[maxidx] << endl;

    return 0;
}