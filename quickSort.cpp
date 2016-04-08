#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void swap(int __toSwap[], int __a, int __b) {
	int temp__ = __toSwap[__a];
	__toSwap[__a] = __toSwap[__b];
	__toSwap[__b] = temp__;
}

int partition(int __toSort[], int __low, int __high) {
	int pivokey__ = __toSort[__low];
	while(__low < __high) {
		
		while(__low < __high && __toSort[__high] >= pivokey__) {
			__high--;
		}
		swap(__toSort, __low, __high);
		
		
		while(__low < __high && __toSort[__low] <= pivokey__) {
			__low++;
		}
		swap(__toSort, __low, __high);
		
	}

	return __low;
}

int partition2(int __toSort[], int __low, int __high) {
	int pivokey__ = __toSort[__low];
	while(__low < __high) {
		
		while(__low < __high && __toSort[__high] >= pivokey__) {
			__high--;
		}
		__toSort[__low] = __toSort[__high];
		
		
		while(__low < __high && __toSort[__low] <= pivokey__) {
			__low++;
		}
		__toSort[__high] = __toSort[__low];
		
	}
	__toSort[__low] = pivokey__;

	return __low;
}

void quickSort(int __toSort[], int __low, int __high) {
	if(__low < __high) {
		int midium__ = partition2(__toSort, __low, __high);
	quickSort(__toSort, __low, midium__ -1);
	quickSort(__toSort, midium__ +1, __high);
	}
	
}

int main(int argc, char const *argv[])
{
	int a[] = {1,9,20,21,2,95,100,5,66};
	quickSort(a, 0, 8);

	for(int i = 0; i < 9; i++) {
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}
