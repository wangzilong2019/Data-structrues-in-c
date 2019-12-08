#include<stdio.h>
#include<Windows.h>
void shellsort(int a[], int length, int delt) {
	int j;
	for (int i = 1 + delt; i < length; i++) {
		if (a[i] < a[i - delt]) {
			a[0] = a[i];
			for (j = i - delt; j > 0 && a[0] < a[j]; j = j - delt) {
				a[j + delt] = a[j];
			}
			a[j + delt] = a[0];
		}
	}
}

int main() {

	system("pause");
	return 0;
}