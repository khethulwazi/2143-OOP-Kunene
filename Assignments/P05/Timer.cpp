#include "Timer.h"

Timer::Timer(int a, int b, int c, int d)
{
	
	hour = 0;
	minutes = 0;
	seconds = 0;
	x = a;
	y = b;
	width = c;
	height = d;

}

Timer::Timer(int h, int m)
{
	hour = h;
	minutes = m;
	seconds = 0;
}

Timer::Timer(int h, int m, int s)
{
	hour = h;
	minutes = m;
	seconds = s;
}



Timer::~Timer()
{
}


void Timer::stopwatch()
{
	hour = 0;
	minutes = 0;
	seconds = 0;
	while (true)
	{
		
		if (seconds < 60)
		{
			seconds++;
		}
		else if (seconds == 60)
		{
			seconds = 0;
			minutes++;
		}
		else if (minutes == 60)
		{
			minutes = 0;
			hour++;
		}		
		std::cout << "Khethulwazi Kunene \nStop Watch: \n";
		std::cout << std::fixed;
		std::cout << "Hour: " << "Mins: " << "Secs: \n";
		std::cout << hour << std::setw(7) << minutes << std::setw(8) << seconds;		
		Sleep(1000);
		system("cls");

	}
}


void Timer::countdown(sf::RenderTarget& window) 
{
	int iCounter;
	std:: cout << "\nEnter a value for the counter\n";
	std::cin >> iCounter;
	
	texture.loadFromFile("./count3.jpg");
	clock.setTexture(texture);
	for (int i = 0; i < xFrames; i++)
	{
		for (int j = 0; j < yFrames; j++)
		{
			frames[i] = { x + i * width, y, width, height };
		}
	}
	clock.setTextureRect(frames[iFrame]);


	while(iCounter >= 0)
	{
		
		std::cout << "Countdown: \n" << std::setw(4) << iCounter;
		window.draw(clock);
		//clock.setTextureRect(frames[iFrame]);
		if (iFrame == 12)
		{
			iFrame = 0;
		}
		iCounter--;
		
		Sleep(1000);
		system("cls");
	}
	
	
	std::cout << "\nCount down timer has expired\n";
}


void Timer::setTime()
{
	std::cout << "Please Enter the hour: ";
	std::cin >> hour;
	std::cout << "\nPlease enter the minutes: ";
	std::cin >> minutes;
	std::cout << "\nPlease enter the seconds: ";
	std::cin >> seconds;
}

void Timer::setTime(int h, int m)
{
	hour = h;
	minutes = m;
}


void Timer::printTime()
{
	while (true)
	{
		if (seconds < 60)
		{
			seconds++;
		}
		else if (seconds == 60)
		{
			seconds = 0;
			minutes++;
		}
		else if (minutes == 60)
		{
			minutes = 0;
			hour++;
		}
		std::cout << std::fixed;
		std::cout << "Hour: " << "Mins: " << "Secs: \n";
		std::cout << hour << std::setw(7) << minutes << std::setw(8) << seconds;
		Sleep(1000);
		system("cls");

	}
}


void Timer::update(float dt)
{
	time += dt;
	while (time >= holdTime)
	{
		time -= holdTime * 2.5;
		advance();
	}
}
