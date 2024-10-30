#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <random>
#include <vector>

namespace CardGame{
    template <typename T> void myShuffle(std::vector<T>& lCard){
        std::random_device rd; 
        std::mt19937 g(rd());
        std::shuffle ( lCard.begin(), lCard.end(), g );
    }
}