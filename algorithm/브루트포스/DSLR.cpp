//모범답안
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char how[10000]; // DSLR중 어떤 방법을 통해 해당칸에 도착했는지 나타내기위한 배열
int from[10000]; // 역추적을 위해 어느칸에서 넘어왔는지 나타내기위한 배열
bool check[10000]; // 재방문을 막기위한 배열
queue<int> q; //bfs
void bfs(int start)
{
	check[start] = true; //bfs
	q.push(start); //bfs
	from[start] = 0; //bfs
	while(!q.empty()) //bfs
	{
		int k = q.front(); //bfs
		q.pop(); //bfs
		
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
void print(int n, int m) // 재귀함수를 통한 역추적 및 출력
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
		memset(check,false,sizeof(check)); // memset함수를 통한 check배열 초기화
		memset(from,0,sizeof(from)); // memset함수를 통한 from배열 초기화
		memset(how,0,sizeof(how)); // memset함수를 통한 how배열 초기화
		bfs(n);
		print(n,m);
		cout << '\n';
	}
	return 0;
}
