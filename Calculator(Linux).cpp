/*Простой калькулятор с проверками и простой защитой от краша.
ВАЖНО: Эта версия для Linux, на винде будут ошибки :(
Плюсы:
- Язык С++ 
- На Linux выходят первые обновы
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
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <cstring>

using namespace std;

//-----------------------[Переменные]-----------------------//
    char line[64]; //начальная переменная
    char calc[] = "calc";
    char ex[] = "exit";
    char vers[] = "version";
    char ver[] = "ver";
    char dis[] = "discr";
    char deb[] = "debug";
    int en = 1; //нужна для работы цикла
	float aa, cc, dd, ee, kk; //числа
	char bb, numberlb; //операторы
	char apanel;
	double a, b, c, x; //числа
	float HALF_PI   = 1.5707963267949;  // половина пи
    float PI = 3.14159265358979; // число пи
    float DOUBLE_PI = 6.2831853071796;  // два пи
    float TOLERANCE = 1e-10; // граница между "нулём" и "ненулём"
	string aaa, bbb, ccc;
	string al, bl, cl;
	
	
//-----------------------[Проверка]-----------------------//
	bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
	
//-----------------------[Контакты]-----------------------//
	char email[64] = "doshikplayer@gmail.com";
	char vkcom[64] = "vk.com/winsomequill";
	
//-----------------------[Версия]-----------------------//
	char version[32] = "Pre-Release Version 1.2.1.1";
	char secretcode[8] = "1291c";
	
//-----------------------[Выход в отдельном коде]-----------------------//
int exit()
{
	cout << "Завершаем процесс..." << endl;
    aa = bb = cc = dd = ee = a = b = c = x = 0;
    	cout << "Переменные очищены!" << endl;
    	cout << "Процесс завершен!" << endl;
    	en = 0;
    	return 0;
}

//-----------------------[Очистка в отдельном коде]-----------------------//
void clear()
{
	aa = bb = cc = dd = ee = a = b = c = x = 0;
}

void sclear()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}
 
 //-----------------------[Варнинг в отдельном коде]-----------------------//
 void warning()
 {
 	cout << "<WARNING> Сработала защита от краша!\n\n" << endl;
 }
 
 //-----------------------[Главный код]-----------------------//
int main()
{
	while(en != 0) //цикл
	{
	aa00:		
	cout << "calc - калькулятор" << endl;
	cout << "discr - дискриминант" << endl;
	cout << "version - версия программы" << endl;
	cout << "debug - debug" << endl;
	cout << "clear - очистить консоль" << endl;
	cout << "exit - выход \n" << endl;
    cin >> line;
    cout << "\n";
    
    if(strcmp(line, deb) == 0)
    {
    	aa01:
    	cout << "Все переменые равны 1\n" << endl;
    	aa = bb = cc = dd = ee = a = b = c = x = 1;
    }
    
    if(strcmp(line, ex) == 0)
    {
    	aa02:
    	if(aa != 0 || bb != 0 || cc != 0 || dd != 0 || ee != 0 || a != 0 || b != 0 || c != 0 || x != 0) //Проверяем переменные на чистоту
    	{
    		//Если переменные багнулись, то чистим Ванишом или другим порошком для стирки
    		exit();
    		} 
    	else{
        //Если все чисто, то выходим
    	cout << "Процесс завершен!" << endl;
    	en = 0;
    	}
    }
	
	if(strcmp(line, calc) == 0)
	{
		aa03:
        cout << "Введите значение а: " << endl;
		cin >> aaa;
		
		if(is_number (aaa))
		{
		aa = atof(aaa.c_str());
		cout << "Введите оператор: " << endl;
		cin >> bb;
		if(bb == 'k') //Корень
		{
             kk=sqrt(aa);
             cout << "Ответ: " << kk << endl;
             cout << "\n" << endl;
             goto aa00;
		} 
		if(bb == '-' || bb == '+' || bb == '/' || bb == '*')
    	{
    		aa04:
        cout << "Введите значение b: " << endl;
		cin >> ccc;
		cc = atof(ccc.c_str());
		}
		else{
			cout << "Такого оператора нету!" << endl;
    		clear();
    		goto aa00;
		}
		}
		else{
			warning();
			clear();
		}
		
		if(bb == '+')
		{
			dd = aa + cc;
			cout << "Ответ: " << dd << endl;
			cout << "\n" << endl;
		}
		if(bb == '-')
		{
			dd = aa - cc;
			cout << "Ответ: " << dd << endl;
			cout << "\n" << endl;
		}
		if(bb == '*')
		{
			dd = aa * cc;
			cout << "Ответ: " << dd << endl;
			cout << "\n" << endl;
		}
		if(bb == '/')
		{
			aa05:
			dd = aa / cc;
			if(cc == 0)
			{
				cout << "Делить на ноль нельзя!" << endl;
			} else {
			cout << "Ответ: " << dd << endl;
			cout << "\n" << endl;
		}
		}
	}
		                                     

	if(strcmp(line, dis) == 0)
	{
		aa06:
      cout << "Введите значение a: ";
      cin >> al;
     if(is_number (al))
		{
			a = atof(al.c_str());
            cout << "Введите значение b: ";
           cin >> bl;
           if(is_number (bl))
	  	{
			b = atof(bl.c_str());
            cout << "Введите значение c: ";
            cin >> cl;
                    if(is_number (cl))
	            	{
		          	c = atof(cl.c_str());
	            	} else {
			              warning();
			              clear();
	            	}
          } else {
			      warning();
		      	clear();
	  	}
	}	else{
			warning();
			clear();
		}
			
		
    if((b*b - 4*a*c) >= 0) //Если дискриминант больше или равен 0
    {
    	aa07:
        x = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a); 
        cout << "Первый корень равен " << x << endl;
        x = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << "Второй корень равен " << x << endl;
        cout << "\n\n\n" << endl;
    }
    else
    {
        cout << "Дискриминант меньше 0, корни невещественные. \n" << endl; //Если все плохо, то выводим краткий ответ :)                                         
    }
	}
	
	if(strcmp(line, "clear") == 0)
	{
		aa08:
		sclear();
	}
	
	if(strcmp(line, vers) == 0)
	{
		aa09:
		cout << "-------------------------------------------------------" << endl;
		cout << version << " (By WinsomeQuill)" << endl;
		cout << vkcom << endl;
		cout << email << " (PayPal :3)" << endl;
		cout << secretcode << endl;
		cout << "Good luck!" << endl;
		cout << "-------------------------------------------------------\n\n\n" << endl;
        usleep(500000);
        cout << "\r\ B" << flush;
        usleep(500000);
        cout << "\r\  By" << flush;
        usleep(500000);
        cout << "\r\   By " << flush;
        usleep(500000);
        cout << "\r\    By W" << flush;
        usleep(500000);
        cout << "\r\     By Wi" << flush;
        usleep(500000);
        cout << "\r\      By Win" << flush;
        usleep(500000);
        cout << "\r\       By Wins" << flush;
        usleep(500000);
        cout << "\r\        By Winso" << flush;
        usleep(500000);
        cout << "\r\         By Winsom" << flush;
        usleep(500000);
        cout << "\r\          By Winsome" << flush;
        usleep(500000);
        cout << "\r\           By WinsomeQ" << flush;
        usleep(500000);
        cout << "\r\            By WinsomeQu" << flush;
        usleep(500000);
        cout << "\r\             By WinsomeQui" << flush;
        usleep(500000);
        cout << "\r\              By WinsomeQuil" << flush;
        usleep(500000);
        cout << "\r\               By WinsomeQuill" << flush;
        usleep(500000);
        cout << "\r\                By WinsomeQuill :D\n\n\n" << flush << endl;
	}
	//-----------------------[*Режим разработчика*]-----------------------//
	if(strcmp(line, "lb") == 0)
	{
		aa10:
		cout << "Введи номер лейбала: ";
		cin >> line;
		if(strcmp(line, "aa00") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa00;
		}
		if(strcmp(line, "aa01") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa01;
		}
		if(strcmp(line, "aa02") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa02;
		}
		if(strcmp(line, "aa03") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa03;
		}
		if(strcmp(line, "aa04") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa04;
		}
		if(strcmp(line, "aa05") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa05;
		}
		if(strcmp(line, "aa06") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa06;
		}
		if(strcmp(line, "aa07") == 0)
		{
			cout << "Вы перешли на " << line << " лейбел" << endl;
			goto aa07;
		}
	}
}
}
