#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bus.h"
 
struct bus *bhead=NULL;//放公汽信息的头指针
struct bus *bi=NULL; //放公汽信息的最后的指针
//文件存储部分
void initial()
{
	FILE  *fp;
	fp=fopen("bus.txt","r");  //创建文件bus.txt，权限为可读
	if(fp==NULL)
	{
		printf("\n\n无公汽信息文件!");
		return;
	}
	fseek(fp,0,SEEK_END);
	int i,n;
	n=ftell(fp)/sizeof(struct bus);
	//printf("\n\n\n\n一共有%d辆公汽!",n);
	rewind(fp);
    struct bus *p;
	//for
	for(i=0;i<n;i++)
	{
		p=(struct bus *)malloc(sizeof(struct bus ));
		fseek(fp,i*sizeof(struct bus),0);
		fread(p,sizeof(struct bus),1,fp);//写入信息，其中地址是无用的信息
		p->next=NULL;//初始化时下一个指向空，都是一个个单独的
		p->pr=NULL;//让路线为空
		//路线信息存放在文件名为” 车号 “的文件中;车号是唯一的
		FILE  *fp1;
		fp1=fopen(p->num,"r");
		if(!fp1)
			printf("\n%s号车无初始路线!",p->num);
		else
		{
			char * p1;
			p1=(char *)malloc(p->z*40*sizeof(char) );
			fread(p1,p->z*50*sizeof(char),1,fp1);//将路线写入内存
			p->pr=p1;
			fclose(fp1);
		}
		// printf("\n\n\n\n初始化%s号车路线成功!",p->num);
		//路线信息
		if(bhead==NULL)
			bhead=bi=p;
		else
		{
			bi->next=p;
			bi=p;
        }
	}
	//printf("\n\n\n\n初始化%d辆车成功!",n);
	fclose(fp);
}
//新建公交车以及路线的创建
void newb()
{
loop1:
    printf("\n\n\n\n█创建新公汽█\n\n");
    struct bus *p;
	p=(struct bus  *)malloc(sizeof(struct bus ));
	p->next=NULL;
	p->pr=NULL;
loop2:
	printf("\n请输入新公汽号：\n\n");
	scanf("%s",p->num);
	struct bus *pj=bhead;
	while(pj)
	{
		if(strcmp(pj->num,p->num)==0)
		{
			printf("\n\n错误，该公汽号已经存在!\n\n");
			goto loop2;
		}
		pj=pj->next;
	}
	printf("\n请输入新公汽司机姓名：\n");
	scanf("%s",p->driver);
	printf("\n请输入新路线发车时间\n\n");
	scanf("%s",p->stime);
loop3:
	printf("\n\n\n请输入新路线总站台数(>=2)\n\n");
	scanf("%d",&p->z);
	if(p->z>=2)
	{
		p->pr=(char *)malloc( p->z*50*sizeof(char)  );
        p->pr[0]='\0';
		int i;
		char cc[40];
        for(i=1;i<=p->z;i++)
		{
			printf("\n请输入公汽第%d站台名称:",i);
			scanf("%s",cc);
 
			if(i==1)                                 //采用链式存储，尾插法
			{
				strcat(p->pr,cc);
				strcpy(p->start,cc);
			}
			else
			{
				strcat(p->pr,"---->");
				strcat(p->pr,cc);
			}                             
		}
		strcpy(p->end,cc);
		printf("\n\n自动生成公汽路线%s",p->pr);
    }
	else
	{
		printf("\n\n错误，该公汽站台数小于2，请重新输入!\n\n");
		goto loop3;
	}
	if(bhead==NULL)
		bi=bhead=p;
	else
	{
		bi->next=p;
		bi=p;
	}
	printf("\n\n%s号公汽创建成功!",p->num);
	printf("\n\n\n您想  继续新建(A)   退出创建(N)-------请选择 A 或 N \n\n ");
	char c;
	c=getchar();
	if(c=='a'||c=='A')
		goto loop1;
	else
		return;
}
void modifyr(){
    	char c,b[20];
    	printf("\n\n\n\n        █修改路线█\n\n");
    loop:
    	printf("\n请输入要修改路线的公汽号：\n\n");
    	scanf("%s",b);
    	struct bus *p=bhead;
    	int n=1;
    	while(p)
    	{
    		if(strcmp(p->num,b)==0)
    		{
    			printf("\n\n司机姓名：  %s",p->driver);
    			n=0;
    			break;
    		}
    		p=p->next;
        }
    	if(n)
    	{
    		printf("\n\n错误，公汽号不存在!\n\n重新修改(A)   退出修改(N)-------请选择 A 或 N \n\n ");
            char c;
    		c=getchar();
    		if(c=='a'||c=='A')
    			goto loop;
    		else
    			return;
    	}
    loop1:
    	printf("\n\n\n请修改路线总站台数(>=2)\n\n");
    	int nn;
    	scanf("%d",&nn);
    	if(nn>=2)
    	{
    		p->pr=(char *)malloc( p->z*50*sizeof(char)  );
    		p->pr[0]='\0';
    		p->z=nn;
    		int i;
    		char cc[40];
            for(i=1;i<=p->z;i++)
    		{
    			printf("\n请输入公汽第%d站台名称:",i);
                scanf("%s",cc);
    			if(i==1)
    			{
    				strcat(p->pr,cc);
    			    strcpy(p->start,cc);
    			}
    			else
    			{
    				strcat(p->pr,"---->");
    				strcat(p->pr,cc);
    			}
    		}
    	    strcpy(p->end,cc);
    	    printf("\n\n自动生成修改后的路线%s",p->pr);
    	}
    	else
    	{
    		printf("\n\n错误，该公汽站台数小于2，请重新输入!\n\n");
    		goto loop1;
    	}
    	printf("\n\n\n%s号公汽修改成功!",p->num);
    	printf("\n\n\n您想  继续修改(A)   退出修改(N)-------请选择 A 或 N \n\n ");
    	c=getchar();   if(c=='a'||c=='A')
    		goto loop;
    	FILE  *fp;
    	fp=fopen(p->num,"w");
    	fwrite(p,nn*50*sizeof(char),1,fp);
    	fclose(fp);   //保存线路信息
    }//修改公汽
