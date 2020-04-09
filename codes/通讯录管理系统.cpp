#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//设计联系人结构体
struct Person
{
	// 姓名、性别、年龄、电话、住址
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};

//1、添加联系人
void addPerson(struct Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不在添加
	if (abs->m_Size==MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是 1 或者 2 可以退出循环
			//如果输入的有误，重新输入
			cin >> sex;//输入性别
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;

			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		
		//电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作

	}

}

//2、显示所有联系人
void showPerson(struct Addressbooks * abs) 
{
	//判断通讯录人数是否为0，如果为0，提示记录为空；如果不为0，显示记录的联系人信息
	if (abs->m_Size==0)
	{
		cout << "当前的记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name <<"\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone <<"\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");
	system("cls"); //清屏操作 
}


//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1：通讯录  参数2：对比的姓名
int isExist(struct Addressbooks * abs, string name) 
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i; // 找到了，返回这个人在数组中下标
		}

	}
	return -1; //如果遍历结束都没有找到，返回-1

}

//3、删除指定联系人
void deletePerson(struct Addressbooks * abs) 
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	//ret == -1  表示无人,
	//ret != -1  查到了
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新一下通讯录中的人员数
		cout << "删除成功" << endl;

	}
	else 
	{
		cout << "查无此人" << endl;
	
	}

	system("pause");
	system("cls");

}

//4、查找指定联系人信息
void findPerson(struct Addressbooks * abs) 
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在通讯录中
	int ret = isExist(abs, name);
	if (ret != -1) //找到联系人
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ?  "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else 
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//5、修改指定人信息
void moidfyPerson(struct Addressbooks * abs) 
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)// 找到联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		
		//性别
		cout << "请输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				//输入正确，退出循环输入
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;

		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

//6、清空所有联系人
void cleanPerson(struct Addressbooks * abs) 
{
	cout << "请确认是否要清空所有联系人,1：确认清空；2：放弃清空" << endl;
	int ret = 0;
	while (true)
	{
		cout << "请输入是否清空按钮：";
		cin >> ret;

		if (ret == 1)
		{
			abs->m_Size = 0; //将当前记录联系人数量置为0，做逻辑清空操作
			cout << "通讯录已经清空" << endl;
			break;
		}
		else if (ret == 2)
		{
			cout << "放弃清空完成" << endl;
			break;

		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}

//菜单界面
void showMenu() 
{
	cout << "******************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "******************************" << endl;
}


int main() 
{

	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0; 


	int select = 0; //创建一个用户选择输入的变量
	while (true) // 并不是真正意义上的死循环
	{
		showMenu(); // 菜单调用
		cin >> select;
		switch (select)
		{
		case 1: //1、添加联系人
			addPerson(&abs);//传地址，利用地址传递可以修饰实参
			break;
		case 2: //2、显示联系人
			showPerson(&abs);
			break;
		case 3: //3、删除联系人
		//{
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1)
		//	{
		//		cout << "查无此人" << endl;
		//	}
		//	else
		//	{
		//		cout << "找到此人" << endl;
		//	}		
		//}
			deletePerson(&abs);
			break;

		case 4: //4、查找联系人
			findPerson(&abs);
			break;
		case 5: //5、修改联系人
			moidfyPerson(&abs);
			break;
		case 6: //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: //0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
			
	system("pause");
	return 0;
	
}