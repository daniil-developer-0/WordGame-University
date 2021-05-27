#include "wordgame.h"
#include "./ui_wordgame.h"
// #include "windialog.h"

WordGame::WordGame(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::WordGame)
{
    ui->setupUi(this);
    setTopic(0);

    help = new HelpDialog(this);
     connect(ui->goButton, &QPushButton::released, this, &WordGame::PCMove);
     connect(ui->helpButton, &QPushButton::released, this, &WordGame::showHelp);
     connect(ui->HelpFunction, &QAction::triggered, this, &WordGame::showHelp);
     connect(ui->FoodTopic, &QAction::triggered, this, &WordGame::Select1topic);
     connect(ui->AnimalsTopic, &QAction::triggered, this, &WordGame::Select2topic);
     connect(ui->CityTopic, &QAction::triggered, this, &WordGame::Select3topic);
     connect(ui->ExitFunction, &QAction::triggered, this, &QApplication::quit);
}

void WordGame::showHelp() {
    help->show();
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
            "гуляш", "пицца", "каша", "суп", "стейк"};
        break;
    case 1:
        WordGame::dictionary = {"авдотка", "агами", "аддакс", "бабуин", "барсук", "белка", "вилорог", "волк", "верблюд",
                                "газель", "гепард", "гиббон", "дельфин", "дикобраз", "дятел", "еж", "енот", "ерш",
                                "жаба", "жираф", "жук", "зебра", "зубр", "заяц", "ирбис", "игуана", "какаду", "кабан",
                                "кальмар", "кошка", "лань", "лев", "леопард", "макака", "муравьед", "манул", "носорог",
                                "нутрия", "носач", "олень", "овцебык", "орел", "омар", "панда", "пекинес", "паук", "росомаха",
                                "рысь", "сокол", "стрекоза", "сурок", "снегирь", "собака", "тюлень", "тигр", "тукан",
                                "тетерев", "утконос", "угорь", "улитка", "утка", "фазан", "форель", "фруктоед", "фламинго",
                                "хамелеон", "хомяк", "хорек", "цапля", "цикада", "чайка", "червь", "чеглок", "черепаха",
                                "шимпанзе", "шиншилла", "шалашник", "щеголь", "эму", "юнко", "ягуар", "як", "ящерица", "ядозуб", "ястреб"};
        break;
    case 2:
        WordGame::dictionary = {
           "абакан", "адлер", "анапа", "архангельск", "бердянск",
            "балашиха", "батуми", "балтимор", "ванкувер", "вашингтон",
            "владивосток", "гагра", "гуйян", "гродно", "гомель", "детройт",
            "днепропетровск", "донецк", "екатеринбург", "ереван", "елец",
            "женева", "житомир", "железногорск", "загреб", "зальцбург",
            "запорожье", "иваново", "иркутск", "ираклион", "йорк", "йена",
            "калуга", "киев", "кливленд", "колумбус", "кострома", "кременчуг",
            "красноярск", "коломбо", "ленинск", "луганск", "ливерпуль", "марбург",
            "марсель", "мехико", "николаев", "новороссийск", "ньюкасл", "овьедо",
            "омск", "орел", "осло", "павловск", "полтава", "покров", "рига",
            "ровно", "рязань", "рим", "судак", "салем", "саванна", "салават",
            "тула", "тамбов", "тверь", "торонто", "токио", "ужгород", "уфа",
            "фрайбург", "флоренция", "хабаровск", "харьков", "хьюстон", "цюрих",
            "цинадо", "чита", "чанчунь", "чебоксары", "шахты", "шанхай", "щучье",
            "щецин", "эдинбург", "энгельс", "юджин", "южноуральск", "ялта", "якутск",
            "ярославль"
        };
        break;

    default:
        throw "Index of topic not in range of switch!";
        break;
    }
    WordGame::getRandomWord();
    WordGame::setWordInPCInput();
}

void WordGame::setTopic() {
     WordGame::setTopic(0);
}
int WordGame::getTopic()
{
    return WordGame::topic;
}

QString WordGame::getWordByLastCharacter(QString word)
{
    for (auto i = WordGame::dictionary.begin(); i < WordGame::dictionary.end(); i++)
    {
        if (i[0][0] == word[word.length() - 1])
        {
            QString word = i[0];
            WordGame::dictionary.erase(i);
            // i.erase();
            return word;
        }
    }
    return "";
}

void WordGame::getRandomWord()
{
    int random_index = rand() % WordGame::dictionary.size();           // Получаем случайный индекс из вектора
    WordGame::computerWord = WordGame::dictionary[random_index];       // Получаем случайное слово
    WordGame::dictionary.erase(dictionary.begin() + random_index - 1); // Удаляем полученное слово из вектора
}

void WordGame::TrimWords()
{
    QString badSymbols = "ъыь";
    if (userWord[userWord.length() - 1] == badSymbols[0] || userWord[userWord.length() - 1] == badSymbols[1] || userWord[userWord.length() - 1] == badSymbols[2])
        userWord.remove(userWord.length() - 1, 1);
    if (computerWord[computerWord.length() - 1] == badSymbols[0] || computerWord[computerWord.length() - 1] == badSymbols[1] || computerWord[computerWord.length() - 1] == badSymbols[2])
        computerWord.remove(computerWord.length() - 1, 1);
}

// UI
void WordGame::getWordFromUserInput()
{
    WordGame::userWord = ui->UserLine->text();
}

void WordGame::setWordInPCInput()
{
    ui->PCLine->setText(WordGame::computerWord);
}

// Slots

void WordGame::PCMove()
{
    WordGame::getWordFromUserInput();
    if (!(WordGame::userWord == ""))
    {
        WordGame::TrimWords();
        if (WordGame::userWord[0] == WordGame::computerWord[computerWord.length() - 1])
        {
            WordGame::computerWord = WordGame::getWordByLastCharacter(WordGame::userWord);
            if (WordGame::computerWord.isEmpty())
            {
                winDialog = new WinOrLoose(this);
                winDialog->show();
            }
            else
            {
                WordGame::setWordInPCInput();
            }
        }
    }
}

void WordGame::Select1topic() {
    setTopic(0);
}
void WordGame::Select2topic() {
    setTopic(1);
}
void WordGame::Select3topic() {
    setTopic(2);
}
