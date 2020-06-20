////KMP算法
#include<iostream>

#define MAX  9
using namespace std;


//char a[MAX];
int b[MAX+1] = { 0 };
void Next(char a[])
{
	int i = 1, j = 0;
	while (i<MAX-1)
	{
		if (a[i] == a[j])
		{
			b[i] = j+1;
			i++;
			j++;
		}
		else
		{
			
			if (j == 0)//不同判断j是否在开始的地方
			{
				b[i] = 0;
				i++;
			}
			else
			{
				j = b[j - 1];//回到之前的某一个地方
			}
                

		} 
	}

}

int findnode(char a[], char c[],int size)//寻找位置
{
	int i = 0,j=0;
	while (true)
	{
		if ((i == MAX - 1) && (j <= size - 1) || (j == size - 1))
		{
			break;
		}
		if (a[i] == c[j])
		{
			i++;
			j++;
		}
		else
		{
			if (i == 0)
				j++;
			else
			{
				i = b[i];
			}
		}
	}
	if (i!= MAX - 1)
		return -1;
	else
	{
		return j - MAX + 1;
	}
}
int main()
{
	 
	

	
	char a[MAX] = { 'a','b','c','d','a','b','c','a' };
	cout << sizeof(a) / sizeof(char);
	cout << endl;
	Next(a);////求NEXT数组
	for (int i = 0; i < MAX-1; i++)//打印next数组
	{
		cout << b[i];
	}

	char c[17] = { 'b', 'c', 'a', 'c', 'a', 'b', 'c','a','b','c', 'd', 'a', 'b', 'c', 'a', 'c' };
	int size = sizeof(c);//14
	//cout << size;
	int area=findnode(a,c,size);
	cout << endl<<area << endl;
	return 0; 
}