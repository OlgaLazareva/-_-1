#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_polindrom(string word)
{
	int len = word.length(); //word Ч это строка, которую прин€ла функци€. “еперь переменна€ len хранит значение длины строки.
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1]) //ѕосле чего создадим цикл от 0 до len/2 и будем сравнивать элементы.
		{
			return false; //если i-ый элемент не равен элементу len-i-1, то сразу возвращаетс€ false(“о есть не палиндром)
		}
	}
	return true;
}

bool is_palindrome(const string & s)
{
	string r(s); //строчку s скопируем в строчку r
	reverse(r.begin(), r.end()); //разворачиваем строчку в обратную сторону
	return s == r; //если s=r, то возращает true, иначе false
}



vector<string> PalindromFilter(vector<string> words, int minLength) //фильтруем палиндромы
{
	vector<string> output;  //вектор дл€ вывода

	for (auto word : words) {
		if (check_polindrom(word) && word.size() >= minLength)
			output.push_back(word);
	}

	return output; //возвращаем новый вектор
}




int main()
{
	setlocale(LC_ALL, "rus");
	vector<string> words = { "madam","cyyc","vvvo","x" };
	words.resize(100);
	int minLength = 0;
	cout << "ƒлина слова (minLength) = " << endl;
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