#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

#ifdef __DEBUG__
#define DEBUG 1
#else
#define DEBUG 0
#endif

#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

using namespace std;

typedef struct intWithCor {
	int num, x, y;
} intWithCor;

class Compare
{
public:
    bool operator() (intWithCor a, intWithCor b)
    {
    	if (a.num != b.num) 
			return a.num > b.num;
		else {
			if (a.x != b.x) {
				return a.x > b.x;
			} else {
				return a.y > b.y;
			}
		}
    }
};

int cmp2(const void * aa, const void * bb) {
    intWithCor a = *static_cast<const intWithCor*>(aa);
    intWithCor b = *static_cast<const intWithCor*>(bb);
	if (a.num != b.num) 
		if (a.num < b.num) return -1;
		if (a.num > b.num) return 1;
	else {
		if (a.x != b.x) {
			if (a.x < b.x) return -1;
			if (a.x > b.x) return 1;
		} else {
			if (a.y < b.y) return -1;
			if (a.y > b.y) return 1;
		}
	}
    return 0;
}

int cmp(const void * a, const void * b) {
    int arg1 = *static_cast<const int*>(a);
    int arg2 = *static_cast<const int*>(b);
    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}


int main(int argc, char const *argv[])
{
	int a[100], b[100];
	intWithCor sum[10000];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
	}
	qsort(a, n, sizeof(*a), cmp);

	for(int i = 0; i < n; ++i){
		scanf("%d", b + i);
	}

	qsort(b, n, sizeof(*b), cmp);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum[i + n * j].num = a[i] + b[j];
			sum[i + n * j].x = i;
			sum[i + n * j].y = j;
		}
	}

	qsort(sum, n * n, sizeof(*sum), cmp2);

	for(int i = 0; i < n; ++i){
		printf("%d at (%d, %d)\n", sum[i].num, sum[i].x, sum[i].y);
		if (i != n - 1) printf(" ");
	}
// TODO: make the program dynamic with animation.
	return 0;
}