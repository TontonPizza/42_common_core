# include <iostream>
#include "colors/display.hpp"
#include "templates/vector.hpp"
#include <ctime>
#include <vector>

void test_fill_constructor()
{
    print("test fill constructor", color_blue); println();
    ft::vector<std::string> vector = ft::vector<std::string>(10, "hello");
    bool assert = vector.size() == 10 && vector[0] == "hello";

    print("\t");
    if (assert)
        print("fill constructor OK", color_green);
    else
        print("fill constructor KO", color_red);
    println();
    vector.clear();
}

void test_default_constructor()
{
    print("test default constructor", color_blue); println();
    ft::vector<int> vector = ft::vector<int>();
    bool assert = vector.size() == 0;

    print("\t");
    if (assert)
        print("default constructor OK", color_green);
    else
        print("default constructor KO", color_red);
    println();
    vector.clear();
}

void test_range_constructor()
{
    print("test range constructor", color_blue); println();

    int array[] = {0,1,2,3,4,5,6,7,8,9};

    ft::vector<int> vector = ft::vector<int>(array, array + 10);

    bool assert = vector.size() == 10 && vector.capacity() == 10;
    for(size_t i = 0; i < vector.size(); i++)
        assert = assert && vector[i] == array[i];

    print("\t");
    if (assert)
        print("range constructor OK", color_green);
    else
        print("range constructor KO", color_red);
    println();
    vector.clear();
}

void test_copy_constructor(bool t = true)
{
    print("test copy constructor", color_blue); println();

    ft::vector<bool> vector = ft::vector<bool>(10, t);
    ft::vector<bool> copy = ft::vector<bool>(vector);

    bool assert = vector == copy;
    assert = assert && vector.size() == copy.size();
    assert = assert && vector.capacity() == copy.capacity();

    print("\t");
    if (assert)
        print("copy constructor OK", color_green);
    else
        print("copy constructor KO", color_red);
    println();

    vector.clear();
    assert = vector != copy;
    print("\t");
    if (assert)
        print("deep copy constructor OK", color_green);
    else
        print("deep copy constructor KO", color_red);
    println();
    copy.clear();
}

void test_iterators(bool t = true)
{
    print("test iterators", color_blue); println();

    int array[] = {0,1,2,3,4,5,6,7,8,9};

    ft::vector<int> vector = ft::vector<int>(array, array + 10);

    ft::vector<int>::iterator it = vector.begin();
    ft::vector<int>::const_iterator end = vector.end();

    size_t i = 0;
    while (it++ != end)
        i++;
    bool assert = t && i == vector.size() && i == 10;

    print("\t");
    if (assert)
    {
        print("iterate begin to end OK", color_green); println(); print("\t");
        print("const iterator compare to iterator OK", color_green);
    }
    else
    {
        print("iterate begin to end KO", color_red); println(); print("\t");
        print("const iterator compare to iterator KO", color_red);
    }
    println();
    vector.clear();
}

void test_reverse_iterators(bool t = true)
{
    print("test reverse iterators", color_blue); println();

    int array[] = {0,1,2,3,4,5,6,7,8,9};

    ft::vector<int> vector = ft::vector<int>(array, array + 10);

    ft::vector<int>::reverse_iterator it = vector.rbegin();
    ft::vector<int>::const_reverse_iterator end = vector.rend();

    bool assert = t && *it > *(it + 1);

    size_t i = 0;
    while (it++ != end)
    {
        i++;
    }
    assert = assert && i == vector.size() && i == 10;


    print("\t");
    if (assert)
    {
        print("iterate rbegin to rend OK", color_green); println(); print("\t");
        print("const reverse iterator compare to reverse iterator OK", color_green);
    }
    else
    {
        print("iterate begin to end KO", color_red); println(); print("\t");
        print("const iterator compare to iterator KO", color_red);
    }
    println();
    vector.clear();
}

