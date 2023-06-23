// Программа Word Jumple
// Классическая игра головоломка, в которой пользователь отгадывает слова с подсказами или без

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasse", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };
    enum difficulty {EASY,HARD,NUM_DIFF_LEVELS};
    cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels. ";
    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD]; // слово, которое нужно угадать
    string theHint = WORDS[choice][HINT]; // подсказка для слова
    // Я генерирую случайный индекс, исходя из количества слов в массиве. Затем беру две переменные, theWord и theHint и записываю 
    //в них соответсвенно слово, расположенное на данной индексной позиции, и сопровождающую его подсказку.
    string jumble = theWord; // копия слова jumble
    int length = jumble.size(); 
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length); 
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index1];
        jumble[index2] = temp;
        cout << "\t\t\tWelcome to Word Jumble!\n\n";
        cout << "Unscrable the letters to make a word.\n";
        cout << "Enter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n\n";
        string guess;
        cout << "\n\nYour guess: ";
        cin >> guess; 
        // Объясняем пользователю, как играть, в частности как выйти из игры и попросить подсказку.
        while ((guess != theWord) && (guess != "quet"))
        {
            if (guess == "hint")
            {
                cout << theHint;
            }
            else 
            {
                cout << "Sorry. That's not it.";
            }
            cout << "\n\nYour guess: ";
            cin >> guess;
        }
        // Данный цикл предлагает отгадать игроку слово, пока пользователь не угадает слово либо решает не выйти из игры
        if (guess == theWord)
        {
            cout << "\nThat's it! You guessed it!\n";
        }
        cout << "\nThanks for you playing.\n";
        return 0;
    }

}


