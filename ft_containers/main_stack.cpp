# include <iostream>
#include "colors/display.hpp"
#include "templates/stack.hpp"
#include "templates/vector.hpp"
#include <ctime>
#include <vector>
#include <stack>

void test_constructors(bool t = true)
{
    bool assert = t;

    print("test constructors", color_blue); println();

    ft::stack<int> stack = ft::stack<int>();
    assert = assert && stack.size() == 0;

    print("\t");
    if (assert)
        print("default constructor OK", color_green);
    else
        print("default constructor KO", color_red);
    println();


    ft::stack<int, ft::vector<int> > second;
    assert = second.size() == 0;
    print("\t");
    if (assert)
        print("constructor with container type OK", color_green);
    else
        print("default with container type KO", color_red);
    println();


    ft::vector<int> v = ft::vector<int>(10, 5);
    ft::stack<int, ft::vector<int> > third (v);

    assert = third.size() == v.size();
    print("\t");
    if (assert)
        print("constructor from container OK", color_green);
    else
        print("default from container type KO", color_red);
    println();
}

void test_member_fonctions(bool t = true)
{
    bool assert = t;

    print("test member functions", color_blue); println();
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    ft::vector<int> vector = ft::vector<int>(array, array + 10);
    ft::stack<int> stack = ft::stack<int>();
    ft::stack<int, ft::vector<int> > second (vector);

    assert = assert && stack.empty() && !second.empty();

    print("\t");
    if (assert)
        print("empty OK", color_green);
    else
        print("empty KO", color_red);
    println();

    assert = stack.size() == 0 && second.size() == vector.size();
    print("\t");
    if (assert)
        print("size OK", color_green);
    else
        print("size KO", color_red);
    println();

    assert = second.top() == 9;
    print("\t");
    if (assert)
        print("top OK", color_green);
    else
        print("top KO", color_red);
    println();

    stack.push(999);
    second.push(999);
    assert = stack.top() == 999 && second.top() == 999;
    print("\t");
    if (assert)
        print("push OK", color_green);
    else
        print("push KO", color_red);
    println();

    stack.pop();
    second.pop();
    assert = stack.empty() && second.top() == 9;
    print("\t");
    if (assert)
        print("pop OK", color_green);
    else
        print("pop KO", color_red);
    println();
}

void test_overload(bool t = true)
{
    bool assert = t;

    print("test overload", color_blue); println();
    ft::stack<int> s1 = ft::stack<int>();
    ft::stack<int> s2 = ft::stack<int>();

    std::stack<int> d1 = std::stack<int>();
    std::stack<int> d2 = std::stack<int>();

    s1.push(0); s1.push(2); s1.push(7);
    s2.push(8); s2.push(14); s2.push(20);

    d1.push(0); d1.push(2); d1.push(7);
    d2.push(8); d2.push(14); d2.push(20);

    assert = assert && ((d1 == d1) == (s1 == s1)) && ((d1 == d2) == (s1 == s2));
    assert = assert && ((d1 > d2) == (s1 > s2)) && ((s2 <= s2) == (d2 <= d2));


    print("\t");
    if (assert)
        print("overload comparison OK", color_green);
    else
        print("overload comparison OK", color_red);
    println();
}

void test_iterate()
{
    // doest not compile
    // stack._c.begin();
}

int main()
{
    println();
    print("TEST STACK", color_yellow);
    println();
    println();

    test_constructors();
    test_member_fonctions();
    test_overload();
    println();

    return 0;
}

void test_template(bool t = true)
{
    bool assert = t;

    print("test", color_blue); println();
    ft::stack<int> stack = ft::stack<int>();

    print("\t");
    if (assert)
        print("OK", color_green);
    else
        print("KO", color_red);
    println();
}

