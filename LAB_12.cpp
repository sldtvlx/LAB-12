//ФИО, №счета, сумма
//Ключ: №счета	

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<typename G>
G getCorrectNubmer(G inputType)
{
	G inputNumber;
	while (!(cin >> inputNumber) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			cin.ignore();
			cout << "Введите корректное число: ";
		}
	}
	return inputNumber;
}

int i;

struct dat
{
	string fio;
	int acc_number;
	string acc_number1;
	string sum;
};

void Direct_search()					//Прямой поиск
{
	string key;
	int num = -1;
	ofstream F("F.txt");
	dat N1 = { "Иванов Иван Иванович", 123248, "123248", "507263" };
	dat N2 = { "Петров Петр Петрович", 892034, "892034", "263598" };
	dat N3 = { "Алексеев Алексей Алексеевич", 109234, "109234", "648531" };
	dat N4 = { "Александров Александр Александрович", 192823, "192823", "984563" };
	dat N5 = { "Максимов Максим Максимович", 573262, "573262", "651234" };

	dat a[5] = { N1, N2, N3, N4, N5 };
	for (int i = 0; i < 5; i++)
		cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << "Номер счёта:" << a[i].acc_number<< endl << '\t' << "Сумма:" << a[i].sum << endl << "\n";

	cout << "Введи ключ (номер счёта), по которому будет осуществлен поиск: "; key = getCorrectNubmer(key);

	string a1[5]{ N1.acc_number1, N2.acc_number1, N3.acc_number1, N4.acc_number1, N5.acc_number1 };
	for (int i = 0; i < 5; i++)
		if (key == a1[i]) num = i + 1;
	if (num != -1)
	{
		F << "Искомый элемент найден" << endl;
		F << a[i].fio << endl << "Номер счёта:" << a[i].acc_number << endl << "Сумма:" << a[i].sum << endl;
	}
	else
	{
		F << "Искомый элемент не найден";
		F << a[i].fio << endl << '\t' << "Номер счёта:" << a[i].acc_number << endl << '\t' << "Сумма:" << a[i].sum << endl << "\n";
	}
}

void Linear_search()					// Линейный поиск
{
	string key;
	int num = -1;
	ofstream F("F.txt");
	dat N1 = { "Иванов Иван Иванович", 123248, "123248", "507263" };
	dat N2 = { "Петров Петр Петрович", 892034, "892034", "263598" };
	dat N3 = { "Алексеев Алексей Алексеевич", 109234, "109234", "648531" };
	dat N4 = { "Александров Александр Александрович", 192823, "192823", "984563" };
	dat N5 = { "Максимов Максим Максимович", 573262, "573262", "651234" };

	dat a[5] = { N1, N2, N3, N4, N5 };
	for (int i = 0; i < 5; i++)
		cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << "Номер счёта:" << a[i].acc_number << endl << '\t' << "Сумма:" << a[i].sum << endl << "\n";

	cout << "Введи ключ (номер счёта), по которому будет осуществлен поиск: "; key = getCorrectNubmer(key);

	string a1[5]{ N1.acc_number1, N2.acc_number1, N3.acc_number1, N4.acc_number1, N5.acc_number1 };
	for (int i = 0; i < 5; i++)
		if (key == a1[i]) num = i + 1;
	if (num != -1)
	{
		F << "Искомый элемент найден" << endl;
		F << a[i].fio << endl << "Номер счёта:" << a[i].acc_number << endl << "Сумма:" << a[i].sum << endl;
	}
	else
		F << "Искомый элемент не найден";
}

void Interpolation_search()				//Интерполяционный поиск
{
	int key = 0, num = -1, mid = -1, left = 0, right = 4, i, temp, item;
	ofstream F("F.txt");
	dat N1 = { "Иванов Иван Иванович", 123248, "123248", "507263" };
	dat N2 = { "Петров Петр Петрович", 892034, "892034", "263598" };
	dat N3 = { "Алексеев Алексей Алексеевич", 109234, "109234", "648531" };
	dat N4 = { "Александров Александр Александрович", 192823, "192823", "984563" };
	dat N5 = { "Максимов Максим Максимович", 573262, "573262", "651234" };

	dat a[5] = { N1, N2, N3, N4, N5 };
	for (i = 0; i < 5; i++)
		cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << "Номер счёта:" << a[i].acc_number << endl << '\t' << "Сумма:" << a[i].sum << endl << "\n";

	cout << "Введи ключ (номер счёта), по которому будет осуществлен поиск: "; key = getCorrectNubmer(key);

	int a1[5]{ N1.acc_number, N2.acc_number, N3.acc_number, N4.acc_number, N5.acc_number };

	for (i = 1; i < 5; i++)
	{
		temp = a1[i];
		item = i - 1;
		while (item >= 0 && a1[item] > temp)
		{
			a1[item + 1] = a1[item];
			a1[item] = temp;
			item--;
		}
	}

	while (a1[left] <= key && a1[right] >= key && a1[mid] != key)
	{
		mid = left + ((key - a1[left]) * (right - left)) / (a1[right] - a1[left]);
		if (a1[mid] < key)
			left = mid + 1;
		else
			if (a1[mid] > key)
				right = mid - 1;
	}
	if (a1[mid] == key)
		F << " " << num << ") " << '\t' << a[num - 1].fio << endl << '\t' << a[num - 1].acc_number << endl << '\t' << a[num - 1].sum << endl << "\n";
	else F << "Искомый элемент не найден";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu = -1;
	while (menu < 1 || menu > 3)
	{
		cout << "Выбери метод поиска: \n 1. Прямой поиск \n 2. Интерполяционный поиск \n 3. Линейный поиск \n Ввод: ";
		menu = getCorrectNubmer(menu); 
	}

	if (menu == 1) Direct_search();
	if (menu == 2) Interpolation_search();
	if (menu == 3) Linear_search();
}