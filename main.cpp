#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <deque>


using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//                                 Funktionen                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////

// Spiel sachen
void game();
void drawcharacter();
void food();
void eat();
void setupField();
void drawField();
void makemove();
void snake();

// Menü sachen
void startmenu();
void setup();
void rules();
void shop();
void shop_buy();


////////////////////////////////////////////////////////////////////////////////////////////////
//                                 Variablen                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////

int player_pos_X = 1;
int player_pos_Y = 1;

int snake_length = 1;

int shop_price;
int vbucks = 100;

int score = 0;

const int FIELD_WIDTH = 22;
const int FIELD_HEIGHT = 22;
string field[FIELD_WIDTH][FIELD_HEIGHT];

string food_sym = "🍎";
string player_sym = "🐍";

int main() {
    setup();
    startmenu();
    return 0;
}

void setup() {
    srand(static_cast<unsigned int>(time(0)));
    //SetConsoleTitle("Snake by Maria");
    SetConsoleTitleA("Snake von Maria");
    SetConsoleOutputCP(CP_UTF8);
}

void startmenu() {
    vbucks += score;
    system("cls");
    cout << endl << endl << endl << endl;
    cout << "                                       ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗██╗"<< endl;
    cout << "                                       ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝██║"<< endl;
    cout << "                                       ███████╗██╔██╗ ██║███████║█████╔╝ █████╗  ██║"<< endl;
    cout << "                                       ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝  ╚═╝"<< endl;
    cout << "                                       ███████║██║ ╚████║██║  ██║██║  ██╗███████╗██╗"<< endl;
    cout << "                                       ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝"<< endl;
    cout << endl << endl << endl;
    cout << "                                                    ┌─────────────────┐" << endl;
    cout << "                                                    │   1. Game       │" << endl;
    cout << "                                                    │   2. Rules      │" << endl;
    cout << "                                                    │   3. Shop       │" << endl;
    cout << "                                                    │   4. Exit       │" << endl;
    cout << "                                                    └─────────────────┘" << endl;

    string startmenu_in;

    cin >> startmenu_in;

    if (startmenu_in == "1") {
        game();
    } else if (startmenu_in == "2") {
        rules();
    } else if (startmenu_in == "3") {
        shop();
    } else if (startmenu_in == "4") {
        exit(0);
    } else {
        system("cls");
        cout << "Invalid Input";
        Sleep(3000);
        startmenu();
    }

}

void shop() {
    system("cls");
    cout << endl << endl;
    cout << "                                             ███████╗██╗  ██╗ ██████╗ ██████╗" << endl;
    cout << "                                             ██╔════╝██║  ██║██╔═══██╗██╔══██╗" << endl;
    cout << "                                             ███████╗███████║██║   ██║██████╔╝" << endl;
    cout << "                                             ╚════██║██╔══██║██║   ██║██╔═══╝ " << endl;
    cout << "                                             ███████║██║  ██║╚██████╔╝██║     " << endl;
    cout << "                                             ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     " << endl;
    cout << endl << endl;
    cout << "Your balance: " << vbucks << " VBucks" << endl;
    cout << endl;

    cout << "Legendary" << endl;
    cout << "Type 1: Food: 🍆 | Snake: 🐫(2000 Vbucks)" << endl;
    cout << endl;

    cout << "Epic" << endl;
    cout << "Type 2: Food: 🥒 | Snake: 🐙(1500 Vbucks)" << endl;
    cout << endl;

    cout << "Rare" << endl;
    cout << "Type 3: Food: 🥨 | Snake: 🪱(1200 Vbucks)" << endl;
    cout << endl << endl;

    cout << "Type 4: Back" << endl;
    cout << endl;

    string shop_in;
    cin >> shop_in;

    if (shop_in == "1") {
        shop_price = 4000;
        shop_buy();
        food_sym = "🍆";
        player_sym = "🐫";
        shop();
    } else if (shop_in == "2") {
        shop_price = 800;
        shop_buy();
        food_sym = "🥒";
        player_sym = "🐙";
        shop();
    } else if (shop_in == "3") {
        shop_price = 500;
        shop_buy();
        food_sym = "🥨";
        player_sym = "🪱";
        shop();
    } else if (shop_in == "4") {
        startmenu();
    } else if (shop_in == "v" || shop_in == "V") {
        vbucks += 10000;
        shop();
    } else {
        system("cls");
        cout << "Invalid Input" << endl;
        Sleep(2000);
        shop();
    }
}

