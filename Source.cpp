#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_polindrom(string word)
{
	int len = word.length(); //word � ��� ������, ������� ������� �������. ������ ���������� len ������ �������� ����� ������.
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1]) //����� ���� �������� ���� �� 0 �� len/2 � ����� ���������� ��������.
		{
			return false; //���� i-�� ������� �� ����� �������� len-i-1, �� ����� ������������ false(�� ���� �� ���������)
		}
	}
	return true;
}

bool is_palindrome(const string & s)
{
	string r(s); //������� s ��������� � ������� r
	reverse(r.begin(), r.end()); //������������� ������� � �������� �������
	return s == r; //���� s=r, �� ��������� true, ����� false
}



vector<string> PalindromFilter(vector<string> words, int minLength) //��������� ����������
{
	vector<string> output;  //������ ��� ������

	for (auto word : words) {
		if (check_polindrom(word) && word.size() >= minLength)
			output.push_back(word);
	}

	return output; //���������� ����� ������
}




int main()
{
	setlocale(LC_ALL, "rus");
	vector<string> words = { "madam","cyyc","vvvo","x" };
	words.resize(100);
	int minLength = 0;
	cout << "����� ����� (minLength) = " << endl;
	cin >> minLength;
	int sh = 0;
	string a = "";
	for (string i : PalindromFilter(words, minLength))
	{
		sh++;
		if (sh > 1) { a = " "; }
		cout << a << i << endl;
	}


	system("pause");


}