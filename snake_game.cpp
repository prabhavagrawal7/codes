#include<deque>
#include<vector>
#include <ncurses.h>

using namespace std;
#define ll int64_t
class Coordinate // iss class ka naam vectors nahi rakh sakta tha kyuki c++ me already implemented hai voh, toh maine coordinates rakh diya hai
{
public:
    int x, y;
    Coordinate(int x, int y) : x(x), y(y) {}
    Coordinate() : x(0), y(0) {}

    Coordinate operator+(const Coordinate &c) // 2 vectors ka sum
    {
        return Coordinate(this->x + c.x, this->y + c.y);
    }
    bool operator==(const Coordinate &c) // 2 vectors ko check krna ho toh uske liye alag function banana padta hai, mujhe bhi abhi pta chala
    {
        return this->x == c.x && this->y == c.y;
    }
};

/*
Jaise jaise saanp food khayega toh uski body ko store krna padega na, vrna pta kaise chalega ki saanp kis kis length pr chala gya hai
abhi usko khud se ladwane vala logic nahi likha hai but voh bhi likha jaa sakta hai
*/
class SnakeGame
{
public:
    deque<Coordinate> food;
    int n, m;
    deque<Coordinate> snake = {Coordinate(0, 0)};
    Coordinate dir = Coordinate(0, 1); // initially right

    void print_game()
    {
        refresh(); 
        vector<vector<char>> game(n, vector<char>(m, '.'));
        game[food.front().x][food.front().y] = 'F'; 
        for (auto &s : snake)
            game[s.x][s.y] = 'S'; // S mtlb saanp ka koi part hai idhar
        for (auto &row : game)
        {
            for (auto &col : row)
            {
                printw("%c ", col);
            }
            printw("\n");
        }
    }
    /* Ye converter hai simply convert kar dega apne coordinates ko, default me maine (0, 0) dal diya hai*/
    Coordinate coordinate_converter()
    {
        printw("Press arrow keys\n");
        int dir = getch();
        switch (dir)
        {
        case KEY_UP:
            return Coordinate(-1, 0);
        case KEY_DOWN:
            return Coordinate(1, 0);
        case KEY_LEFT:
            return Coordinate(0, -1);
        case KEY_RIGHT:
            return Coordinate(0, 1);
        default:
            return Coordinate(0, 0);
        }
    }
    SnakeGame(int n, int m, vector<Coordinate> food)
    {
        this->food.assign(food.begin(), food.end());
        this->n = n;
        this->m = m;
        while (this->food.size())
        {
            clear(); 
            // food ko lene ke baad up down left right input me lena hai
            print_game();
            refresh();
            printw("Use arrow keys to change direction of snake\n");
            auto new_dir = coordinate_converter();
            if (new_dir == Coordinate(0, 0) || new_dir + this->dir == Coordinate(0, 0))
            {
                printw("Invalid direction\n");
                continue;
            }
            Coordinate head = snake.front();
            Coordinate new_head = head + new_dir;
            if (new_head.x < 0 || new_head.x >= n || new_head.y < 0 || new_head.y >= m)
            {
                printw("Game over, you hit the wall\n");
                return;
            }
            if (find(snake.begin(), snake.end(), new_head) != snake.end())
            {
                printw("You hit yourself bro !! Bhai fir se program shuru kar lo toh shi ho jayega\n");
                return;
            }
            snake.push_front(new_head);
            this->dir = new_dir;
            if (new_head.x == this->food.front().x && new_head.y == this->food.front().y)
                this->food.pop_front();
            else
                this->snake.pop_back();
        }
        printw("You won the game !!\n");
    }
};
// int main()
// {
//     // food vagarah yahi pr le lena hai, aur hmm yaad rakhna 0 based indexing hogi isme
//     srand(time(0)); 
//     initscr();            // Initialize ncurses
//     cbreak();             // Disable line buffering
//     noecho();             // Don't display user input
//     keypad(stdscr, TRUE); // Enable special keys like arrow keys

//     int n = 10, m = 10;
//     int food_count = rand() % (n * m);
//     vector<Coordinate> food;
//     for (int i = 0; i < food_count; i++)
//     {
//         Coordinate c = Coordinate(rand() % n, rand() % m);
//         if (find(food.begin(), food.end(), c) == food.end())
//             food.push_back(c); // maintaining the density
//     }
//     SnakeGame game(n, m, food);
//     // sleep for 
//     endwin(); // Cleanup and exit ncurses

//     return 0;
// }
