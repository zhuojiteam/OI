#include <stdio.h>
#include <stdlib.h>

typedef struct Node * pNode;
typedef struct Node {
	// Starting from the high positions?

	short digit;
	pNode pNext;

} Node;

typedef struct LongInt {

	pNode essence;
	int length;

} LongInt;

void print(LongInt myLongInt);
pNode newNode(short digit);
LongInt zeroLongInt();
pNode newNullNode();
LongInt nullLongInt();


void print(LongInt myLongInt) {
	char * myString;
	myString = (char *)malloc(myLongInt.length * sizeof(char));

	pNode _p = myLongInt.essence; // Temperal variables start with an underline.
	int i = 0;
	while (_p != NULL) {
		*(myString + myLongInt.length - (++i)) = _p->digit + 48;
		_p = _p->pNext;
	}
	printf("%s\n", myString);
}

pNode newNode(short digit) {
	pNode newNode_1 = (pNode)malloc(sizeof(Node));
	newNode_1->digit = digit;
	newNode_1->pNext = NULL;

	return newNode_1;
}



LongInt zeroLongInt() {
	

	LongInt newLongInt;
	newLongInt.length = 1;
	newLongInt.essence = newNode(0);

	return newLongInt;
}

pNode newNullNode() {
	pNode newNode_1 = NULL;
	return newNode_1;
}

LongInt nullLongInt() {

	LongInt newLongInt;
	newLongInt.length = 0;
	newLongInt.essence = newNullNode();
	// I'm really in fear of initializations...
	// I don't know what is the best. That's the source of dread.
	return newLongInt;

}

// How to do unit test in these cases?


pNode appendBefore(pNode node, short digit) {
	pNode newNode_1 = newNode(digit);
	newNode_1->pNext = node;

	return newNode_1;
}

pNode appendBefore(pNode node, short digit);
pNode appendAfter(pNode node, short digit);

pNode appendAfter(pNode node, short digit) {
	pNode newNode_1 = newNode(digit);
	if (node != NULL) node->pNext = newNode_1;
	return newNode_1;

}




// How to copy and duplicate an object in memory?

LongInt product(LongInt num, short num_2) {

	LongInt product;
	product = nullLongInt();
	short extra = 0;
	pNode _p = num.essence;

	for (int i = 0; i < num.length; ++i)
	{

		extra += _p->digit;
	}
}

LongInt leftShift(LongInt num) {
	++num.length;
	num.essence = appendBefore(num.essence, 0);
	// This is legislated because it is confined in the single number itself.
}

LongInt realSum(LongInt num_1, LongInt num_2);

LongInt sum(LongInt num_1, LongInt num_2) {
	if (num_1.length > num_2.length) return realSum(num_1, num_2);
	else return realSum(num_2, num_1);
	// so we are assuming that the first argument is longer than the second argument...
}

LongInt realSum(LongInt num_1, LongInt num_2) { // If we hide the sum function, maybe we can

	LongInt sum = nullLongInt();

// How to initialize it?
	short extra = 0;
	pNode p_1 = num_1.essence;
	pNode p_2 = num_2.essence;
	pNode _start;
// Handling exceptional cases are very cumbersome
	for (int i = 0; i < num_2.length; ++i)
	{
		extra = extra + p_1->digit + p_2->digit;

		sum.essence = appendAfter(sum.essence, extra % 10);
// This is bad. Performance reduction...
		if (i == 0) {
			_start = sum.essence;
		}

		extra /= 10;

		p_1 = p_1->pNext;
		p_2 = p_2->pNext;

	}

	for (int i = num_2.length; i < num_1.length; ++i)
	{
		extra = extra + p_1->digit;

		sum.essence = appendAfter(sum.essence, extra % 10);
		extra /= 10;

		p_1 = p_1->pNext;
	}

	if (extra > 0)
	{
		sum.essence = appendAfter(sum.essence, extra % 10);
		sum.length = num_1.length + 1;
	}
	else {
		sum.length = num_1.length;
	}
	sum.essence = _start;
	return sum;

}

LongInt product(LongInt num_1, LongInt num_2) {

}


int stringToNumber(char * string, int length) {
	int _result = 0;
	for (int i = 0; i < length; ++i)
	{
		_result *= 10;
		_result += *(string + i) - 48;
	}
}

LongInt stringToLongNumber(char * string, int length) {
	LongInt newLongInt = nullLongInt();

	for (int i = 0; i < length; ++i)
	{

		newLongInt.essence = appendBefore(newLongInt.essence, *(string+i) - 48);
		++newLongInt.length;
	}

	return newLongInt;


} // We should unit-test this. We should test this unit...

int main(int argc, char const *argv[])
{
	// int length, numberOfCrosses;
	int length_1, length_2;

	// scanf("%d %d", &length, &numberOfCrosses);
	scanf("%d %d", &length_1, &length_2);

	char * number_1, * number_2;
	number_1 = (char *)malloc(length_1 * sizeof(char));
	number_2 = (char *)malloc(length_2 * sizeof(char));

	scanf("%s", number_1);
	scanf("%s", number_2);

// Simplification and elaboration



	// printf("%s\n", number);


	LongInt myLongInt_1 = stringToLongNumber(number_1, length_1);
	print(myLongInt_1);

	LongInt myLongInt_2 = stringToLongNumber(number_2, length_2);
	print(myLongInt_2);

	print(sum(myLongInt_1, myLongInt_2));
// Logic is not avoidable...
	return 0;
}