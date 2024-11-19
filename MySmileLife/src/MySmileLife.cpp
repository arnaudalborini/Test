#include "MySmileLife.hpp"
#include "CarteMSL.hpp"

using MySmileLife::CarteMSL;

CarteMSL*                   MySmileLife::ToCarteMSL(CardGame::Carte* crt)       {return dynamic_cast<CarteMSL*>(crt);}
const CarteMSL*             MySmileLife::ToCarteMSL(const CardGame::Carte* crt) {return dynamic_cast<const CarteMSL*>(crt);}
MySmileLife::_pc_CarteMSL   MySmileLife::ToCarteMSL(CardGame::_pc_Carte crt)    {return dynamic_pointer_cast<const CarteMSL>(crt);}
MySmileLife::_p_CarteMSL    MySmileLife::ToCarteMSL(CardGame::_p_Carte crt)     {return dynamic_pointer_cast<CarteMSL>(crt);}