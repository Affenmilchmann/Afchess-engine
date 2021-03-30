#include "ChessBoard.hpp"

ChessBoard::ChessBoard() { blacks_move = false; }

char toUpper(char inp) {
	return (char)(inp - 32);
}

std::string ChessBoard::getCharCoords(sf::Vector2i coords, sf::Vector2u window_size) {
    if (coords.x < 0 || coords.y < 0 || 
        coords.x > window_size.x || coords.y > window_size.y) {
            return "Off";
    }

    char x = 'a' + (8 * coords.x / window_size.x);
    int y = (8 * coords.y / window_size.y);

    if (!blacks_move) {
        y = 8 - y;
    }

    return std::string(1, x) + std::to_string(y);
}

void ChessBoard::mainLoop(sf::RenderWindow *window, sf::Vector2i mouse_pos) {
	if (is_right_button_pressed && pointed_piece != nullptr) {
		pointed_piece->pieceIsBeingMoved(mouse_pos);
	}
	
	draw(window);
}

void ChessBoard::draw(sf::RenderWindow *window) {


    window->draw(board_sprite);
    for (auto it = pieces.begin(); it != pieces.end(); ++it) {
		it->draw(window);
	}
}

void ChessBoard::leftButtonPressed() {
	is_right_button_pressed = true;
}

void ChessBoard::leftButtonReleased() {
	is_right_button_pressed = false;
}

bool ChessBoard::isColliding(sf::Vector2i mouse_pos, sf::Vector2u window_size) {
	if (is_right_button_pressed) 
		return false;

    std::string char_coords = getCharCoords(mouse_pos, window_size);

    for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i].isColliding(char_coords)) {
			if (pointed_piece != &pieces[i]) {
            	pointed_piece = &pieces[i];
				std::cout << "Piece sign: " << pointed_piece->type << "\n";
			}
            return true;
        }
	}

    pointed_piece = nullptr;
    return false;
}

void ChessBoard::setPosition(std::string fen_string, float main_window_size) {
    int curr_row = 7, curr_col = 0;
	int board_size = main_window_size;
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
			curr_row -= 1;
			curr_col = 0;
			continue;
		}

		curr_col += 1;

		pieces.push_back(Piece(type, piece_textures[type], position, type[0] == 'w', board_size));

        std::cout << type << "  " << position << "\n";
	}
}

void ChessBoard::loadTextures(float main_window_size) {
    pieces_img.loadFromFile("img/ChessPiecesArray.png");
	board_texture.loadFromFile("img/board_c.png");
	board_sprite.setTexture(board_texture);

    float scale_factor = (main_window_size / board_texture.getSize().x);

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