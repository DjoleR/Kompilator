#include "izraz.hpp"

extern map<char, int> tablicaPromenljivih;
extern vector<map<char, int> > stekPromenljivih;
extern void yyerror(string s);

int Saberi::Izracunaj() 
{
  return _levi->Izracunaj() + _desni->Izracunaj();
}

int Oduzmi::Izracunaj() 
{
  return _levi->Izracunaj() - _desni->Izracunaj();
}

int Pomnozi::Izracunaj() 
{
  return _levi->Izracunaj() * _desni->Izracunaj();
}

int Podeli::Izracunaj() 
{
  if (_desni->Izracunaj() != 0)
    return _levi->Izracunaj() / _desni->Izracunaj();
  else
    {
      cerr << "Nedozvoljeno deljenje 0.";
      return EXIT_FAILURE;
    }
}

int UMinus::Izracunaj() 
{
  return -_levi->Izracunaj();
}


int ModOper::Izracunaj() 
{
  return _levi->Izracunaj() % _desni->Izracunaj();
}

int Konstanta::Izracunaj() 
{
  return _vrednost;
}

int IdIzraz::Izracunaj() 
{
  map<char,int>::iterator i = stekPromenljivih.back().find(_id);
  
  if (i != stekPromenljivih.back().end())
    {
      return stekPromenljivih.back()[_id] ;
    }
  else
    {
      string s = (string)&_id;
      yyerror("Niste definisali promenljivu : " + s);
      return 0;
    }
}

int Manje::Izracunaj() 
{
  return _levi->Izracunaj() < _desni->Izracunaj();
}

int Vece::Izracunaj() 
{
  return _levi->Izracunaj() > _desni->Izracunaj();
}

int Jednako::Izracunaj() 
{
  return _levi->Izracunaj() == _desni->Izracunaj();
}

int ManjeJednako::Izracunaj() 
{
  return _levi->Izracunaj() <= _desni->Izracunaj();
}

int VeceJednako::Izracunaj() 
{
  return _levi->Izracunaj() >= _desni->Izracunaj();
}

int Razlicito::Izracunaj() 
{
  return _levi->Izracunaj() != _desni->Izracunaj();
}
