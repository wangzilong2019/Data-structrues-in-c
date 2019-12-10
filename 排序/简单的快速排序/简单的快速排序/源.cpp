#include<stdio.h>
#include<Windows.h>
//һ�˼򵥵Ŀ��������㷨
int QKPass(int a[], int low, int high) {
	//ѡ���׼��¼
	int x = a[low];
	while (low < high) {
		while (low < high && a[high] >= x) {
			//high���ҵ����ҵ�С��x�ļ�¼
			high--;
		}
		if (low < high) {
			//�ҵ�С��x�ļ�¼�����롰�յ�Ԫ��a[low]
			a[low] = a[high];
			low++;
		}
		while (low < high && a[low] < x) {
			//low�������ҵ�����x�ļ�¼
			low++;
		}
		if (low < high) {
			//�ҵ�����x�ļ�¼�����롰�յ�Ԫ��a[high]
			a[high] = a[low];
			high--;
		}
	}
	//����׼��¼���浽low=high��λ��
	a[low] = x;
	//���ػ�׼��¼��λ��
	return low;
}
//�����Ŀ��������㷨
void QKSort(int a[], int low, int high) {
	while (low < high) {
		int pos = QKPass(a, low, high);
		//�����ӱ���п�������
		QKSort(a, low, pos - 1);
		//���Ҳ��ӱ���п�������
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