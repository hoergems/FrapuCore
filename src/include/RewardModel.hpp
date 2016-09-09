#ifndef __FRAPU_REWARD_MODEL_HPP__
#define __FRAPU_REWARD_MODEL_HPP__
#include "typedefs.hpp"

namespace frapu
{

class RewardModel
{
public:
    RewardModel() {
	
    }
    
    double illegalMovePenaly = 1.0;
    
    double illegalActionPenalty = 1.0;
    
    double stepPenalty = 1.0;
    
    double exitReward = 1000.0;
    
    double discountFactor = 0.99;

};

}

#endif
