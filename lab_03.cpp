#include <iostream>
using namespace std;

class Area
{
    private:

    float side;
    float length;
    float breadth;
    float radius;

    public:

    Area(float s=1, float l=1, float b=1, float r=1)
    {
        this->side = s;
        this->length = l;
        this->breadth = b;
        this->radius = r;
    }

    friend inline float Square(Area c1);
    friend inline float Rect(Area c1);
    friend inline float Circle(Area c1);
};
class Volume
{
    private:

    float height;

    public:

    Volume(float h = 1)
    {
        this->height = h;
    }

    inline float Cube(Area a1)
    {
        return (this->height * Square(a1));
    }
    inline float Cuboid(Area a1)
    {
        return (this->height * Rect(a1));
    }
    inline float Sphere(Area a1)
    {
        return (this->height * Circle(a1));
    }
    void comp_cube(Area a1, Area a2, Volume h1, Volume h2)
    {
        if(h1.Cube(a1) > h2.Cube(a2))
            cout << "\tCube-1 is greater in volume" << endl;
        else if (h1.Cube(a1) < h2.Cube(a2))
            cout << "\tCube-2 is greater in volume" << endl;
        else
            cout << "\t\tBoth Cubes are equal in volume" << endl;
    }
    void comp_cuboid(Area a1, Area a2, Volume h1, Volume h2)
    {
        if(h1.Cuboid(a1) > h2.Cuboid(a2))
            cout << "\tCuboid-1 is greater in volume" << endl;
        else if (h1.Cuboid(a1) < h2.Cuboid(a2))
            cout << "\tCuboid-2 is greater in volume" << endl;
        else
            cout << "\tBoth Cuboids are equal in volume" << endl;
    }
    void comp_sphere(Area a1, Area a2, Volume h1, Volume h2)
    {
        if(h1.Sphere(a1) > h2.Sphere(a2))
            cout << "\tSphere-1 is greater in volume" << endl;
        else if (h1.Sphere(a1) < h2.Sphere(a2))
            cout << "\tSphere-2 is greater in volume" << endl;
        else
            cout << "\tBoth Spheres are equal in volume" << endl;
    }
};

inline float Square(Area c1)
{
    return (c1.side * c1.side);
}
inline float Rect(Area c1)
{
    return (c1.length * c1.breadth);
}
inline float Circle(Area c1)
{
    return (3.1415f * c1.radius * c1.radius);
}

int main()
{
    int ch=0;

    cout << "1.Area of a Square" << endl;
    cout << "2.Area of a Rectangle" << endl;
    cout << "3.Area of a Circle" << endl;
    cout << "4.Volume of a Cube" << endl;
    cout << "5.Volume of a Cuboid" << endl;
    cout << "6.Volume of a Sphere" << endl;
    cout << "7.Compare Cubes" << endl;
    cout << "8.Compare Cuboids" << endl;
    cout << "9.Compare Spheres" << endl;
    cout << "10.Exit" << endl;

    while(ch != 10)
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1: 
                {   
                    float s;
                    cout << "Enter Side of Square: ";
                    cin >> s;
                    Area a1(s);
                    cout << "\tArea of Square is : " << Square(a1) << endl;
                }
                break;
            case 2:
                {
                    float l,b;
                    cout << "Enter Length and Breadth of Rectangle: ";
                    cin >> l >> b;
                    Area a2(1,l,b);
                    cout << "\tArea of Rectangle is : " << Rect(a2) << endl;
                }
                break;
            case 3:
                {
                    float r;
                    cout << "Enter Radius of the Cicle : ";
                    cin >> r;
                    Area a3(1,1,1,r);
                    cout << "\tArea of Circle is : " << Circle(a3) << endl;
                }
                break;
            case 4:
                {
                    float s;
                    cout << "Enter Side of Cube: ";
                    cin >> s;
                    Area a1(s);
                    Volume v1(s);
                    cout << "\tVolume of cube is : " << v1.Cube(a1) << endl;
                }
                break;
            case 5:
                {
                    float l,b,h;
                    cout << "Enter Lenght, Breadth and Height of Cuboid : ";
                    cin >> l >> b >> h;
                    Area a1(1,l,b);
                    Volume v1(h);
                    cout << "\tVolume of Cuboid is : " << v1.Cuboid(a1) << endl;
                }
                break;
            case 6:
                {
                    float r;
                    cout << "Enter Radius of the Sphere : ";
                    cin >> r;
                    Area a1(1,1,1,r);
                    Volume v1(r);
                    cout << "\tVolume of Sphere is : " << (4/3.0)*v1.Sphere(a1) << endl;
                }
                break;
            case 7:
                {
                    float s1,s2;
                    cout << "Enter Sides of two Cubes : ";
                    cin >> s1 >> s2;
                    Area a1(s1),a2(s2);
                    Volume v1(s1),v2(s2);
                    v1.comp_cube(a1,a2,v1,v2);
                }
                break;
            case 8:
                {
                    float l1,l2,b1,b2,h1,h2;
                    cout << "Enter Lenght, Breadth and Height of Cuboid-1 : ";
                    cin >> l1 >> b1 >> h1;
                    cout << "Enter Lenght, Breadth and Height of Cuboid-2 : ";
                    cin >> l2 >> b2 >> h2;
                    Area a1(1,l1,b1),a2(1,l2,b2);
                    Volume v1(h1),v2(h2);
                    v1.comp_cuboid(a1,a2,v1,v2);
                }
                break;
            case 9:
                {
                    float r1,r2;
                    cout << "Enter Radii of Sphere-1 & Sphere-2 : ";
                    cin >> r1 >> r2;
                    Area a1(1,1,1,r1),a2(1,1,1,r2);
                    Volume v1(r1),v2(r1);
                    v1.comp_sphere(a1,a2,v1,v2);
                }
                break;
            default : cout << "Enter the correct choice!" << endl;
        }
    }

    return 0;
}