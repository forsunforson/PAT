#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    char ans[1000];
    int b,k=0;
    cin>>a>>b;
    int yushu=0;
    for(auto i:a) {
        int num = i - '0';
        num+=yushu;
        if(num>=b) {
            //cout<<num<<"除以"<<b<<"够除 ";
            int x = num/b;
            ans[k++]=x+'0';
            //cout<<"商"<<x;
            yushu=num%b*10;
            //cout<<"余"<<yushu<<endl;
        }
        else {
            //cout<<num<<"除以"<<b<<"不够除 ";
            ans[k++]='0';
            //cout<<"商0";
            yushu=num*10;
            //cout<<"余"<<yushu<<endl;
        }
    }

    if(ans[0]!='0') {
        for(int i=0;i<k;i++) {
            cout<<ans[i];
        }
        cout<<" "<<yushu/10<<endl;}
    else {
        for(int i=1;i<k;i++) {
            cout<<ans[i];
        }
        cout<<" "<<yushu/10<<endl;
    }
    return 0;
}