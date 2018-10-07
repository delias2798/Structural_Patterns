//
// Created by Josue Chaves on 10/6/18.
//

#include "iostream"
/**
 * Iamginemos que tenemos un carro, el mismo carro nos provee a nosotros una interfaz para poder utilizarlo
 * en este caso nuestra interfaz va a ser un facade que va a conectar las clase necesarias para utilizar
 * nuetsro carro de una manera sencilla.
 */

class Motor{ //Acá esta el motor, puede encenderse o apagarse.
private:
    bool isOn;
public:
    Motor(){
        isOn = false;
    }

    void encender(){
        isOn = true;
        std::cout<< "Motor Encendido" << std::endl;
    }
    void apagar(){
        isOn = false;
        std::cout<< "Motor Encendido" << std::endl;
    }
};

class CajaMarchas { //La caja de marchas, que nos permite cambiar las marchas de carro.
private:
    int marcha;
public:

    CajaMarchas() {
      marcha = 0;
    }

    void cambiarMarcha(int pMarcha) {
        if (-1 <= pMarcha && pMarcha <= 5) {
            marcha += pMarcha;
            std::cout << imprimirMarcha() << std::endl;
        } else if (pMarcha == 10) {
            marcha = 0;
            std::cout << imprimirMarcha() << std::endl;
        } else if (pMarcha == 11) {
            marcha = -1;
            std::cout << imprimirMarcha() << std::endl;
        } else {
            std::cout << imprimirMarcha() << std::endl;
        }
    }

    std::string imprimirMarcha() {
        if (marcha == 0) {
            return " Su auto está en neutro. ";
        } else if (marcha == -1) {
            return "Su auto está en reversa.";
        } else {
            return "Su auto está en " + std::to_string(marcha);
        }
    }
};

class CarroFacade{  // Acá se encuentra nuestro carro, onecta todas las clases, y nos da los metodos necesarios
                    //para poder utilizarlo.
private:
    Motor *motor = new Motor();   //Creamos el Motor
    CajaMarchas *cajaMarchas = new CajaMarchas(); //Inicializamos la caja de marchas

public:
    void encenderCarro(){
        std::cout << "Encendiendo Carro" << std::endl;
        motor->encender();
    }

    void apagarCarro(){
        std::cout << "Aoagando Carro" << std::endl;
        motor->apagar();
    }

    void subirMarcha(){
        std::cout << "Subiendo marcha" << std::endl;
        cajaMarchas->cambiarMarcha(1);
    }
    void bajarMarcha(){
        std::cout << "Bajando marcha" << std::endl;
        cajaMarchas->cambiarMarcha(-1);
    }
    void reversa(){
        std::cout << "Reversa" << std::endl;
        cajaMarchas->cambiarMarcha(11);
    }
    void neutro(){
        std::cout << "Neutro" << std::endl;
        cajaMarchas->cambiarMarcha(10);
    }

};

int main(){
    CarroFacade *facade = new CarroFacade();
    facade->encenderCarro();
    facade->subirMarcha();
    facade->bajarMarcha();
    facade->neutro();
    facade->apagarCarro();
}

