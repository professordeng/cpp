#include <iostream>
#include <Windows.h>	//需要引用Windows.h
using namespace std;
 
int main(int argc, char* argv[])
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int i=255;i>=0;i--)
	{
		SetConsoleTextAttribute(hConsole, i);
		cout<<"what color is this?"<<endl;
	}
 
	cin.get();
	return 0;
}
