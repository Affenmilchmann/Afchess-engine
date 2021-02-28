#include "Piece.hpp"

Piece::Piece(std::string type,  sf::Texture *texture, std::string position, bool is_white, int board_size) {
    //setting fields
    this->position = position;
    this->is_white = is_white;
    this->type = type;  

    //setting sprite
    int texture_size = texture->getSize().x;
    int sprite_size = (int)floor((float)board_size / 8);
    float scale_factor = (float)sprite_size / texture_size;

    sprite.setTexture(*texture);
    sprite.setScale(scale_factor, scale_factor);

    //setting sprite coords
    int x = (int)(position[0]) - (int)'a';
    int y = (int)(position[1]) - (int)'1';
    
    sprite.setPosition(x * sprite_size, y * sprite_size);
}

void Piece::draw(sf::RenderWindow *window) {
    window->draw(sprite);
}

std::string Piece::getCharCoords() {
    return position;
}

sf::Vector2i Piece::getNumCoords() {
    int x = (int)(position[0]) - (int)'a';
    int y = (int)(position[1]) - (int)'1';

    return sf::Vector2i(x, y);
}