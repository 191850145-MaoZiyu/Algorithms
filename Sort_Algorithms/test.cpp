#include "sort.h"
#include "test.h"
#include <ctime>
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
        printf("Scale: n = %d\n", n);
        Sort s(n);
        rand_data;
        sort_and_check(bubble, i);
        sort_and_check(insertion, i);
        sort_and_check(shell, i);
        sort_and_check(selection, i);
        sort_and_check(heap, i);
        sort_and_check(merge, i);
        sort_and_check(quick, i);
        sort_and_check(counting, i);
    }
    return 0;
}
