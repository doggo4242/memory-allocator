/*
Copyright 2020 doggo4242 Development

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include <bits/stdc++.h>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif
using namespace std;

int *x;
#ifdef __WIN32
int lu[]={SIGBREAK,SIGABRT,SIGTERM,SIGINT};
#endif
void handler(int sig)
{
	#ifdef __WIN32
	int *p=find(lu,lu+4,sig);
	cout << *p << endl;
	#endif
	free(x);
	exit(1);
}

int main(int argc, char *argv[])
{
#ifndef _WIN32
	signal(SIGHUP, handler);
	signal(SIGQUIT, handler);
	signal(SIGKILL, handler);
#else
	signal(SIGBREAK,handler);
#endif
	signal(SIGABRT, handler);
	signal(SIGTERM, handler);
	signal(SIGINT, handler);
	#ifdef __WIN32
	for(int i = 0;i<sizeof(lu)/sizeof(int);i++)
	{
		cout << lu[i] << endl;
	}
	#endif
	int r;
	if(argc>1)
	{
		r=atoi(argv[1]);
	}
	else
	{
		cout << "How much ram should be used in GB?" << endl;
		cin >> r;
		cout << r << endl;
	}
	x = (int*)(malloc(r*10000000000));
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
	cout << "memory filled, enter \'c\' or Ctrl-C to deallocate" << endl;
	while(1)
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
