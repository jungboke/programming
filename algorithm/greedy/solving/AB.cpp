#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    /*
        b의 개수만큼 미리 b를 배치해놓고 가장 왼쪽에 a를 배치하면 가능한 쌍의
        개수가 b개 만큼 늘어나기 때문에 가장 왼쪽에 모든 a를 배치하는 경우
        최대 쌍의 개수가 a*b만큼 되서 가능한 쌍의 개수는 0~a*b개가 됨.
        필요한 k개의 쌍에서 가장 왼쪽에 들어갈 수있는 a의 개수를 cnt[b]
        (b는 해당칸에 a를 놓을시 늘어나는 쌍의 개수)에 넣으면서 동시에 k를
        b만큼 줄여나가면 b사이들에 들어가는 a의 개수를 정할수 있음.
    */
    int n, k;
    cin >> n >> k;
    for(int a=0;a<=n;a++)
    {
        int b = n-a;
        if(a*b<k) continue;
        vector<int> cnt(b+1);
        for(int i=0;i<a;i++)
        {
            int d = min(b,k);
            cnt[d]++;
            k-=d;
        }
        for(int i=b;i>=0;i--)
        {
            for(int j=0;j<cnt[i];j++)
            {
                cout << 'A';
            }
            if(i>0)
            {
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';    
    return 0;
}