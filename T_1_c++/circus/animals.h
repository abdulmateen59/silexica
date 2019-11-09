#include <string>
using namespace std;

class animals{
    public: 
        string name;
        int  age;

    public:
        animals() {}
        ~animals() {}
        animals(string _name ,int _age){
            name = _name;
            age = _age;
        }

        string get_name(){
            return name;
        }

        int get_age(){
            return age;
        }

        virtual bool get_strips() {}

        virtual bool get_rideable() {}
};


class horse : public virtual animals{
    protected: 
        bool rideable = false;

    public:
        horse() : animals() {}
        horse(bool _rideable , string _name , int _age ) : animals(_name,_age){
            rideable = _rideable;
        }

       virtual bool get_rideable(){
            return rideable;
        }

};


class zebra : public virtual animals{
    protected: 
        bool has_strips = false;

    public:
        zebra() : animals() {}
        zebra(bool _has_strips , string _name , int _age ) : animals(_name,_age){
            has_strips = _has_strips;
        }

        virtual bool get_strips(){
            return has_strips;
        }

};


class zebroid : public horse , public zebra{
    public:
        zebroid(): horse() , zebra() {}
        zebroid(bool _rideable , bool _has_strips , string _name , int _age) : horse(_rideable, _name, _age) , zebra(_has_strips, _name, _age) , animals(_name,_age){}
    public:
        bool get_strips() override{
            return has_strips;
        }

        bool get_rideable() override{
            return rideable;
        }
    
};