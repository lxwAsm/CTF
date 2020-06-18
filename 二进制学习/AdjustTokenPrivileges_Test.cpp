// AdjustTokenPrivileges_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "AdjustTokenPrivilegesTest.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/* 修改当前进程令牌访问权限
	if (FALSE == EnbalePrivileges(::GetCurrentProcess(), SE_DEBUG_NAME))
	{
		printf("Enable Privileges Error!\n");
		return -1;
	}

	printf("Enable Privileges OK!\n");*/
	char	*namebuf = "Hello";
	int		namesize = 5;
	char	buffer[100] = { 0 };
	int i = 0;
	do {
		char cVar5 = (namebuf[i] ^ 0x29) + namesize;
		if ((cVar5 < 'A') || ('Z' < cVar5)) {
			cVar5 = namesize + 'R';
		}
		buffer[i] = cVar5;
		(buffer+1)[i] = 0;
		i = i + 1;
		namesize = namesize-1;
	} while (namesize != 0);
	i = 0;
	namesize = 5;
	do {
		char cVar5 = (namebuf[i] ^ 0x27) + namesize + 1;
		if ((cVar5 < 'A') || ('Z' < cVar5)) {
			cVar5 = namesize + 'M';
		}
		(buffer+5)[i] = cVar5;
		(buffer+6)[i] = 0;
		i = i + 1;
		namesize = namesize + -1;
	} while (namesize != 0);
	int j = 0;
	for (int j = 0; buffer[j] != 0; j++){
		char cipher = buffer[j] + 5;
		if ('Z' < (char)cipher) {
			cipher = (buffer)[j] - 8;
		}
		cipher = cipher ^ 0xc;
		if ((char)cipher < 'A') {
			cipher = (char)j + 0x4b;
		}
		else {
			if ('Z' < (char)cipher) {
				cipher = 0x4b - (char)j;
			}
		}
		printf("%c", cipher);
	}
	printf("\ndone");
	system("pause");
	return 0;
}

