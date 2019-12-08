#include<stdio.h>
#include<Windows.h>
int main() {
	int a[7];
	for (int i = 1; i < 7; i++) {
		scanf_s("%d",&a[i]);
	}
	for (int i = 2; i < 7; i++) {
		a[0] = a[i];
		int j = i - 1;
		while (a[0] < a[j]) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = a[0];
	}
	for (int i = 0; i < 7; i++) {
		printf("%d",a[i]);
	}
	system("pause");
	return 0;
}