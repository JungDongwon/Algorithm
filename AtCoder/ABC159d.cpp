// 주의 사항
// 1. n의 범위가 1 <= n <= 2*10^5 이다.
//    그러므로 O(n^2)이면 시간초과가 난다.
//    O(n)에 풀 수 있는 방법을 모색해야한다.
//    이런 문제는 부분합 유형을 활용하면 time complexity를 줄일 수 있다. 
//    total을 O(n)에 미리 구해놓고 for문을 돌면서 각 출력값에 대하여 O(1)에 구할 수 있는 값을 빼면 총 O(n)으로 풀 수 있다.
// 2. 큰 수를 다룰 때는 자료형을 주의해야 한다.
//    습관적으로 배열이나 total 같은 변수를 int로 선언하면 overflow가 난다.
//    의식적으로 처음부터 long long으로 선언하자. (특히 배열!! 실수 많이함...)

#include <iostream>
#include <vector>
using namespace std;
long long a[200001];
long long b[200001];
int main() {
	long long n;
	cin >> n;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		a[i]=t;
		b[t]+=1;
	}
	long long total=0;
	for(int i=1;i<=n;i++){
		total+=b[i]*(b[i]-1)/2;		
	}
	
	for(int i=0;i<n;i++){
		cout << total-(b[a[i]]-1) << '\n';	
	}
}
