#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void MakeRand(int * arr,int len)
{
	int random;

	srand((unsigned int)time(NULL));
	for (int i = 0;i < len;i++)
	{
	again:;
		random = rand() % 9 + 1;
		for (int k = 0;k <= i - 1;k++)
		{
			if (arr[k] == random)
			{
				goto again;
			}
		}
		arr[i] = random;
	}
}

void PrintArr(int * arr, int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void InNumber(int * arr, int len)
{
	cout << "���ڸ� 3�� �Է����ּ��� : ";
	for (int i = 0;i < len;i++)
	{
		cin >> arr[i];
	}
}

void PrintResult(string arr[], int len)
{
	int s = 0;	// ��Ʈ����ũ
	int b = 0;	// ��
	int out = 0; // �ƿ�

	for (int i = 0;i < len;i++)
	{
		if (arr[i] == "0")
		{
			s++;
		}
		else if (arr[i] == "��")
		{
			b++;
		}
		else if (arr[i] == "X")
		{
			out++;
		}
	}

	cout << "S : " << s << " B : " << b << " OUT : " << out << endl;
}

void Game(int arr[],int in[],string result[], int len)
{
	int flag = 0;
	int i,k;
	for (i = 0;i < len;i++)
	{
		for (k = 0;k < len;k++)
		{
			if (arr[i] == in[k])
			{
				flag = 1;
				if (i == k)
				{
					result[i] = "0";
					flag = 0;
					break;
				}
				else {
					break;
				}
			}
			else {
				result[i] = "X";
				flag = 0;
			}
		}
		if (flag == 1)
		{
			result[i] = "��";
			flag = 0;
		}
	}
}

void comp(int arr[], int in[],int len)
{
	int count = 0;
	for (int i = 0;i < len;i++)
	{
		if (arr[i] == in[i])
		{
			count++;
		}
	}
	if (count == len)
	{
		cout << "���� ����!!" << endl;
		exit(1);
	}

}

int main(void)
{
	int arr[3];
	int in[3] = { 0,0,0};
	string result[3];

	int len = sizeof(arr) / sizeof(int);

	MakeRand(arr,len);
	
	cout << "���� ����!" <<endl<<"0 0 0 �Է½� ���� ����" << endl;
	while (1)
	{
		InNumber(in, len);
		if (in[0] == 0 && in[1] ==0 && in[2] == 0)
		{
			cout << "���� ����" << endl;
			exit(1);
		}
		Game(arr, in, result, len);
		PrintResult(result, len);
		comp(arr, in, len);
	}
	
	system("pause");
	return 0;
}