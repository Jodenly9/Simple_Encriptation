#include <iostream>
#include <cstdlib>

using namespace std;
/*Programa que encripta una cadena de caracteres utilizando la tecnica de inversion y desplazamiento.
Ejemplo:
Si invoco Encriptar con texto = "AON" y clave = 1 entonces
el texto quedaría transformado a "OPB" ya que:
- La primera transformación de AON sería invertirlo -> NOA
- Luego, como el parámetro @clave es 1, se suma 1 a cada carácter en el texto invertido -> "OPB"*/

//Función que calcula el tamaño de una cadena de caracteres.
int tamCadena(char texto[]);

//Nota: La función modificará la cadena de caracteres original para reflejar el texto encriptado.
void Encriptar(char texto[], unsigned int clave);

int SimpleEncriptation(){
    char texto[100];
	string claveStr;
    unsigned int clave;

    cout<< "Ingrese el texto a encriptar (Menos de 100 Caracteres): ";
    cin.getline(texto, 100);

    do{
        cout<< "Ingrese la clave de encriptación (Número entero menor o igual a 100): ";
        cin>> claveStr;

        try{
            clave = atoi(claveStr.c_str());
            if(clave> 100) {
                cout<<"Error: La clave debe ser un entero menor o igual a 100."<< endl;
            }
        }catch(const std::invalid_argument&) {
            cout<< "Error: La clave debe ser un número entero."<< endl;
            clave= 101;
        }
    }while(clave> 100);

    Encriptar(texto, clave);
    return 0;
}

int tamCadena(char texto[]){
	int contador = 0;
	for(int i=0; texto[i] != '\0'; i++){
		contador++;
	}
	return contador;
}

void Encriptar(char texto[], unsigned int clave){
	int j = 0;
    int contador = tamCadena(texto);
    char texto2[101];
	
	// Invierte la cadena de texto y guarda el resultado en texto2.
	for(int n=contador -1; n>=0; n--){
		texto2[j] = texto[n];
		j++;
	}
	texto2[j] = '\0';

	cout<<"Texto Original: "<<texto<<endl;
	cout<<"Primera Transformacion (Invertir): "<<texto2<<endl;

	// Encripta el texto sumando la clave a cada carácter.
	for(int z=0; texto2[z] != '\0'; z++){
		texto2[z] = texto2[z] + 1;
	}
	cout<<"Segunda Transformacion (Encriptar): "<<texto2<<endl;
}