/*
t1 整数拆分
分数 10
作者 张庆
单位 集美大学

给定一个整数n，将其无序拆分成最大数为k的拆分数，（n,k不超出100）
要求：所有的拆分方案不重复。
如当n=4,k=4时，一共有5种拆分方案，拆分如下：
(1)4=1+1+1+1
(2)4=1+1+2
(3)4=1+3
(4)4=2+2
(5)4=4

输入格式:
每一行输入一组整数n,k，遇到键盘结束符^Z或文件结束符EOF时结束输入。
输出格式:
按行输出每组的拆分方案数。 

输入样例:
4,4
5,4
输出样例:
5
6
代码长度限制 16 KB
时间限制 400 ms
内存限制 64 MB
栈限制 8192 KB  
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n ,k;
    char r;
    while(cin >> n >> r >> k){
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int j = 1; j <= k; j++)
            for(int i = j; i <= n; i++)
                dp[i] += dp[i - j];
        cout << dp[n] << endl;
    }
    return 0;
}