## 排序算法

包括各种比较排序：

- `冒泡排序 —— bubble_sort`

- `插入排序 —— insertion_sort`

- `希尔排序 —— shell_sort`

- `选择排序 —— selection_sort`

- `堆排序 —— heap_sort`

- `归并排序 —— merge_sort` 

- `快速排序 —— quick_sort`；

还包括一个线性时间排序：

- `计数排序 —— counting_sort`；

包含三个文件：`sort.h` ，`check.cpp`， `sort.cpp`

一些宏定义：

```C++
// Do not modify these macros 不要修改这些宏
#define str(x) #x									// 字符串 x
#define green(s) "\033[1;32m" str(s) "\033[0m"		// 绿色字符串 s
#define red(s)   "\033[1;31m" str(s) "\033[0m"		// 红色字符串 s
#define sort_type(name) void name(int l, int r)		// 排序函数
#define sort_(type) s.type ## _sort(bound)			// 用来使用排序函数，宏 bound 见下
// 下面这个宏可以用来测试排序函数（使用方法见 check.cpp）
// 首先生成随机数，然后采用相应的排序算法，最后检查并返回结果，可测多组样例
#define rand_sort_and_check(type, times)                                                \
    s.rand_nums(bound);                                                                 \
    s.type ## _sort(bound);                                                             \
    if (s.check(bound))                                                                 \
        printf(output_format, str(type ## _sort), times, green(Accepted));              \
    else                                                                                \
        printf(output_format, str(type ## _sort), times, red(Wrong));
// Can modify these macros	可以修改这些宏
#define __EASYTEST__								// 弱数据，可修改数据范围
#ifdef __EASYTEST__
    #define maxn 10000
    #define minn 100
#else
	#define maxn 10000000
	#define minn 1000
#endif
#define output_format "%15s: Case: %3d: %s\n"		// 测试输出格式，可修改
#define bound 0, n - 1								// 对数组操作的范围，可修改
```

使用方法：

1. 首先创建一个类

	```C++
	Sort s(n);	// n 是数组大小，从 0 到 n - 1
	```

2. 然后给数组赋初值

	```C++
	s.rand_nums(l, r);	// 为数组下标在 [l, r] 的范围内随机生成不超过 maxnum 的正整数
	s.read_nums(l, r);	// 为数组下标在 [l, r] 的范围内读入 int 类型的数（不要超过 maxnum，但是某些排序算法不支持负数）
	// 可以将 l, r 换成 bound 宏，比如 s.read_nums(bound)
	```

3. 选择相应的排序算法然后输出结果（比如归并排序）

	```C++
	s.merge(l, r);
	s.print_nums(l, r);
	```

其他操作见 `check.cpp`
