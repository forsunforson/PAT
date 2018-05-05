#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    int buf[10] = {0};
    cin >> str1;
    for(auto c: str1) {
        int n = c - '0';
        buf[n]++;
    }
    for(int i=0;i<10;++i) {
        if(buf[i]==0) continue;
        else {
            cout<<i<<":"<<buf[i]<<endl;
        }
    }
    return 0;
}