#include <SFML/Graphics.hpp>

struct Piece {
	std::string position;
	sf::Texture texture;
};

class ChessGraphics {
    private:
		sf::RenderWindow main_window;
		Piece pieces;
		sf::Image pieces_img;

		Piece tmp_p;
		sf::Texture tmp_tt;
		sf::Sprite tmp_s;

	public:
		void mainLoop();
		ChessGraphics(int size = 500);
};	