#include <SFML/Graphics.hpp>
#include "math.h"
#include <iostream>

class Piece {
    private:
        sf::Sprite sprite;
        std::string position;

    public:
        Piece(std::string type, sf::Texture *texture, std::string position, bool is_white, int board_size);

        bool is_white;
        //wK wQ wR wB wN wP bK bQ bR bB bN bP
        std::string type;

        void draw(sf::RenderWindow *window);
        bool isColliding(std::string char_coords);
        std::string getCharCoords();
        sf::Vector2i getNumCoords();
};