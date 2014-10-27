#include "MainBitmapFont.h"


MainBitmapFont::MainBitmapFont()
{
    
}

MainBitmapFont::~MainBitmapFont()
{

}

bool MainBitmapFont::LoadBitmap(const std::string& filename)
{
    BitmapFont::LoadBitmap(filename);
    Initialize();
    return true;
}

void MainBitmapFont::Initialize()
{
    // TODO: (Pavel) this should be configuration

    // numbers
    AddCharacter('0', 591, 29, 30, 42);
    AddCharacter('1', 638, 29, 22, 42);
    AddCharacter('2', 670, 29, 30, 42);
    AddCharacter('3', 715, 29, 30, 42);
    AddCharacter('4', 756, 29, 30, 42);
    AddCharacter('5', 804, 29, 30, 42);
    AddCharacter('6', 846, 29, 30, 42);
    AddCharacter('7', 891, 29, 30, 42);
    AddCharacter('8', 936, 29, 30, 42);
    AddCharacter('9', 981, 29, 30, 42);

    // uppercase letters
    AddCharacter('A', 290, 117, 37, 51);
    AddCharacter('B', 338, 117, 37, 51);
    AddCharacter('C', 387, 117, 37, 51);
    AddCharacter('D', 437, 117, 37, 51);
    AddCharacter('E', 484, 117, 37, 51);
    AddCharacter('F', 527, 117, 30, 51);
    AddCharacter('G', 570, 117, 40, 51);
    AddCharacter('H', 623, 117, 37, 51);
    AddCharacter('I', 671, 117, 15, 51);
    AddCharacter('J', 695, 117, 35, 51);
    AddCharacter('K', 739, 117, 37, 51);
    AddCharacter('L', 788, 117, 35, 51);
    AddCharacter('M', 831, 117, 48, 51);
    AddCharacter('N', 892, 117, 42, 51);
    AddCharacter('O', 939, 117, 42, 51);
    AddCharacter('P', 994, 117, 30, 51);
    AddCharacter('Q', 17, 205, 43, 51);
    AddCharacter('R', 73, 205, 37, 51);
    AddCharacter('S', 123, 205, 32, 51);
    AddCharacter('T', 169, 205, 37, 51);
    AddCharacter('U', 219, 205, 37, 51);
    AddCharacter('V', 266, 205, 37, 51);
    AddCharacter('W', 319, 205, 52, 51);
    AddCharacter('X', 388, 205, 37, 51);
    AddCharacter('Y', 440, 205, 37, 51);
    AddCharacter('Z', 492, 205, 37, 51);

    // lowercase letters
    AddCharacter('a', 758, 205, 27, 43);
    AddCharacter('b', 802, 205, 27, 43);
    AddCharacter('c', 847, 205, 27, 43);
    AddCharacter('d', 890, 205, 27, 43);
    AddCharacter('e', 935, 205, 27, 43);
    AddCharacter('f', 981, 205, 20, 43);
    AddCharacter('g', 17, 289, 27, 55);
    AddCharacter('h', 62, 290, 27, 55);
    AddCharacter('i', 107, 290, 12, 55);
    AddCharacter('j', 134, 290, 27, 55);
    AddCharacter('k', 169, 290, 27, 55);
    AddCharacter('l', 214, 290, 12, 55);
    AddCharacter('m', 240, 290, 45, 55);
    AddCharacter('n', 301, 290, 27, 55);
    AddCharacter('o', 345, 290, 30, 55);
    AddCharacter('p', 391, 290, 30, 55);
    AddCharacter('q', 436, 290, 30, 55);
    AddCharacter('r', 482, 290, 22, 55);
    AddCharacter('s', 518, 290, 27, 55);
    AddCharacter('t', 556, 290, 27, 55);
    AddCharacter('u', 593, 290, 27, 55);
    AddCharacter('v', 638, 290, 30, 55);
    AddCharacter('w', 685, 290, 45, 55);
    AddCharacter('x', 748, 290, 30, 55);
    AddCharacter('y', 796, 290, 30, 55);
    AddCharacter('z', 845, 290, 27, 55);
}
