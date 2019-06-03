#include "BashyTerminal.h"

	BashyTerminal::BashyTerminal(sf::RenderWindow& window,sf::Texture *terminalTexture,sf::Vector2u imageCount, float switchTime, float speed) : animation(terminalTexture, imageCount, switchTime) {//inicializálás list 

		this->speed = speed;
		row = 0;

		body.setSize(sf::Vector2f(73.0f,47.0f));

		body.setPosition(sf::VideoMode::getDesktopMode().width * 0.5, sf::VideoMode::getDesktopMode().height * 0.5); //középre állítja remélhetőleg minden gépen tesztelni

		body.setTexture(terminalTexture);

	}

	void BashyTerminal::Draw(sf::RenderWindow& window) {
	
		window.draw(body);
	
	}

	void BashyTerminal::Update(float deltaTime) { // sima eazy controll semmi extra
		
		sf::Vector2f movement(0.0f,0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			movement.y -= speed*deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			movement.y += speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			movement.x -= speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			movement.x += speed * deltaTime;
		animation.Update(row,deltaTime);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
	}