#ifndef WORDGAME_H
#define WORDGAME_H

#include <QMainWindow>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include <QApplication>
#include "winorloose.h"
#include "helpdialog.h"
//#include <QRegExp>

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
    void setTopic();

    /**
     * @brief Геттер для темы
     * 
     * @return int Индекс темы
     */
    int getTopic();

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
     * @return QString Рандомное слово
     */
    void getRandomWord();

    void TrimWords();

    // UI
    void getWordFromUserInput();
    void setWordInPCInput();

    // Slots
    void PCMove();
    void Select1topic();
    void Select2topic();
    void Select3topic();
    void showHelp();


private:
    Ui::WordGame *ui;

    WinOrLoose *winDialog;
    HelpDialog *help;

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
    QString userWord;

    /**
     * @brief Слово, которое выбрал компьютер
     * 
     */
    QString computerWord;
};
#endif // WORDGAME_H
