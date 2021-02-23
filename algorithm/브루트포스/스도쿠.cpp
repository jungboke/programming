#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[10][10];
bool c1[10][10]; // c1[x][y] : x행에 숫자 y있으면 true;  
bool c2[10][10]; // c2[x][y] : x열에 숫자 y있으면 true;
bool c3[10][10]; // c3[x][y] : x번째 네모에 숫자 y있으면 true;

int square(int x,int y){
	return ((x/3)*3 + (y/3));
}
void cal(int n) {
	if(n==81){
	
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
		}
		exit(0);
	}
	int x = n/9;
	int y = n%9;	
	int z = square(x,y); 
	if(a[x][y] != 0)
		cal(n+1);
	else{
	for(int i=1;i<10;i++){
		if(c1[x][i] == false && c2[y][i] == false && c3[z][i] == false)
			{
			c1[x][i] = true;
			c2[y][i] = true;
			c3[z][i] = true;
			a[x][y] = i;
			cal(n+1);
			a[x][y] = 0;
			c1[x][i] = false;
			c2[y][i] = false;
			c3[z][i] = false;
			}
	}
	}
	
}


int main(int argc, char** argv) {

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> a[i][j];
			if(a[i][j] != 0){
				c1[i][a[i][j]] = true;
				c2[j][a[i][j]] = true;
				c3[square(i,j)][a[i][j]] = true;
			}
		}
	}
	cal(0);
	
	
}
