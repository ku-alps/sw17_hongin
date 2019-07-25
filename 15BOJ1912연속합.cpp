#include <iostream>
using namespace std;

int main(){
    int n, arr[100001], dp[100001][4];
    cin >> n;
    
    arr[0] = 0;
    for (int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }
    
    dp[0][0] = 0; dp[0][1] = 0;
    dp[0][2] = 0; dp[0][3] = 0;
    for (int i = 1 ; i <= n ; i++){
        dp[i][0] = max(dp[i-1][0] + arr[i], dp[i-1][2] + arr[i]);
        dp[i][1] = 0;
        dp[i][2] = max(dp[i-1][1] + arr[i], dp[i-1][3] + arr[i]);
        dp[i][3] = 0;
//        cout << dp[i][0] << "\t";
    }
//    cout << endl;
//    for (int i = 1 ; i <= n ; i++)
//        cout << dp[i][1] << "\t";
//    cout << endl;
//    for (int i = 1 ; i <= n ; i++)
//        cout << dp[i][2] << "\t";
//    cout << endl;
//    for (int i = 1 ; i <= n ; i++)
//        cout << dp[i][3] << "\t";
//    cout << endl;
    
    int max = -100000000, can;
    for (int i = 1 ; i <= n ; i++){
        can = dp[i][0] > dp[i][2] ? dp[i][0] : dp[i][2];
        if (can > max) max = can;
    }
    cout << max << endl;

    return 0;
}

/*
 수열에서 최대값 구하기
 디피 냄새
 10 -4 3 1 5 6 -35 12 21 -1 --> 12 + 21 = 33 정답
 이차원 배열 냄새
 경우의 수를 따져보자
 
 연속 불연속은 이웃하는 두 항사이에서 모든 경우를 다 따질 수 있는거 아냐?
 선택한다 안한다 (두 개 선택하는 법)
 선택 선택
 선택 노선
 노선 선택
 노선 노선
 OO 연
 OX 불
 XO 불
 XX 불
 
 둘칸은 연속을 잇거나 연속을 시작하거나 연속을 종료하거나 막장이거나이지.
 그 전칸도 연속을 잇거나 연속을 시작하거나 연속을 종료하거나 막장이거나이지.
 아. 세칸을 봐야겠네
 
 다시 경우의 수를 따진다 (세 개 선택하는 법)
 두 칸씩 연결해서 볼까
 OOO 연-연
 OOX 연-불
 OXO 불-불
 XOO 불-연
 OXX 불-불
 XOX 불-불
 XXO 불-불
 XXX 불-불
 
 수는 한개 이상이니까... 한 개를 연속으로 봐야하네?
 그냥 O 연, X 불로 처리하면 되네
 
 OOO 연-연
 OOX 연-불
 OXO 불-연
 XOO 연-연
 OXX 불-불
 XOX 연-불
 XXO 불-연
 XXX 불-불
 
 중간칸을 잘 보면, 다음칸 의 선택의 경우는 4개 조합이지만, 전칸의 경우도 4조합 고려하네
 뒷 칸에서 최대값은 어떻게 구하지?
 뒷 두칸 OO OX XO XX로 정렬해
 
 연-연 OOO XOO
 연-불 OOX XOX
 불-연 OXO XXO
 불-불 OXX XXX
 
 정답 각이네
 불이 뜨면 0으로 초기화하면 되는 건가
 그런 것 같은데?
 이차원 배열을 그려나가는데, 안에 채워지는 값이 ... 연속이며 동시에 최대인 누적값들로 채우는 거냐?
 그래서 이차원배열을 다시 읽어서 최대값을 찾는거냐?
 그런 듯.

 저거 구현하면 어케되냐? 몰겠네
 
 막칸이
 OO     OO+O XO+O       dp0+arr dp2+arr
 OX     OO+X XO+X       dp0     dp2
 XO     OX+O XX+O       dp1+arr dp3+arr
 XX     OX+X XX+X       dp1     dp3
 이렇게 나누는 건가.
 
 나누고 뭐 어떻게 해야하지?
 계산을 바꿔야 하나?
 OO     OO+O XO+O       dp0+arr dp2+arr
 OX     OO+X XO+X       0     0
 XO     OX+O XX+O       dp1+arr dp3+arr
 XX     OX+X XX+X       0     0
 
 아니네 합이 음수일 수 있구나..
 2
 -2 -1
 
 OO     OO+O XO+O       dp0+arr dp2+arr
 OX     OO+X XO+X       dp0+0     dp2+0
 XO     OX+O XX+O       dp1+arr dp3+arr
 XX     OX+X XX+X       dp1+0     dp3+0
 -2    -3
 0    -2
 -2    -1
 0    0
 
 아닌가 OO XO 중에서 봐야하나
 
 아 알았다..!
 계산은
 OO     OO+O XO+O       dp0+arr dp2+arr
 OX     OO+X XO+X       0     0
 XO     OX+O XX+O       dp1+arr dp3+arr
 XX     OX+X XX+X       0     0
 이걸로
 
 마지막에 선택은 OO XO에서
 
 두시간 걸렸네
 
 */

