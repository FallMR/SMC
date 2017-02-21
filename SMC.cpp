// SMC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

char key = 0x4A;
char input[101];
char str[] = "#########S #   ###   # ######  ##     ### ####E##      #########";
char arr[] = { 0x27, 0x3D, 0x37, 0x37, 0x0C, 0x21, 0x05, 0x46, 0x0A, 0x3E, 0x20, 0x2C, 0x22, 0x3E, 0x47, 0x2C, 0x12, 0x3B, 0x29, 0x05, 0x56, 0x01, 0x0A };

struct Node
{
	int x, y;
};

void crypt(unsigned char *M, int length, unsigned char *C)
{
	for(int i = 0; i < length; i++)
	{
		C[i] = M[i] ^ key;
	}
}

int main(int argc, char* argv[])
{

	//
// 	Encrypt(data,sizeof(data),edata);
// 	FILE *fp = fopen("C:\\edata.bin","wb");
// 	fwrite(edata,sizeof(edata),1,fp);
// 	fclose(fp);
// 	return 0;
	//
	printf("Please input your code(less than 30 characters): ");
	scanf("%s", input);

	crypt((unsigned char*)0x00408B01,311,(unsigned char*)0x00408B01);
	
	Node n;
	n.x = 1, n.y = 1;

	int length = strlen(input);

	bool flag = false;

	if (length == 23)
	{
		for (int i = 0; i < length; i++)
		{
			switch (input[i])
			{
			case 'w':
				n.x -= 1;
				break;
			case 's':
				n.x += 1;
				break;
			case 'a':
				n.y -= 1;
				break;
			case 'd':
				n.y += 1;
				break;
			default:
				break;
			}
			if (str[n.x * 8 + n.y] == '#') break;
			if (str[n.x * 8 + n.y] == 'E')
			{
				flag = true;
				break;
			}
		}
	}

	if (flag)
	{
		for (int i = 0; i < length; i++)
			arr[i] ^= input[i];
		printf("%s\n", arr);
	}


	system("pause");
	return 0;
}
