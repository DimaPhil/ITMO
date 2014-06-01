#include <iostream>
#include <stdio.h>

using namespace std;

long long f (long long x)
{
	long long an = 1;
	for(int i = 1; i <= x; i++)
		an = an * i;
	return an;
}

int main()
{
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);

    long long n, k, ans, ans1, z = 0;
    bool used[50] = {0};
    used[0] = 1;

    cin >> n >> k;
    k++;
    while (n > 0)
    {
    	//cout << "n =  " << n << " k = " << k << " f(n-1) = " << f(n-1) << " z = " << z;

        ans = k / f(n - 1) + 1 + z;
        if (k % f(n - 1) == 0)
			ans--;
		ans1 = ans;        	
    	while (used[ans])
    		ans++;                                           
    	
    	//cout << " ans = " << ans << " ans1 = " << ans1 << endl;		
    	cout << ans << " ";
    	
    	used[ans] = 1; 
    	k = k - f(n - 1) * (ans1 - 1 - z);
    	n--;
    	if (ans == z + 1)
    		z++;
    }
	return 0;
}

