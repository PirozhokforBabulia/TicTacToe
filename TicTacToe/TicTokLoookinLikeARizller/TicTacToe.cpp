// TicTokLoookinLikeARizller.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <string>
void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
bool checkWinner(char* spaces, char computer, char player);
bool checkTie(char* spaces);
using namespace std;
int main()
{
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = '\n';
    std::string check;
    char computer;
    bool IsPlayerCheck = false;
  
    bool running = true;
    do {
        
        std::cout << "choose who you want to play X or O:";
        if (player != '\n')
        cin.clear();

        getline(cin, check);
        player = check[0];
        
        player = toupper(player);
    } while ((player != 'X' && player != 'O') || !(check.length() == 1));
    if (player == 'X')
    {
        drawBoard(spaces);
        computer = 'O';
    }
    else
    {
        computer = 'X';
    }
    
    
    while(running)
    {
        if(IsPlayerCheck || player == 'X')
        {
            playerMove(spaces, player);
            drawBoard(spaces);
        }
        
        if (checkWinner(spaces, computer, player))
        {
            
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            break;
        }
        
        computerMove(spaces, computer);
        IsPlayerCheck = true;
        drawBoard(spaces);
        
        if (checkWinner(spaces, computer, player))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            break;
        }
    }

    std::cout << "Thanks for playing";

}

void drawBoard(char* spaces)
{
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< spaces[0] <<"  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "-----+-----+-----" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "-----+-----+-----" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playerMove(char* spaces, char player)
{
    int number;
    do
    {
        
        
            std::cout << "Type a number where you want to go (1 is a top left 9 is a bottom right):";
            std::cin >> number;
            if (!std::cin.fail() ||number == '\n') {

                number--;

                if (spaces[number] == ' ')
                {
                    spaces[number] = player;
                    break;
                }
            }
            else
            {
                    cin.clear();
                    cin.ignore();
            }
        
       
    } while ((!(number > 0) || !(number < 8) || (spaces[number] != ' ')));
    
}
void computerMove(char* spaces, char computer)
{
    int number;
    srand(time(NULL));
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
                break;
        }
    }
}
bool checkWinner(char* spaces, char computer, char player)
{
    
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {

        spaces[0] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";
        
        
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {

        spaces[3] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";
        

    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {

        spaces[6] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";
       

    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {

        spaces[0] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";
        

    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {

        spaces[1] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";

    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {

        spaces[2] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";

    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {

        spaces[0] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";

    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {

        spaces[2] == player ? std::cout << "YOU WIN\n" : std::cout << "You lose!\n";

    }
    else
    {
        return 0;
    }
    return 1;
}
bool checkTie(char* spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "ITs A TIE\n";
    return true;
}