//모범답안
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0, 0, 1, -1}; // 상하좌우 움직이기 위한 x,y 값 배열
int dy[] = {1, -1, 0, 0};
int go(vector<string> &board, vector<bool> &check, int x, int y) {
int ans = 0;
for (int k=0; k<4; k++) {
int nx = x+dx[k];
int ny = y+dy[k];
if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
if (check[board[nx][ny]-'A'] == false) {
check[board[nx][ny]-'A'] = true;
int next = go(board, check, nx, ny); // 처음 리턴받는 값은 1
if (ans < next) {
ans = next; // ans의 처음값 1
}
check[board[nx][ny]-'A'] = false;
}
}
}
return ans + 1; // 처음 갈수있는곳까지 이동한후 1 리턴함. 그후 갈수있는곳까지 가면 1씩 추가됨
}
int main() {
int n, m;
cin >> n >> m;
vector<string> board(n); // n X m 개의 알파벳 입력을 위한 vector<string>생성 * 이렇게하면 board[a][b]식으로 접근가능
for (int i=0; i<n; i++) {
cin >> board[i]; // 알파벳 입력
}
vector<bool> check(26); // 지나온 알파벳을 체크하기 위한 총 알파벳 개수 25개의 bool형 check배열 생성
check[board[0][0]-'A'] = true; // 시작점 알파벳 check
cout << go(board, check, 0, 0) << '\n'; // 재귀함수 실행
return 0;
}
