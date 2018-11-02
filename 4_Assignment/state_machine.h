#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <bitset>

using namespace std;

struct state {
    string name;
    void (*function)(string text);
    struct state *next = NULL;
}table[5];

string symbol_table[15][25];

int location_counter = 0;
int symbol_count = 0;
