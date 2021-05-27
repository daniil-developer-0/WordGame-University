#include "wordgame.h"
#include "./ui_wordgame.h"

WordGame::WordGame(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::WordGame)
{
    ui->setupUi(this);
    setTopic(0);

}

WordGame::~WordGame()
{
    delete ui;
}

void WordGame::setTopic(int TopicIndex)
{
    switch (TopicIndex)
    {
    case 0:
        WordGame::dictionary = {
            "бекон", "говядина", "курица",
            "утка", "ветчина", "мясо", "печень",
            "баранина", "куропатка", "птица",
            "сосиска", "филе", "индейка", "телятина",
            "оленина", "треска", "угорь", "окунь", "сельд",
            "скумбрия", "щука", "судак", "камбала", "семга",
            "сардина, форель", "спаржа", "авокадо",
            "фасоль", "бобы", "свекла", "брокколи",
            "капуста", "морковь", "огурец", "баклажан",
            "чеснок", "чечевица", "горох", "помидор",
            "шпинат", "репа", "яблоко", "абрикос", "банан",
            "ягода", "ежевика", "черника", "кешью", "вишня", "виноград",
            "грейпфрут", "лимон", "лайм", "дыня", "апельсин", "персик",
            "арахис", "груша", "ананас", "слива", "малина", "клубника",
            "арбуз", "гречка", "зерно", "рис", "пшеница", "сыр",
            "творог", "сливки", "яйца", "мороженое", "кефир", "молоко",
            "сметана", "йогурт", "булочка", "карамель", "шоколад",
            "корица", "крекер", "кекс", "десерт", "глазурь", "мед", "желе",
            "нуга", "сахар", "ириска", "штрудель", "вафля", "котлета",
            "гуляш", "пицца", "каша", "суп", "стейк"
        };
        break;
    case 1:

        break;
    case 2:

        break;

    default:
        throw "Index of topic not in range of switch!";
        break;
    }
}
int WordGame::getTopic() {
    return WordGame::topic;
}

QString WordGame::getWordByLastCharacter(QChar character) {
    // Проходимся по всем элементам вектора и находим слово на нашу букву. В ином случае возвращаем null
    for (auto i = WordGame::dictionary.begin(); i < WordGame::dictionary.end(); i++) {
        if(i[0][0] == character) {
            QString word = i[0];
            WordGame::dictionary.erase(i);
            return word;
        }
    }
    return NULL;
}

QString WordGame::getWordByLastCharacter(QString word) {
    for (auto i = WordGame::dictionary.begin(); i < WordGame::dictionary.end(); i++) {
        if(i[0][0] == word[0]) {
            QString word = i[0];
            WordGame::dictionary.erase(i);
            return word;
        }
    }
    return NULL;
}

QString WordGame::getRandomWord() {
    int random_index = rand() % WordGame::dictionary.size(); // Получаем случайный индекс из вектора
    QString random_word = WordGame::dictionary[random_index]; // Получаем случайное слово
    WordGame::dictionary.erase(random_index); // Удаляем полученное слово из вектора
    return random_word; // Возвращаем слово
}