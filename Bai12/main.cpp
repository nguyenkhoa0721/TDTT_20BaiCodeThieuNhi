#include <bits/stdc++.h>
using namespace std;

#define MAX 1e3
#define ll long long
#define pii pair<int, int>

pii add(pii p, int i, int j){
    pii r;
    r.first = p.first + i;
    r.second = p.second + j;
    return r;
}

void printSquare(int i, int j){
    int _min = min(i, j);
    j += i; i = _min; j -= _min; 
    vector<pii> p(4);
    pii o = {0,0};
    o.first = -(i+j)/2;
    o.second = -(i+j)/2;
    p[0] = add(o, i, j);
    p[1] = add(p[0], i, j);
    p[2] = add(p[1], j, -1*i);
    p[3] = add(p[2], -1*i, -1*j);
    for(pii _p: p){
        cout<<_p.first<<" "<<_p.second<<endl;
    }
}

bool checkByFermatTheorem(int s){
    for (int i = 2; i * i <= s; i++) {
        int count = 0;
        if (s % i == 0) {
            while (s % i == 0) {
                count++;
                s /= i;
            }            
            if (i % 4 == 3 && count % 2 != 0)
                return 0;
        }
    }        
    return s % 4 != 3;  
}

void solution(){
    int s;
    cin >> s;

    // for(int i=0; i<=sqrt(s)+1; ++i){
    //     for(int j=0; j<=sqrt(s)+1; ++j){
    //         if(i*i+j*j==s){
    //             printSquare(i, j);
    //             return;
    //         }
    //     }
    // }
    
    unordered_map<int, int> set;
    for (int i = 0; i * i <= s; ++i) {
 
        
        set[i * i] = 1;
        if (set.find(s - i * i) != set.end()) {
            printSquare(sqrt(s - i * i), i);
            return;
        }
    }
    
    cout<<"Impossible";
}

int main(){
    solution();
    return 0;
}