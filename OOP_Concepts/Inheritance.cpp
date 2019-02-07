#include<iostream>
using namespace std;

class mother_bird{
public:
    void print (mother_bird a);
    int kind;
protected:
    int share_secret;
private:
    int secret;
};
                                        ///Public Inheritance
class public_birb: public mother_bird{  ///public -> public
public:                                 ///protected -> protected
    birb(){                             ///private -> x
        kind = 2;
        share_secret = 3;
        ///secret = 4;   ///private data of class does not inherit from parent class
    }
};
                                              ///Protected Inheritance
class protected_birb: protected mother_bird{  ///public -> protected
public:                                       ///protected -> protected
    birb(){                                   ///private -> x
        kind = 2;
        share_secret = 3;
    }
};

void print(mother_bird a){
    cout << a.kind << endl;
}


int main(){

    public_birb science;
    protected_birb harro;
    print(science);
    science.kind = 5;
    ///science.share_secret = 3;  /// You can't access protected data outside of classes
    ///science.secret = 3;  cuz "secret" is private duh

    ///harro.kind = 123;   Protected Inheritance will change public to protected
    return 0;
}
