#include "ChessGraphics.hpp"
#include "iostream"
#include "math.h"

ChessGraphics::ChessGraphics(std::string fen_string, int size) {
	main_window.create(sf::VideoMode(size, size), "AfChess");

	chess_board.loadTextures(main_window.getSize().x);
	chess_board.setPosition(fen_string, main_window.getSize().x);
}


void ChessGraphics::mainLoop() {
	sf::Event ev;

	while (main_window.isOpen()) {
		main_window.clear();
		
		draw();

		main_window.display();
		while (main_window.pollEvent(ev)) {
			switch (ev.type) {
				case sf::Event::Closed:
					main_window.close();
					break;
				}
			}	
		}
}	

void ChessGraphics::draw() {
	chess_board.draw(&main_window);
}

