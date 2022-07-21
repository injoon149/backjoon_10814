#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


//vector에서 원소를 주면 인덱스를 반환하는 함수
//int findX(vector<pair<int, string>> a, pair<int,string> x)
//{
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a.at(i) == x) return i;
//	}
//	return -1;
//}

struct MyFunctor {
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		return a.first < b.first;
	}
};

int main()
{
	MyFunctor mf;
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<int, string>> v;

	int a = 0;
	cin >> a;
	int b = 0;
	string s = "";
	
	for (int i = 0; i < a; i++)
	{
		cin >> b >> s;
		v.push_back(make_pair(b,s));
	}
	//stable_sort : 원래 입력받았던 순서를 유지, 보존시켜주는 정렬
	stable_sort(v.begin(), v.end(), mf);

	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << iter->first << " " << iter->second << '\n';
	}

	return 0;
}