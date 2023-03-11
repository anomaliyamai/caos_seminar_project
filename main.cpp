#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int SQUARE_SIZE = 80;

class Piece {
public:
    enum class Type { None, King, Queen, Rook, Bishop, Knight, Pawn };
    enum class Color { None, White, Black };

    Piece() : type(Type::None), color(Color::None) {}

    Piece(Type type, Color color) : type(type), color(color) {}

    Type getType() const {
        return type;
    }

    Color getColor() const {
        return color;
    }

private:
    Type type;
    Color color;
};

class Board {
public:
    Board();

    void init();

    Piece getPiece(int row, int col) const;

    bool move(int fromRow, int fromCol, int toRow, int toCol);

    bool isCheck() const;

    bool isCheckmate() const;

    bool isStalemate() const;

private:
    std::vector<std::vector<Piece>> squares;
    Piece::Color turn;
    std::vector<sf::Vector2i> legalMoves;
};

class Player {
public:
    Player(Piece::Color color) : color(color) {}

    Piece::Color getColor() const {
        return color;
    }

    virtual sf::Vector2i getMove(const Board& board) = 0;

private:
    Piece::Color color;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(Piece::Color color, sf::RenderWindow& window) : Player(color), window(window) {}

    sf::Vector2i getMove(const Board& board) override;

private:
    sf::RenderWindow& window;
};

class AIPlayer : public Player {
public:
    AIPlayer(Piece::Color color) : Player(color) {}

    sf::Vector2i getMove(const Board& board) override;

private:
    int evaluate(const Board& board) const;

    int evaluateMaterial(const Board& board) const;

    int evaluatePosition(const Board& board) const;
};

class Game {
public:
    Game();

    void run();

private:
    void handleEvents();

    void render();

    void update();

    bool isGameOver() const;

    sf::RenderWindow window;
    Board board;
    std::vector<std::unique_ptr<Player>> players;
    std::vector<sf::RectangleShape> squares;
    sf::RectangleShape highlight;
    bool pieceSelected;
    sf::Vector2i selectedSquare;
};

Board::Board() {
    squares.resize(8, std::vector<Piece>(8));
}

void Board::init() {
    for (int col = 0; col < 8; ++col) {
        squares[1][col] = Piece(Piece::Type::Pawn, Piece::Color::White);
        squares[6][col] = Piece(Piece::Type::Pawn, Piece::Color::Black);
    }

    squares[0][0] = Piece(Piece::Type::Rook, Piece::Color::White);
    squares[0][7] = Piece(Piece::Type::Rook, Piece::Color::White);
    squares[7][0] = Piece(Piece::Type::Rook, Piece::Color::Black);
}