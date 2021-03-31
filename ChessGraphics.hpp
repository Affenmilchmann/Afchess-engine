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
			sf::Vector2u size = sf::Vector2u(500, 500));
		
		void mainLoop();
		void mouseHandler();
};	