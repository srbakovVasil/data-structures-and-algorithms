//https://www.hackerrank.com/contests/sda-2020-2021-test5-trgdcw/challenges/challenge-2712/submissions/code/1328070573
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack> 
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<int>s;
    stack<int>s2;
    int n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num >= 0) {
            sum += num;
            s.push(num);
        }
        else if (num == -1)
        {
            if (!s.empty()) {
                int tmp = s.top();
                s.pop();
                s2.push(tmp);
                sum -= tmp;
            }
        }
        else if (num == -2)
        {
            if (!s2.empty()) {
                int tmp = s2.top();
                s2.pop();
                s.push(tmp);
                sum += tmp;
            }
        }
    }
    cout << sum;
    return 0;
}
