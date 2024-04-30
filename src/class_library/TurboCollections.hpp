#include <string>
#include "iostream"

using namespace std;

namespace TurboCollections {
    class TurboMaths {
    public:
        static vector<int> GetOddNumbers(int maxNumber){}
        static vector<int> GetEvenNumbers(int maxNumber){}

    };


    class Vector3 {
        public:
        float x,y,z;
        Vector3(float x, float y, float z) : x{x}, y{y}, z{z} {}
    };
}