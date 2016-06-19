#include<stdio.h>
#include<math.h>

int prime(int, int);
int myprimes[100000];
int cnt = 0;
void populate(int sn)
{
	int i = 0, j = 0;
	int primeArray[100000];
	for(i = 2; i < 100000; i++)
	{
		primeArray[i] = 1;
		myprimes[i] = 0;
	}
	//step 1 ; find all primes till sqrt(bigger number)
	int k = sqrt(sn);
	int val = sqrt(k);

	//first sieve
	for(i = 2; i <= val; i++)
	{
		
		if(primeArray[i] == 1)
		{
			for(j = i*i; j<=k; j=j+i)
				primeArray[j] = 0;
		}
	}
	for(i = 2; i <= k; i++)
	{
	
		if(primeArray[i] == 1)
			myprimes[cnt++] = i;
	}
	

		
}

int main()
{
	//no of items from user
	int nitem;
	int sn,fn;
	int p, num;
	scanf("%d", &nitem);
	int primes[100000];
	while(nitem--)
	{
		scanf("%d", &fn);
		//printf("%d",fn);
		scanf("%d", &sn);
		//prime(fn, sn);
	
	//all numbers are prime initially
	for(int i = 0; i < 100000; i++)
	{
		primes[i] = 1;
	}
	populate(sn);
	for(int i = 0; i < cnt; i++)
	{
		p = myprimes[i];
		//printf("%d", p);
		if(p==0)
			p = 1;
		num = (fn / p) * p;
	
		for(int i = num; i <= sn; i = i + p)
		{
			if(i < fn)
				continue;
			primes[i - fn] = 0;
		}
	}

	for(int i = 0; i < cnt; i++)
	{
		if(myprimes[i]>= fn && myprimes[i] <= sn)
			printf("%d\n",myprimes[i]);
	}
	for(int i = 0; i < sn-fn + 1; i++)
	{
		if(primes[i] == 1 && (i+fn)!=1)
			printf("%d\n", i + fn);
	}
	printf("\n");
	}
	return 0;
}

