#ifndef __NAREDBA_HPP_
#define __NAREDBA_HPP_

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include "izraz.hpp"

using namespace std;

class Naredba
{
public:
  virtual int Izvrsi() = 0;
  virtual int getRedni() const = 0;
  virtual ~Naredba() {};
  virtual void setRedni(int a) = 0;
  virtual void resetRedni()  = 0;
};


class Blok : public Naredba						      
{									      
public:								      
  Blok(vector<Naredba*> *v)						      
    :_niz(v), _redni(0)
  {}									      
  ~Blok()								      
  {
    for(vector<Naredba*>::iterator i = _niz->begin(); i != _niz->end(); i++) 
      delete (*i);							      
									      
    delete _niz;							      
  }				
  Blok(const Blok& _n)
  :_niz(_n._niz), _redni(0)
  {}
  Blok operator= (const Blok& _n)
  {
    _niz = _n._niz;
    _redni = _n._redni;
    return *this;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 0; }
  
  int Izvrsi() ;	

private:	
  vector<Naredba*> *_niz;
  int _redni;
 									      
};

class IspisiIzraz : public Naredba
{
public:
  IspisiIzraz(Izraz *i)
  :_izraz(i), _redni(1)
  {}
  ~IspisiIzraz()
  {
    delete _izraz;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 1; }
  int Izvrsi() ;
				      
private:
  Izraz* _izraz;
  int _redni;
};

class IspisiString : public Naredba
{
public:
  IspisiString(string s)
  :_string(s), _redni(2)
  {}
  ~IspisiString()
  {}
  inline int getRedni() const
  { 
    return _redni;
  }

  int Izvrsi() 
  {
    if (_string.at(_string.length() - 2) == '\\' &&  _string.at(_string.length() - 1) == 'n')
      cout << _string.substr(0, _string.length()-2) <<  endl;
    else
      cout << _string;

    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 2; }

private:
  string _string;
  int _redni;
};

class DodelaIzraz : public Naredba
{
public:
  DodelaIzraz(char c, Izraz *i)
    :_id(c), _izraz(i), _redni(3)
  {}
  ~DodelaIzraz()
  {
    delete _izraz;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }

  int Izvrsi() ;
  inline void resetRedni() { _redni = 3; }
private:
  char _id;
  Izraz* _izraz;
  int _redni;
};


class UnesiIzraz : public Naredba
{
public:
  UnesiIzraz(char c)
  :_id(c), _redni(4)
  {}
  ~UnesiIzraz(){};
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }

  int Izvrsi() ;
  inline void resetRedni() { _redni = 4; }
private:
  char _id;
  int _redni;
};

class AkoJeOndaIzraz : public Naredba
{
public:
  AkoJeOndaIzraz(Izraz* i, Naredba *n)
    :_izraz(i), _naredba(n), _redni(5)
  {}
  ~AkoJeOndaIzraz()
  {
    delete _naredba;
    delete _izraz;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 5; }
  int Izvrsi() ;

private:
  Izraz *_izraz;
  Naredba *_naredba;
  int _redni;
};

class AkoJeOndaIzrazInace : public Naredba
{
public:
  AkoJeOndaIzrazInace(Izraz* i, Naredba *n1, Naredba *n2)
    :_izraz(i), _naredba1(n1), _naredba2(n2), _redni(6)
  {}
  ~AkoJeOndaIzrazInace()
  {
    delete _naredba1;
    delete _naredba2;
    delete _izraz;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 6; }
  int Izvrsi() ;

private:
  Izraz *_izraz;
  Naredba *_naredba1;
  Naredba *_naredba2;
  int _redni;
};


class DokJeRadiNaredba : public Naredba
{
public:
  DokJeRadiNaredba(Izraz* i, Naredba *n1)
    :_izraz(i), _naredba(n1), _redni(7)
  {}
  ~DokJeRadiNaredba()
  {
    delete _naredba;
    delete _izraz;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 7; }
  int Izvrsi() ;

private:
  Izraz *_izraz;
  Naredba *_naredba;
  int _redni;
};



class PonavljajDokJeNaredba : public Naredba
{
public:
  PonavljajDokJeNaredba(Izraz* i, Naredba *n1)
    :_izraz(i), _naredba(n1), _redni(8)
  {}
  ~PonavljajDokJeNaredba()
  {
    delete _naredba;
    delete _izraz;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 8; }
  int Izvrsi() ;

private:
  Izraz *_izraz;
  Naredba *_naredba;
  int _redni;
};

class ZaNaredba : public Naredba
{
public:
  ZaNaredba(Naredba* inic, Izraz* uslov, Naredba* inic2, Naredba* blok)
    :_inic(inic), _uslov(uslov), _inic2(inic2), _blok(blok), _redni(9)
  {}
  ~ZaNaredba()
  {
    delete _inic;
    delete _uslov;
    delete _inic2;
    delete _blok;
  }
  inline int getRedni() const
  { 
    return _redni;
  }
  int Izvrsi() ;
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 9; }
private:
  Naredba* _inic;
  Izraz* _uslov;
  Naredba* _inic2;
  Naredba* _blok;
  int _redni;
};

class VratiNaredba : public Naredba
{
public:
  VratiNaredba(Izraz* _i)
  :_izraz(_i), _redni(11)
  {}
  ~VratiNaredba()
  {
    delete _izraz;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }

  int Izvrsi()  { return _izraz->Izracunaj(); } ;

  inline int getRedni() const
  { 
    return _redni;
  }
  inline void resetRedni() { _redni = 11; }
private:
  Izraz* _izraz;
  int _redni;
};



#endif
