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
		cout << "输入的时间有误" << endl;
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
	cout << "初始化显示时间为:\t\t";
	myclock++.showtime();

	cout << "执行myClock++后的时间为:\t";

	//先执行ShowTime()，输出myClock=23:59:59，
	//再执行myClock++，此时myClock=00:00:00
	(myclock++).showtime();

	cout << "执行++myClock后的时间为:\t";

	//先执行++myClock，此时myClock=00:00:01
	//再执行ShowTime()，输出myClock=00:00:01
	(++myclock).showtime();
}