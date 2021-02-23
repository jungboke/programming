//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check(int mask, vector<int> &alps)
{
	int cnt = 0;
	for(int alp : alps)
	{
		if((alp&((1<<26)-1-mask))==0)
		cnt++;
	}
	return cnt;
}

int go(int index,int k,int mask,vector<int> &alps)
{
	if(k<0) return 0;
	if(index == 26) return check(mask,alps);
	int ans = 0;
	int t = go(index+1,k-1,mask|(1<<index),alps);
	if(ans<t) ans = t;
	if(index != 'a'-'a'&&index != 'n'-'a'&&index != 't'-'a'&&index != 'i'-'a'&&index != 'c'-'a')
	{
		t = go(index+1,k,mask,alps);
		if(ans<t) ans = t;
	}
	return ans;
}


int main(int argc, char** argv) {
	
	int n,k;
	cin >> n >> k;
	vector<int> alps(n);
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(char k : s)
		{
			alps[i] |= (1<<(k-'a')); // 단어별 알파벳 비트마스크 
		}
	}
	cout << go(0,k,0,alps) << '\n';
	return 0;
}
