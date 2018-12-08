#pragma once
#include <chrono>
#include <iomanip>
#include <Windows.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>


class Timer : public sf::Sprite 
{
private:
	static constexpr int nFrames = 12;
	static constexpr int xFrames = 3;
	static constexpr int yFrames = 4;
	int hour, minutes, seconds, width, height, x, y;
	static constexpr float holdTime = 1.0f;
	Sprite clock;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iFrame = 0;
	float time = 0.0f;
	void advance()
	{
		if (++iFrame >= nFrames)
		{
			iFrame = 0;
		}
	}

public:
	Timer() = default;
	Timer(int a, int b, int c, int d);
	Timer(int h, int m);
	Timer(int h, int m, int s);
	~Timer();
	void stopwatch();
	void countdown(sf::RenderTarget& window);
	void setTime();
	void setTime(int h, int m);
	void printTime();
	void update(float dt);
};

