#include <vector>
#include <algorithm>
#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;
class Solution {
public:
	/**
     * 
     * @param n int整型 
     * @param pos int整型vector 
     * @param dir int整型vector 
     * @param r int整型 
     * @param q int整型 
     * @return int整型vector
     */
	vector<int> solve(int n, vector<int>& pos, vector<int>& dir, int r, int q) {
        // 补全代码
        vector<int> res;
        for(int i=0;i<n;i++){
            int m=2*i;
            if(pos[m]*pos[m]+pos[m+1]*pos[m+1]<r*r){
                if(cos(q/2)<double(dir[0]*pos[m]+dir[1]*pos[m+1])/(sqrt(dir[0]*dir[0])*sqrt(dir[1]*dir[1]))){
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
int n;
vector<int> Pos;
vector<int> Dir;
vector<int> Res;
int R, Q;
int x, y;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		Pos.push_back(x);
		Pos.push_back(y);
	}
	scanf("%d%d", &x, &y);
	Dir.push_back(x);
	Dir.push_back(y);
	scanf("%d%d", &R, &Q);
	Solution sol;
	Res = sol.solve(n, Pos, Dir, R, Q);
	for(auto res:Res) cout << res << " ";
	return 0;
}