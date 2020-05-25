#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Mammal {
protected:
    int age; // Age of a mammal
    int size; // Size of a mammal
    bool isHungry; // A mammal can be hungry or not
    string family; // family: like cats or bears
    fstream file;
public:
    // Default constructor
    Mammal(string filename = "tiger.txt") {
        family = "cats";
        file.open(filename);
        if (file.is_open()) {
            file >> age;
            file >> size;
            file >> isHungry;
        }
        else {
            age = 10;
            size = 25;
            isHungry = false;
            family = "tiger";
        }
    }
    // Copy constructor
    Mammal(const Mammal& m) :
        age(m.age), size(m.size), isHungry(m.isHungry), family(m.family) {}
    // Virtual destructor
    virtual ~Mammal() {
        cout << "Calling virtual destructor of Mammal" << endl;
    }
};

class Cats : public Mammal {
protected:
    string colourOfSkin;
    string colourOfEyes;
    string genus; // Genus: Felinae, Pantherinae,Proailurinae

    virtual void run(int speed = 60) {
        cout << "Running. Should be overriden in childs" << endl;
    }

public:
    virtual ~Cats() {
        cout << "Calling virtual destructor of cats" << endl;
    }

    virtual void hunt() {
        cout << "Hunting. Should be overriden in childs" << endl;
        run(40);
    }



    Cats(string filename) :Mammal(filename), genus("cats")
    {
        if (file.is_open()) {
            file >> colourOfSkin;
            file >> colourOfEyes;
        }
        else {
            colourOfSkin = "brown";
            colourOfEyes = "green";
        }
    }

    Cats(const Cats& c) : genus(c.genus), colourOfSkin(c.colourOfSkin), colourOfEyes(c.colourOfEyes),
        Mammal(c) {}
};

class Tiger : public Cats
{
    int fangLength; // length of fangs
    int speed; // Speed of a tiger
    string breed; // Breed of a tiger
    int averageDailyCourse; // Average Daily Course


    // running
    void run(int t_speed) {
        speed = t_speed;
        cout << "The tiger is running. Speed: " << t_speed << endl;
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

    ~Tiger() {
        cout << "Calling tiger's dtor" << endl;
    }

    // Default constructor
    Tiger(string filename = "tiger.txt") : Cats(filename)
    {
        if (file.is_open()) {
            file >> fangLength;
            file >> speed;
            file >> breed;
            file >> averageDailyCourse;
        }
        else {
            fangLength = 10;
            speed = 50;
            breed = "Amur";
            averageDailyCourse = 40;
        }
    }


    // copying constructor
    Tiger(Tiger const& instance) :
        Cats(instance), fangLength(instance.fangLength), speed(instance.speed), breed(instance.breed),
        averageDailyCourse(instance.averageDailyCourse)
    {}
};

// Friendly operator function
ostream& operator<<(ostream& output, const Tiger& T) {
    output << "Breed: " << T.breed << endl;
    output << "Colour of skin: " << T.colourOfSkin << endl;
    output << "Colour of eyes: " << T.colourOfEyes << endl;
    output << "Age: " << T.age << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << "Length of fangs: " << T.fangLength << endl;
    output << "Average daily course: " << T.averageDailyCourse << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}


int main() {
    // Calling default constructor
    Tiger t1;
    // Tiger t2 is a copy of t1
    Tiger t2 = t1;
    // Visualization
    cout << t1 << endl;
    cout << t2;
    // Calling method of the class
    t1.hunt(50);
}