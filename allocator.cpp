#include <bits/stdc++.h>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif
using namespace std;

int main()
{
	int r;
	cout << "How much ram should be used in GB?" << endl;
	cin >> r;
	cout << r << endl;
	int *x = (int*)(malloc(r*10000000000));
	if(x==NULL)
	{
		cout << "allocation failed, please retry";
		free(x);
		exit(1);
	}
	cout << "memory allocated, memory will start to fill in 5 seconds." << endl;
	cout << "when memory filling begins, your computer may freeze." << endl;
	cout << "this depends on available memory and how much memory you choose to allocate." << endl;
	cout << "enter Ctrl-C to cancel at any time." << endl;
	#ifdef _WIN32
		Sleep(5000);
	#else
		sleep(5);
	#endif
	for(int i = 0;i<(r*10000000000);i++)
	{
		x[i]=0;
	}
	cout << "allocation complete, enter \'c\' or Ctrl-C to deallocate" << endl;
	while(true)
	{
		if(getchar() == 'c')
		{
			free(x);
			return 0;
		}
		#ifdef _WIN32
			Sleep(10);
		#else
			usleep(10000);
		#endif
	}
	return 0;
}
