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

bool Piece::moveTo(std::string position, sf::Vector2u window_size, sf::Vector2i mouse_pos) {
    if (this->position == position) 
        return false;

    this->position = position;
    
    int size_x = window_size.x / 8;
    int size_y = window_size.y / 8;

    sprite.setPosition(mouse_pos.x - mouse_pos.x % size_x, mouse_pos.y - mouse_pos.y % size_y);

    return true;
}

void Piece::moveToItsCoords(sf::Vector2u window_size, bool blacks_move) {
    sf::Vector2i own_num_coords = getNumCoords(window_size);
    sprite.setPosition(own_num_coords.x, own_num_coords.y);

    if (!blacks_move)
        flip(window_size);
}

void Piece::flip(sf::Vector2u window_size) {
    sf::Vector2f pos = sprite.getPosition();

    sprite.setPosition(pos.x, (7.f / 8) * window_size.y - pos.y);
}

void Piece::pieceIsBeingMoved(sf::Vector2i position, sf::Vector2u window_size) {
    //window_size.y / 8 is piece size and window_size.y / 16 is half of this size
    sprite.setPosition(
                        position.x - window_size.x / 16, 
                        position.y - window_size.y / 16
                        );
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

sf::Vector2i Piece::getNumCoords(sf::Vector2u window_size) {
    int x = (int)(position[0]) - (int)'a';
    int y = (int)(position[1]) - (int)'1';

    x = window_size.x * x / 8;
    y = window_size.y * y / 8;

    return sf::Vector2i(x, y);
}