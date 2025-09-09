/*
t2 LX402 区间异或
分数 10
作者 李昕
单位 中国石油大学（华东）

题目背景
《C/C++简明双链教程》
知识点：T411,T431,T26C

计算l,l+1,l+2,...r的异或和

输入格式
输入包括两个整数l和r，空格分隔，1≤l<r≤10^18
输出格式
输出题目描述中的异或和

样例输入
3 6
样例输出
4
提示 当数值范围比较大时，依靠循环叠加速度会比较慢，要利用异或运算自身的特点，减少循环次数

代码长度限制 16 KB
时间限制 400 ms
内存限制 64 MB
栈限制 8192 KB
*/

#include <iostream>
using namespace std;
typedef long long LL;
LL XOR(LL n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
}
int main(){
    LL l, r;
    cin >> l >> r;
    LL result = XOR(r) ^ XOR(l - 1);
    cout << result << endl;
    return 0;
}