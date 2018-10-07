//
// Created by Josue Chaves on 10/6/18.
//
#include<iostream>
#include<string>


using namespace std;

class   ReproductorNuevo { //El cliente quiere utilizar este Objeto
public:
	virtual void Reproducir() = 0;	//Esta es la función que el cliente desea utilizar
};

class ReproductorAntiguo{ //Este es el reproductor que tenemos.
	string _cancion;
public:
    ReproductorAntiguo(string cancion) :_cancion(cancion){}

	void AntiguoReproducir(int volume)	//Esta es la función que tenemos
	{
		cout << "\nReproduciendo canción: " << _cancion << " a un volumen de :" << volume << "\n";
	}
};

class Adapter : public ReproductorNuevo, private ReproductorAntiguo {

	int _volumen;

public:
	Adapter(string cancion, int volumen) :_volumen(volumen), ReproductorAntiguo(cancion){}
	void Reproducir(){		//Viene de la herencia publica
        AntiguoReproducir(_volumen);	//Viene de la herencia privada
	}
};

int main() {
    ReproductorNuevo* nuevoDisco = new Adapter("Zombie", 75);
	nuevoDisco->Reproducir();
	cout << "\n";               // La llamada a la función de la interfaz es guiada por el adaptador al código heredado
        delete nuevoDisco;
	return 0;
}