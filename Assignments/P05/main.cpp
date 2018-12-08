//Khethulwazi Kunene
//CMPS 2143 - A05
//This program creates a user defined clock class,
//which we can manipulate in order to count down,
//or count up.

#include "Timer.h"


using namespace std;
/*
class Counter {
	// Your awesomeness here...
};
*/

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;

	Timer t(0,0,400,419);
	float x = 50;
	float y = 50;


	
	//t.stopwatch();
	t.setTime(12,30);

	//auto tp = std::chrono::steady_clock::now();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//float changeInTime;
		//{
		//	const auto new_tp = std::chrono::steady_clock::now();
		//	changeInTime = std::chrono::duration<float>(new_tp - tp).count();
		//	tp = new_tp;
		//}

		t.printTime();
		t.countdown(window);

		window.clear();
		//window.draw(t);
		window.display();
	}

	return 0;
}
