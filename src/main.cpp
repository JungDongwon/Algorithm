#include <iostream>
#include <queue>
using namespace std;
bool d[201][201];
bool ans[201];
int main() {
	freopen("a.txt","r",stdin);
	int a,b,c;
	cin >> a >> b >> c;
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	d[0][0] = true;
	ans[c] = true;
	while(!q.empty()){
		int x,y,z;
		x = q.front().first;
		y = q.front().second;
		z = c-x-y;
		q.pop();
		int nx,ny,nz;
		//x->y 물->용기
		nx=x,ny=y,nz=z;
		ny+=nx;
		nx=0;
		if(ny>b){ nx=ny-b; ny=b; } 
		if(!d[nx][ny]){
			q.push(make_pair(nx,ny));
			d[nx][ny]=true;
			if(nx==0) ans[nz]=true;
		}
		//x->z
		nx=x,ny=y,nz=z;
		nz+=nx;
		nx=0;
		if(nz>c){ nx=nz-c; nz=c; } 
			if(!d[nx][ny]){
			q.push(make_pair(nx,ny));
			d[nx][ny]=true;
			if(nx==0) ans[nz]=true;
		}
		//y->x
		nx=x,ny=y,nz=z;
		nx+=ny;
		ny=0;
		if(nx>a){ ny=nx-a; nx=a; } 
			if(!d[nx][ny]){
			q.push(make_pair(nx,ny));
			d[nx][ny]=true;
			if(nx==0) ans[nz]=true;
		}
		//y->z
		nx=x,ny=y,nz=z;
		nz+=ny;
		ny=0;
		if(nz>c){ ny=nz-c; nz=c; } 
			if(!d[nx][ny]){
			q.push(make_pair(nx,ny));
			d[nx][ny]=true;
			if(nx==0) ans[nz]=true;
		}
		//z->x
		nx=x,ny=y,nz=z;
		nx+=nz;
		nz=0;
		if(nx>a){ nz=nx-a; nx=a; } 
		if(!d[nx][ny]){
			q.push(make_pair(nx,ny));
			d[nx][ny]=true;
			if(nx==0) ans[nz]=true;
		}
		//z->y
		nx=x,ny=y,nz=z;
		nx+=ny;
		ny=0;
		if(ny>b){ nz=ny-b; ny=b; } 
			if(!d[nx][ny]){
			q.push(make_pair(nx,ny));
			d[nx][ny]=true;
			if(nx==0) ans[nz]=true;
		}
	}
	for(int i=0;i<=200;i++){
		if(ans[i]) cout << i << " ";
	}
	cout << '\n';
} 