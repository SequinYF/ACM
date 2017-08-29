/********************************************************************
* File Name: c.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  8/30 00:02:16 2017
*************************************************************************/

#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int pre[1000001];
int ver[1000001];
int ans[1000001];

int find_(int x){
    int t = x;

    if(pre[t] == 0){
        pre[t] = t;
    }

    while(pre[t] != t){
        t = pre[t];
    }

    return t;
}

bool join_(int x, int y){

    int xx = find_(x);
    int yy = find_(y);
    if(xx != yy){
        pre[xx] = yy;
        return false;
    }

    return true;
}



int main(){
   // ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int mmin = 1000000;
    int mmax = -1000000;
    for(int i = 1; i <= n; i++) {
    	cin >> ver[i];
 
    }
   // cout << mmin << mmax << endl;
    for(int i = 1; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	join_(b, a);
    }
    int ret;
    for(int i = n; i > 0; i--) {
    	int t = i;
    	while(pre[t] != t){
    		t = pre[t];
 			mmin = min(ver[t], mmin);
			mmax = max(ver[t], mmax);
 			
    	}
    	mmin = min(mmin, ver[i]);
    	mmax = max(ver[i], mmax);
    	//cout << mmin << mmax << endl;
    	t = i;
    	ret = mmax;
 		while(pre[t] != t){
        	t = pre[t];
        	if(ver[t] == mmin) {
        		ret = __gcd(mmax, ret);
        	}else
        		ret = __gcd(ver[t], ret);
    	}
    	ans[i] = ret;
    	
	}

	for(int i = 1; i <= n; i++) {
    	cout << ans[i] << endl;
    }
}
   
    
 