#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int num;
    int de_score=0, cai_score=0;
    int total_score;
    int grade = 0;
    bool operator < (const Student &b) const{
        if(grade != b.grade) {
            return grade < b.grade;
        }
        else if(total_score != b.total_score) {
            return total_score > b.total_score;
        }
        else if(de_score != b.de_score) {
            return de_score > b.de_score;
        }
        else {
            return num < b.num;
        }
    }
}s_list[100000];

int main() {
    int n=0,l=0,h=0;
    cin >> n >> l >> h;
    for(int i=0; i < n; ++i) {
        cin >> s_list[i].num >> s_list[i].de_score >> s_list[i].cai_score;
        s_list[i].total_score = s_list[i].de_score + s_list[i].cai_score;
        if(s_list[i].de_score<l || s_list[i].cai_score<l) {
            s_list[i].grade = 5;
        }
        else if(s_list[i].de_score>=h && s_list[i].cai_score>=h) {
            s_list[i].grade = 1;
        }
        else if(s_list[i].cai_score<h && s_list[i].de_score>=h) {
            s_list[i].grade = 2;
        }
        else if(s_list[i].de_score >= s_list[i].cai_score) {
            s_list[i].grade = 3;
        }
        else s_list[i].grade = 4;
    }

    int count = 0;
    for(int i=0; i < n; ++i) {
        if(s_list[i].grade < 5) count++;
    }
    sort(s_list, s_list+n);
    cout << count << endl;
    for(int i=0; i < count; ++i) {
        cout << s_list[i].num << " " << s_list[i].de_score << " " ;
        cout << s_list[i].cai_score << endl;
    }
    return 0;
}