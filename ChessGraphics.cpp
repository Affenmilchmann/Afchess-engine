#include "ChessGraphics.hpp"

ChessGraphics::ChessGraphics(int size)
{
	main_window.create(sf::VideoMode(size, size), "AfChess");

	//pieces_img.loadFromFile("img/ChessPiecesArray.png");

	tmp_tt.loadFromFile("img/ChessPiecesArray.png", sf::IntRect(10, 10, 32, 32));
	tmp_s.setTexture(tmp_tt);
}


void ChessGraphics::mainLoop()
{
	sf::Event ev;

	while (main_window.isOpen())
	{
		main_window.display();
		main_window.draw(tmp_s);
		while (main_window.pollEvent(ev))
		{
			switch (ev.type)
			{
				case sf::Event::Closed:
					main_window.close();
					break;
				}
			}	
		}
}	