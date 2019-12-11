#include<stdio.h>
#include<Windows.h>
//重建堆过程
void sift(int a[], int k, int m) {
	//假设a[k...m]是以a[k]为根的完全二叉树；且分别以a[2*k]和a[2*k+1]为根的左子树和右子树的大根堆调整a[k]；使整个序列满足性质
	int temp, i, j,flag;
	temp = a[k];
	i = k;
	j = 2 * i;
	flag = 0;
	while (j <= m && !flag) {
		if (j + 1 <= m && a[j] < a[j + 1]) {
			//若存在右子树，且右子树根的关键字大，则沿右分支筛选
			j = j + 1;
		}
		if (temp > a[j]) {
			flag = 1;
		}
		else {
			a[i] = a[j];
			i = j;
			j = i * 2;
		}
	}
	//将a[k]填入到适当的位置
	a[i] = temp;

}
//建初堆算法
void crt_heap(int a[], int n) {
	//对记录数组a建堆，n为数组中元素的个数
	//自从第[n/2]个记录起开始建堆筛选；即最后一个非叶子节点的位置
	for (int i = n / 2; i >= 1; i--) {
		sift(a, i, n);
	}
}
//进行堆排序，升序排列
void HeapSort(int a[], int n) {
	
	crt_heap(a, n);
	for (int i = n; i >= 2; i--) {
		//将堆顶记录和堆尾记录互换
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		//调整a[1...i-1]使其变成堆
		sift(a, 1, i - 1);
	}
	for (int i = 1; i <=n; i++) {
		printf("%d",a[i]);
	}
}
int main() {
	int a[8];
	for (int i = 1; i < 8; i++) {
		scanf_s("%d",&a[i]);
	}
	HeapSort(a,7);
	system("pause");
	return 0;
}