#include <iostream>
#include "compositeProduct.cpp"
#include "simpleProduct.cpp"

using namespace std;

int main() {

    simpleProduct *ram4gb = new simpleProduct("Memoria RAM 4GB", 750, "KingStone");
    simpleProduct *ram8gb = new simpleProduct("Memoria RAM 8GB", 1000, "KingStone");

    simpleProduct *disk500gb = new simpleProduct("Disco Duro 500GB", 1500, "ACME");
    simpleProduct *disk1tb = new simpleProduct("Disco Duro 1TB", 2000, "ACME");

    simpleProduct *cpuAMD = new simpleProduct("AMD phenon", 4000, "AMD");
    simpleProduct *cpuIntel = new simpleProduct("Intel i7", 4500, "Intel");

    simpleProduct *smallCabinete = new simpleProduct("Gabinete Pequeño", 2000, "ExCom");
    simpleProduct *bigCabinete = new simpleProduct("Gabinete Grande", 2200, "ExCom");

    simpleProduct *monitor20inch = new simpleProduct("Monitor 20'", 1500, "HP");
    simpleProduct *monitor30inch = new simpleProduct("Monitor 30'", 2000, "HP");

    simpleProduct *simpleMouse = new simpleProduct("Raton Simple", 150, "Genius");
    simpleProduct *gammerMouse = new simpleProduct("Raton Gammer", 750, "Alien");

    compositeProduct *gamerPC = new compositeProduct("Gammer PC");
    gamerPC->addProduct(*ram8gb);
    gamerPC->addProduct(*disk1tb);
    gamerPC->addProduct(*cpuIntel);
    gamerPC->addProduct(*bigCabinete);
    gamerPC->addProduct(*monitor30inch);
    gamerPC->addProduct(*gammerMouse);

    compositeProduct *homePC = new compositeProduct("Casa PC");
    homePC->addProduct(*ram4gb);
    homePC->addProduct(*disk500gb);
    homePC->addProduct(*cpuAMD);
    homePC->addProduct(*smallCabinete);
    homePC->addProduct(*monitor20inch);
    homePC->addProduct(*simpleMouse);

    compositeProduct *pc2x1 = new compositeProduct("Paquete PC Gammer + Casa");
    pc2x1->addProduct(*gamerPC);
    pc2x1->addProduct(*homePC);

    cout << "Welcome to ComputerShop\n\n"
            << "We have to offer you:\n"
            << "1-Memoria RAM 4GB\n"
            << "2-Memoria RAM 8GB\n"
            << "3-Disco Duro 500GB\n"
            << "4-Disco Duro 1TB\n"
            << "5-AMD phenon\n"
            << "6-Intel i7\n"
            << "7-Gabinete Pequeño\n"
            << "8-Gabinete Grande\n"
            << "9-Monitor 20'\n"
            << "10-Monitor 30'\n"
            << "11-Raton Simple\n"
            << "12-Raton Gammer\n"
            << "13-Gammer PC\n"
            << "14-Casa PC\n"
            << "15-Paquete PC Gammer + Casa\n"
            << "Enter the number of the desired item";
    int a;
    cin >> a;
    cout << "You just bought: ";
    if(a == 1){
        cout << "Memoria RAM 4GB\n" << "The price is: $750\n";
    }
    else if(a == 2){
        cout << "Memoria RAM 8GB\n" << "The price is: $1000\n";
    }
    else if(a == 3){
        cout << "Disco Duro 500GB\n" << "The price is: $1500\n";
    }
    else if(a == 4){
        cout << "Disco Duro 1TB\n" << "The price is: $2000\n";
    }
    else if(a == 5){
        cout << "AMD phenon\n" << "The price is: $4000\n";
    }
    else if(a == 6){
        cout << "Intel i7\n" << "The price is: $4500\n";
    }
    else if(a == 7){
        cout << "Gabinete Pequeño\n" << "The price is: $2000\n";
    }
    else if(a == 8){
        cout << "Gabinete Grande\n" << "The price is: $2200\n";
    }
    else if(a == 9){
        cout << "Monitor 20'\n" << "The price is: $1500\n";
    }
    else if(a == 10){
        cout << "Monitor 30'\n" << "The price is: $2000\n";
    }
    else if(a == 11){
        cout << "Raton Simple\n" << "The price is: 150\n";
    }
    else if(a == 12){
        cout << "Raton Gammer\n" << "The price is: $750\n";
    }
    else if(a == 13){
        cout << "Gammer PC\n" << "The price is: $12450\n";
    }
    else if(a == 14){
        cout << "Casa PC\n" << "The price is: $9900\n";
    }
    else{
        cout << "Paquete PC Gammer + Casa\n" << "The price is: $22350\n";
    }
    cout << "Thanks for your visit";
    return 0;
}