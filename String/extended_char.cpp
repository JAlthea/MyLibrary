#include <cstdio> //C IO
#include <iostream> //C++ IO
#include <clocale>

int main()
{
	setlocale(LC_ALL, "KO");
	wchar_t c = L'가';
	wchar_t d = L'나';
	wcout << c << '\n';
	wprintf(L"%c\n", d);
	putwchar(L'다');
}
