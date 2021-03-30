#include <SFML/Graphics.hpp>
#include <vector>
#include "ChessBoard.hpp"

class ChessGraphics {
    private:
		sf::RenderWindow main_window;

		sf::Cursor arrow;
		sf::Cursor hand;

		sf::CircleShape mouse_pos_pointer;
		sf::Vector2i mouse_pos;

		ChessBoard chess_board;

		void draw();

	public:
		ChessGraphics(
			std::string fen_string = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", 
			int size = 500);
		
		void mainLoop();
		void mouseHandler();
};	