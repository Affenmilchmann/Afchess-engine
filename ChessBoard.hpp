#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "Piece.hpp"
#include <iostream>

class ChessBoard {
    private:
		std::vector<Piece> pieces;
		std::map<std::string, sf::Texture*> piece_textures;

        sf::Image pieces_img;
        sf::Texture board_texture;
		sf::Sprite board_sprite;

        sf::Vector2u main_window_size;
        Piece* pointed_piece;

        bool is_left_button_pressed;
        bool blacks_move;
        bool is_flipped;
        bool do_flip_on_move;

        void draw(sf::RenderWindow *window);
        std::string getCharCoords(sf::Vector2i coords, sf::Vector2u window_size);

    public:
        ChessBoard();

        void showStats();

        void mainLoop(sf::RenderWindow *window, sf::Vector2i mouse_pos);

        void loadTextures(sf::Vector2u main_window_size);
        void setPosition(std::string fen_string);
        void windowResized(sf::Vector2u new_size);
        bool isMouseColliding(sf::Vector2i mouse_pos, sf::Vector2u window_size);
        void leftButtonPressed();
        void leftButtonReleased(sf::Vector2i mouse_pos);
        void flip();
        void doFlipOnMove();
};