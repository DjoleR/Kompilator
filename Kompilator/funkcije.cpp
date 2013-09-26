#include "funkcije.hpp"

extern map<string, DefinicjaFunkcije*> tablicaFunkcija;
extern vector< map<char, int> > stekPromenljivih;

int DefinicjaFunkcije::Izvrsi() 
{
  resetRedni();

  int pom = _blok->Izvrsi();

  stekPromenljivih.pop_back();

  return pom;
}


int IdFunkcija::Izvrsi() 
{
  map<string, DefinicjaFunkcije*>::iterator it = tablicaFunkcija.find(_nazivFje); 
  map<char,int> pomTabla; 

  resetRedni();

  if(_realniParametri != NULL)
    {
      if (it == tablicaFunkcija.end())
	{
	  cerr << "Nepoznata funkcija : " << _nazivFje << "." << endl;
	  exit(1);
	}

      if (it->second->getParametri() == NULL)
	{
	  cerr << "Pogresan broj argumenata funkcije." << endl;
	  exit(1);
	}
      
      if (it->second->getParametri()->size() != _realniParametri->size())
	{
	  cerr << "Pogresan broj argumenata funkcije." << endl;
	  exit(1);
	}
      
      for(unsigned i = 0; i < _realniParametri->size(); i++)
	{
	  
	  int a = (*_realniParametri)[i]->Izracunaj();
	  pomTabla[(*(it->second->getParametri()))[i]] = a;
	}
    }
 

  stekPromenljivih.push_back(pomTabla);

  int pom = it->second->Izvrsi();

  return pom;
}

int IdFunkcija::Izracunaj() 
{
  resetRedni();
  return Izvrsi();
}

int DefinicjaFunkcije::Izracunaj() 
{
  resetRedni();
  return Izvrsi();
}

