#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "Piece.hpp"
#include "ChessBoard.hpp"

class ChessGraphics {
    private:
		sf::RenderWindow main_window;

		ChessBoard chess_board;

		void draw();

	public:
		ChessGraphics(
			std::string fen_string = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R", 
			int size = 500);
		
		void mainLoop();
};	