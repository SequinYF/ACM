#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int mmap[4][4];
int ii, jj;
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
queue <int> q;

bool l_check(int a, int b){
	if(a > 0 && a <= 3 && b > 0 && b <= 3){
		return true;
	}

	return false;
}

bool check(){
	if(mmap[1][1] == 1)
		if(mmap[1][2] == 2)
			if(mmap[1][3] == 3)
				if(mmap[2][1] == 4)
					if(mmap[2][2] == 5)
						if(mmap[2][3] == 6)
							if(mmap[3][1] == 7)
								if(mmap[3][2] == 8)
									if(mmap[3][3] == 0){
										return true;
									}
	return false;
}

void bfs(int a, int b){
	if(check()){
		cout << "YES" << endl;
		return;
	}

	while(!q.empty()){
		q.pop();
	}
	q.push()
	while(!q.empty()){

	}
	for(int i = 0; i < 4; i++){
		int aa = a + dir[i][0];
		int bb = b + dir[i][1];
		if(l_check(aa, bb)){
			dfs(aa, bb);
		}
	}
}


int main(){

	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			int & tt = mmap[i][j];
			cin >> tt;
			if(tt == 0){
				ii = i; jj = j;;
			}
		}
	}
	bfs(ii, jj);
}

