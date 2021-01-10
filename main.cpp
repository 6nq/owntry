#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bus.h"
 
int main()
{
	printf("\n\n               ★ 欢迎使用公汽查询系统!★");
	initial();
	char c1;
	do
	{
		show1();
		c1=getchar();
		switch ( c1 )
		{
		case 'a':
		case 'A':showb();break;
		case 'b':
		case 'B':
			{
				char c3;
				do
				{
					show3();
					c3=getchar();
					switch ( c3)
					{
					case 'a':
					case 'A':lookb();break;
					case 'b':
					case 'B':lookr();break;
					case 'c':
					case 'C':break;
					}
				}while(c3!='c'&&c3!='C');
			}break;
		case 'c':
		case 'C':newb();break;
		case 'd':
		case 'D':
			{
				char c2;
				do
				{
					show2();
					c2=getchar();
					switch ( c2)
					{
					case 'a':
					case 'A':modifyr();break;
					case 'b':
                    case 'B':modifyb();break;
					case 'c':
                    case 'C':delb();break;
					}
				}while(c2!='d'&&c2!='D');
			}break;
		case 'E':
		case 'e':release();
        save();
        break;
		}
	}while(c1!='f'&&c1!='F');
	save();
	printf("\n\n  ★ 谢谢您的使用!★");
	return 0;
}
