#pragma once


class Field
{
    int x;
    int y;

    public:
    void set_x(int X)
    {
        this->x = X;
    }
    void set_y(int Y)
    {
        this->y = Y;
    }
    int get_x()const
    {
        return x;
    }
    int get_y()const
    {
        return y;
    }
};