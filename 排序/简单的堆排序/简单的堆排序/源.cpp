#include<stdio.h>
#include<Windows.h>
//�ؽ��ѹ���
void sift(int a[], int k, int m) {
	//����a[k...m]����a[k]Ϊ������ȫ���������ҷֱ���a[2*k]��a[2*k+1]Ϊ�������������������Ĵ���ѵ���a[k]��ʹ����������������
	int temp, i, j,flag;
	temp = a[k];
	i = k;
	j = 2 * i;
	flag = 0;
	while (j <= m && !flag) {
		if (j + 1 <= m && a[j] < a[j + 1]) {
			//�������������������������Ĺؼ��ִ������ҷ�֧ɸѡ
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
	//��a[k]���뵽�ʵ���λ��
	a[i] = temp;

}
//�������㷨
void crt_heap(int a[], int n) {
	//�Լ�¼����a���ѣ�nΪ������Ԫ�صĸ���
	//�Դӵ�[n/2]����¼��ʼ����ɸѡ�������һ����Ҷ�ӽڵ��λ��
	for (int i = n / 2; i >= 1; i--) {
		sift(a, i, n);
	}
}
//���ж�������������
void HeapSort(int a[], int n) {
	
	crt_heap(a, n);
	for (int i = n; i >= 2; i--) {
		//���Ѷ���¼�Ͷ�β��¼����
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		//����a[1...i-1]ʹ���ɶ�
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