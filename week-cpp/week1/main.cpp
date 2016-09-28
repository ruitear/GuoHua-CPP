#include"week1.h"

//day1 1的个数  只考虑数为正数的情况
//int countNum(int num)
//{
//	int count = 0;//注意这里假设1个个数不超出最大int范围，如果可能超出，类型换位long
//	while (num)
//	{
//		count += (num % 10 == 1) ? 1 : 0;
//		num = num / 10;
//	}
//	return count;
//}
//int countNumofOne(int num)
//{
//	if (num <= 0)return 0;
//	else
//	{
//		int countofOne = 0;
//		for (int i = 1; i <= num; ++i)
//			countofOne += countNum(i);
//		return countofOne;
//	}
//}

int main()
{
	int n;

	//cin >> n;
	/*for (int i = 900; i <= 1000; ++i)
	{*/
		/*int number1 = countNumofOne2(21);
		int number2 = countNumofOne(21);
		cout << number1 << " " << number2 << endl;*/
	/*}*/
		/*int aa = -INT_MAX;
		cout << aa;*/
	/*string str;
	cin >> str;
	cout << str<<endl;*/
/*
	vector<int> vec=StrToInt(str);
	for (auto &a : vec)
	{
		cout << a << ' ';
	}*/
	int num;
	/*string ss;
	while (cin >> num)
	{
		ss=scaleTenTwElve(num);
		reverse(ss.begin(), ss.end());
		cout << ss << endl;
	}
	short int x = 0x1122;
	char x0, x1;
	x0 = ((char*)&x)[0];
	x1 = ((char*)&x)[1];*/
	//cout << x0 << endl;
	string str = "guohua";
	const string str2 = "uestc";;
	str.insert(0, str2);
	return 0;
}