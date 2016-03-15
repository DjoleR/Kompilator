#ifndef __FUNKCIJE_HPP__
#define __FUNKCIJE_HPP__

#include "naredba.hpp"
#include "izraz.hpp"


class DefinicjaFunkcije : public Izraz, public Naredba
{
public:
  DefinicjaFunkcije(string _n, vector<char> *_vi , Naredba *_b)
    :  _nazivFje(_n), _parametri(_vi), _blok(_b), _redni(12)
  {}

  DefinicjaFunkcije(const DefinicjaFunkcije *_f)
  :  _nazivFje(_f->_nazivFje), _parametri(_f->_parametri), _blok(_f->_blok), _redni(12)
  {}

  ~DefinicjaFunkcije()
  {
    delete _parametri;
    delete _blok;
  }

  int Izvrsi();
  int Izracunaj();
  int getRedni() const { return _redni; } ;
  inline void setRedni(int a)
  {
    _redni = a;
  }

  string getNaziv()
  {
    return _nazivFje;
  }

  vector<char>* getParametri()
  {
    return new vector<char>(*_parametri);
  }
  inline void resetRedni() { _redni = 12; }
private:
  DefinicjaFunkcije operator=(const DefinicjaFunkcije& _f);
  DefinicjaFunkcije (const DefinicjaFunkcije& _f);

  string _nazivFje;
  vector<char> *_parametri;
  Naredba *_blok;
  int _redni;
};



class IdFunkcija : public Izraz, public Naredba
{
public:
  IdFunkcija(string _n, vector<Izraz*> *_vi)
    : _realniParametri(_vi), _nazivFje(_n), _redni(10)
  {}

  ~IdFunkcija()
  {
    delete _realniParametri;
  }

  int Izvrsi();
  int Izracunaj();
  int getRedni() const { return _redni; } ;

  string getNaziv()
  {
    return _nazivFje;
  }
  inline void setRedni(int a)
  {
    _redni = a;
  }
  inline void resetRedni() { _redni = 10; }
private:
  IdFunkcija operator=(const IdFunkcija& _f);
  IdFunkcija (const IdFunkcija& _f);

  vector<Izraz*> *_realniParametri;
  string _nazivFje;
  int _redni;
};

#endif
