#include<stdio.h>
#include<Windows.h>
//一趟简单的快速排序算法
int QKPass(int a[], int low, int high) {
	//选择基准记录
	int x = a[low];
	while (low < high) {
		while (low < high && a[high] >= x) {
			//high从右到左找到小于x的记录
			high--;
		}
		if (low < high) {
			//找到小于x的记录，送入“空单元”a[low]
			a[low] = a[high];
			low++;
		}
		while (low < high && a[low] < x) {
			//low从左到右找到大于x的记录
			low++;
		}
		if (low < high) {
			//找到大于x的记录，送入“空单元”a[high]
			a[high] = a[low];
			high--;
		}
	}
	//将基准记录保存到low=high的位置
	a[low] = x;
	//返回基准记录的位置
	return low;
}
//完整的快速排序算法
void QKSort(int a[], int low, int high) {
	while (low < high) {
		int pos = QKPass(a, low, high);
		//对左部子表进行快速排序
		QKSort(a, low, pos - 1);
		//对右部子表进行快速排序
		QKSort(a, pos + 1, high);
	}
	if (low == high) {
		for (int i = 0; i < 5; i++) {
			printf("%d",a[i]);
		}
		
	}
}
int main() {
	int a[5], low, high;
	for (int i = 0; i < 5; i++) {
		scanf_s("%d",&a[i]);
	}
	low = 0;
	high = 4;
	QKSort(a, low, high);
	system("pause");
	return 0;
}