void shop_buy() {
    if (vbucks > shop_price) {
        vbucks -= shop_price;
    } else {
        system("cls");
        cout << "Your Balance is to low!" << endl;
        Sleep(2000);
        shop();
    }
}

void rules() {
    system("cls");
    cout << endl << endl;
    cout << "                                        ██████╗ ██╗   ██╗██╗     ███████╗███████╗\n";
    cout << "                                        ██╔══██╗██║   ██║██║     ██╔════╝██╔════╝\n";
    cout << "                                        ██████╔╝██║   ██║██║     █████╗  ███████╗\n";
    cout << "                                        ██╔══██╗██║   ██║██║     ██╔══╝  ╚════██║\n";
    cout << "                                        ██║  ██║╚██████╔╝███████╗███████╗███████║\n";
    cout << "                                        ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝╚══════╝\n";
    cout << endl << endl << endl;
    cout << "           The objective of Snake is to eat as much food as possible to grow in length and score points." << endl << endl;
    cout << "                    The player can press W, A, S and D to move the snake around the game board." << endl << endl;
    cout << "                     When the snake eats apples, it grows longer, and the player earns points." << endl << endl;
    cout << "                The game ends when the snake collides with itself or the boundaries of the game board." << endl << endl;
    cout << endl << endl << endl << endl;

    string rules_in;
    cout << "Type 1. Back" << endl;
    cin >> rules_in;

    if (rules_in == "1") {
        startmenu();
    } else {
        system("cls");
        rules();
    }
}

void game() {
    setupField();
    food();
    snake();

}

const int MAX_SNAKE_LENGTH = 100;

int snake_X[MAX_SNAKE_LENGTH];
int snake_Y[MAX_SNAKE_LENGTH];

void food() {
    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            if (field[x][y] == food_sym) {
                field[x][y] = "  ";
            }
        }
    }


    for (int i = 0; i < 5; i++) {
        int food_pos_1_X = rand() % 20 + 1;
        int food_pos_1_Y = rand() % 20 + 1;

        if (field[food_pos_1_X][food_pos_1_Y] == player_sym) {
            field[food_pos_1_X][food_pos_1_Y] = player_sym;
            food();
        }

        if (field[food_pos_1_X][food_pos_1_Y] == "  " && field[food_pos_1_X][food_pos_1_Y] != player_sym) {
            field[food_pos_1_X][food_pos_1_Y] = food_sym;
        }

    }
}

void setupField() {
    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            if (x == 0 || x == FIELD_WIDTH - 1) {
                field[x][y] = "██";
            } else if (y == 0 || y == FIELD_HEIGHT - 1) {
                field[x][y] = "██";
            } else {
                field[x][y] = "  ";
            }
        }
    }
}

void drawField() {
    system("cls");
    for (int i = 0; i < FIELD_WIDTH; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void snake() {
    bool life = true;
    int snake_length = 1;

    int player_pos_X = 5;
    int player_pos_Y = 5;


    snake_X[0] = player_pos_X;
    snake_Y[0] = player_pos_Y;

    while (life) {
        drawField();

        field[snake_X[snake_length - 1]][snake_Y[snake_length - 1]] = "  ";

        for (int i = snake_length - 1; i > 0; --i) {
            snake_X[i] = snake_X[i - 1];
            snake_Y[i] = snake_Y[i - 1];
        }

        string input;
        cin >> input;

        if (input == "w" || input == "W") {
            player_pos_X--;
        } else if (input == "a" || input == "A") {
            player_pos_Y--;
        } else if (input == "s" || input == "S") {
            player_pos_X++;
        } else if (input == "d" || input == "D") {
            player_pos_Y++;
        } else {
            system("cls");
            snake();
        }

        if (player_pos_X <= 0 || player_pos_Y <= 0 || player_pos_X >= FIELD_HEIGHT - 1 || player_pos_Y >= FIELD_WIDTH - 1) {
            life = false;
            break;
        }

        for (int i = 1; i < snake_length; ++i) {
            if (snake_X[i] == player_pos_X && snake_Y[i] == player_pos_Y) {
                life = false;
                break;
            }
        }

        snake_X[0] = player_pos_X;
        snake_Y[0] = player_pos_Y;

        if (field[player_pos_X][player_pos_Y] == food_sym) {
            snake_length += 1;
            score += 1;
            food();
        }

        field[player_pos_X][player_pos_Y] = player_sym;

        Sleep(100);
    }

    system("cls");
    cout << "verloren nigga" << endl;
    Sleep(2500);
    startmenu();
}