class Shape{
private:
    double x, y ;// 위치에대한 넓이
public:
    double get_x(){} //
    double get_y(){} //
    void set_x(){} //
    void set_y(){} //

};


class Circle : public Shape{
    //has-a 관계
    private:
        // Shape s;
};