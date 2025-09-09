/*
5 凑零钱
分数 30
作者 陈越
单位 浙江大学
韩梅梅喜欢满宇宙到处逛街。现在她逛到了一家火星店里，发现这家店有个特别的规矩：你可以用任何星球的硬币付钱，但是绝不找零，当然也不能欠债。韩梅梅手边有 10 
4
  枚来自各个星球的硬币，需要请你帮她盘算一下，是否可能精确凑出要付的款额。

输入格式：
输入第一行给出两个正整数：N（≤10^4）是硬币的总个数，M（≤10^2）是韩梅梅要付的款额。第二行给出 N 枚硬币的正整数面值。数字间以空格分隔。

输出格式：
在一行中输出硬币的面值 V1≤V2≤...≤Vk，满足条件 V1+V2+...+Vk=M。数字间以 1 个空格分隔，行首尾不得有多余空格。若解不唯一，则输出最小序列。若无解，则输出 No Solution。

注：我们说序列{ A[1],A[2],⋯ }比{ B[1],B[2],⋯ }“小”，是指存在 k≥1 使得 A[i]=B[i] 对所有 i<k 成立，并且 A[k]<B[k]。

输入样例 1：
8 9
5 9 8 7 2 3 4 1
输出样例 1：
1 3 5
输入样例 2：
4 8
7 2 4 3
输出样例 2：
No Solution
代码长度限制
16 KB
时间限制
300 ms
内存限制
64 MB
栈限制
8192 KB
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int value[10101];
int dp[1001];
int path[10001][110];
bool cmp(const int &a, const int &b){
    return a > b;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> value[i];
    sort(value, value + N, cmp);
    memset(path, 0, sizeof(path));
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = M; j >= 0; j--) {
            if(j - value[i] >= 0 && dp[j - value[i]] == 1){
                dp[j] = 1;
                path[i][j] = 1;
            }
        }
    }
    if(dp[M] == 0)
        printf("No Solution\n");
    else {
        vector<int> res;
        int i = N - 1, j = M;
        while(i >= 0 && j > 0) {
            if(path[i][j] == 1) {
                res.push_back(value[i]);
                j -= value[i];
            }
            i -= 1;
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i == res.size() - 1 ? '\n':' ');
    }
    return 0;
}