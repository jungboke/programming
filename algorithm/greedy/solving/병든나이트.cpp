#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    /*
        칸의 세로 n 기준으로 case분류해서 문제를 푸는 방식.
        n이 1이면 어떤 이동방법도 적용할수 없으니 1,
        n이 2이면 1칸 위아래 이동하는 방법밖에 적용못하고, 그것도 4번이상
        적용불가능하기 때문에 min(4,(m+1)/2)로 해결함.
        n이 3보다 크면 모든 이동방법 적용가능하지만, 가로 7이상일 경우만
        모든 이동방법 적용 가능하기 때문에 이때는 가로길이도 7이상과 아닐때로
        case분류함.
    */
    int n,m;
    cin >> n >> m;
    if(n==1)
    {
        cout << 1 << '\n';
    }
    else if(n==2)
    {
        cout << min(4,(m+1)/2) << '\n';
    }
    else if(n>2)
    {
        if(m<7)
        {
            cout << min(4,m) << '\n';
        }
        else
        {
            cout << m-2 << '\n';
        }
    }

    return 0;
}