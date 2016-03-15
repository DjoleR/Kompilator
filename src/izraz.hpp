#ifndef __IZRAZ_HPP__
#define __IZRAZ_HPP__
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>


using namespace std;

extern vector<map<char,int> > stekPromenljivih;

class Izraz
{
public:
  virtual int Izracunaj()  = 0;
  virtual ~Izraz(){};
};

class Saberi: public Izraz
{
public:
  Saberi(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Saberi()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Saberi operator=(const Saberi a);
  Saberi(const Saberi& a);
  Izraz *_levi, *_desni;
};

class Oduzmi: public Izraz
{
public:
  Oduzmi(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Oduzmi()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Izraz *_levi, *_desni;
};

class Pomnozi: public Izraz
{
public:
  Pomnozi(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Pomnozi()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Izraz *_levi, *_desni;
};

class Podeli: public Izraz
{
public:
  Podeli(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Podeli()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Izraz *_levi, *_desni;
};

class UMinus: public Izraz
{
public:
  UMinus(Izraz *levi)
    :_levi(levi)
  {}
  ~UMinus()
  {
    delete _levi;
  }
  int Izracunaj() ;

private:
  Izraz *_levi;
};


class ModOper: public Izraz
{
public:
  ModOper(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~ModOper()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Izraz *_levi, *_desni;
};

class Konstanta : public Izraz
{
public:
  Konstanta(int a)
    :_vrednost(a)
  {}
  ~Konstanta() 
  {}
  int Izracunaj() ;

private:
  Konstanta operator=(Konstanta& a);
  Konstanta(Konstanta& a);
  int _vrednost;
};

class IdIzraz : public Izraz
{
public:
  IdIzraz(char c)
    :_id(c)
  {}
  ~IdIzraz() 
  {}
  int Izracunaj() ;

private:
  IdIzraz operator=(IdIzraz& a);
  IdIzraz(IdIzraz& a);
  char _id;
  int _vrednost;
};

class Manje: public Izraz
{
public:
  Manje(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Manje()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Manje operator=(const Manje a);
  Manje(const Manje& a);
  Izraz *_levi, *_desni;
};

class Vece: public Izraz
{
public:
  Vece(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Vece()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Vece operator=(const Vece a);
  Vece(const Vece& a);
  Izraz *_levi, *_desni;
};

class Jednako: public Izraz
{
public:
  Jednako(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Jednako()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Jednako operator=(const Jednako a);
  Jednako(const Jednako& a);
  Izraz *_levi, *_desni;
};

class ManjeJednako: public Izraz
{
public:
  ManjeJednako(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~ManjeJednako()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  ManjeJednako operator=(const ManjeJednako a);
  ManjeJednako(const ManjeJednako& a);
  Izraz *_levi, *_desni;
};

class VeceJednako: public Izraz
{
public:
  VeceJednako(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~VeceJednako()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  VeceJednako operator=(const VeceJednako a);
  VeceJednako(const VeceJednako& a);
  Izraz *_levi, *_desni;
};

class Razlicito: public Izraz
{
public:
  Razlicito(Izraz *levi, Izraz *desni)
    :_levi(levi), _desni(desni)
  {}
  ~Razlicito()
  {
    delete _levi;
    delete _desni;
  }
  int Izracunaj() ;

private:
  Razlicito operator=(const Razlicito a);
  Razlicito(const Razlicito& a);
  Izraz *_levi, *_desni;
};



#endif
