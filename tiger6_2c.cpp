#include <string>
#include <iostream>
#include <fstream>
using namespace std;



class Tiger
{

    class Head {

        class Eye {
            string colour; // colour of an eye
            double diameter; // diameter of an eye
        public:
            Eye(string colour="red", double diameter=0.5) : colour(colour), diameter(diameter) {}
            Eye(const Eye& e) : colour(e.colour), diameter(e.diameter) {}
            friend ostream& operator<<(ostream& output, const Tiger& T);
        };

        class Fang {
            int length; // length of a fang
            bool isDull; // dull or not 
        public:
            friend ostream& operator<<(ostream& output, const Tiger& T);
            Fang(int length=34, bool isDull=false) : length(length), isDull(isDull) {}
            Fang(const Fang& f) : length(f.length), isDull(f.isDull) {}
        };

        double height; // measurements of a head: height
        double width;  // measurements of a head: width
        double depth; // measurements of a head: depth
        int h_degree; // angle of rotation
        Eye* eyes; // eyes are a part of head
        Fang* fangs; // fangs are a part of head
    public:
        // rotating head
        void rotate(int degree) {
            h_degree = degree;
            cout << "The head is rotated at" << h_degree;
        }

    public:
        // Default constructor
        Head(string colourOfEyes= "red", double diameterOfEyes=5.0,
            int lengthOfFangs=10, bool areFangsDull=false,
            double height=54.3, double width=22.4, double depth=54.6) :
            height(height), width(width), depth(depth), h_degree(0) {
            eyes = new Eye[2];
            eyes[0] = Eye(colourOfEyes, diameterOfEyes);
            eyes[1] = Eye(colourOfEyes, diameterOfEyes);
            fangs= new Fang[2];
            fangs[0] = Fang(lengthOfFangs, areFangsDull);
            fangs[1] = Fang(lengthOfFangs, areFangsDull);
        }

        // Copy constructor
        Head(const Head& h):height(h.height), width(h.width), depth(h.depth), h_degree(h.h_degree) {
            eyes = new Eye[2];
            eyes[0] = h.eyes[0];
            eyes[1] = h.eyes[1];
            fangs = new Fang[2];
            fangs[0] = Fang(h.fangs[0]);
            fangs[1] = Fang(h.fangs[1]);
        }
        friend ostream& operator<<(ostream& output, const Tiger& T);
        // Destructor
        ~Head() {
            delete[] fangs;
            delete[] eyes;
        }
    };

    int speed; // Speed of a tiger
    string breed; // Breed of a tiger
    int age; // Age of a mammal
    int size; // Size of a mammal
    bool isHungry; // A mammal can be hungry or not
    string colourOfSkin;
    Head head;


    // running
    void run(int t_speed) {
        speed = t_speed;
        cout << "The tiger is running. Speed: " << t_speed << endl;
        // Call method of inner class
        head.rotate(90);
    }

public:
    // Friendly operator function for output. Definition.
    friend ostream& operator<<(ostream& output, const Tiger& T);
    // hunting
    void hunt(int t_speed = 30) {
        if (!isHungry) cout << "Tiger is not hungry, so he don't hunt" << endl;
        else {
            if (age < 2) cout << "Tiger is hungry, he makes known about it tigress" << endl;
            else {
                cout << "Tiger is hungry, it begins to hunt." << endl;
                run(t_speed);
            }
        }
    }

    // Default constructor
    Tiger(int age=5, int size=9, bool isHungry=false, string colourOfSkin="orange", string colourOfEyes="red", double diameterOfEyes=54.0,
        int lengthOfFangs=34, bool areFangsDull=false,
        double h_height=3.5, double h_width=6.7, double h_depth=5.4, 
        int speed=340, string breed="Bengal") : head(colourOfEyes, diameterOfEyes, lengthOfFangs, areFangsDull, h_height, h_width, h_depth),
    age(age), size(size), speed(speed), breed(breed), isHungry(isHungry), colourOfSkin(colourOfSkin) {}
   


    // copying constructor
    Tiger(Tiger const& instance):age(instance.age), size(instance.size), speed(instance.speed), breed(instance.breed), isHungry(instance.isHungry), colourOfSkin(instance.colourOfSkin),
        head(instance.head)
    {}
};

// Friendly operator function
ostream& operator<<(ostream& output, const Tiger& T) {
    output << "Breed: " << T.breed << endl;
    output << "Colour of skin: " << T.colourOfSkin << endl;
    output << "Colour of eyes: " << T.head.eyes[0].colour << endl;
    output << "Length of fangs: " << T.head.fangs[0].length << endl;
    output << "Age: " << T.age << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}


int main() {
    // Calling default constructor
    Tiger t1(10,15, true,"black", "green");
    // Tiger t2 is a copy of t1
    Tiger t2 = t1;
    // Visualization
    cout << t1 << endl;
    cout << t2;
    // Calling method of the class
    t1.hunt(50);
}