#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
void go(vector<int> words, int alp, int index, int count){
    if(count==0){
        int temp = 0;
        for(int word : words){
            if((word&((1<<26)-1-alp))==0) temp++; 
        }
        ans.push_back(temp);
        return;
    }
    if(index==26) return;
    go(words,alp|(1<<index),index+1,count-1);
    if(index!='a'-'a'&&index!='n'-'a'&&index!='t'-'a'&&index!='i'-'a'&&index!='c'-'a'){
        go(words,alp,index+1,count);
    }
}



int main() {

    int n, k;
    cin >> n >> k;
    vector<int> words(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(char c : s){
            int a = c - 'a';
            words[i] = words[i] | (1<<a);    
        }
    }
    go(words,0,0,k);
    cout << *max_element(ans.begin(),ans.end()) << '\n';
    return 0;
}