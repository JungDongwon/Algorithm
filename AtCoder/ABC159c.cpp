// 소수점 12번째까지 출력해야하는 문제
// printf 함수를 사용하고 포멧을 "%.12f" 을 지정해야 하는 것을 알아야 한다.
// cout 은 포멧 지정이 불가함.
#include <iostream>
using namespace std;
int main() {
	int L;
	cin >> L;
	printf("%.12f",(double)L*L*L/27);
}
