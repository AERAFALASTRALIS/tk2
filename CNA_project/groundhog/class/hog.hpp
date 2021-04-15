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
    std::deque<double> _tempV3;
    std::list<double> temp;
    std::list<double> listcalcul;
    std::list<double> abnormalTemp;
    int _period;
    double _g;
    int _r;
    int _switcheHelper;
    int _switchesCount;
    double _v1;
    double _v2;
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

hog::hog(int period) : _period(period), _g(0), _r(0), _switcheHelper(0), _switchesCount(0), _s(0), _flag(false)
{
}

hog::~hog()
{
}

double hog::getLast()
{
    float back = listcalcul.back();
    return back;
}

void hog::DoMeG()
{
    _g = 0;
    size_t size = geV2Sisze();
    size_t ct = size - _period;
    for (; ct != size ;ct++){
        double tmp = _tempV2[ct] - _tempV2[ct - 1];
        _g += (tmp > 0) ? tmp : 0;
    }
    _g /= _period;
}

void hog::DoMeR()
{
    _switcheHelper = _r;
    _v1 = _tempV2[geV2Sisze() - _period - 1];
    _r = round( ( _tempV2.back() - _v1 ) / _v1 * 100 );
    if ((_switcheHelper > 0 && _r < 0 || _switcheHelper < 0 && _r > 0) && _switcheHelper){
        abnormalTemp.push_back(_v1);
        _flag = true;
    }
}

void hog::DoMeS()
{
    double mean = 0;
    double tmp = 0;
    double x = 0;
    for (size_t i = 7; i != 0; i--){
        tmp = _tempV2.at(geV2Sisze() - i);
        x += tmp;
        mean += pow(tmp, 2);
    }
    _s = sqrt((mean/_period - pow(x/_period, 2)));
}

void hog::removeFront()
{
    temp.pop_front();
    listcalcul.pop_front();
}

void hog::addtmp(double tmp)
{
    temp.push_back(tmp);
}

void hog::addabtmp(double tmp)
{
    abnormalTemp.push_back(tmp);
}

void hog::addlistcalcul(double tmp)
{
    listcalcul.push_back(tmp);
}

int hog::geV2Sisze()
{
    return _tempV2.size();
}

void hog::fillTempV2(double temp)
{
    _tempV2.push_back(temp);
}

void hog::display()
{
    // displaying G
    std::cout << "g=";
    if (_tempV2.size() > _period)
        std::cout << std::setprecision(2) << std::fixed << _g <<'\t';
    else
        std::cout << "nan" << '\t';
    // displaying R

    // on aberation trigger flag
    // std::cout << "r=" << (r ? std::to_string(r) : "nan") << "%\t";
    std::cout << "r=";
    if (_r)
        std::cout << _r << "%\t";
    else
        std::cout << "nan" << "%\t";
    // displaying S

    // std::cout << "s=" << (s ? std::to_string(s) : "nan");
    std::cout << "s=";
    if (_s)
        std::cout << std::setprecision(2) << std::fixed << _s;
    else
        std::cout << "nan";
    // displaying variayion if nedded
    if (_flag) {
        std::cout << "\t a switch occurs";
        _switchesCount++;
        _flag = false;
    }

    //end of the line we flush the string and restart until STOP or crtl+D
    std::cout << std::endl;
}

void hog::printWeird()
{
    std::cout << "Global tendency switched " << _switchesCount << " times" << std::endl;
    std::cout << "5 weirdest values are [";
    int size = abnormalTemp.size();
    int i = 0;
    for (double tmp : abnormalTemp){
        std::cout << tmp;
        if (tmp != abnormalTemp.back())
            std::cout << ", ";
        if (i++ == 5)
            break;
    }
    std::cout << "]" << std::endl;
}

#endif // HOG_HH
