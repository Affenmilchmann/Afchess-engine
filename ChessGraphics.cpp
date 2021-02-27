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
	int x = 0, y = 0;
	int piece_size = (int)round((float)main_window.getSize().x / 8);
	for (auto it = pieces.begin(); it != pieces.end(); ++it) {
		x = (int)(it->position[0]) - (int)'a';
		y = (int)(it->position[1]) - (int)'1';

		//flip if blacks view
		if (blacks_move) {
			y = 7 - y;
		}

		//scaling
		x *= piece_size;
		y *= piece_size;

		it->sprite.setPosition(sf::Vector2f(x, y));
		main_window.draw(it->sprite);
	}
}

void ChessGraphics::loadTextures() {
	pieces_img.loadFromFile("img/ChessPiecesArray.png");
	board_texture.loadFromFile("img/board_c.png");
	board_sprite.setTexture(board_texture);

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


	float scale_factor = ((float)main_window.getSize().x / board_texture.getSize().x);

	board_sprite.setScale(scale_factor, scale_factor);
}

void ChessGraphics::setPosition(std::string fen_string) {
	int curr_row = 0, curr_col = 0;
	int piece_size = (int)floor((float)main_window.getSize().x / 8);
	float piece_scale_factor = 0.0;
	for (int i = 0; i < (int)fen_string.length(); i++) {
		Piece tmp_piece;
		tmp_piece.position = "a1";
		tmp_piece.type = "ZZ";
		tmp_piece.position[0] = (char)((int)'a' + curr_col);
		tmp_piece.position[1] = (char)((int)'1' + curr_row);

		//white pieces
		if (fen_string[i] <= 'Z' and fen_string[i] >= 'A') {
			tmp_piece.type[0] = 'w';
			tmp_piece.type[1] = fen_string[i];
		}
		//black pieces
		else if (fen_string[i] <= 'z' and fen_string[i] >= 'a') {
			tmp_piece.type[0] = 'b';
			// toLower()
			tmp_piece.type[1] = toUpper(fen_string[i]);
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

		tmp_piece.sprite.setTexture(*piece_textures[tmp_piece.type]);
		piece_scale_factor = (float)piece_size / piece_textures[tmp_piece.type]->getSize().x;
		tmp_piece.sprite.setScale(piece_scale_factor, piece_scale_factor);

		pieces.push_back(tmp_piece);
	}
}
