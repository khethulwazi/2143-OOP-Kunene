/**
* Khethulwazi Kunene
* CMPS 2143 - Terry Griffin
* Program 04 - Game of Life
* Date - 10/15/2018
*/

#include "gameOfLife.h"


void init(std::ifstream& infile);
void run(RenderWindow &window, std::ifstream& infile);

int main() {
	std::ifstream infile;
	infile.open("data.txt");


	init(infile);


	return 0;
}

void init(std::ifstream& infile) {

	RenderWindow window(VideoMode(600, 600), "Game of Life");
	Vector2u size = window.getSize();
	//unsigned int width = size.x;
	//unsigned int height = size.x;

	//gameOfLife G(window, rows/*width / CELLSIZE*/, cols/*height / CELLSIZE*/);


	run(window, infile);


}

void run(RenderWindow &window, std::ifstream& infile) {


	gameOfLife G(window);
	int frameRate = 5;											//slower frame rate for visibility
	int frameCount = 0;
	


	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();

		G.resetBoard();
		G.randomlyPopulate();
		G.printBoard();
		

		window.setFramerateLimit(frameRate);					//sets window to desired frame rate
		window.display();



		frameCount++;
	}


}
