#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <array>
#include <iterator>
#include <string_view>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
enum ChessColor
{
    COLOR_WHITE,
    COLOR_BLACK,
    MAX_COLOR
};
enum ChessType
{
    PAWN_1,
    PAWN_2,
    PAWN_3,
    PAWN_4,
    PAWN_5,
    PAWN_6,
    PAWN_7,
    PAWN_8,
    ROOK_L,
    ROOK_R,
    HORSE_L,
    HORSE_R,
    BISHOP_L,
    BISHOP_R,
    QUEEN,
    KING,
    MAX_TYPE
};
struct ChessPiece
{
    ChessColor color;
    ChessType type;
};
void printPiece(const ChessPiece &chess)
{
    switch (chess.color)
    {
        case COLOR_WHITE: cout << "White "; break;
        case COLOR_BLACK: cout << "Black "; break;
    }
    switch (chess.type)
    {
        case PAWN_1:   cout << "pawn_1"; break;
        case PAWN_2:   cout << "pawn_2"; break;
        case PAWN_3:   cout << "pawn_3"; break;
        case PAWN_4:   cout << "pawn_4"; break;
        case PAWN_5:   cout << "pawn_5"; break;
        case PAWN_6:   cout << "pawn_6"; break;
        case PAWN_7:   cout << "pawn_7"; break;
        case PAWN_8:   cout << "pawn_8"; break;
        case ROOK_L:   cout << "rook_L"; break;
        case ROOK_R:   cout << "rook_R"; break;
        case HORSE_L:  cout << "horse_L"; break;
        case HORSE_R:  cout << "horse_R"; break;
        case BISHOP_L: cout << "bishop_L"; break;
        case BISHOP_R: cout << "bishop_R"; break;
        case QUEEN:    cout << "queen"; break;
        case KING:     cout << "king"; break;
    }
}
void printChess(array<ChessPiece, 32> &chess)
{
    for (const auto &piece : chess)
    {
        printPiece(piece);
        cout << ' ';
    }
    cout << '\n';
}
void swapStruct(ChessPiece &a, ChessPiece &b)
{
    ChessPiece c = a;
    a = b;
    b = c;
}
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void shuffleChess(array<ChessPiece, 32> &chess)
{
    for (int i(0); i < 32; ++i)
    {
        int iSwap = getRandomNumber(0, 31);
        swapStruct(chess[i], chess[iSwap]);
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    array<ChessPiece, 32>chess{};
    int piece{};
    for (int color(0); color < MAX_COLOR; ++color)
    {
        for (int type(0); type < MAX_TYPE; ++type)
        {
            chess[piece].type = static_cast<ChessType>(type);
            chess[piece].color = static_cast<ChessColor>(color);
            ++piece;
        }
    }
    printChess(chess);
    shuffleChess(chess);
    cout << endl;
    printChess(chess);
    _getch();
    return 0;
}
