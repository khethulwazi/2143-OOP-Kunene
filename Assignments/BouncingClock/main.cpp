/*khethulwazi kunene									**
**cmps 2143												**
**Clock assignment -									**
**getting a gameclock gameclock to set to different		**
**positions on screen like a screensaver				**
*********************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Tile.h"
#include "Group.h"

using namespace std;
int flagX = 1;
int flagY = 1;

class DrawMe : public Group{
private:
    Tile smiley;
    sf::RectangleShape rectangle;
    float angle;
public:
    DrawMe(){
        smiley.resetTile(128,128,"./smiley.png");
        smiley.setPosition(sf::Vector2f(100.0, 100.0));
        smiley.setSize(64,64);
        smiley.setOrigin(64.0,64.0);

        rectangle.setSize(sf::Vector2f(100, 100));
        rectangle.setFillColor(sf::Color::Black);
        rectangle.setOutlineColor(sf::Color::Green);
        rectangle.setOutlineThickness(2);
        rectangle.setOrigin(50,50);
        rectangle.setPosition(100, 100);

        angle = .01;
        
        this->push_back(rectangle);
        this->push_back(smiley);

    }

    void changeSmiley(string image){
        smiley.setTileTexture(image);
    }

    void update(){
        rectangle.rotate(angle);

        angle += .0001;
    }
};

class GameClock{
private:
    sf::Text text;          // var to hold clock digits
    sf::Clock gameClock;    // SFML clock type
    sf::Time startTime;
    sf::Font font;
    sf::Color textColor;
	sf::Vector2f coord;
	sf::Vector2f origin;
    int fontSize;
	float x, y;

public:
    GameClock(sf::RenderWindow &window, int gameWidth, int gameHeight){
        gameClock.restart();
        if (!font.loadFromFile("Segment7Standard.otf")) {
            cout << "Error loading font 'Segment7Standard.otf'...";
            exit(0);
        }
		x = gameWidth / 2;
		y = gameHeight / 2;

        fontSize = 48;

        textColor = sf::Color(0, 255, 0); // green

        text.setFont(font); // font is a sf::Font

        // set the string to display
        text.setString("0");

        text.setCharacterSize(fontSize); // in pixels, not points!

        text.setFillColor(textColor);

        text.setStyle(sf::Text::Bold);

		start(window, gameWidth, gameHeight,x,y);
    }

	//allows the clock the print to screen 
	//in new position
    void printClock(sf::RenderWindow &window,int gameWidth, int gameHeight){
		sf::Vector2f pos = text.getPosition();
		int itime = gameClock.getElapsedTime().asSeconds();
		string stime = to_string(itime);
		text.setString(stime);
		//attempting to update the position
		//each time the clock is printed 
		//make the reverse by multiplying the flag by -1
		if (pos.x > gameWidth) {
			flagX *= -1;
		}
		if (pos.x <= 0) {
			flagX *= -1;

		}
		if (pos.y > gameHeight) {
			flagY *= -1;
		}
		if(pos.y <= 0) {
			flagY *= -1;
		}
		text.move(sf::Vector2f(flagX, flagY));
		window.draw(text);
    }

	//will initialize the clock
	//to a central position and run
	void start(sf::RenderWindow &window, float gameWidth, float gameHeight,float x, float y) {
		int itime = gameClock.getElapsedTime().asSeconds();

		string stime = to_string(itime);

		text.setString(stime);

		float textWidth = text.getLocalBounds().width;
		float textHeight = text.getLocalBounds().height;

		origin = { textWidth / 2.0f, textHeight / 2.0f };
		coord = { x, y };

		text.setOrigin(origin);
		text.setPosition(coord);
		window.draw(text);
	}	
	//returns text
	//N/A
	sf::Text getText()
	{
		return text;
	}

};

int main()
{
	float width = 300;
	float height = 350;

    sf::RenderWindow window(sf::VideoMode(width, height), "SFML Smiley!");

    GameClock G(window,width,height);
	sf::Text t;
    
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		//prints clock to screen 
		//with movement
		G.printClock(window, width, height );
		window.display();

	}
    return 0;
}
