#include "stack.h"

#include<assert.h>

using namespace std;

EmptyStackException EmptyStackEx;
FullStackException FullStackEx;

int main()
{
    stack s;
    
    assert(s.getSize() == 8);
    
    s.push("1");
    s.push("2");
    s.push("3");
    s.push("4");
    s.push("5");
    s.push("6");
    s.push("7");
    s.push("8");

    try
    {
        s.push("5");
    }
    catch (FullStackException& ex)
    {
        cout << ex.what() << " thrown" << endl;
    }

    assert(s.getTop() == "8");

    assert(s.getSize() == 8);
    
    stack s1 = s;
    assert(s1.getSize() == 8);
    
    stack s2(s);
    assert(s2.getSize() == 8);

    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();

    try
    {
        s.pop();
    }
    catch (EmptyStackException& ex)
    {
        cout << ex.what() << " thrown" << endl;
    }

    return 0;
}
