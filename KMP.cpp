////KMP�㷨
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
			
			if (j == 0)//��ͬ�ж�j�Ƿ��ڿ�ʼ�ĵط�
			{
				b[i] = 0;
				i++;
			}
			else
			{
				j = b[j - 1];//�ص�֮ǰ��ĳһ���ط�
			}
                

		} 
	}

}

int findnode(char a[], char c[],int size)//Ѱ��λ��
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
	Next(a);////��NEXT����
	for (int i = 0; i < MAX-1; i++)//��ӡnext����
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