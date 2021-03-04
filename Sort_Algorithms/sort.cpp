#include <bits/stdc++.h>
#include "sort.h"
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    Sort s(n);
    s.read_nums(bound);
    s.merge_sort(bound);
    s.print_nums(bound);
    return 0;
}
 
