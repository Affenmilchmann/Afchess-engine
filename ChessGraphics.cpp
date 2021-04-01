#include "ChessGraphics.hpp"
#include "iostream"
#include "math.h"

ChessGraphics::ChessGraphics(std::string fen_string, sf::Vector2u size) {
	main_window.create(sf::VideoMode(size.x, size.y), "AfChess");
	main_window.setFramerateLimit(30);

	arrow.loadFromSystem(sf::Cursor::Arrow);
	hand.loadFromSystem(sf::Cursor::Hand);

	mouse_pos_pointer.setRadius(4);
	mouse_pos_pointer.setFillColor(sf::Color::Green);

	chess_board.loadTextures(main_window.getSize());
	chess_board.setPosition(fen_string);
}


void ChessGraphics::mainLoop() {
	sf::Event ev;

	while (main_window.isOpen()) {
		main_window.clear();
		
		mouseHandler();
		chess_board.mainLoop(&main_window, mouse_pos);

		main_window.display();
		while (main_window.pollEvent(ev)) {
			switch (ev.type) {
				case sf::Event::Closed:
					main_window.close();
					break;
				
				case sf::Event::MouseButtonPressed:
					if (ev.mouseButton.button == sf::Mouse::Left) {
						chess_board.leftButtonPressed();
					}
					break;

				case sf::Event::MouseButtonReleased:
					if (ev.mouseButton.button == sf::Mouse::Left) {
						chess_board.leftButtonReleased(mouse_pos);
					}
					break;

				case sf::Event::Resized:
					chess_board.windowResized(sf::Vector2u(ev.size.width, ev.size.height));
					break;

				case  sf::Event::KeyPressed:
					if (ev.key.code == sf::Keyboard::F) {
						chess_board.flip();
					}
					break;
				}
			}	
		}
}	

void ChessGraphics::draw() {
	//chess_board.draw(&main_window);
}

void ChessGraphics::mouseHandler() {
	mouse_pos = sf::Mouse::getPosition(main_window);
	/*mouse_pos_pointer.setPosition(mouse_pos.x - 4, mouse_pos.y - 4);
	main_window.draw(mouse_pos_pointer);*/
	
	if (chess_board.isColliding(mouse_pos, main_window.getSize()))
		main_window.setMouseCursor(hand);
	else
		main_window.setMouseCursor(arrow);
}
