//모범답안
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char how[10000];
int from[10000];
bool check[10000];
queue<int> q;
void bfs(int start)
{
	check[start] = true;
	q.push(start);
	from[start] = 0;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		
		int D = (2*k)%10000;
		if(check[D] == false)
		{
		check[D] = true;
		from[D] = k;
		how[D] = 'D';
		q.push(D);
		}
		
		int S = k-1;
		if(S == -1) S = 9999;
		if(check[S] == false)
		{
		check[S] = true;
		from[S] = k;
		how[S] = 'S';
		q.push(S);
		}
		
		int L = (k%1000)*10 + (k/1000);
		if(check[L] == false)
		{
		check[L] = true;
		from[L] = k;
		how[L] = 'L';
		q.push(L);
		}
		
		
		int R = k/10 + (k%10)*1000;
		if(check[R] == false)
		{
		check[R] = true;
		from[R] = k;
		how[R] = 'R';
		q.push(R);
		}
	}
}
void print(int n, int m)
{
	if(n == m) return;
	print(n,from[m]);
	cout << how[m];
}
int main(int argc, char** argv) {
	
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		memset(check,false,sizeof(check));
		memset(from,0,sizeof(from));
		memset(how,0,sizeof(how));
		bfs(n);
		print(n,m);
		cout << '\n';
	}
	return 0;
}
