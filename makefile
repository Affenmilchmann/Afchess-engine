CFLAGS=-std=c++17 -c -Wall
DB=-g -c
CC=g++
SFML=-lsfml-graphics -lsfml-window -lsfml-system

run: compile
	./run

debug: dmain.o dChessGraphics.o dChessBoard.o dPiece.o
	g++ dmain.o dChessGraphics.o dChessBoard.o dPiece.o -o dbrun $(SFML)
	gdbgui dbrun

compile: main.o ChessGraphics.o ChessBoard.o Piece.o
	$(CC) main.o ChessGraphics.o ChessBoard.o Piece.o -o run $(SFML)


dmain.o: main.cpp
	$(CC) $(DB) main.cpp -o dmain.o

dChessGraphics.o: ChessGraphics.cpp
	$(CC) $(DB) ChessGraphics.cpp -o dChessGraphics.o

dChessBoard.o: ChessBoard.cpp
	$(CC) $(DB) ChessBoard.cpp -o dChessBoard.o

dPiece.o: Piece.cpp
	$(CC) $(DB) Piece.cpp -o dPiece.o


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

ChessGraphics.o: ChessGraphics.cpp
	$(CC) $(CFLAGS) ChessGraphics.cpp

ChessBoard.o: ChessBoard.cpp
	$(CC) $(CFLAGS) ChessBoard.cpp

Piece.o: Piece.cpp
	$(CC) $(CFLAGS) Piece.cpp


cleanjunk:
	rm -rf *.o
clean:
	rm -rf *.o main
	rm -rf *.d
	rm -f run