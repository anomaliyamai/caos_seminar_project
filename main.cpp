#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно размером 800x800 пикселей
    sf::RenderWindow window(sf::VideoMode(800, 800), "Desk");

    // Создаем белую и черную клетки
    sf::RectangleShape whiteSquare(sf::Vector2f(100, 100));
    whiteSquare.setFillColor(sf::Color::White);

    sf::RectangleShape blackSquare(sf::Vector2f(100, 100));
    blackSquare.setFillColor(sf::Color::Black);

    // Отображаем шахматную доску
    while (window.isOpen()) {
        // Очищаем экран
        window.clear();

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                // Определяем цвет клетки
                if ((i + j) % 2 == 0) {
                    whiteSquare.setPosition(i * 100, j * 100);
                    window.draw(whiteSquare);
                } else {
                    blackSquare.setPosition(i * 100, j * 100);
                    window.draw(blackSquare);
                }
            }
        }

        // Отображаем новое изображение на экране
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
