#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "Piece.hpp"
#include <iostream>

class ChessBoard {
    private:
		std::vector<Piece> pieces; //all board pieces are held here
		std::map<std::string, sf::Texture*> piece_textures; //all piece textures are held here

        sf::Image pieces_img; //pieces image. It will be cropped into piece_textures
        sf::Texture board_texture;
		sf::Sprite board_sprite;

        sf::Vector2u main_window_size; //this keeps window size so we dont need to ask it many times
        Piece* pointed_piece; //pointer, that points to piece which is being hovered over by a mouse at the moment

        bool is_left_button_pressed;
        bool blacks_move;
        bool is_flipped; //is board flipped now (is black pieces are on the bottom)
        bool do_flip_on_move; //do autoflip on move on not

        void draw(sf::RenderWindow *window); //for the funcs see cpp files
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