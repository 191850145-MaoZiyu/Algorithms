#include <bits/stdc++.h>
#include "sort.h"
using namespace std;
int main(void)
{
    random_device rd; 
    default_random_engine engine(rd());
    uniform_int_distribution<> dis(0, maxn); 
    auto dice = bind(dis, engine);
    int test_times = 100;
    for (int i = 1; i <= test_times; i++)
    {
        int n;
        do {
            n = dice();
        } while (n < minn);
        Sort s(n);
        rand_sort_and_check(bubble, i);
        rand_sort_and_check(insertion, i);
        rand_sort_and_check(shell, i);
        rand_sort_and_check(selection, i);
        rand_sort_and_check(heap, i);
        rand_sort_and_check(merge, i);
        rand_sort_and_check(quick, i);
        rand_sort_and_check(counting, i);
    }
    return 0;
}
