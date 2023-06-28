#include <cmath>
#include <iostream>
using namespace std;

class Yclock 
{
private:
	int hour, minute, second;

public:
	Yclock(int h = 0, int m = 0, int s = 0);
		void showtime();
	Yclock &operator++();
	Yclock operator++(int);
};

Yclock::Yclock(int h, int m, int s)
{
	if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
	{
		hour = h;
		minute = m;
		second = s;
	}
	else
		cout << "�����ʱ������" << endl;
}

void Yclock::showtime()
{
	cout << hour << ";" << minute << ":" << second << endl;
}

Yclock &Yclock::operator++()
{
	second++;
	if (second >= 60)
	{
		minute++;
		second %= 60;
		if (minute >= 60)
		{
			hour++;
			minute %= 60;
			hour %= 24;
		}
		return *this;
	}
}

Yclock Yclock::operator++(int)
{
	Yclock old = *this;
	++(*this);
	return old;
}

int main() {
	Yclock myclock(23, 59, 59);
	cout << "��ʼ����ʾʱ��Ϊ:\t\t";
	myclock++.showtime();

	cout << "ִ��myClock++���ʱ��Ϊ:\t";

	//��ִ��ShowTime()�����myClock=23:59:59��
	//��ִ��myClock++����ʱmyClock=00:00:00
	(myclock++).showtime();

	cout << "ִ��++myClock���ʱ��Ϊ:\t";

	//��ִ��++myClock����ʱmyClock=00:00:01
	//��ִ��ShowTime()�����myClock=00:00:01
	(++myclock).showtime();
}