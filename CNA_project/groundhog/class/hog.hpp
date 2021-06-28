#if !defined(HOG_HH)
#define HOG_HH
#include <iostream>
#include <string>
#include <cstring>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <numeric>

class hog
{
private:
    std::deque<double> _tempV2;
    std::list<double> temp;
    std::list<double> listcalcul;
    std::list<double> abnormalTemp;
    int _period;
    double _g;
    int _r;
    int _switcheHelper;
    int _switchesCount;
    double _s;
    bool _flag;
public:
    hog(int);
    ~hog();
    void fillTempV2(double);
    int geV2Sisze();
    void DoMeG();
    void DoMeR();
    void DoMeS();
    void display();
    void printWeird();
    void addabtmp(double);

    // Trash to delete
    void addtmp(double);
    void addlistcalcul(double);
    void removeFront();
    double getLast();

};

#endif // HOG_HH
