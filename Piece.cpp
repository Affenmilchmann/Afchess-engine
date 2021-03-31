#include "Piece.hpp"

Piece::Piece(std::string type,  sf::Texture *texture, std::string position, bool is_white, sf::Vector2u board_size) {
    //setting fields
    this->position = position;
    this->is_white = is_white;
    this->type = type;  

    //setting sprite
    int sprite_size_x = (int)floor((float)board_size.x / 8);
    int sprite_size_y = (int)floor((float)board_size.y / 8);

    float scale_factor_x = (float)sprite_size_x / texture->getSize().x;
    float scale_factor_y = (float)sprite_size_y / texture->getSize().y;

    sprite.setTexture(*texture);
    sprite.setScale(scale_factor_x, scale_factor_y);

    //setting sprite coords
    int x = (int)(position[0]) - (int)'a';
    int y = 7 - ((int)(position[1]) - (int)'1');
    
    sprite.setPosition(x * sprite_size_x, y * sprite_size_y);
}

void Piece::windowResized(sf::Vector2u new_size) {
    int sprite_size_x = (int)floor((float)new_size.x / 8);
    int sprite_size_y = (int)floor((float)new_size.y / 8);

    float scale_factor_x = (float)sprite_size_x / sprite.getTexture()->getSize().x;
    float scale_factor_y = (float)sprite_size_y / sprite.getTexture()->getSize().y;

    sprite.setScale(scale_factor_x, scale_factor_y);
}

void Piece::pieceIsBeingMoved(sf::Vector2i position) {
    sprite.setPosition(position.x, position.y);
}

bool Piece::isColliding(std::string char_coords) {
    return char_coords == position;
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