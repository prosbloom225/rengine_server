#include "Attack.h"

Attack::Attack(BaseEntity *defender, double amount){
    this->amount = amount;
    this->defender = defender;
}
void Attack::execute(){
    defender->setHp(defender->getHp() - amount);
    delete this;
}
