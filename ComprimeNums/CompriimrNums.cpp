#include<iostream>
#include<vector>

using namespace std;

/*��ͨ����*/
long long getPowers(int a, int b) {
	if (b == 1) {
		return a;
	}
	return a * getPowers(a, b - 1);
}

/*������*/
long long QuickPower(int base, int power) {
	long long res = 1;
	while (power) {
		if (power & 1) {//����base��power��λ�ƺ��ж�base��Ӧλ��power���λ���Ƿ�Ϊ0
			res *= base;
		}
		base *= base;//ÿ���Գˣ���������ż���ݱ�
		power >>= 1;
	}
	return res;
}

/*ŷ������*/
long long EulerFunction(long long n) {
	long long res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			while (n % i == 0) {
				n = n / i;
			}
		}
	}
	if (n > 1) {
		res = res / n * (n - 1);
	}
	return res;
}


int main() {

	long long  inputA = 0, inputB = 0;
	
	cin >> inputA >> inputB;
	cout << EulerFunction(QuickPower(inputA,inputB)) % 998244353 << endl;

	return 0;
}