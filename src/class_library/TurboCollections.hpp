#include <string>
#include "iostream"

using namespace std;

namespace TurboCollections {
    class TurboMaths {
    public:
        static vector<int> GetOddNumbers(int maxNumber){
            vector<int> oddNumbers;
            for(int i = 0; i <= maxNumber; ++i){
                if (i % 2 != 0){
                    oddNumbers.push_back(i);
                }
            }
            return oddNumbers;
        }

        static vector<int> GetEvenNumbers(int maxNumber){
            vector<int> evenNumbers;
            for(int i = 0; i <= maxNumber; ++i){
                if (i % 2 == 0){
                    evenNumbers.push_back(i);
                }
            }
            return evenNumbers;
        }

    };


    class Vector3 {
        public:
        float x,y,z;
        Vector3(float x, float y, float z) : x{x}, y{y}, z{z} {}
    };
}