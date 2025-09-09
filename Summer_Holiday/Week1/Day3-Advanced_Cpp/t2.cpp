/*
t2 离散背包问题的递归分治解法
分数 25
作者 陈越
单位 浙江大学
离散背包问题是这样定义的：给定一个总承重量为 W 的背包和 n 件物品的集合 S={s1,⋯,sn}，其中第 i 件物品有其重量 wi 和价值 vi 。如果将第 i 件物品 si 的 xi部分（xi或者为 1，或者为 0）放入背包，则放入的重量为xi⋅wi，放入的价值为xi⋅vi。要求一种分派方案x=(x1,⋯,x )，在满足约束条件 R: Σi=1nxi⋅wi≤W（即装入的物品总重量不超过背包承重）的前提下，使优化函数 f( 
x)=Σi=1nxi⋅vi取极大值（即装入的物品总价值最大）。本题就请你实现解决这个问题的递归分治解法。

输入格式：
输入首先在第一行中给出正整数 n（≤20）和正实数 W（≤500）。随后两行各给出 n 个不超过 2000 的正实数，分别为 n 件物品的重量和价值，即第一行第 i 个数字表示第 i 件物品的重量，第二行对应位置表示其价值。同行数字间以空格分隔。

输出格式：
首先在第一行输出装入物品的最大总价值，要求输出小数点后 2 位。随后一行输出最优分派方案的分量 (x1,⋯,xn)。简单起见，每个分量后面跟一个空格。

输入样例：
5 11.0
1 2 5 6 7
1 6 18 22 28

输出样例：
40.00
0 0 1 1 0 

代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
栈限制
8192 KB
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Item{
    double weight;
    double value;
    double ratio;
    int index;
};
bool compareItems(const Item& a, const Item& b){
    return a.ratio > b.ratio;
}
double calculateBound(int i, double currentWeight, double currentValue, double W, const vector<Item>& items, int n){
    double bound = currentValue;
    double remaining = W - currentWeight;
    for(int j = i; j < n && remaining > 1e-5; j++){
        if(remaining >= items[j].weight){
            bound += items[j].value;
            remaining -= items[j].weight;
        }else{
            bound += items[j].ratio * remaining;
            remaining = 0;
            break;
        }
    }
    return bound;
}
void dfs(int i, double currentWeight, double currentValue, vector<int>& currentChoices, 
         vector<int>& bestChoices, double& bestValue, const vector<Item>& items, double W, int n){
    if(i == n){
        if(currentValue > bestValue + 1e-5){
            bestValue = currentValue;
            for(int j = 0; j < n; j++) bestChoices[j] = currentChoices[j];
        }
        return;
    }
    double bound = calculateBound(i, currentWeight, currentValue, W, items, n);
    if(bound <= bestValue + 1e-5) return;
    dfs(i + 1, currentWeight, currentValue, currentChoices, bestChoices, bestValue, items, W, n);
    if(currentWeight + items[i].weight <= W + 1e-5){
        currentChoices[items[i].index] = 1;
        dfs(i + 1, currentWeight + items[i].weight, currentValue + items[i].value, 
            currentChoices, bestChoices, bestValue, items, W, n);
        currentChoices[items[i].index] = 0;
    }
}
int main(){
    int n;
    double W;
    cin >> n >> W;
    vector<double> weights(n), values(n);
    for(int i = 0; i < n; i++)cin >> weights[i];
    for(int i = 0; i < n; i++)cin >> values[i];
    vector<Item> items(n);
    for(int i = 0; i < n; i++)items[i] = {weights[i], values[i], values[i] / weights[i], i};
    sort(items.begin(), items.end(), compareItems);
    vector<int> currentChoices(n, 0);
    vector<int> bestChoices(n, 0);
    double bestValue = 0.0;
    dfs(0, 0.0, 0.0, currentChoices, bestChoices, bestValue, items, W, n);
    cout << fixed << setprecision(2) << bestValue << endl;
    for(int i = 0; i < n; i++)cout << bestChoices[i] << " ";
    return 0;
}