#include <iostream>

class Fraction
{
private:
	int chis;
	int znam;
public:
	Fraction() { chis = 0; znam = 0; }
	Fraction(int c, int z) { chis = c; znam = z; }
	Fraction(const Fraction &ob);  // êîíñòðóêòîð êîïèè
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
	int NOD(Fraction);   // íàèáîëüøèé îáùèé äåëèòåëü
	int NOD_int(int, int); // ÍÎÄ äëÿ èñïîëüçîâàíèÿ â äðóãèõ ôóíêöèÿõ
	int NOK_int(int, int); // ÍÎÊ äëÿ èñïîëüçîâàíèÿ â äðóãèõ ôóíêöèÿõ
	int NOK(Fraction); // íàèìåíüøèå îáùèå êðàòíîå
};

// ïåðåãðóçêà íå ðàâíî
bool Fraction::operator !=(Fraction f2) 
{
	int z = NOK_int(this->znam, f2.znam); // íàõîäèì ÍÎÊ
	this->chis = this->chis * (z / this->znam); // ïðèâîäèì ÷èñëèòåëü
	f2.chis = f2.chis * (z / f2.znam);  // ïðèâîäèì çíàìåíàòåëü
	if (this->chis != f2.chis) // åñëè çíàìåíàòåëè íå ðàâíû
		return 1;
	else
		return 0;

}
// ïåðåãðóçêà  ðàâíî
bool Fraction::operator == (Fraction f2)
{
	if (this->znam == f2.znam && this->chis == f2.chis) // åñëè çíàìåíàòåëè è ÷èñëèòåëè ðàâíû, òî è äðîáè ðàâíû
		return 1;
	else
	{
		int z = NOK_int(this->znam, f2.znam); //íàõîäèì ÍÎÊ
		this->chis = this->chis * (z / this->znam);
		f2.chis = f2.chis * (z / f2.znam);
		if (this->chis == f2.chis) // åñëè ÷èñëèòåëè ðàâíû
			return 1;
		else
			return 0;
	}

	return 0;
}
// ïåðåãðóçêà ìåíüøå
bool Fraction::operator<(Fraction f2)
{

	if (this->znam != f2.znam && this->chis != f2.chis) // åñëè ðàçíûå çíàìåíàòåëè è ÷èñëèòåëè
	{
		int z = NOK_int(this->znam, f2.znam); // ÍÎÊ
		this->chis = this->chis * (z / this->znam); // ïðèâîäèì ê îáùåìó çíàìåíàòåëþ
		f2.chis = f2.chis * (z / f2.znam);
		if (this->chis < f2.chis)
			return 1;
		else
			return 0;
	}

	if (this->znam == f2.znam) // åñëè ó äðîáåé îäèíàêîâûå çíàìåíàòåëè
	{
		if (this->chis < f2.chis)
			return 1;
		else
			return 0;
	}
	if (this->chis == f2.chis) // åñëè îäèíàêîâûå ÷èñëèòåëè
	{
		if (this->znam < f2.znam)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
// ïåðåãðóçêà áîëüøå
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
//óìíîæåíèå
Fraction Fraction ::operator*(Fraction f2) 
{                                          
	this->chis = this->chis * f2.chis;
	this->znam = this->znam * f2.znam;
	return *this;

}
//äåëåíèå
Fraction Fraction ::operator / (Fraction f2) 
{
	this->chis = this->chis * f2.znam; // ÷èñëèòåëü ïåðâîé íà çíàìåíàòåëü âòîðîé
	this->znam = this->znam * f2.chis; // çíàìåíàòåëü ïåðâîé íà ÷èñëèòåëü âòîðîé
	return *this;
}
//ñóììà
Fraction Fraction::operator+(Fraction f2)
{
	int z = NOK_int(this->znam, f2.znam); // ÍÎÊ
	this->chis = this->chis*(z / this->znam);
	f2.chis = f2.chis * (z / f2.znam);
	this->chis = this->chis + f2.chis;
	this->znam = z;
	return *this;
}
//âû÷èòàíèå
Fraction Fraction::operator - (Fraction f2)
{
	int z = NOK_int(this->znam, f2.znam);
	this->chis = this->chis*(z / this->znam);
	f2.chis = f2.chis * (z / f2.znam);
	this->chis = this->chis - f2.chis;
	this->znam = z;
	return *this;
}
//ïðèñâîåíèå
Fraction Fraction:: operator = (Fraction f2)
{
	this->chis = f2.chis;
	this->znam = f2.znam;
	return *this;
}
// õîðîøèé àëãîðèòì ïî íàõîæäåíèþ ÍÎÄ
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

Fraction::Fraction(const Fraction &ob) // êîíñòðóêòîð êîïèè
{
	this->chis = ob.chis;
	this->znam = ob.znam;
}
//-------Ââîä äðîáåé-------
void Fraction::Enter()  
{
	std::cout << "Ââåäèòå ÷èñëèòåëü äðîáè " << std::endl;
	std::cin >> chis;
	std::cout << "Ââåäèòå çíàìåíàòåëü " << std::endl;
	std::cin >> znam;
	
}
//------Âûâîä äðîáåé-----
void Fraction::Show() 
{
	std::cout << chis << "/" << znam << " ";
}
int main()
{
	Fraction f1, f2, f3;
	Fraction f11,f12,f13,f14;
	setlocale(0, "rus");
	std::cout << "Ââîä äðîáåé " << std::endl;
	f1.Enter(); f2.Enter();
	f11 = f1; f12 = f1; f13 = f1,f14=f1;
	std::cout << "Ñëîæåíèå äðîáåé ";
	f1.Show(); std::cout << " + "; f2.Show();
	std::cout << " = ";f3 = f1 + f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Âû÷èòàíèå äðîáåé ";
	f11.Show();  std::cout << " - "; f2.Show();
	std::cout << " = "; f3 = f11 - f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Äåëåíèå äðîáåé ";
	f12.Show(); std::cout << " / ";  f2.Show();
	std::cout << " = "; f3 = f12 / f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Óìíîæåíèå äðîáåé ";
	f13.Show();  std::cout << " * "; f2.Show(); 
	std::cout << " = "; f3 = f13 * f2; f3.Show();
	std::cout << std::endl;
	std::cout << "Ïðèñâîåíèå äðîáåé ";
	f3 = f1 = f2;
	std::cout << "f1= ";
	f1.Show(); std::cout << ", f2= "; f2.Show();
	std::cout << std::endl;
	system("pause");
	
}
