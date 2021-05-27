#ifndef WORDGAME_H
#define WORDGAME_H

#include <QMainWindow>
#include <vector>
#include <stdlib>
#include <time>

QT_BEGIN_NAMESPACE
namespace Ui { class WordGame; }
QT_END_NAMESPACE

class WordGame : public QMainWindow
{
    Q_OBJECT

public:
    WordGame(QWidget *parent = nullptr);
    ~WordGame();

    /**
     * @brief Установка темы. Меняет содержимое `dictionary`
     * 
     * @param TopicIndex Индекс темы
     */
    void setTopic(int TopicIndex);

    /**
     * @brief Геттер для темы
     * 
     * @return int Индекс темы
     */
    int getTopic();

    /**
     * @brief Выбор рандомного слова, которое начинается на  из словаря `dictionary`
     * 
     * @param character Последняя буква исходного слова
     * @return QString Слово
     */
    QString getWordByLastCharacter(QChar character);
    /**
     * @brief Выбор рандомного слова, которое начинается на  из словаря `dictionary`
     * 
     * @param word Исходное слово
     * @return QString Слово
     */
    QString getWordByLastCharacter(QString word);

    /**
     * @brief Геттер для рандомного слова из словаря
     * 
     * @return QString 
     */
    QString getRandomWord();




private:
    Ui::WordGame *ui;

    /**
     * @brief Порядковый номер темы (начиная с 0). По умолчанию - 0.
     * 
     */
    int topic = 0;

    /**
     * @brief Словарь для выбранной темы
     * 
     */
    std::vector<QString> dictionary;

    /**
     * @brief Слово, которое ввёл пользователь
     * 
     */
    QString userWord

    /**
     * @brief Слово, которое выбрал компьютер
     * 
     */
    QString computerWord;
};
#endif // WORDGAME_H
