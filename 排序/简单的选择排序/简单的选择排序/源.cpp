#include<stdio.h>
#include<math.h>
#include<Windows.h>
void SelectSort(int a[],int n) {
	for (int i = 0; i < n-1; i++) {
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[k]) {
				k = j;
			}
			if (k != i) {
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d",a[i]);
	}

}
int main() {
	int a[5], len;
	for (int i = 0; i < 5; i++) {
		scanf_s("%d",&a[i]);
	}
	len = 5;
	SelectSort(a, len);
	system("pause");
	return 0;
}