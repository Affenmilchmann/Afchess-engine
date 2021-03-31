#include <SFML/Graphics.hpp>
#include "math.h"
#include <iostream>

class Piece {
    private:
        sf::Sprite sprite;
        std::string position;

    public:
        Piece(std::string type, sf::Texture *texture, std::string position, bool is_white, sf::Vector2u board_size);

        bool is_white;
        //wK wQ wR wB wN wP bK bQ bR bB bN bP
        std::string type;

        void draw(sf::RenderWindow *window);

        void windowResized(sf::Vector2u new_size);
        bool isColliding(std::string char_coords);
        void pieceIsBeingMoved(sf::Vector2i position);

        std::string getCharCoords();
        sf::Vector2i getNumCoords();
};