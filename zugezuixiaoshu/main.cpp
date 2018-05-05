#include <iostream>
using namespace std;

int main() {
    int buf[10]={0};
    int n;
    for(int i=0;i<10;++i) {
        cin >> buf[i];
    }
    for(int i=1;i<10;++i) {
        if(buf[i]>0) {
            cout<<i;
            buf[i]--;
            break;
        }
    }
    for(int i=0;i<10;++i) {
        while(buf[i]>0) {
            cout << i;
            buf[i]--;
        }
    }
    cout << endl;
    return 0;
}