void test_capacity(bool t = true)
{
    print("test capacity", color_blue); println();

    ft::vector<bool> vector = ft::vector<bool>(10, true);

    bool assert = t && vector.size() == 10;

    print("\t");
    if (assert)
        print("size OK", color_green);
    else
        print("size KO", color_red);
    println();

    vector.resize(70);
    assert = vector.capacity() >= 70;
    print("\t");
    if (assert)
        print("capacity  after resize up OK", color_green);
    else
        print("capacity after resize up KO", color_red);
    println();

    vector.resize(4);
    assert = vector.size() == 4;
    print("\t");
    if (assert)
        print("size after resize down OK", color_green);
    else
        print("size after resize down KO", color_red);
    println();

    assert = !vector.empty();
    vector.resize(0);
    assert = assert && vector.empty();
    print("\t");
    if (assert)
        print("empty OK", color_green);
    else
        print("empty KO", color_red);
    println();

    vector.reserve(100);
    assert = vector.capacity() >= 100;
    print("\t");
    if (assert)
        print("reserve OK", color_green);
    else
        print("reserve KO", color_red);
    println();

    vector.clear();
}

void test_element_access(bool t = true)
{
    print("test element access", color_blue); println();
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    ft::vector<int> vector = ft::vector<int>(array, array + 10);
    bool assert = t;
    for (size_t i = 0; i < vector.size(); i++)
        assert = assert && vector[i] == array[i];

    print("\t");
    if (assert)
        print("element access [] OK", color_green);
    else
        print("element access [] KO", color_red);
    println();

    assert = true;
    for (size_t i = 0; i < vector.size(); i++)
        assert = assert && vector.at(i) == array[i];

    print("\t");
    if (assert)
        print("element access at OK", color_green);
    else
        print("element access at KO", color_red);
    println();

    assert = true;
    for (int i = 0; i < 3; i++)
    {
        assert = assert && vector.at(0) == array[i];
        vector.erase(vector.begin());
    }

    print("\t");
    if (assert)
        print("element access front OK", color_green);
    else
        print("element access front KO", color_red);
    println();

    assert = true;
    assert = assert && vector.at(vector.size() - 1) == array[9];

    print("\t");
    if (assert)
        print("element access back OK", color_green);
    else
        print("element access back KO", color_red);
    println();

    vector.clear();
}

void test_modifiers(bool t = true)
{
    print("test modifiers", color_blue); println();
    ft::vector<int> vector = ft::vector<int>(100, 1);
    bool assert = t;

    vector.assign(5, -1);
    assert = vector.at(5 - 1) == -1;
    assert = assert && vector.size() == 5;


    print("\t");
    if (assert)
        print("assign OK", color_green);
    else
        print("assign KO", color_red);
    println();
    vector.clear();

    size_t size = vector.size();
    vector.push_back(9);
    assert = vector.size() == size + 1 && vector[size] == 9;
    print("\t");
    if (assert)
        print("pushback OK", color_green);
    else
        print("pushback KO", color_red);
    println();

    size = vector.size();
    vector.pop_back();
    assert = vector.size() == size - 1;
    print("\t");
    if (assert)
        print("pop OK", color_green);
    else
        print("pop KO", color_red);
    println();
    vector.clear();
}

void test_insert(bool t = true)
{
    print("test insert", color_blue); println();
    ft::vector<int> vector = ft::vector<int>(1, 1);
    bool assert = t;

    vector.insert(vector.begin(), 200);
    assert = assert && vector.size() == 2 && vector[0] == 200;

    print("\t");
    if (assert)
        print("insert OK", color_green);
    else
        print("insert OK", color_red);
    println();

    vector.insert(vector.begin(), 3, 300);

    assert = vector.size() == 5 && (vector[0] == vector[1]) && (vector[1] == vector[2]) && (vector[1] == 300);
    print("\t");
    if (assert)
        print("insert fill OK", color_green);
    else
        print("insert fill OK", color_red);
    println();

    ft::vector<int> source = ft::vector<int>(5, 400);
    vector.insert(vector.begin(), source.begin(), source.end());

    assert = vector.size() == 5 + source.size() && vector[0] == 400;
    print("\t");
    if (assert)
        print("insert range OK", color_green);
    else
        print("insert range OK", color_red);
    println();
    vector.clear();
}

void test_erase(bool t = true)
{
    print("test erase", color_blue); println();
    int array[] = {0,1,2,3};
    ft::vector<int> vector = ft::vector<int>(array, array + 4);
    bool assert = t;

    vector.erase(vector.begin() + 1);
    assert = assert && vector[0] == 0 && vector[1] == 2 && vector.size() == 3;

    print("\t");
    if (assert)
        print("erase OK", color_green);
    else
        print("erase KO", color_red);
    println();

    vector.erase(vector.begin(), vector.end() - 1);
    assert = vector.size() == 1 && vector[0] == 3;
    print("\t");
    if (assert)
        print("erase range OK", color_green);
    else
        print("erase range KO", color_red);
    println();
    vector.clear();
}

