//
// Created by elias on 01/10/18.
//

#include <iostream>

/*
 * First you create a pool
 * Then call a Factory class who make different objects
 * The class Gazillion called by Factory, shared the same object but with
 * different information.
 * Finally when objects of the poll are deleted you access without problem
 * to the information.
 * */

class Gazillion
{
public:
    Gazillion(int value_one)
    {
        m_value_one = value_one;
        std::cout << "ctor: " << m_value_one << '\n';
    }
    ~Gazillion()
    {
        std::cout << m_value_one << ' ';
    }
    void report(int value_two)
    {
        std::cout << m_value_one << value_two << ' ';
    }
private:
    int m_value_one;
};

class Factory
{
public:
    static Gazillion *get_fly(int in)
    {
        if (!s_pool[in])
            s_pool[in] = new Gazillion(in);
        return s_pool[in];
    }
    static void clean_up()
    {
        std::cout << "dtors: ";
        for (int i = 0; i < X; ++i)
            if (s_pool[i])
                delete s_pool[i];
        std::cout << '\n';
    }
    static int X, Y;
private:
    static Gazillion *s_pool[];
};

int Factory::X = 6, Factory::Y = 10;
Gazillion *Factory::s_pool[] =
        {
                0, 0, 0, 0, 0, 0
        };

int main()
{
    for (int i = 0; i < Factory::X; ++i)
    {
        for (int j = 0; j < Factory::Y; ++j)
            Factory::get_fly(i)->report(j);
        std::cout << '\n';
    }
    Factory::clean_up();
}

