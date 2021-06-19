#define __EASYTEST__
// if not define __EASYTEST__, please not use sort whose time complexity is O(n^2)
#ifdef __EASYTEST__
    #define maxn 10000
    #define minn 1000
#else
	#define maxn 1000000
	#define minn 10000
#endif
#define output_format   "\b\b\b\b\b\b\b\b\b\bsort_time = %5ums, %s\n"
#define bound           0, n - 1
#define str(x) 			#x
#define green(s) 		"\033[1;32m" str(s) "\033[0m"
#define red(s)   		"\033[1;31m" str(s) "\033[0m"
#define SORT(type) 		s.type ## _sort(bound)
#define sec             * 1U
#define ms              * 1000U sec
#define us              * 1000U ms
#define rand_data                                                                       \
    do {                                                                                \
        for (int j = 0; j < n; j++)                                                     \
        {                                                                               \
            s.nums[j] = dice();                                                         \
            s.maximum = std::max(s.maximum, s.nums[j]);                                 \
            s.minimum = std::min(s.minimum, s.nums[j]);                                 \
        }                                                                               \
    } while (0)
#define sort_and_check(type, times)                                                     \
    do {                                                                                \
        printf("%15s: Case %3d: sorting...", str(type ## _sort), times);                \
        fflush(stdout);\
        clock_t begin, end;                                                             \
        begin = clock();                                                                \
        SORT(type);                                                                     \
        end = clock();                                                                  \
        unsigned int sort_time = (end - begin) * 1.0 / CLOCKS_PER_SEC * 1 ms;           \
    	if (s.check(bound))                                                             \
    	    printf(output_format, sort_time, green(Accepted));          \
    	else                                                                            \
    	    printf(output_format, sort_time, red(Wrong));		        \
    } while (0)