void test_swap(bool t = true)
{
    print("test swap", color_blue); println();
    ft::vector<int> vector = ft::vector<int>(10, 0);
    ft::vector<int> other = ft::vector<int>(5, 5);
    bool assert = t;

    vector.swap(other);
    ft::vector<int>::iterator first_it = vector.begin() + 2;
    ft::vector<int>::iterator second_it = other.begin() + 2;

    for (int i = 0; i < 5; i++)
        assert = assert && vector[i] == 5;
    for (int i = 0; i < 10; i++)
        assert = assert && other[i] == 0;

    print("\t");
    if (assert)
        print("swap content OK", color_green);
    else
        print("swap content KO", color_red);
    println();

    assert = *(first_it) == 5 && *(first_it + 1) == 5 && *(second_it) == 0 && *(second_it + 1) == 0;
    print("\t");
    if (assert)
        print("swap iterator OK", color_green);
    else
        print("swap iterator KO", color_red);
    println();

    vector.clear();
}

void test_clear(bool t = true)
{
    print("test clear", color_blue); println();
    ft::vector<int> vector = ft::vector<int>(10, 1);
    bool assert = t;

    vector.clear();

    assert = assert && vector.empty();

    print("\t");
    if (assert)
        print("clear OK", color_green);
    else
        print("clear KO", color_red);
    println();
    vector.clear();
}

void test_overload(bool t = true)
{
    print("test overload", color_blue); println();

    int array_1[] = {0,1,2,3};
    int array_2[] = {7,8,9};

    ft::vector<int> v1 = ft::vector<int>(array_1, array_1 + 4);
    ft::vector<int> v2 = ft::vector<int>(array_2, array_2 + 3);

    std::vector<int> s1 = std::vector<int>(array_1, array_1 + 4);
    std::vector<int> s2 = std::vector<int>(array_2, array_2 + 3);

    bool assert = t;

    assert = assert && ((v1 == v2) == (s1 == s2)) && ((v1 > v2) == (s1 > s2)) && ((v1 <= v2) == (s1 <= s2));

    print("\t");
    if (assert)
        print("overload comparison OK", color_green);
    else
        print("overload comparison OK", color_red);
    println();
    v1.clear();
    v2.clear();
    s1.clear();
    s2.clear();
}

void test_efficiency(bool t = true)
{
    print("test efficiency", color_blue); println();

    std::time_t start = std::time(0);
    ft::vector<int> vector = ft::vector<int>(10000, 0);
    for (int i = 0; i < 20000; i++)
    {
        vector.clear();
        vector = ft::vector<int>(10000, 5);
    }
    std::time_t end = std::time(0);
    size_t  ft_time = end - start;

    start = std::time(0);
    std::vector<int> vec = std::vector<int>(10000, 0);
    for (int i = 0; i < 20000; i++)
    {
        vec.clear();
        vec = std::vector<int>(10000, 5);
    }
    end = std::time(0);

    size_t std_time = end - start;

    bool assert = t;

    assert = ft_time <= (std_time + 1) * 20;

    print("\t");
    if (assert)
        print("speed test OK", color_green);
    else
        print("speed test KO", color_red);
    std::cout << " ft : std =  " << ft_time << " : " << std_time;
    println();
    vector.clear();
    vec.clear();
}




int main()
{
    println();
    print("TEST VECTOR", color_yellow);
    println();println();
    test_default_constructor();
    test_fill_constructor();
    test_range_constructor();
    test_copy_constructor();
    test_iterators();
    test_reverse_iterators();
    test_capacity();
    test_element_access();
    test_modifiers();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_overload();
    test_efficiency();
    println();

    return 0;
}

void test_template(bool t = true)
{
    print("test", color_blue); println();
    ft::vector<int> vector = ft::vector<int>();
    bool assert = t;

    print("\t");
    if (assert)
        print("OK", color_green);
    else
        print("KO", color_red);
    println();
    vector.clear();
}