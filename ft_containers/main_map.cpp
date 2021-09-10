#include "templates/map.hpp"
#include "colors/display.hpp"
#include "templates/pair.hpp"
#include <ctime>
#include <string>
#include <sstream>
# include <iostream>

std::string keys[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
std::string values[] = {"1", "2", "3", "4", "5", "6", "7", "8"};

void test_constructor(bool t = true)
{
    bool assert = t;

    print("test constructors", color_blue); println();
    ft::map<std::string, std::string> first;

    assert = first.empty();

    print("\t");
    if (assert)
        print("default constructor OK", color_green);
    else
        print("default constructor KO", color_red);
    println();

    ft::pair<std::string, std::string> item = ft::make_pair(keys[0], values[0]);
    first.insert(item);
    item = ft::make_pair(keys[1], values[0]);
    first.insert(item);

    ft::map<std::string, std::string> second(first.begin(), first.end());
    assert = second.size() == 2;
    print("\t");
    if (assert)
        print("range constructor OK", color_green);
    else
        print("range constructor KO", color_red);
    println();

    ft::map<std::string, std::string> third(second);

    assert = third.size() == 2;
    print("\t");
    if (assert)
        print("copy constructor OK", color_green);
    else
        print("copy constructor KO", color_red);
    println();
    first.clear();
    second.clear();
    third.clear();
}

void test_iterators(bool t = true)
{
    bool assert = t;

    print("test iterators", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    for(int i = 0; i < 8; i++)
    {
        ft::pair<std::string, std::string> item = ft::make_pair(keys[i], values[7 - i]);
        first.insert(item);
    }

    assert = (first.begin())->first == keys[0];
    assert = assert && (--first.end())->first == keys[7];

    print("\t");
    if (assert)
        print("begin and end OK", color_green);
    else
        print("begin and end KO", color_red);
    println();

    assert = first.rbegin()->first == keys[7];
    assert = assert && (--first.rend())->first == keys[0];
    print("\t");
    if (assert)
        print("reverse begin and end OK", color_green);
    else
        print("reverse begin and end KO", color_red);
    println();
    first.clear();
}

void test_capacity(bool t = true)
{
    bool assert = t;

    print("test capacity", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    assert = first.empty();

    ft::pair<std::string, std::string> item = ft::make_pair(keys[0], values[0]);

    first.insert(item);
    assert = assert && first.size() == 1;


    print("\t");
    if (assert)
    {
        print("empty OK", color_green);    println();    print("\t");
        print("size OK", color_green);

    }
    else
    {
        print("empty KO", color_red);    println();    print("\t");
        print("size KO", color_red);
    }
    println();


    size_t max_size = first.max_size();
    assert = max_size > 0;
    std::stringstream ss;
    ss << max_size;
    print("\t");
    if (assert)
    {
        print("max size OK : ", color_green); print(ss.str(), color_green);
    }
    else
    {
        print("max size KO : ", color_red); print(ss.str(), color_green);
    }

    println();
    first.clear();
}

void test_access_operator(bool t = true)
{
    bool assert = t;

    print("test access operator", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    for(int i = 0; i < 8; i++)
    {
        ft::pair<std::string, std::string> item = ft::make_pair(keys[i], values[i]);
        first.insert(item);
    }

    assert = first[keys[0]] == values[0];
    assert = assert && first[keys[5]] == values[5];

    print("\t");
    if (assert)
        print("access operator [] OK", color_green);
    else
        print("access operator [] KO", color_red);
    println();
    first.clear();
}

void test_modifiers(bool t = true)
{
    bool assert = t;

    print("test modifiers", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    for(int i = 0; i < 8; i++)
    {
        ft::pair<std::string, std::string> item = ft::make_pair(keys[i], values[i]);
        first.insert(item);
    }

    assert = first.size() == 8;

    print("\t");
    if (assert)
        print("insert OK", color_green);
    else
        print("insert KO", color_red);
    println();

    first.erase(first.find(keys[1]));
    assert = first.size() == 7 && first.find(keys[1]) == first.end();
    print("\t");
    if (assert)
        print("erase OK", color_green);
    else
        print("erase KO", color_red);
    println();

    ft::map<std::string, std::string> second;

    first.swap(second);

    assert = first.empty() && second.size() == 7 && second.find(keys[0]) != second.end();
    print("\t");
    if (assert)
        print("swap OK", color_green);
    else
        print("swap KO", color_red);
    println();

    first.clear();
    second.clear();

    assert = first.empty() && second.empty();
    print("\t");
    if (assert)
        print("clear OK", color_green);
    else
        print("clear KO", color_red);
    println();
}

void test_observers(bool t = true)
{
    bool assert = t;

    print("test observers", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    for(int i = 0; i < 8; i++)
    {
        ft::pair<std::string, std::string> item = ft::make_pair(keys[i], values[i]);
        first.insert(item);
    }

    ft::map<std::string, std::string>::key_compare k_c = first.key_comp();

    std::string highest = first.rbegin()->first;
    assert = k_c(first.begin()->first, highest);

    print("\t");
    if (assert)
        print("key compare OK", color_green);
    else
        print("key compare KO", color_red);
    println();

    ft::pair<std::string, std::string> top_it = *(first.rbegin());
    assert = first.value_comp()(*first.begin(), top_it);
    print("\t");
    if (assert)
        print("value compare OK", color_green);
    else
        print("value compare KO", color_red);
    println();
}

void test_operations(bool t = true)
{
    bool assert = t;

    print("test operations", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    for(int i = 1; i < 8; i++)
    {
        ft::pair<std::string, std::string> item = ft::make_pair(keys[i], values[i]);
        first.insert(item);
    }

    ft::pair<std::string, std::string> item = ft::make_pair(keys[0], values[0]);
    first.insert(item);
    item = ft::make_pair(keys[0], values[2]);
    first.insert(item);
    item = ft::make_pair(keys[0], values[3]);
    first.insert(item);


    assert = first.find(keys[0]) != first.end();
    assert = assert && (first.find(values[5]) == first.end());

    print("\t");
    if (assert)
        print("find OK", color_green);
    else
        print("find KO", color_red);
    println();

    assert = first.count(keys[0]) == 1;
    assert = assert && first.count(values[0]) == 0;


    print("\t");
    if (assert)
        print("count OK", color_green);
    else
        print("count KO", color_red);
    println();

    ft::map<std::string, std::string>::iterator f = first.find(keys[5]);

    assert = first.lower_bound(f->first)->first == keys[5];
    assert = assert && first.upper_bound(f->first)->first == keys[6];
    print("\t");
    if (assert)
        print("lower and upper OK", color_green);
    else
        print("lower and upper KO", color_red);
    println();


    ft::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> range = first.equal_range(f->first);
    size_t  count = 0;
    ft::map<std::string, std::string>::iterator it = range.first;
    while(it != range.second)
    {
        it++;
        count++;
    }

    print("\t");
    if (assert)
        print("equal range OK", color_green);
    else
        print("equal range KO", color_red);
    println();

}

void test_allocator(bool t = true)
{
    bool assert = t;

    print("test allocator", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    ft::map<std::string, std::string>::allocator_type alc = first.get_allocator();

    assert = alc.max_size() > 0;

    print("\t");
    if (assert)
        print("get allocator OK", color_green);
    else
        print("get allocator KO", color_red);
    println();
    first.clear();
}

void test_subject_specific(bool t = true)
{
    bool assert = t;

    print("test subject specific", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();

    for(int i = 5; i < 6; i++)
    {
        ft::pair<std::string, std::string> item = ft::make_pair(keys[i], values[i]);
        first.insert(item);
    }

    ft::map<std::string, std::string>::iterator lower = first.lower_bound(keys[5]);
    ft::pair<std::string, std::string> item = ft::make_pair(keys[4], values[4]);
    first.insert(item);
    item = ft::make_pair(keys[6], values[6]);
    first.insert(item);

    assert = lower->first == keys[5] && first.upper_bound(lower->first)->first == keys[6];

    print("\t");
    if (assert)
        print("iterators not changed after insert OK", color_green);
    else
        print("iterators not changed after insert KO", color_red);
    println();

    ft::map<std::string, std::string>::iterator beg = first.begin();
    first.erase(lower);

    assert = beg->first == keys[4];
    print("\t");
    if (assert)
        print("iterators not changed after deletion OK", color_green);
    else
        print("iterators not changed after deletion KO", color_red);
    println();
}

#include <map>
#include <cstdlib>


void test_efficiency(bool t = true)
{
    print("test efficiency", color_blue); println();

    int ft_loop = 50000;

    std::time_t start = std::time(0);
    ft::map<int, int> first;
    for (int i = 0; i < ft_loop; i++)
        first[i] = i;
    for (int i = 0; i < ft_loop; i++)
        first.find(5000);
    std::time_t end = std::time(0);
    size_t  ft_time = end - start;

    start = std::time(0);
    std::map<int, int> second;
    for (int i = 0; i < ft_loop; i++)
        second[i] = i;
    for (int i = 0; i < ft_loop; i++)
        second.find(10000);
    end = std::time(0);

    size_t std_time = end - start;

    bool assert = t;

    assert = ft_time + 20 <= (std_time + 1) * 20;

    print("\t");
    if (assert)
        print("speed test OK", color_green);
    else
        print("speed test KO", color_red);
    std::cout << " ft : std =  " << ft_time << " : " << std_time;
    println();
    first.clear();
    second.clear();
}

int main()
{
    println();
    print("TEST MAP", color_yellow);
    println();println();
    test_constructor();
    test_iterators();
    test_capacity();
    test_access_operator();
    test_modifiers();
    test_observers();
    test_operations();
    test_allocator();
    test_subject_specific();
    test_efficiency();
    return 0;
}

void test_template(bool t = true)
{
    bool assert = t;

    print("test", color_blue); println();
    ft::map<std::string, std::string> first = ft::map<std::string, std::string>();


    print("\t");
    if (assert)
        print("OK", color_green);
    else
        print("KO", color_red);
    println();
    first.clear();
}