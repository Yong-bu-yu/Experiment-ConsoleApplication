#include <stdio.h>
#include<list>
void Menu()
{
	printf("\n\t\t\t\t顺序表的各种操作");
	printf("\n\t\t=================================================");
	printf("\n\t\t|\t\t1——建立顺序表\t\t\t|");
	printf("\n\t\t|\t\t2——插入元素\t\t\t|");
	printf("\n\t\t|\t\t3——删除元素\t\t\t|");
	printf("\n\t\t|\t\t4——按位置查找元素\t\t|");
	printf("\n\t\t|\t\t5——按元素值查找其在表中位置\t|");
	printf("\n\t\t|\t\t6——求顺序表的长度\t\t|");
	printf("\n\t\t|\t\t0——返回\t\t\t|");
	printf("\n\t\t=================================================\n");
	printf("\t\t请输入菜单号（0-6）：");
}
int main(int argc, char* argv[])
{
	std::list<int>List;
	std::list<int>::iterator j;
	int n, i, loc, x, y;
	char ch1, ch2, a;
	ch1 = 'y';
	while (ch1 == 'y' || ch1 == 'Y')
	{
		int flag = 0;
		Menu();
		scanf_s("%c", &ch2);
		getchar();
		switch (ch2)
		{
		case '1':
			printf("请输入建立线性表的个数：");
			scanf_s("%d", &n);
			printf("请输入元素：");
			for (int k = 0; k<n; k++)
			{
				scanf_s("%d", &i);
				List.push_back(i);
			}
			printf("建立的线性表为：");
			for (j = List.begin(); j != List.end(); j++)
				printf("%d ", *j);
			break;
		case '2':
			printf("请输入要插入的位置：");
			scanf_s("%d", &i);
			printf("请输入要插入的元素值：");
			scanf_s("%d", &x);
			if (!List.empty())
			{
				for (n = 1, j = List.begin(); n < i; n++)
				{
					j++;
					y = List.size();
					if (n >= y)
						break;
				}
				List.insert(j, 1, x);
				printf("已成功在第%d的位置上插入%d，插入后的线性表为：\n", i, x);
			}
			else
				printf("插入不成功！");
			for (j = List.begin(); j != List.end(); j++)
				printf("%d ", *j);
			break;
		case '3':
			printf("请输入要删除的元素：");
			scanf_s("%d", &i);
			List.remove(i);
			printf("已成功删除，删除后的线性表为：\n");
			for (j = List.begin(); j != List.end(); j++)
				printf("%d ", *j);
			break;
		case '4':
			printf("请输入要查找元素的位置：");
			scanf_s("%d", &i);
			if (!List.empty())
			{
				for (j = List.begin(), loc = 0; j != List.end(); j++)
				{
					loc++;
					y = List.size();
					if (y < i)
						flag = 1;
					if (loc == y || y < i||loc==i)
						break;
				}
				if (flag != 1)
					printf("查找元素值为%d的位置为：%d", i, *j);
				else
					printf("查找元素出错！");
			}
			else
				printf("查找不成功！");
			break;
		case '5':
			printf("请输入要查找的元素：");
			scanf_s("%d", &i);
			for (j = List.begin(),loc=0; j != List.end(); j++, loc++)
			if (*j == i)
				printf("当前线性表%d元素在%d上", i, loc+1);
			break;
		case '6':
			printf("当前线性表的长度为%d", List.size());
			break;
		case '0':
			ch1 = 'n';
			break;
		default:
			printf("输入有误，请输入0-6进行选择");
			break;
		}
		if (ch2 != '0')
		{
			printf("\n按回车键继续，按任意键返回主菜单\n");
			a = getchar();
			if (a != '\xA')
			{
				getchar();
				ch1 = 'n';
			}
		}
	}
	system("pause");
	return 0;
}
