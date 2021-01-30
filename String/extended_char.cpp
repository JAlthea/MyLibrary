#include <cstdio> //C IO
#include <cstring>
#include <clocale>  //for setlocale
#include <iostream> //C++ IO
#include <string>
#include <sstream>


/*
char : 1byte (-128 ~ 127)
signed char : 1byte (-128 ~ 127)
unsigned char : 1byte (0 ~ 255)
wchar_t : 2byte (0 ~ 65535)

위의 4가지의 경우는 완전히 같지 않음을 유의해야 한다.
char와 signed char의 경우, 같은 의미로 쓰일 수는 있으나 엄밀하게는 다르다고 생각하자.

ASCII의 0 ~ 127은 현재 사용하는 문자, 128 ~ 255는 예전에 사용했던 특수문자에 해당한다.
128번 부터는 현재 표준이 아니고, 운영체제마다 호환이 되지 않는다.

Java와 같은 다른 OOP에서 문자형으로 사용하는 Unicode에 해당하는 문자를 다루기 위해서는 wchar_t 를 사용하자.

[참고]
https://stackoverflow.com/questions/75191/what-is-an-unsigned-char
https://shaeod.tistory.com/228
https://blog.naver.com/lhk0523/140141011673
*/

int main()
{
	setlocale(LC_ALL, "KO");
	wchar_t c = L'가';
	wchar_t d = L'나';
	wchar_t s[] = L"다 함께";
	wstring ws = L"캬캬Abc";
	wcout << c << '\n';
	wprintf(L"%c\n", d);
	wprintf(L"%s\n", s);
	wcout << ws;
	cout << sizeof(d) << '\n';
	cout << sizeof(s) << '\n';
	cout << sizeof(ws) << '\n';
}
