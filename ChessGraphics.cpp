#include "ChessGraphics.hpp"
#include "iostream"
#include "math.h"

char toUpper(char inp) {
	return (char)(inp - 32);
}

ChessGraphics::ChessGraphics(int size) {
	blacks_move = false;

	main_window.create(sf::VideoMode(size, size), "AfChess");

	loadTextures();
	setPosition();
}


void ChessGraphics::mainLoop() {
	sf::Event ev;

	while (main_window.isOpen()) {
		main_window.clear();
		
		main_window.draw(board_sprite);
		
		drawPieces();

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

void ChessGraphics::drawPieces() {
	for (auto it = pieces.begin(); it != pieces.end(); ++it) {
		it->draw(&main_window);
	}
}

void ChessGraphics::loadTextures() {
	pieces_img.loadFromFile("img/ChessPiecesArray.png");
	board_texture.loadFromFile("img/board_c.png");
	board_sprite.setTexture(board_texture);

	float scale_factor = ((float)main_window.getSize().x / board_texture.getSize().x);

	board_sprite.setScale(scale_factor, scale_factor);

	piece_textures["bQ"] = new sf::Texture();
	piece_textures["bQ"]->loadFromImage(pieces_img, sf::IntRect(0, 0, 60, 60));
	piece_textures["wQ"] = new sf::Texture();
	piece_textures["wQ"]->loadFromImage(pieces_img, sf::IntRect(0, 60, 60, 60));

	piece_textures["bK"] = new sf::Texture();
	piece_textures["bK"]->loadFromImage(pieces_img, sf::IntRect(60, 0, 60, 60));
	piece_textures["wK"] = new sf::Texture();
	piece_textures["wK"]->loadFromImage(pieces_img, sf::IntRect(60, 60, 60, 60));

	piece_textures["bR"] = new sf::Texture();
	piece_textures["bR"]->loadFromImage(pieces_img, sf::IntRect(120, 0, 60, 60));
	piece_textures["wR"] = new sf::Texture();
	piece_textures["wR"]->loadFromImage(pieces_img, sf::IntRect(120, 60, 60, 60));

	piece_textures["bN"] = new sf::Texture();
	piece_textures["bN"]->loadFromImage(pieces_img, sf::IntRect(180, 0, 60, 60));
	piece_textures["wN"] = new sf::Texture();
	piece_textures["wN"]->loadFromImage(pieces_img, sf::IntRect(180, 60, 60, 60));

	piece_textures["bB"] = new sf::Texture();
	piece_textures["bB"]->loadFromImage(pieces_img, sf::IntRect(240, 0, 60, 60));
	piece_textures["wB"] = new sf::Texture();
	piece_textures["wB"]->loadFromImage(pieces_img, sf::IntRect(240, 60, 60, 60));

	piece_textures["bP"] = new sf::Texture();
	piece_textures["bP"]->loadFromImage(pieces_img, sf::IntRect(300, 0, 60, 60));
	piece_textures["wP"] = new sf::Texture();
	piece_textures["wP"]->loadFromImage(pieces_img, sf::IntRect(300, 60, 60, 60));
}

void ChessGraphics::setPosition(std::string fen_string) {
	int curr_row = 0, curr_col = 0;
	int board_size = main_window.getSize().x;
	for (int i = 0; i < (int)fen_string.length(); i++) {
		std::string position = "a1";
		std::string type = "ZZ";

		position[0] = (char)((int)'a' + curr_col);
		position[1] = (char)((int)'1' + curr_row);

		//white pieces
		if (fen_string[i] <= 'Z' and fen_string[i] >= 'A') {
			type[0] = 'w';
			type[1] = fen_string[i];
		}
		//black pieces
		else if (fen_string[i] <= 'z' and fen_string[i] >= 'a') {
			type[0] = 'b';
			type[1] = toUpper(fen_string[i]);
		}
		//skips
		else if (fen_string[i] <= '8' and fen_string[i] >= '1') {
			curr_col += (int)fen_string[i] - (int)'0';
			continue;
		}
		else if (fen_string[i] == '/') {
			curr_row += 1;
			curr_col = 0;
			continue;
		}

		curr_col += 1;

		pieces.push_back(Piece(type, piece_textures[type], position, type[0] == 'w', board_size));
	}
}
