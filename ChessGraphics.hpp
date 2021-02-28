#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "Piece.hpp"

class ChessGraphics {
    private:
		sf::RenderWindow main_window;
		std::vector<Piece> pieces;
		std::map<std::string, sf::Texture*> piece_textures;

		sf::Image pieces_img;
		sf::Texture board_texture;
		sf::Sprite board_sprite;

		bool blacks_move;

		void setPosition(std::string fen_string = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
		void loadTextures();
		void drawPieces();

		void draww(sf::RenderWindow *w);

	public:
		void mainLoop();
		ChessGraphics(int size = 500);
};	