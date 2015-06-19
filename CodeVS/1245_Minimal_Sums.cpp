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

int cmp(const void * a, const void * b) {
    int arg1 = *static_cast<const int*>(a);
    int arg2 = *static_cast<const int*>(b);
    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}


int main(int argc, char const *argv[])
{
	int a[100000], b[100000];
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

	// for(int i = 0; i < n; ++i){
	// 	printf("%d, %d\n", a[i], b[i]);
	// }

	// auto comp = [] (int &a, int &b) -> bool { return a < b; };
	priority_queue<intWithCor, vector<intWithCor>, Compare> sums, border;
	int i, j, num, level = 0;
	num = n;
	intWithCor tempIntWithCor, minIntWithCor_1, minIntWithCor_2;
	// printf("Fucking before %d\n", num);
	tempIntWithCor.num = (a[0] + b[0]);
	tempIntWithCor.x = 0;
	tempIntWithCor.y = 0;

	sums.push(tempIntWithCor);
	--num;

	tempIntWithCor.num = (a[0] + b[1]);
	tempIntWithCor.x = 0;
	tempIntWithCor.y = 1;
	border.push(tempIntWithCor);

	tempIntWithCor.num = (a[1] + b[0]);
	tempIntWithCor.x = 1;
	tempIntWithCor.y = 0;
	border.push(tempIntWithCor);	

	while (num > 0) {
		debug_print("=====Starting====== %d\n", 1);

		// Taking in from the heap, No no no you should first generate the border...
		// The next elements are taken from the border.
		minIntWithCor_1 = border.top();
		border.pop();
		if (border.size() >= 1) {
			minIntWithCor_2 = border.top();
			debug_print("first %d, %d. second %d, %d\n", minIntWithCor_1.x, minIntWithCor_1.y, minIntWithCor_2.x, minIntWithCor_2.y);
			if (minIntWithCor_2.x != minIntWithCor_1.x || minIntWithCor_2.y != minIntWithCor_1.y) {
				debug_print("They are different! %d\n", 1);
			} else {
				border.pop();
			}
		}

		
		// You should double check that there is no duplication in the border?
		// No you should use map in the border...
		sums.push(minIntWithCor_1);
		debug_print("Pushing at %d, %d\n", minIntWithCor_1.x, minIntWithCor_1.y);

		tempIntWithCor.x = minIntWithCor_1.x + 1;
		tempIntWithCor.y = minIntWithCor_1.y;
		tempIntWithCor.num = a[tempIntWithCor.x] + b[tempIntWithCor.y];
		border.push(tempIntWithCor);
		// TODO: abstraction here...
		tempIntWithCor.x = minIntWithCor_1.x;
		tempIntWithCor.y = minIntWithCor_1.y + 1;
		tempIntWithCor.num = a[tempIntWithCor.x] + b[tempIntWithCor.y];
		border.push(tempIntWithCor);
		debug_print("=====Ending====== %d\n", 1);
		// printf("\n");
		num--;
	}
	// printf("Fucking! %lu\n", sums.size());
	num = n;
	while (sums.size() > 0 && num > 0) {
		debug_print("%d at %d, %d\n", sums.top().num, sums.top().x, sums.top().y);
		// printf("%d at (%d, %d)\n", sums.top().num, sums.top().x, sums.top().y);
		printf("%d", sums.top().num);
		if (num > 1) {
			printf(" ");
		}
		sums.pop();
		--num;
	}
// TODO: make the program dynamic with animation.
	return 0;
}