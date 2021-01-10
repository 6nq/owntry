#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
 
struct bus
{
	char num[30];//车号
	char driver[50];//司机
	char stime[30];//发车时间
	char start[30];//起始站
	char end[30];//终点站
	int  z;//站数
	char *pr;//指向路线的首指针
	struct bus *next;//下一辆车的结构体
};
 
void initial();//文件查询
void newb();//新建公交线
void modifyr();//修改线路
void modifyb();//修改公汽
void showb();//显示所有公汽信息
void lookb();//查询公汽信息
void lookr();//查询站
void delb();//删除公汽数据信息
void save();//存储文件
void release();//清空数据
void show1(); //主菜单
void show2(); //系统管理菜单
void show3(); //查询菜单
 
#endif // BUS_H_INCLUDED
