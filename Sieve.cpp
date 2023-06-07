// C++ program to print all primes smaller than or equal to n
// using Sieve of Eratosthenes
// Time Complexity O(N*LOG(LOG(N)))
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(vector<bool>&prime)
{
    int n=prime.size()-1;
	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
        // Here we know p is prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}
}
int main()
{
	int n = 30;
    vector<bool>prime(n+1,true);
	SieveOfEratosthenes(prime);
    // Print all prime numbers
	for (int p=2; p<=n; p++)
	if (prime[p])
		cout << p << " ";
	return 0;
}
