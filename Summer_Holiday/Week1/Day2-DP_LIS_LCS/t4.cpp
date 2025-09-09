/*
t4 整数n拆成平方数的和
分数 20
作者 高见元
单位 湖北经济学院
对于一个正整数n(<100000)，想把它拆成k个不同正整数x1,x2,...,xk的平方和，
即满足n=x1^2+x2^2+...+xk^2，求x1+x2+...+xk的最大值。如果无法拆分，则输出0。

输入格式:
一个正整数n。

输出格式:
分2行，第一行为对应x1+x2+...+xk的最大值，
如果最大值不为0时，则紧接着换一行输出最小字典序的x1 x2 ...xk，否则仅输出第1行的0。

输入样例:
在这里给出一组输入。例如：
6
50
5001

输出样例:
0
12
1 2 3 6
295
1 3 4 5 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 23 24 25

代码长度限制 16 KB
时间限制 1200 ms
内存限制 256 MB
栈限制 8192 KB
*/
#include <iostream>
using namespace std;
int d[100010][101], a[10000];
int dp(int n, int k){
    if (n < k * k)  return -10000;
    else if(d[n][k])  return d[n][k];
    else if (n == k * k) return d[n][k] = k;
    else return d[n][k] = max(k + dp(n - k * k, k + 1), dp(n, k + 1));
}
int main(){
    int n, s, t = 1, ans = 0, sum = 0, i;
    bool p = 1;
    cin >> n;
    s = n;
    dp(n, 1);
    while (p && s){
        if (d[s][t] == t + d[s - t * t][t + 1]){
            a[ans] = t;
            sum += t;
            ans++;
            s -= t * t;
            t++;
        }
        else if (d[s][t] == d[s][t + 1])t++;
        else{
            cout << '0' << endl;
            p = 0;
        }
    }
    if(p){
        cout << sum << endl;
        for(i = 0; i < ans; i++){
            if(i) cout << ' ';
            cout << a[i];
        }
    }
    return 0;
}