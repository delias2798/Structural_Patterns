#include <iostream>
using namespace std;
/* Implementation interface*/
class animalImp{
public:
    string kind;

    animalImp(string _kind){
        kind = _kind;
    }

    virtual void attack(){
        cout << kind<< " attack" << endl;
    }

    virtual void move(){
        cout << kind<< " move" << endl;
    }
};
/*Implementation class*/
class aquaticImp: public animalImp{

public:
    aquaticImp (string _kind): animalImp(_kind){
        kind = _kind;
    }

    void attack(){
        cout << kind<< " attack with a bite in the water" << endl;
    }

    void move(){
        cout << kind<< " swim through the water" << endl;
    }
};
/*Implementation class*/
class overlandImp : public animalImp{

public:
    overlandImp (string _kind): animalImp(_kind){
            kind = _kind;
    }

    void attack(){
        cout << kind<<" attack with the claw at the ground" << endl;
    }

    void move(){
        cout << kind<< " walk through the land" << endl;
    }
};
/* Abstraction interface*/
class animal{

protected:
    animalImp *imp;

public:

    animal(){}

    animal(string _kind){
        imp = new animalImp(_kind);
    }
    virtual void attack(){
        imp->attack();
    }
    virtual void move(){
        imp->move();
    }
};
/*Abstraction class*/
class aquatic: public animal{

public:
    aquatic(string _kind){
        imp = new aquaticImp(_kind);
    }
};
/*Abstraction class*/
class overland : public animal{

public:
    overland(string _kind){
        imp = new overlandImp(_kind);
    }
};

int main() {
    animal *animals[3];
    animals[0] = new animal("Eagle");
    animals[1] = new aquatic("Shark");
    animals[2] = new overland("Wolf");

    for (int i = 0; i < 3; i ++){
        animals[i]->attack();
        animals[i]->move();
    }
    cout << "Example use as reference: https://sourcemaking.com/design_patterns/bridge/cpp/1";
}