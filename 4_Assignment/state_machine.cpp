#include "state_machine.h"

void title_directive(string text)
{
    // Walk through the rest of the string
}

void model_directive(string text)
{
    // Walk through the rest of the string
}

void stack_directive(string text)
{
    // Walk through the rest of the string
}

void data_segment(string text)
{
    // Walk through the rest of the string
}

int increment_func(string type)
{
    if (type == "DB")
        return 1;
    if (type == "DW")
        return 2;
    if (type == "DD")
        return 4;
    if (type == "DQ")
        return 8;
}

void add_symbol(string name, string value)
{
    symbol_table[symbol_count][0] = name;
    symbol_table[symbol_count][1] = value;
    
    symbol_count++;
}

string hex_to_hex(string value)
{
    string value1 = value.substr(0, value.size() - 1);
    return value1;    
}

string binary_to_hex(string value)
{
    bitset<8> bs(value);
    unsigned n = bs.to_ulong();
    stringstream ss;
    ss << hex << n;
    string result;
    ss >> result;
    return result;
}

void variable_declaration(string text)
{
    stringstream tokens(text);

    string variable_name, variable_type, value;    
    tokens >> variable_name;
    tokens >> variable_type;
    tokens >> value;
    
    printf("\n%04d", location_counter);
    location_counter = location_counter + increment_func(variable_type);
    
    add_symbol(variable_name, value);
    
    if (value == "?")
    {
        cout << "\t";
        for (int i = 0; i < increment_func(variable_type); i++)
        {
            cout << "00";
        }
    }
    else
    {
        if (value.substr(value.length() - 1) ==  "H")
            value = hex_to_hex(value);
        if (value.substr(value.length() - 1) ==  "B")
            value = binary_to_hex(value);
        cout << "\t" << value;
    }
}

int main(int argc, char **argv)
{
    void (*function_ptr)(string);
    
    table[0].name = "TITLE";
    table[0].function = &title_directive;
    table[0].next = NULL;
    
    table[1].name = ".MODEL";
    table[1].function = &model_directive;
    table[1].next = NULL;
    
    table[2].name = ".STACK";
    table[2].function = &stack_directive;
    table[2].next = NULL;
    
    table[3].name = ".DATA";
    table[3].function = &data_segment;
    table[3].next = NULL;
    
    table[4].name = "variable_declaration";
    table[4].function = &variable_declaration;
    table[4].next = NULL;
    
    ifstream file(argv[1]);
    string line;    
    
    while (getline(file, line))
    {
        stringstream text(line);
        string token;
        
        text >> token;
        
        if (token.at(0) == ';')
        {
            continue;
        }
        
        int directive_flag = 0;
        for (int i = 0; i < 4; i++)
        {
            if (token == table[i].name)
            {
                (*(table[i].function))(line);
                directive_flag = 1;
            }
        }
        
        if (directive_flag == 0)
        {
            (*(table[4].function))(line);
            
        }
    }
    
    cout << endl;
    return 0;
}
