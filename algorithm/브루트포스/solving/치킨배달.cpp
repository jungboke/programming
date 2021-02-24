#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int a[60][60];
vector<pair<int,int>> h; // 집의 좌표를 넣기위한 배열 
vector<pair<int,int>> c; // 치킨집의 좌표를 넣기위한 배열 
vector<int> result;
vector<int> cal;
bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.first < b.first);
}


int main(int argc, char** argv) {

	int n, m;
	cin >> n >> m;
	int x= 0, y= 0; // x는 집의수 y는 치킨집의 수 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				h.push_back(make_pair(i,j));
				x++;
			}
			if(a[i][j] == 2){
				c.push_back(make_pair(i,j));
				y++;
			} 
		}
	}
	sort(c.begin(),c.end(),sortbyfirst);
	for(int i=0;i<y-m;i++)
	cal.push_back(0);
	for(int i=0;i<m;i++)
	cal.push_back(1);
	
	sort(cal.begin(),cal.end());
	do{
		int real = 0;
		for(int i=0;i<x;i++){
			int ans = -1;
			for(int j=0;j<y;j++){
				if(cal[j]==0)
					continue;
				else if(cal[j]==1){
					int temp = abs(h[i].first-c[j].first) + abs(h[i].second-c[j].second);
					if(ans == -1 || ans>temp)
						ans = temp; 
				}	
			}
			real += ans;
			}
			result.push_back(real);
	}while(next_permutation(cal.begin(),cal.end()));
	
	
	cout << *min_element(result.begin(),result.end()) << '\n';	
	
	return 0;
}
