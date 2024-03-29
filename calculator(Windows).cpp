/*Простой калькулятор с проверками и простой защитой от краша.
ВАЖНО: Эта версия для винды :)
Плюсы:
- Язык С++
- Поддержка русского языка
- Есть цикл
- Есть корень
- Не уходит в бесконечный цикл при буквах
- Красивое оформление комментов
- Красивая анимация команды "version"
Минусы:
- В корне нужно вводить два числа
- Куча мусора
- Есть баги
*/

#include <iostream>
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <dos.h>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <cstring>

using namespace std;

//-----------------------[Переменные]-----------------------//
char line[64]; //начальная переменная
const char calc[] = "calc";
const char ex[] = "exit";
const char vers[] = "version";
const char dis[] = "discr";
const char deb[] = "debug";
const char clearconsole[] = "clear";
int en = 1; //нужна для работы цикла
int koren = 1;
float aa, cc, dd, ee; //числа
char bb; //оператор
double a, b, c, x; //числа
string aaa, bbb, ccc;
string al, bl, cl;


//-----------------------[Проверка]-----------------------//
bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

//-----------------------[Контакты]-----------------------//
const char email[64] = "doshikplayer@gmail.com";
const char vkcom[64] = "vk.com/winsomequill";

//-----------------------[Версия]-----------------------//
const char version[64] = "Pre-Release Version 1.2.0.7 (Windows)";

//-----------------------[Выход в отдельном коде]-----------------------//
void exit()
{
	cout << "Завершаем процесс..." << endl;
	aa = bb = cc = dd = ee = a = b = c = x = 0;
	cout << "Переменные очищены!" << endl;
	cout << "Процесс завершен!" << endl;
	en = 0;
}

//-----------------------[Чистка переменных в отдельном коде]-----------------------//
void clear()
{
	aa = bb = cc = dd = ee = a = b = c = x = 0;
}

//-----------------------[Варнинг в отдельном коде]-----------------------//
void warning()
{
	cout << "<WARNING> Сработала защита от краша!\n\n" << endl;
}

//-----------------------[Главный код]-----------------------//
int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus"); // настройка локальной функции
	while (en != 0) //цикл
	{

		cout << "calc - калькулятор" << endl;
		cout << "discr - дискриминант" << endl;
		cout << "version - версия программы" << endl;
		cout << "clear - очистить консоль" << endl;
		cout << "debug - debug" << endl;
		cout << "exit - выход \n" << endl;
		cin >> line;
		cout << "\n";

		if (strcmp(line, deb) == 0)
		{
			cout << "Все переменые равны 1\n" << endl;
			aa = bb = cc = dd = ee = a = b = c = x = 1;
		}

		if (strcmp(line, clearconsole) == 0)
		{
			for (int l = 0; l < 80; l++)
			{
				cout << "\n" << endl;
			}
		}

		if (strcmp(line, ex) == 0)
		{
			if (aa != 0 || bb != 0 || cc != 0 || dd != 0 || ee != 0 || a != 0 || b != 0 || c != 0 || x != 0) //Проверяем переменные на чистоту
			{
				//Если переменные багнулись, то чистим Ванишом или другим порошком для стирки
				exit();
			}
			else {
				//Если все чисто, то выходим
				cout << "Процесс завершен!" << endl;
				en = 0;
			}
		}

		if (strcmp(line, calc) == 0)
		{
			cout << "Введите значение а: " << endl;
			cin >> aaa;

			if (is_number(aaa))
			{
				aa = atof(aaa.c_str());
				cout << "Введите оператор: " << endl;
				cin >> bb;
				if (bb == '-' || bb == '+' || bb == '/' || bb == '*' || bb == 'k')
				{

					if (bb == 'k')
					{
						dd = sqrt(aa);
						cout << "Ответ: " << dd << endl;
						cout << "\n" << endl;
						clear();
					}

					cout << "Введите значение b: " << endl;
					cin >> ccc;
					cc = atof(ccc.c_str());
				}
				else {
					warning();
				}
			}
			else {
				warning();
				clear();
			}

			if (bb == '+')
			{
				dd = aa + cc;
				cout << "Ответ: " << dd << endl;
				cout << "\n" << endl;
			}
			if (bb == '-')
			{
				dd = aa - cc;
				cout << "Ответ: " << dd << endl;
				cout << "\n" << endl;
			}
			if (bb == '*')
			{
				dd = aa * cc;
				cout << "Ответ: " << dd << endl;
				cout << "\n" << endl;
			}
			if (bb == '/')
			{
				dd = aa / cc;
				if (cc == 0)
				{
					cout << "Делить на ноль нельзя!" << endl;
				}

				if (cc < 0 || cc <= 9)
				{
					warning();
				}
				cout << "Ответ: " << dd << endl;
				cout << "\n" << endl;
			}

			/*	if(bb == 'k') //Корень
				{
					 dd=sqrt(aa);
					 cout << "Ответ: " << dd << endl;
					 cout << "\n" << endl;
				} */

		}


		if (strcmp(line, dis) == 0)
		{
			cout << "Введите значение a: ";
			cin >> al;
			if (is_number(al))
			{
				a = atof(al.c_str());
				cout << "Введите значение b: ";
				cin >> bl;
				if (is_number(bl))
				{
					b = atof(bl.c_str());
					cout << "Введите значение c: ";
					cin >> cl;
					if (is_number(cl))
					{
						c = atof(cl.c_str());
					}
					else {
						warning();
						clear();
					}
				}
				else {
					warning();
					clear();
				}
			}
			else {
				warning();
				clear();
			}


			if ((b * b - 4 * a * c) >= 0) //Если дискриминант больше или равен 0
			{
				x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
				cout << "Первый корень равен " << x << endl;
				x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
				cout << "Второй корень равен " << x << endl;
				cout << "\n\n\n" << endl;
			}
			else
			{
				cout << "Дискриминант меньше 0, корни невещественные. \n" << endl; //Если все плохо, то выводим краткий ответ :)                                         
			}
		}


		if (strcmp(line, vers) == 0)
		{
			cout << "-------------------------------------------------------" << endl;
			cout << version << " (By WinsomeQuill)" << endl;
			cout << vkcom << endl;
			cout << email << endl;
			cout << "Good luck!" << endl;
			cout << "-------------------------------------------------------\n\n\n" << endl;
			Sleep(300);
			cout << "\r\ B" << flush;
			Sleep(300);
			cout << "\r\  By" << flush;
			Sleep(300);
			cout << "\r\   By " << flush;
			Sleep(300);
			cout << "\r\    By W" << flush;
			Sleep(300);
			cout << "\r\     By Wi" << flush;
			Sleep(300);
			cout << "\r\      By Win" << flush;
			Sleep(300);
			cout << "\r\       By Wins" << flush;
			Sleep(300);
			cout << "\r\        By Winso" << flush;
			Sleep(300);
			cout << "\r\         By Winsom" << flush;
			Sleep(300);
			cout << "\r\          By Winsome" << flush;
			Sleep(300);
			cout << "\r\           By WinsomeQ" << flush;
			Sleep(300);
			cout << "\r\            By WinsomeQu" << flush;
			Sleep(300);
			cout << "\r\             By WinsomeQui" << flush;
			Sleep(300);
			cout << "\r\              By WinsomeQuil" << flush;
			Sleep(300);
			cout << "\r\               By WinsomeQuill" << flush;
			Sleep(300);
			cout << "\r\                By WinsomeQuill :D\n\n\n" << flush << endl;
		}
	}
}
