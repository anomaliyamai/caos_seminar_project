# Игра в шахматы!
**Состав команды:**
- [Афанасьев Олег](https://t.me/afanasevo)
- [Иванов Павел](https://t.me/vladkrytoi)
- [Судаков Илья](https://t.me/sudakovcom)

**Задача**

Жесткие ботари очень любят расслабиться по-ботарьски. Самое лучшее времяпровождение - это размять свои мозги в игре шахматы с другими ботарями! 

**Функционал**

Сто процентов будет графический интерфейс (меню и все остальное). Пользователь будет взаимодействовать с ним с помощью компьютерной мышки (то есть устройство ввода - мышь, устройство вывода - монитор). Будет возможность играть по сети и еще несколько фич по вдохновению авторов (некоторые уже описаны в интерфейсе для пользователя). Сама игра будет представлять из себя классические шахматы по всем канонам.

**Стек технологий**
1) [C++.](https://ru.wikipedia.org/wiki/C%2B%2B)
2) [Simple and Fast Multimedia Library C++ Edition.](https://www.sfml-dev.org/)
3) Возможно другие!!!!!!!

**Крутые способности:**
1) В игру можно будет играть по сети (sfml network).
2) Во время игры пользователи смогут писать текстовые сообщения друг другу и отправлять реакции.
3) Будут так же звуки ходов, важных событий, возможна фоновая музыка.

**Интерфейс для пользователя:**
1) Игроки должны выбрать себе nickname.
2) Игрокам будет предложен цвет, за который они будет играть (возможно будет что-то кроме черного и белого), и в зависимости от выбраных цветов, определяется порядок в котором ходят игроки.
3) Время каждого игрока на обдумывание будет засекаться как в классических шахматах.
4) Чтобы игрок походил определенной фигурой, он должен нажать на нее, после этого будут подсвечены поля, куда она может сходить, на одно из подсвеченных полей должен будет нажать игрок. Если игрок нажмет на неподсвеченную клетку, то игра подскажет, что ход некорректный. Если игрок еще не сходил данной фигурой и передумал ей ходить, то он должен нажать повторно на выбранную фигуру.
5) Игра будет проходить по правилам классических шахмат, в случае достижения пешкой границы, будет предложен обмен пешки на другую фигуру, будут показаны доступные фигуры (картинки), на которую нужно будет нажать. 
6) В случае победы/поражения игрока, на экране будет появляться соответствующее сообщение (картинка).
7) Будут присутствовать примитивные звуки при взаимодействии пользователя с интерфейсом.
8) Также будут доступны некоторые дополнительные режимы (Шашки Mode, Random расположение фигур Mode, Игра с самим собой - и другие по мере вдохновения авторов).

## Распределение задач между участниками

- Иванов Павел: проработка общей архитектуры проекта (представление фигур, игровое поле), алгоритмизация некоторых режимов игры (Random расположение фигур), работа с механикой слона и ладьи, ответственный за библиотеки и идейный вдохновитель использования SFML в проекте, помощь сокомандникам по проекту по SFML из-за уже имеющегося до проекта опыта использования данной библиотеки, подготовка набора картинок по завершении игры (пункт 6) интерфейса).

- Афанасьев Олег: работа с так называемыми корнер-кейсами и правилами игры в шахматы как в действиях фигур, так и в невозможных ситуациях на доске или сигнализация о том что случилось (яркий пример - Пат) или например, проработка того, что в какой-то момент король может сделать рокировку, а в какой-то момент уже нельзя. Работа со временем в партиях. Реализация режима игры с самим собой. Работа с механикой короля и пешки (возможные ходы и те или иные ситуации как взятие пешки на проходе или та же рокировка, шахи).

- Судаков Илья: возможность играть по сети с другими игроками (sfml network) и возможность у них же обмениваться сообщениями или реакциями, работа с механикой ферзя и коня, графическое представление игры: поле, фигуры, подсветка возможных ходов и др., реализация звукового сопровождения (сигнализация о ходе, фоновая музыка, победа/поражение, звуки при взаимодействии с интерфейсом игры, например, нажатие на кнопки в меню), подготовка Шашки mode.

## Контрольная точка 4 (текущий прогресс по проекту)

1) Настройка SFML на компьютерах каждого из участников.
2) Разбор базовых туториалов по библиотеке, например, [тут](https://www.sfml-dev.org/documentation/2.5.1/index.php). Посмотрели процесс компиляции [здесь](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).
3) Углубление в модули SFML и понимания того, что нам нужно. Так, базово нам нужно три вещи, которые уже были озвучены ранее:
   - Мы хотим, чтобы игроки могли играть по сети и обмениваться сообщениями друг с другом - используем модуль [network](https://www.sfml-dev.org/documentation/2.5.1/group__network.php).
   - Хотим, чтобы была фоновая музыка, клики и прочие звуковые сопровождения при взаимодействии с интерфейсом игры - используем [audio](https://www.sfml-dev.org/documentation/2.5.1/group__audio.php).
   - И самое нужное и необходимое для нас это графика, отвечающая за всю суть игры, для этого нам необходим соответствующий модуль [graphics](https://www.sfml-dev.org/documentation/2.5.1/group__graphics.php).
   В настоящий момент мы выбираем нужные нам методы из библиотеки и пытаемся осознать, как имеющуюся документацию приложить к требованиям по интерфейсу для нашей игры.
4) Проработка базовой архитектуры проекта. Для фигур мы будем делать соответствующий класс Figure, где будут изменяющиеся поля для идентификации каждой из фигур (белые/черные, король/пешка/ферзь/..), общие методы (например, когда фигуру срубили), допустимые и невозможные ходы для каждой из фигур (это будет std::vector, куда при каждом ходе мы будем обсчитывать для фигуры, куда ей можно и нельзя), сеттеры/геттеры. Также будет реализован класс для поля Chessboard, где будут массивы размера 16 элементов класса Figure для белых и для черных, будет трекаться ситуация о том произошел мат или нет, чей сейчас ход, будет делаться выбор фигуры для хода и соответствующих изменений на доске в графическом смысле, а также будут сделаны методы для калькуляции ходов и ситуации на доске, то есть как раз будет заполняться std::vector с возможными и невозможными ходами для каждого объекта класса Figure.
