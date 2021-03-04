// Do not modify these macros
#define str(x) #x
#define green(s) "\033[1;32m" str(s) "\033[0m"
#define red(s)   "\033[1;31m" str(s) "\033[0m"
#define sort_type(name) void name(int l, int r)
#define sort_(type) s.type ## _sort(bound)
#define rand_sort_and_check(type, times)                                                \
    s.rand_nums(bound);                                                                 \
    s.type ## _sort(bound);                                                             \
    if (s.check(bound))                                                                 \
        printf(output_format, str(type ## _sort), times, green(Accepted));              \
    else                                                                                \
        printf(output_format, str(type ## _sort), times, red(Wrong));
// Can modify these macros
#define __EASYTEST__
#ifdef __EASYTEST__
    #define maxn 10000
    #define minn 100
#else
	#define maxn 10000000
	#define minn 1000
#endif
#define output_format "%15s: Case: %3d: %s\n"
#define bound 0, n - 1

class Sort {
private:
    int n, maximum, minimum;
    void max_heapify(int root, int l, int r)
    {
        int node = l, left = node * 2 + 1 - root;
        while (left <= r)
        {
            if (left + 1 <= r && nums[left] < nums[left + 1])
                left++;
            if (nums[node] > nums[left])
                return;
            else
            {
                std::swap(nums[node], nums[left]);
                node = left;
                left = node * 2 + 1 - root;
            }
        }
    }
public:
    int *nums;
    Sort (int n)
    {
        this->n = n;
        this->maximum = 0;
        this->minimum = 0x7f7f7f7f;
        nums = new int[n];
    }
    bool check(int l, int r)        // increase
    {
        for (int i = l; i < r; i++)
            if (nums[i] > nums[i + 1])
                return false;
        return true;
    }
    // Comparison sort
    sort_type(bubble_sort)          // bubble_sort      O(n^2)
    {
        for (int i = l; i <= r; i++)
            for (int j = r - 1; j >= l; j--)
                if (nums[j + 1] < nums[j])
                    std::swap(nums[j + 1], nums[j]);
    }
    sort_type(insertion_sort)       // insert_sort      O(n^2)
    {
        for (int i = l; i <= r; i++)
        {
            int key = nums[i], j = i - 1;
            while (j >= l && nums[j] > key)
            {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }
    sort_type(shell_sort)           // shell_sort       O(n^1.3)
    {
        int length = r - l + 1;
        int h = 1;
        while (h < length / 3)
            h = 3 * h + 1;
        while (h >= 1)
        {
            for (int i = h + l; i <= r; i++)
                for (int j = i; j >= h + l && nums[j] < nums[j - h]; j -= h) 
                    std::swap(nums[j], nums[j - h]);
            h = h / 3;
        }
    }
    sort_type(selection_sort)       // select_sort      O(n^2)
    {
        for (int i = l; i <= r; i++)
        {
            int index = i;
            for (int j = i + 1; j <= r; j++)
                if (nums[index] > nums[j])
                    index = j;
            std::swap(nums[index], nums[i]);
        }
    }
    sort_type(heap_sort)            // heap_sort        O(nlogn)
    {
        for (int i = (l + r - 1) / 2; i >= l; i--)
            max_heapify(l, i, r);
        for (int i = r; i > l; i--)
        {
            std::swap(nums[l], nums[i]);
            max_heapify(l, l, i - 1);
        }
    }
    sort_type(merge_sort)           // merge_sort       O(nlogn)
    {
        if (l < r)
        {
            int m = l + ((r - l) >> 2);
            merge_sort(l, m);
            merge_sort(m + 1, r);
            // merge(l, m, r);
            int *t = new int[r - l + 1];
            int p = l, q = m + 1, s = 0;
            while (p <= m && q <= r)
                t[s++] = nums[p] > nums[q] ? nums[q++] : nums[p++];
            while (p <= m)
                t[s++] = nums[p++];
            while (q <= r)
                t[s++] = nums[q++];
            for (int i = 0; i < r - l + 1; i++)
                nums[l + i] = t[i];
        }
    }    
    sort_type(quick_sort)           // quick_sort       O(nlogn)
    {
        if (l >= r)
            return;
        int i = l, j = r, base = nums[l]; 
        while (i < j)
        {
            while (nums[j] >= base && i < j)
                j--;
            while (nums[i] <= base && i < j)
                i++;
            if (i < j)
                std::swap(nums[i], nums[j]);
        }
        nums[l] = nums[i];
        nums[i] = base;
        quick_sort(l, i - 1);
        quick_sort(i + 1, r);
    }
    // Linear time sort
    sort_type(counting_sort)        // counting_sort    O(n)
    {
        int *cnt = new int[maximum + 1];
        memset(cnt, 0, sizeof(int) * (maximum + 1));
        int *temp = new int[n + 1];
        for (int i = l; i <= r; i++)
            cnt[nums[i]]++;
        for (int i = minimum; i <= maximum; i++)
            cnt[i] += cnt[i - 1];
        for (int i = r; i >= l; i--)
            temp[cnt[nums[i]]--] = nums[i];
        nums = temp;
    }
    void print_nums(int l, int r)
    {
        for (int i = l; i <= r; i++)
            std::cout << nums[i] << " ";
        std::cout << std::endl;
    }
    void read_nums(int l, int r)
    {
        for (int i = l; i <= r; i++)
        {
            std::cin >> nums[i];
            maximum = std::max(maximum, nums[i]);
            minimum = std::min(minimum, nums[i]);
        }
    }
    void rand_nums(int l, int r)
    {
        std::random_device rd; 
        std::default_random_engine engine(rd());
        std::uniform_int_distribution<> dis(0, maxn); 
        auto dice = bind(dis, engine);
        for (int i = l; i <= r; i++)
        {
            nums[i] = dice();
            maximum = std::max(maximum, nums[i]);
            minimum = std::min(minimum, nums[i]);
        }
    }
};

