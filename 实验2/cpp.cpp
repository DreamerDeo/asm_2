#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef char BYTE;

extern "C" int _cdecl iq(BYTE*, int*, BYTE);
extern "C" int _cdecl oq(BYTE*, int*, BYTE*);
extern "C" int _cdecl pq(BYTE*, int, int);

extern "C" BYTE buffer[16];
extern "C" int ip;
extern "C" int op;
extern "C" int n;

extern "C" void incp(int *p)
{
	*p = (*p + 1) % 16;
}

int main()
{
	ip = 0;
	op = 0;
	n = 0;
	int ret;
	char chr;
	char c;
	printf("����ѡ��ESC �˳���- ���һ���ַ���+ ��ӡ��ǰ���У�0-9��A-Z������У�����������\n");
	while (1)
	{
		c = _getche();
		if (c == 0x1B)
		{
			break;
		}
		if (c == '-')
		{
			ret = oq(buffer, &op, &chr);
			if (ret == 0)
			{
				printf("\nEMPTY!\n");
			}
			else
			{
				printf("���Ԫ��Ϊ��%c\n", chr);
			}
			continue;
		}
		if (c == '+')
		{
			printf("\n��ǰ�������ݣ�");
			pq(buffer, ip, op);
			printf("�����±꣺%d ��β�±꣺%d\n", op, ip);
			continue;
		}

		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
		{
			ret = iq(buffer, &ip, c);
			if (ret == 0)
			{
				printf("\nFULL!\n");
			}
			continue;
		}
	}
	return 0;
}
