#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    cin>>str1;
    auto idxe = str1.find('E');

    int power=0;
    for(int i=(int)idxe+2;i<str1.length();++i) {
        power = 10*power + str1[i]-'0';
    }

    if(str1[0]=='-') {
        cout<<'-';
    }

    if(power==0) {
        for(int i=1;i<idxe;++i) {
            cout<<str1[i];
        }
    }
    else {
        if(str1[idxe+1]=='-') {
            cout<<"0.";
            for(int i=1;i<power;++i) {
                cout<<'0';
            }
            cout<<str1[1];
            for(int i=3;i<idxe;++i) {
                cout<<str1[i];
            }
        }
        else {
            cout<<str1[1];
            int num=idxe-3;
            if(power>num) {
                for(int i=3;i<idxe;++i) {
                    cout<<str1[i];
                }
                for(int i=0;i<power-num;++i) {
                    cout<<'0';
                }
            }
            else {
                for(int i=3;i<power+3;++i) {
                    cout<<str1[i];
                }
                cout<<'.';
                for(int i=power+3;i<idxe;++i) {
                    cout<<str1[i];
                }
            }
        }
    }
    return 0;
}