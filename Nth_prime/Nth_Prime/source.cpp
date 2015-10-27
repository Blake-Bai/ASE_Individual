#include<iostream>
#include<windows.h>
#include<math.h>
#pragma comment(lib,"winmm.lib")

using namespace std;
int Get_Nth_Prime(int N, int *prime, bool *is_prime,int prime_max)
{

	int tot = 1;
	for (int i = 3; i <= prime_max; i += 2)
	{
		is_prime[i] = true;
	}
	is_prime[2] = true;
	prime[0] = 2;
	for (int i = 3; i <= prime_max; i += 2)
	{
		if (is_prime[i])
		{
			prime[tot] = i;
			if (tot == N - 1)return prime[N - 1];
			++tot;
		}
		for (int j = 1; long long(i)*(prime[j])<= prime_max && j < tot; ++j)
		{
			int mark_id = i * (prime[j]);
			is_prime[mark_id] = false; 
			if (i%(prime[j]) == 0)
			{
				break;
			}
		}
	}
	//printf("tot %d\n", tot);
	return prime[N-1];
}

int main()
{
	int N;
	printf("input N: ");
	cin >> N;
	if (N<1 || N>100000000)
	{
		printf("wrong N,not in the range!\n");
		return 0;
	}
	else
	{
		int prime_max = N*log(N) + N*log(log(N));
		if (N < 6)prime_max = 11;
		int prime_id_max = 100000000;
		int *prime = new int[prime_id_max];
		bool *is_prime = new bool[prime_max];
		//DWORD t1, t2;
		//t1 = timeGetTime();
		printf("%d\n",  Get_Nth_Prime(N, prime, is_prime, prime_max));
		//t2 = timeGetTime();
		//printf("time:%d\n", (t2 - t1) * 1);
		delete[]prime; prime = NULL;
		delete[]is_prime; is_prime = NULL;
		return 0;
	}
}