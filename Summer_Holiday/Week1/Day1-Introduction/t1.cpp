/*
t1 简单的异或
分数 19
作者 HBU_DS_刘哲轩_赵润朔
单位 河北大学

给定一个二进制整数n，长度不超过10^5
现在请你回答有多少对整数(a,b)满足以下条件：
a+b ≤ n
a+b = a XOR b

其中，XOR代表异或运算。
由于答案可能很大，请你输出答案对1e9+7取模的结果。

输入格式
一个二进制整数，长度不超过10^5

输出格式
输出满足条件的(a,b)数量，答案对1e9+7取模。

测试样例一
输入：
10
输出：
5

测试样例二
输入：
1111111111111111111
输出：
162261460

代码长度限制 16 KB
时间限制 400 ms
内存限制 64 MB
栈限制 8192 KB
*/

#include <iostream>
#include <string>
using namespace std;
const int mod = 1000000007;
int main() {
    string s;
    cin >> s;
    long long tight = 1, free = 0;
    for (char c : s) {
        if (c == '1') {
            free = (free * 3 + tight) % mod;
            tight = (tight * 2) % mod;
        } else {
            free = (free * 3) % mod;
        }
    }
    cout << (free + tight) % mod << endl;
    return 0;
}