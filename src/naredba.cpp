#include "naredba.hpp"
#include <map>


extern vector<map<char,int> > stekPromenljivih;


int Blok::Izvrsi() 						     
{									     
   vector<Naredba*>::iterator i = _niz->begin();

   resetRedni();
   
   while( i != _niz->end()) 
     {
       int p;
       if ((*i)->getRedni() != 11)
	 {
	   p = (*i)->Izvrsi();

	   if ((*i)->getRedni() == 11)
	     {
      	       setRedni(11);
	       (*i)->resetRedni();
	       return p;
	     }
	 }
       else 
	 {
	   setRedni(11);
	   return (*i)->Izvrsi();
	 }

       i++;
     }

   return _redni;
}

int IspisiIzraz::Izvrsi() 
{
  cout << _izraz->Izracunaj();
  return _redni;
}


int DodelaIzraz::Izvrsi() 
{
  stekPromenljivih.back()[_id] = _izraz->Izracunaj();
  return _redni;
}

int UnesiIzraz::Izvrsi() 
{
  cin >> stekPromenljivih.back()[_id];
  return _redni;
}

int AkoJeOndaIzraz::Izvrsi() 
{
  resetRedni();

  if (_izraz->Izracunaj())
    {
      if (_naredba->getRedni() == 11)
	  setRedni(11);

      return _naredba->Izvrsi();
    }
  else
    {
      return _redni;
    }
}


int AkoJeOndaIzrazInace::Izvrsi() 
{
  resetRedni();
 
  if (_izraz->Izracunaj())
    {
      if (_naredba1->getRedni() == 11)
	  setRedni(11);

      return _naredba1->Izvrsi();
    }
  else
    {
      if (_naredba2->getRedni() == 11)
	  setRedni(11);

      return _naredba2->Izvrsi();
    }
 
}


int DokJeRadiNaredba::Izvrsi() 
{
  while (_izraz->Izracunaj() != 0)
    _naredba->Izvrsi();

  return _redni;
}

int PonavljajDokJeNaredba::Izvrsi() 
{
    do
      { 
	_naredba->Izvrsi(); 
      }
    while (_izraz->Izracunaj() != 0);

  return _redni;
}

int ZaNaredba::Izvrsi() 
{
  _inic->Izvrsi();
  while(_uslov->Izracunaj())
    {
      _blok->Izvrsi();
      _inic2->Izvrsi();
    }
  
  return _redni;
}
