#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "Piece.hpp"

class ChessBoard {
    private:
		std::vector<Piece> pieces;
		std::map<std::string, sf::Texture*> piece_textures;

        sf::Image pieces_img;
        sf::Texture board_texture;
		sf::Sprite board_sprite;

    public:
        ChessBoard();

        bool blacks_move;

        void draw(sf::RenderWindow *window);
        void loadTextures(float main_window_size);
        void setPosition(std::string fen_string, float main_window_size);

};