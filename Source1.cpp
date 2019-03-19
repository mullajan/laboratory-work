#include <iostream>

class Fraction
{
private:
	int chis;
	int znam;
public:
	Fraction() { chis = 0; znam = 0; }
	Fraction(int c, int z) { chis = c; znam = z; }
	Fraction(const Fraction &ob);  // конструктор копии
	void Enter();
	void Show();
	Fraction operator = (Fraction);
	Fraction operator + (Fraction);
	Fraction operator - (Fraction);
	Fraction operator * (Fraction);
	Fraction operator / (Fraction);
	bool operator != (Fraction);
	bool operator > (Fraction);
	bool operator < (Fraction);
	bool operator == (Fraction);
	int NOD(Fraction);   // наибольший общий делитель
	int NOD_int(int, int); // НОД для использования в других функциях
	int NOK_int(int, int); // НОК для использования в других функциях
	int NOK(Fraction); // наименьшие общие кратное
};

// перегрузка не равно
bool Fraction::operator !=(Fraction f2) 
{
	int z = NOK_int(this->znam, f2.znam); // находим НОК
	this->chis = this->chis * (z / this->znam); // приводим числитель
	f2.chis = f2.chis * (z / f2.znam);  // приводим знаменатель
	if (this->chis != f2.chis) // если знаменатели не равны
		return 1;
	else
		return 0;

}
// перегрузка  равно
bool Fraction::operator == (Fraction f2)
{
	if (this->znam == f2.znam && this->chis == f2.chis) // если знаменатели и числители равны, то и дроби равны
		return 1;
	else
	{
		int z = NOK_int(this->znam, f2.znam); //находим НОК
		this->chis = this->chis * (z / this->znam);
		f2.chis = f2.chis * (z / f2.znam);
		if (this->chis == f2.chis) // если числители равны
			return 1;
		else
			return 0;
	}

	return 0;
}
// перегрузка меньше
bool Fraction::operator<(Fraction f2)
{

	if (this->znam != f2.znam && this->chis != f2.chis) // если разные знаменатели и числители
	{
		int z = NOK_int(this->znam, f2.znam); // НОК
		this->chis = this->chis * (z / this->znam); // приводим к общему знаменателю
		f2.chis = f2.chis * (z / f2.znam);
		if (this->chis < f2.chis)
			return 1;
		else
			return 0;
	}

	if (this->znam == f2.znam) // если у дробей одинаковые знаменатели
	{
		if (this->chis < f2.chis)
			return 1;
		else
			return 0;
	}
	if (this->chis == f2.chis) // если одинаковые числители
	{
		if (this->znam < f2.znam)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
// перегрузка больше
bool Fraction::operator>(Fraction f2)
{

	if (this->znam != f2.znam && this->chis != f2.chis)
	{
		int z = NOK_int(this->znam, f2.znam);
		this->chis = this->chis * (z / this->znam);
		f2.znam = f2.znam * (z / f2.znam);
		if (this->chis > f2.chis)
			return 1;
		else
			return 0;
	}

	if (this->znam == f2.znam)
	{
		if (this->chis > f2.chis)
			return 1;
		else
			return 0;
	}
	if (this->chis == f2.chis)
	{
		if (this->znam < f2.znam)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
//умножение
Fraction Fraction ::operator*(Fraction f2) 
{                                          
	this->chis = this->chis * f2.chis;
	this->znam = this->znam * f2.znam;
	return *this;

}
//деление
Fraction Fraction ::operator / (Fraction f2) 
{
	this->chis = this->chis * f2.znam; // числитель первой на знаменатель второй
	this->znam = this->znam * f2.chis; // знаменатель первой на числитель второй
	return *this;
}
//сумма
Fraction Fraction::operator+(Fraction f2)
{
	int z = NOK_int(this->znam, f2.znam); // НОК
	this->chis = this->chis*(z / this->znam);
	f2.chis = f2.chis * (z / f2.znam);
	this->chis = this->chis + f2.chis;
	this->znam = z;
	return *this;
}
//вычитание
Fraction Fraction::operator - (Fraction f2)
{
	int z = NOK_int(this->znam, f2.znam);
	this->chis = this->chis*(z / this->znam);
	f2.chis = f2.chis * (z / f2.znam);
	this->chis = this->chis - f2.chis;
	this->znam = z;
	return *this;
}
//присвоение
Fraction Fraction:: operator = (Fraction f2)
{
	this->chis = f2.chis;
	this->znam = f2.znam;
	return *this;
}
// хороший алгоритм по нахождению НОД
int Fraction::NOD_int(int x, int y) 
{
	while (x && y)
		if (x >= y)
			x %= y;
		else
			y %= x;
	return x | y;
}

int Fraction::NOD(Fraction f2)
{
	while (this->znam && f2.znam)
		if (this->znam >= f2.znam)
			this->znam %= f2.znam;
		else
			f2.znam %= this->znam;
	return this->znam | f2.znam;
}

int Fraction::NOK(Fraction f2)
{
	return this->znam / NOD_int(this->znam, f2.znam)*f2.znam;

}

int Fraction::NOK_int(int x, int y)
{
	return x / NOD_int(x, y)*y;
}

Fraction::Fraction(const Fraction &ob) // конструктор копии
{
	this->chis = ob.chis;
	this->znam = ob.znam;
}
//-------Ввод дробей-------
void Fraction::Enter()  
{
	std::cout << "Введите числитель дроби " << std::endl;
	std::cin >> chis;
	std::cout << "Введите знаменатель " << std::endl;
	std::cin >> znam;
	
}
//------Вывод дробей-----
void Fraction::Show() 
{
	std::cout << chis << "/" << znam << " ";
}
int main()
{
	Fraction f1, f2, f3;
	Fraction f11,f12,f13,f14;
	setlocale(0, "rus");
	std::cout << "Ввод дробей " << std::endl;
	f1.Enter(); f2.Enter();
	f11 = f1; f12 = f1; f13 = f1,f14=f1;
	std::cout << "Сложение дробей ";
	f1.Show(); std::cout << " + "; f2.Show();
	std::cout << " = ";f3 = f1 + f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Вычитание дробей ";
	f11.Show();  std::cout << " - "; f2.Show();
	std::cout << " = "; f3 = f11 - f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Деление дробей ";
	f12.Show(); std::cout << " / ";  f2.Show();
	std::cout << " = "; f3 = f12 / f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Умножение дробей ";
	f13.Show();  std::cout << " * "; f2.Show(); 
	std::cout << " = "; f3 = f13 * f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Присвоение дробей ";
	f3 = f1 = f2;
	std::cout << "f1= ";
	f1.Show(); std::cout << ", f2= "; f2.Show();
	std::cout << std::endl;
	system("pause");
	
}