#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int print_int()
{
	int res;
	do
	{
		try
		{
			string numStr;
			cout << "Введите число: ";
			getline(cin, numStr);
			res = stoi(numStr);
			return res;
		}
		catch (const exception& ex)
		{
			cout << "Ошибка: " << ex.what() << ".\n";
		}
	} while (true);
}
double division(double A, double B);
template <typename T > void showArr(T arr[], int length);
template <typename T > void fillArr(T arr[], int length,int min,int max);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	//Выход за числовой диапазон
	/*try {
		cout << "Введите число от 1 до 10: ";
		cin >> n;
		if (n < 1)
			throw 0;
		if (n > 10)
			throw "Введённое число больше указанного диапазона.\n";
		cout << "Число введенно корректно.\n";
	}
	catch (const int ex) {
		if (ex == 0)
			cout << "Ошибка!Введённое число меньше указанного диапазона.\n";
	}
	catch (const char ex[]) {
		cout << "Ошибка!" << ex << endl;
	}*/
	// "Защита от нуба"
	/*bool check = false;
	do {
		try {
			string numStr;
			cout << "Введите число: ";
			getline(cin, numStr);
			n = stoi(numStr);
			cout << "Введенно число " << n << endl;
			check = true;
		}
		catch (const exception& ex) {
			cout << "Ошибка: " << ex.what() << ".\n";
		}
	} while (!check);*/
	/*n = print_int();
	cout << "Введенно " << n << endl;*/
	//Делениe
	/* try
	{
		cout << "Введите два числа: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const logic_error& ex)
	{
		cout << "Ошибка:" << ex.what() << endl;
	}*/
	string path = "file.txt";
	//Проверка открытия файла
	/*ofstream out;
	//Разрешаем объекту класса бросать исключения
	out.exceptions(ios::badbit | ios::failbit | ios::eofbit);
	try {
		out.open(path);

		string str;
		cout << "Введите строку:\n";
		getline(cin, str);
		out << str + "\n";
		cout << "Запись помещена в файл.\n";

		out.close();
	}
	catch(const ios::failure&ex) {
		cout << "Ошибка: " << ex.what() << endl;
		cout << "Код ошибки: " << ex.code() << endl;
	}*/
	//
	cout << "Введите длину массива: ";
	cin >> n;
	try{
		int* arr = new int[n] {};
		cout << "Изначальный массив:\n";
		showArr(arr, n);
		fillArr(arr, n, 10, 31);
		cout << "Итоговый массив:\n";
		showArr(arr, n);
	}
	catch (const underflow_error& ex){
		cout << "Ошибка: " << ex.what() << endl;
	}
	catch (const bad_array_new_length& ex){
		cout << "Ошибка создания массива: " << ex.what() << endl;
	}
	catch (const invalid_argument& ex)
	{
		cout << "Ошибка диапазона: " << ex.what() << endl;
	}

	return 0;
}
double division(double A, double B)
{
	if (B == 0)
		throw logic_error("division by zero");

	return A / B;
}
template <typename T > void showArr(T arr[], int length){
	if (length <= 0)
		throw underflow_error("Длина массива должна быть положительной");
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
template <typename T > void fillArr(T arr[], int length, int min, int max){
	if (length <= 0)
		throw underflow_error("Длина массива должна быть положительной");
	if (max <= min)
		throw invalid_argument("Конец диапазона должен быть больше, чем начало");
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}