void modifyb()
{
	char c,b[20];
	printf("\n\n\n\n        █修改公汽█\n\n");
loop:
	printf("\n请输入要修改路线的公汽号：\n\n");
	scanf("%s",b);
	struct bus *p=bhead;
	int n=1;
	while(p)
	{
		if(strcmp(p->num,b)==0)
		{
			printf("\n\n司机姓名：  %s   发车时间： %s AM",p->driver,p->stime );
			n=0;
			break;
		}
		p=p->next;
	}
	if(n)
	{
		printf("\n\n错误，公汽号不存在!\n\n重新修改(A)   退出修改(N)-------请选择 A 或 N \n\n ");
		c=getchar();
        if(c=='a'||c=='A')
			goto loop;
		else
			return;
	}
	printf("\n请输入要修改%s公汽的新司机：\n\n",p->num);
	scanf("%s",p->driver);
	printf("\n请输入要修改%s公汽的发车时间：\n\n",p->num);
	scanf("%s",p->stime);
	printf("\n\n\n%s号公汽修改成功!",p->num);
	printf("\n\n\n您想  继续修改(A)   退出修改(N)-------请选择 A 或 N \n\n ");
	c=getchar();
	if(c=='a'||c=='A')
		goto loop;
}
//公交线路信息
void showb()
{
	struct bus *p=bhead;
	if(!p)
	{
		printf("\n\n公汽线路信息数据库为空!");
		return;
	}
	else
	{
		printf("\n\n\n                 █公汽信息数据库█          ");
		printf("\n|-------------------------------------------------------------------------|");
	}
	int n=1;
	while(p)
	{
		printf("\n|   公汽号：%s     站数：%d    发车时间：%s AM  司机：%s ",p->num, p->z, p->stime,p->driver);
		printf("\n|   █路线：  %s",p->pr);  printf("\n|-------------------------------------------------------------------------|");
		n=0;
		p=p->next;
	}
	if(n)
		printf("\n\n公汽线路信息数据库为空!");
}
//查看路线
void lookb()
{
	char c,b[20];
	//printf("\n\n\n\n        █查询路线█\n\n");
loop:
	printf("\n请输入要查询的公汽号：\n\n");
	scanf("%s",b);
	struct bus *p=bhead;
	int n=1;
	while(p)
	{
		if(strcmp(p->num,b)==0)
		{
			n=0;
	      	break;
		}
		p=p->next;
	}
	if(n)
	{
		printf("\n\n错误，公汽号不存在!\n\n重新输入(A)   退出查询(N)-------请选择 A 或 N \n\n ");
		c=getchar();
		if(c=='a'||c=='A')
			goto loop;
		else
			return;
	}
	printf("\n|-------------------------------------------------------------------------|");
	printf("\n|   公汽号：%s     站数：%d    发车时间：%s AM  司机：%s ",p->num, p->z, p->stime,p->driver);
	printf("\n| 路线：  %s",p->pr);
	printf("\n|-------------------------------------------------------------------------|");
	printf("\n\n\n%s号公汽查询成功!",p->num);
	printf("\n\n\n您想  继续查询(A)   退出查询(N)-------请选择 A 或 N \n\n ");
	c=getchar();
	if(c=='a'||c=='A')
		goto loop;
}
//查询公汽
void lookr()
{
	printf("\n\n\n\n        █查询公汽█\n\n");
	char c,b[40];
loop:
	printf("\n        [查询公汽菜单]");  printf("\n|-----------------------------------|");
	printf("\n \n   \n   \n    请选择查询方式:         ");  printf("\n|-----------------------------------|");
	printf("\n|           A[ 起始站查询  ]        |");  printf("\n|-----------------------------------|");
	printf("\n|           B[ 终点站查询  ]        |");     printf("\n|-----------------------------------|");
	printf("\n|           C[  退出       ]        |");     printf("\n|-----------------------------------|");
	c=getchar();
	if(c=='B'||c=='b')
	{
		printf("\n请输入要查询的终点站：\n\n");
		scanf("%s",b);
		struct bus *p=bhead;
		int n=1;
		printf("\n   您可以乘坐以下公汽到达%s",p->end);
		printf("\n|-------------------------------------------------------------------------|");
		while(p)
		{
			if(strcmp(p->end,b)==0)
			{
				n=0;
				printf("\n|公汽号：%s     路线：  %s" ,p->num,p->pr);
				printf("\n|-------------------------------------------------------------------------|");
			}
			p=p->next;
		}
		if(n)
		{
			printf("\n\n错误，终点站不存在!\n\n重新输入(A)   退出查询(N)-------请选择 A 或 N \n\n ");
			c=getchar();
			if(c=='a'||c=='A')
				goto loop;
		}
		printf("\n\n您想 继续查询(A)   退出查询(N)-------请选择 A 或 N \n\n ");
		c=getchar();
		if(c=='a'||c=='A')
			goto loop;
	}
	if(c=='A'||c=='a')
	{
		printf("\n请输入要查询的起始站：\n\n");
		scanf("%s",b);
		struct bus *p=bhead;
		//int n=1;
	//	printf("\n   您可以乘坐以下公汽起始站为%s",p->start);
		int n=1;
		printf("\n   您可以乘坐以下公汽起始站为%s",p->start);
		printf("\n|-------------------------------------------------------------------------|");
		while(p)
		{
			if(strcmp(p->start,b)==0)
			{
				n=0;
				printf("\n|公汽号：%s     路线：  %s" ,p->num,p->pr);
				printf("\n|-------------------------------------------------------------------------|");
			}
			p=p->next;
		}
		if(n)
		{
			printf("\n\n错误，起始站不存在!\n\n重新输入(A)   退出查询(N)-------请选择 A 或 N \n\n ");
			c=getchar();
			if(c=='a'||c=='A')
				goto loop;
		}
		printf("\n\n您想 继续查询(A)   退出查询(N)-------请选择 A 或 N \n\n ");
		c=getchar();
		if(c=='a'||c=='A')  goto loop;
	}
    if(c==' '||c=='\n')
        goto loop;
}
//删除公汽
void delb()
{
   char b[20];
   printf("\n\n\n\n        █删除公汽█\n\n");
loop:
   printf("\n请输入要删除路线的公汽号：\n\n");
   scanf("%s",b);
   struct bus *p=bhead;
   struct bus *p1=bhead;
   int n=1,y=0;
   while(p)
	{
		if(strcmp(p->num,b)==0)
		{
			n=0;
			break;
		}
	    y++;
	    if(y>1)
		p1=p1->next;
	    p=p->next;
   }
   char c;
	if(n)
	{
		printf("\n\n错误，公汽号不存在!\n\n重新输入(A)   退出删除(N)-------请选择 A 或 N \n\n ");
		c=getchar();
		if(c=='a'||c=='A')
			goto loop;
		else
			return;
	}
	if(p==bhead)bhead=bhead->next;
	else
		p1->next=p->next;
	printf("\n删除路线的公汽成功!\n\n");
	printf("\n\n您是  继续删除(A)   退出删除(N)-------请选择 A 或 N \n\n ");
	c=getchar();
	if(c=='a'||c=='A')
		goto loop;
}
void save()
{
	FILE  *fp;
	fp=fopen("bus.txt","w");
    struct bus *p;
	p=bhead;
	int n=0;
	while(p)
	{
		//第一个while
		fseek(fp,n*sizeof(struct bus),0);
		fwrite(p,sizeof(struct bus ),1,fp);
		n++;
		FILE *fp1;
		fp1=fopen(p->num,"w");
		fwrite(p->pr,p->z*50*sizeof(char),1,fp1);
		fclose(fp1);
		p=p->next;
	}
	fclose(fp);
	//printf("\n\n\n\n保存%d辆车成功!",n);
}
//数据清空
void release()
{
	 bhead=bi=NULL;
	 printf("\n\n\n数据清空成功!");
}


