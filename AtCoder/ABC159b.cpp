//strong palindrome 확인하는 문제
// 길이가 짝수인 string에 대하여 evenpalin()이라는 함수로 펠린드롬을 확인하였고
// 길이가 홀수인 string에 대하여 oddpalin()이라는 함수로 펠린드롬을 확인함
// 파라미터를 추가하여 두 함수를 하나로 합치면 깔끔하고 코드 길이를 줄일 수 있음. 타임어택이므로 생략함.

#include <iostream>
#include <string>
using namespace std;
bool oddpalin(string s){
	int m = s.length();
	for(int i=0;i<(m-1)/2;i++){
		if(s[i]!=s[m-i-1]){
			return false;	
		}
	}
	return true;
}
bool evenpalin(string s){
	int m = s.length();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			return false;	
		}
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	int n;
	n = s.length();
	if(oddpalin(s)){
		string t= "";
		for(int i=0;i<(n-1)/2;i++){
			t+=s[i];	
		}
		if(evenpalin(t)){
			cout << "Yes" <<'\n';
			return 0;
		}
	}
	cout << "No" <<'\n';
}
