#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<int> num, vector<char> a){
    for(int i=0;i<num.size()-1;i++){
        if(a[i] == '<'){
            if(num[i] >= num[i+1]){
                return false;
            }
        }
        else if(a[i] == '>'){
            if(num[i] <= num[i+1]){
                return false;
            }
        }
    }
    return true;    
}



int main() {

    int k;
    cin >> k;
    vector<char> a(k);    
    for(int i=0;i<k;i++){
        cin >> a[i];
    }
    vector<int> num(k+1);
    for(int i=0;i<k+1;i++){
        num[i] = 9-i;
    }
    do{
        if(check(num,a)==true){
            for(int i=0;i<k+1;i++){
                cout << num[i];
            }
            cout << '\n';
            break;
        }
        
    }while(prev_permutation(num.begin(),num.end()));
    vector<int> num2(k+1);
    for(int i=0;i<k+1;i++){
        num[i] = i;
    }
    do{
        if(check(num,a)==true){
            for(int i=0;i<k+1;i++){
                cout << num[i];
            }
            cout << '\n';
            break;
        }
        
    }while(next_permutation(num.begin(),num.end()));
    return 0;
}