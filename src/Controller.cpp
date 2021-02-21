#include <iostream>
#include <cstdio>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include "ConsoleControl.h"
#include "Header.h"
#include <windows.h>
#include <algorithm>
#include <string>
#include <locale>


#pragma execution_character_set( "utf-8" ) //PODER ESCRIBIR EN LA CONSOLA CON CARACTERES ESPAÑOLES

using namespace std;

void ListInventario() {
	ConsoleSetColor(YELLOW, BLACK);
	int numItems = 0, fila = 12;
	ConsoleXY(3, fila); fila++;
	cout << "Items en el inventario: ";

	//MUESTRA LOS ITEMS QUE HAY EN ESA SALA
	for (int i = 0; i < _TOTAL; i++)
	{
		if (items[i].location == -1) { //SI LA POSICION DE UN ITEM ES IGUAL A LA SALA A LA QUE ESTAMOS
			if (numItems > 0) cout << ", ";
			cout << items[i].name;
			numItems++;
		}
	}
	if (numItems == 0) { //SI NO SE HA ENCONTRADO NINGUN ITEM EN LA SALA
		ConsoleSetColor(RED, BLACK);
		cout << "No hay items en el inventario.";
	}
	else cout << ".";
	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);
}

void ListItemsSala(int idSala) {
	ConsoleSetColor(GREEN, BLACK);
	int numItems = 0, fila = 12;
	ConsoleXY(3, fila); fila++;
	cout << "Items en la sala: ";

	//MUESTRA LOS ITEMS QUE HAY EN ESA SALA
	for (int i = 0; i < _TOTAL; i++)
	{
		if (items[i].location == idSala) { //SI LA POSICION DE UN ITEM ES IGUAL A LA SALA A LA QUE ESTAMOS
			if (numItems > 0) cout << ", ";
			cout << items[i].name;
			numItems++;
		}
	}
	if (numItems == 0) { //SI NO SE HA ENCONTRADO NINGUN ITEM EN LA SALA
		cout << "No hay items en la sala.";
	}
	else cout << ".";
}

void ReadSala(int idsala, bool &playing) {
	int fila = 2;
	switch (idsala) {
		//QUE ESCRIBIR EN CADA SALA
	default:
		playing = false;
		break;
	case 1:
		ConsoleXY(3, fila); fila++;
		cout << "No hay rastro de la diosa, y ya no se oye su bonita voz." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Mirando al sur, hacia el mar, se ven los barcos pesqueros." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Parece que aunque grite no me van a oír." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "En el suelo hay una piedra mediana, creo que podría moverla..." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "No quiero presumir, ¡Pero estoy bastante fuerte!" << endl;
		if (Mundo.PiedraMedianaMovida) {
			if (items[LlaveDeCasa].location == 1) {
				fila++; ConsoleXY(3, fila); fila++;
				cout << "Debajo hay la llave de mi casa." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Siempre olvido donde dejo las cosas jejeje..." << endl;
			}
		}
		break;
	case 2:
		ConsoleXY(3, fila); fila++;
		cout << "Mira, ya he llegado, aquí está la puerta de mi casa." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Puedo entrar a mi hogar hacia el este, aunque el camino sigue hacia el norte." << endl;
		break;
	case 3:
		ConsoleXY(3, fila); fila++;
		cout << "Hogar dulce hogar." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "El salón de mi casa es muy espacioso." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Dentro hay una mesa con 2 sillas, por si tengo visitas." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Hay también unas escaleras para subir al segundo piso." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Si salgo por el norte entraré en mi garaje, aunque no tengo coche :(." << endl;
		break;
	case 4:
		ConsoleXY(3, fila); fila++;
		cout << "Bienvenido a mi habitación!" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Mi cama, como siempre, sin hacer... Siempre me da mucha pereza." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "La ventana apunta al norte." << endl;

		if (Mundo.VentanaHabiacion)
		{
			ConsoleXY(3, fila); fila++;
			cout << "Hacia el norte hay el campo de manolo." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Tiene trigo, vacas, obejas, y muy mala hostia." << endl;
		}

		if (Mundo.isEgg) {
			ConsoleXY(3, fila); fila++;
			cout << "La Gallina puso un Huevo De Oro!" << endl;
		}

		break;
	case 5:
		ConsoleXY(3, fila); fila++;
		if (Mundo.DialogCoche == false) {
			cout << "¡EH! ¡AQUÍ FALTA MI COCHE!" << endl;
			ConsoleXY(3, fila); fila++; ConsoleWait(1000);
			cout << "Es lo que diría si tubiera un coche :(" << endl;
			Mundo.DialogCoche = true;
		}
		else {
			ConsoleXY(3, fila); fila++;
			cout << "Si ahorro, algún dia compraré un coche..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "¡Y podré marchar a la gran ciudad de una vez por todas!" << endl;
		}
		Mundo.ResetCruce = true;
		break;
	case 69:
		ConsoleXY(3, fila); fila++;
		cout << "He llegado a un cruce..." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Hay un cartel en medio del camino." << endl;
		if (!Mundo.ResetCruce)
		{
			ConsoleXY(3, fila); fila++;
			cout << "NORTE: PUEBLO" << endl;
			ConsoleXY(3, fila); fila++;
			cout << "SUD: MERCADO PRINCIPAL" << endl;
			ConsoleXY(3, fila); fila++;
			cout << "OESTE: MONTE PERDICIÓN" << endl;
		}
		break;
	case 6:
		ConsoleXY(3, fila); fila++;
		cout << "He llegado al Mercado Principal" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Nadamás entrar a la calle, la primera tienda que encuentro es la de Manolo." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "La calle sigue hacia el sur." << endl;

		if (!Mundo.LlavesManolo)
		{
			fila++;
			ConsoleXY(3, fila); fila++;
			cout << "A lo mejor si le pido las llaves me las da." << endl;
		}

		Mundo.ResetCruce = true;
		break;
	case 7:
		ConsoleXY(3, fila); fila++;
		cout << "Aquí está la tienda de Paquita." << endl;
		ConsoleXY(3, fila); fila++; fila++;
		cout << "Es la mujer de Manolo, y al contrario que él, Paquita es muy maja :)" << endl;
		if (!Mundo.DialogPaquita && !Mundo.GallinaPaquita) {
			ConsoleXY(3, fila); fila++;
			cout << "Tengo que traer Pan o Trigo para las gallinas de Paquita..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "¡Quiero la recompensa!" << endl;
		}
		break;
	case 8:
		ConsoleXY(3, fila); fila++;
		cout << "MMMMMMmmmmm... El restaurante de Ramen." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Gus es el propietario. No suele ser muy majo, pero en la tienda," << endl;
		ConsoleXY(3, fila); fila++;
		cout << "¡El cliente siempre tiene la razón!" << endl;
		ConsoleXY(3, fila); fila++; fila++;
		cout << "Aunque sólo son clientes los que pagan :(" << endl;

		if (Mundo.DialogGus)
		{
			ConsoleXY(3, fila); fila++;
			cout << "Gus dice que si le traigo alguna moneda de oro de verdad," << endl;
			ConsoleXY(3, fila); fila++; fila++;
			cout << "¡Me dará un cupón de ramen gratis por un año!" << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Aunque no se si me está vacilando o no..." << endl;
		}

		break;
	case 9:
		ConsoleXY(3, fila); fila++; fila++;
		cout << "¡BRAGAS A UN EURO! ¡BRAGAS A UN EURO!" << endl;
		ConsoleXY(3, fila); fila++; fila++;
		cout << "                 ···" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "¡BRAGAS A UN EURO! ¡BRAGAS A UN EURO!" << endl;
		break;
	case 10:
		ConsoleXY(3, fila); fila++;
		cout << "¡He llegado a la plaza de la Ciudad!" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Al norte está la Iglesia," << endl;
		ConsoleXY(3, fila); fila++;
		cout << "y al oeaste está la Herrería de Monacio." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "En el centro se encuentra la Fuente de la ciudad." << endl;
		if (Mundo.MonedaEnFuente && items[MonedaDeOro].location == idsala)
		{
			ConsoleXY(3, fila); fila++; fila++;
			cout << "En el fondo de la fuente hay una Moneda de Oro y una Alcantarilla abierta..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "A saber a dónde lleva y porqué está abierta..." << endl;
		}
		else if (Mundo.MonedaEnFuente) {
			ConsoleXY(3, fila); fila++; fila++;
			cout << "En el fondo de la fuente hay una Alcantarilla abierta..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "A saber a dónde lleva y porqué está abierta..." << endl;
		}
		else {
			ConsoleXY(3, fila); fila++; fila++;
			cout << "Hay personas que creen que tirar dinero en ellas les concede deseos." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Confieso que muchas veces he recogido dinerito para comprar comida :(" << endl;
		}
		Mundo.ResetCruce = true;
		break;
	case 11:
		ConsoleXY(3, fila); fila++;
		cout << "Éste sitio está muy oscuro..." << endl;
		ConsoleXY(3, fila); fila++; fila++;
		cout << "Sólo hay unas velas iluminando, todo parece muy turbio..." << endl;

		if (items[DiccionarioSatanico].location == idsala && !Mundo.isDictionaryRead)
		{
			ConsoleXY(3, fila); fila++; fila++;
			cout << "En el centro de la sala veo un libro, en la portada pone Diccionario Satanico..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "           ···" << endl;
		}
		else if (Mundo.isDictionaryRead) {
			ConsoleXY(3, fila); fila++;
			cout << "Según lo que he aprendido del lenguaje Satánico," << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Los textos de sangre que hay en el suelo dicen:" << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Rafaz'el no es un Demonio malo." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Sólo es que tiene mucha hambre siempre..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Y le encanta comer humanos..." << endl;
		}
		break;
	case 12:
		ConsoleXY(3, fila); fila++;
		cout << "La Iglesia me da mucho mal rollo..." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Antes no era creyente pero ahora que he hablado con una Diosa" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Supongo que el Cura no está tan loco." << endl;
		if (Mundo.isChestOpen)
		{
			ConsoleXY(3, fila); fila++;
			cout << "El Cofre Sagrado tenía dentro un trozo de Metal Sagrado..." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "Esperaba que tubiera más cosas, ha sido un poco una decepción." << endl;
			ConsoleXY(3, fila); fila++;
			cout << "A lo mejor si se lo llevo al Herrero puede hacer algo con él." << endl;
		}
		else {
			ConsoleXY(3, fila); fila++;
			cout << "Me pregunto que habrá en el Cofre Sagrado, ojalá poder abrirlo." << endl;
		}
		break;
	case 13:
		ConsoleXY(3, fila); fila++;
		cout << "Ésta es la Herrería." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "El Herrero es un viejo muy majo, habla siempre mucho." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Y conoce muchas leyendas e historias..." << endl;

		if (Mundo.DialogLeyenda)
		{
			ConsoleXY(3, fila); fila++;
			cout << "Me encantaría ser el Joven de la Leyenda del Huevo de Oro..." << endl;
		}

		break;
	case 14:
		ConsoleXY(3, fila); fila++;
		cout << "El campo de Manolo... Que buen lugar para echar siestas jejeje" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Es un campo de trigo enorme, y suele tener los animales sueltos por aquí." << endl;
		ConsoleXY(3, fila); fila++; fila++;
		cout << "Muchas veces me manda vigilarlos pero a mi me da pereza." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Al norte hay el castillo abandonado... Nunca nadie va allí." << endl;
		ConsoleXY(3, fila); fila++;
		cout << "Se oyen ruidos raros y pasan cosas muy extrañas." << endl;
		break;
	case 15:
		DialogDemonio();
		ReprintHUD(666);
		ConsoleXY(3, fila); fila++;
		cout << "¡COÑO! ¡Que miedo!" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "ESTE DEBE DE SER RAFAZ'EL, EL DEMONIO MALVADO" << endl;
		ConsoleXY(3, fila); fila++;
		cout << "¡¿QUE HAGO AHORA?!" << endl;
		break;
	}
	if (playing)
	{
		ListItemsSala(idsala); // DESPUES DE LA DESCRIPCION MUESTRO QUÉ ITEMS HAY EN LA SALA ACTUAL
	}
}

int ParseAction(string &accion) {
	int result = 0;

	if (accion == "INVENTARIO") return 5;
	if (accion == "AYUDA" || accion == "HELP") return 6;
	if (accion == "EXIT" || accion == "QUIT") return 9999999;

	//VERBOS 
	if (accion.find("USAR") != ::string::npos) result = result + 2000000;
	if (accion.find("COGER") != ::string::npos) result = result + 4000000;
	if (accion.find("SOLTAR") != ::string::npos) result = result + 5000000;
	if (accion.find("DAR") != ::string::npos) result = result + 6000000;
	if (accion.find("HABLAR") != ::string::npos) result = result + 7000000;
	if (accion.find("MOVER") != ::string::npos) result = result + 8000000;
	if (accion.find("PEGAR") != ::string::npos) result = result + 9000000;
	if (accion.find("EMPUJAR") != ::string::npos) result = result + 10000000;
	if (accion.find("TIRAR") != ::string::npos) result = result + 11000000;
	else if (accion.find("MIRAR") != ::string::npos) result = result + 3000000;
	else if (accion.find("ABRIR") != ::string::npos) result = result + 12000000;
	else if (accion.find("IR") != ::string::npos) result = result + 1000000; // "ABRIR"	CONTIENE "IR" ASÍ QUE USO ELSE PARA QUE NO LO SUME 2 VECES. 
	if (accion.find("CERRAR") != ::string::npos) result = result + 13000000;
	if (accion.find("ENCENDER") != ::string::npos) result = result + 14000000;
	if (accion.find("QUITAR") != ::string::npos) result = result + 15000000;
	if (accion.find("PONER") != ::string::npos) result = result + 16000000;
	if (accion.find("LEER") != ::string::npos) result = result + 17000000;
	if (accion.find("HACER") != ::string::npos) result = result + 18000000;

	if (accion.find("CONTAR LEYENDA") != ::string::npos) result = result + 19000000;
	if (accion.find("FORJAR ESPADA") != ::string::npos) result = result + 20000000;
	else if (accion.find("ESPADA SAGRADA") != ::string::npos) result = result + 5000;
	if (accion.find("FORJAR LLAVE") != ::string::npos) result = result + 21000000;

	//ITEMS 
	if (accion.find("LLAVE DE CASA") != ::string::npos) result = result + 1000;
	if (accion.find("PIEDRA") != ::string::npos) result = result + 2000;
	if (accion.find("LLAVE DE ORO") != ::string::npos) result = result + 3000;
	if (accion.find("METAL SAGRADO") != ::string::npos) result = result + 4000;
	if (accion.find("PUERTA") != ::string::npos) result = result + 6000;
	if (accion.find("ESCALERA") != ::string::npos || accion.find("ESCALERAS") != ::string::npos) result = result + 8000;
	if (accion.find("VENTANA") != ::string::npos) result = result + 9000;
	if (accion.find("DICCIONARIO SATANICO") != ::string::npos) result = result + 10000;
	if (accion.find("CUPON DE RAMEN") != ::string::npos) result = result + 11000;
	if (accion.find("TRIGO") != ::string::npos) result = result + 12000;
	if (accion.find("GALLINA") != ::string::npos) result = result + 13000;
	if (accion.find("HUEVO DE ORO") != ::string::npos) result = result + 14000;
	if (accion.find("MONEDA DE ORO") != ::string::npos) result = result + 15000;
	if (accion.find("CAMA") != ::string::npos) result = result + 16000;
	if (accion.find("CARTEL") != ::string::npos) result = result + 17000;
	if (accion.find("LLAVES DE CAMPO") != ::string::npos) result = result + 18000;
	if (accion.find("MANOLO") != ::string::npos) result = result + 19000;
	if (accion.find("PAQUITA") != ::string::npos) result = result + 20000;
	if (accion.find("GUS") != ::string::npos) result = result + 21000;
	if (accion.find("BRAGAS") != ::string::npos) result = result + 22000;
	if (accion.find("FUENTE") != ::string::npos) result = result + 23000;
	if (accion.find("ALCANTARILLA") != ::string::npos) result = result + 24000;
	if (accion.find("HERRERO") != ::string::npos) result = result + 25000;
	if (accion.find("COFRE SAGRADO") != ::string::npos) result = result + 26000;
	if (accion.find("LUCES") != ::string::npos) result = result + 27000;
	// IRÉ AÑADIENDO A MEDIDA QUE NECESITE MAS 

	//DIRECCIONES
	if (accion.find("NORTE") != ::string::npos) result = result + 1;
	if (accion.find("SUR") != ::string::npos || accion.find("SUD") != ::string::npos) result = result + 2;
	if (accion.find("OESTE") != ::string::npos) result = result + 4;
	else if (accion.find("ESTE") != ::string::npos) result = result + 3;
	//

	return result;
}

void PerformAction(int numAction, int &idSala) {
	int fila = 18;
	bool GetDropControl = false;

	if (numAction == 5) {
		ListInventario();
		GetDropControl = true;
	}

	if (numAction == 6) {
		ShowHelp(idSala);
		GetDropControl = true;
	}

	if (numAction == 17010000) { //LEER DICCIONARIO SATANICO
		if (items[DiccionarioSatanico].location == -1 || items[DiccionarioSatanico].location == idSala)
		{
			ReadDictionary(idSala);
			GetDropControl = true;
		}
	}

	//GET - DROP
	switch (numAction) {
		case 4001000: //COGER LLAVE DE CASA
			if (items[LlaveDeCasa].location == 1 && Mundo.PiedraMedianaMovida) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Llave de Casa..." << endl;
				items[LlaveDeCasa].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else if (items[LlaveDeCasa].location == idSala && items[LlaveDeCasa].location != 1) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Llave de Casa..." << endl;
				items[LlaveDeCasa].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué llave ni que llave?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4018000: //COGER LLAVES DE CAMPO
			if (items[LlavesDeCampo].location == idSala) {
				if (Mundo.DialogManolo)
				{
					ConsoleXY(3, fila); fila++;
					cout << "Sí claro... No le cuido los animales ni de coña..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "Cogiendo Llaves de Campo..." << endl;
					items[LlavesDeCampo].location = -1; //GUARDAR EN EL INVENTARIO
					GetDropControl = true;
					Mundo.DialogManolo = false;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "Cogiendo Llaves de Campo..." << endl;
					items[LlavesDeCampo].location = -1; //GUARDAR EN EL INVENTARIO
					GetDropControl = true;
					Mundo.DialogManolo = false;
				}
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué llave ni que llave?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4003000: //COGER LLAVE DE ORO
			if (items[LlaveDeOro].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Llave de Oro..." << endl;
				items[LlaveDeCasa].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué llave ni que llave?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4004000: //COGER METAL SAGRADO
			if (items[MetalSagrado].location == idSala && Mundo.isChestOpen) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Metal Sagrado..." << endl;
				items[MetalSagrado].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Metal Sagrado ni que Metal Sagrado?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4005000: //COGER ESPADA SAGRADA
			if (items[EspadaSagrada].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Espada Sagrada..." << endl;
				items[EspadaSagrada].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Espada Sagrada ni que Espada Sagrada?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4015000: //COGER MONEDA DE ORO
			if (items[MonedaDeOro].location == idSala && Mundo.MonedaEnFuente) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Moneda De Oro..." << endl;
				items[MonedaDeOro].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Moneda De Oro ni que Moneda De Oro?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4011000: //COGER CUPON DE RAMEN
			if (items[CuponDeRamen].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Cupon De Ramen..." << endl;
				items[CuponDeRamen].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Cupon De Ramen ni que Cupon De Ramen?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4012000: //COGER TRIGO
			if (items[Trigo].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Trigo..." << endl;
				items[Trigo].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Trigo ni que Trigo?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4013000: //COGER GALLINA
			if (items[Gallina].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Gallina..." << endl;
				items[Gallina].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Gallina ni que Gallina?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4014000: //COGER HUEVO DE ORO
			if (items[HuevoDeOro].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Huevo De Oro..." << endl;
				items[HuevoDeOro].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Huevo De Oro ni que Huevo De Oro?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4010000: //COGER DICCIONARIO SATANICO
			if (items[DiccionarioSatanico].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Diccionario Satanico..." << endl;
				items[DiccionarioSatanico].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Diccionario Satanico ni que Diccionario Satanico?..." << endl;
				GetDropControl = true;
			}
			break;
		case 4016000: //COGER LLAVE DEL CAMPO
			if (items[LlavesDeCampo].location == idSala) {
				ConsoleXY(3, fila); fila++;
				cout << "Cogiendo Llaves de Campo..." << endl;
				items[LlavesDeCampo].location = -1; //GUARDAR EN EL INVENTARIO
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Llaves de Campo ni que Llaves de Campo?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5001000: //DEJAR LLAVE DE CASA
			if (items[LlaveDeCasa].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Llave de Casa..." << endl;
				items[LlaveDeCasa].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué llave ni que llave?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5018000: //DEJAR LLAVE DE CASA
			if (items[LlavesDeCampo].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Llaves de Campo..." << endl;
				items[LlavesDeCampo].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué llaves ni que llaves?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5003000: //DEJAR LLAVE DE ORO
			if (items[LlaveDeOro].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Llave de Oro..." << endl;
				items[LlaveDeCasa].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué llave ni que llave?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5004000: //DEJAR METAL SAGRADO
			if (items[MetalSagrado].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Metal Sagrado..." << endl;
				items[MetalSagrado].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Metal Sagrado ni que Metal Sagrado?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5005000: //DEJAR ESPADA SAGRADA
			if (items[EspadaSagrada].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Espada Sagrada..." << endl;
				items[EspadaSagrada].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Espada Sagrada ni que Espada Sagrada?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5015000: //DEJAR MONEDA DE ORO
			if (items[MonedaDeOro].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Moneda De Oro..." << endl;
				items[MonedaDeOro].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Moneda De Oro ni que Moneda De Oro?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5011000: //DEJAR CUPON DE RAMEN
			if (items[CuponDeRamen].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Cupon De Ramen..." << endl;
				items[CuponDeRamen].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Cupon De Ramen ni que Cupon De Ramen?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5012000: //DEJAR TRIGO
			if (items[Trigo].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Trigo..." << endl;
				items[Trigo].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Trigo ni que Trigo?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5013000: //DEJAR GALLINA
			if (items[Gallina].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Gallina..." << endl;
				items[Gallina].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Gallina ni que Gallina?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5014000: //DEJAR HUEVO DE ORO
			if (items[HuevoDeOro].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Huevo De Oro..." << endl;
				items[HuevoDeOro].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Huevo De Oro ni que Huevo De Oro?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5010000: //DEJAR DICCIONARIO SATANICO
			if (items[DiccionarioSatanico].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Diccionario Satanico..." << endl;
				items[DiccionarioSatanico].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Diccionario Satanico ni que Diccionario Satanico?..." << endl;
				GetDropControl = true;
			}
			break;
		case 5016000: //DEJAR LLAVE DEL CAMPO
			if (items[LlavesDeCampo].location == -1) {
				ConsoleXY(3, fila); fila++;
				cout << "Dejando Diccionario Satanico..." << endl;
				items[LlavesDeCampo].location = idSala; //DEJAR EN LA SALA
				GetDropControl = true;
			}
			else {
				ConsoleXY(3, fila); fila++;
				cout << "¿Qué Diccionario Satanico ni que Diccionario Satanico?..." << endl;
				GetDropControl = true;
			}
			break;
	}

	//

	if (!GetDropControl) {
		switch (idSala) {
		default:
			ConsoleXY(3, fila); fila++;
			cout << "¡¿Dónde estas?! ... ERROR DE CÓDIGO :(" << endl;
			break;
		case 1: //ACANTILADO
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 2;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				ConsoleXY(3, fila); fila++;
				cout << "Sí claro, ahora voy y salto al mar desde aquí arriba..." << endl;
				ConsoleXY(3, fila); fila++; fila++;
				cout << "¡Soy tonto pero no estoy loco!" << endl;
				break;
			case 8002000: // MOVER PIEDRA
				if (!Mundo.PiedraMedianaMovida) {
					ConsoleXY(3, fila); fila++;
					cout << "¡AAAARGH!... ¡La he podido mover!" << endl;
					ConsoleXY(3, fila); fila++;
					Mundo.PiedraMedianaMovida = true;
					items[LlaveDeCasa].location = 1;
				}
				else { //SI YA HE MOVIDO LA PIEDRA NO NECESITO MOVERLA MAS.
					ConsoleXY(3, fila); fila++;
					cout << "PFFFfffff... Me da pereza mover más esta piedra :(" << endl;
				}
				break;
			case 10002000: // EMPUJAR PIEDRA
				if (!Mundo.PiedraMedianaMovida) {
					ConsoleXY(3, fila); fila++;
					cout << "¡AAAARGH!... ¡La he podido empujar!" << endl;
					ConsoleXY(3, fila); fila++;
					Mundo.PiedraMedianaMovida = true;
					items[LlaveDeCasa].location = 1;
				}
				else { //SI YA HE MOVIDO LA PIEDRA NO NECESITO MOVERLA MAS.
					ConsoleXY(3, fila); fila++;
					cout << "PFFFfffff... Me da pereza empujar más esta piedra :(" << endl;
				}
				break;
			}
			break;
		case 2: //CAMINO DE CASA
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
	
				if (items[LlavesDeCampo].location == -1 && !Mundo.PuertaCampoAbierta)
				{
					ConsoleXY(3, fila); fila++;
					cout << "Abriendo puerta del campo..." << endl;
					Mundo.PuertaCampoAbierta = true;
					idSala = 14;
					ConsoleXY(3, fila); fila++;
					cout << "Caminando..." << endl;
				}
				else if (!Mundo.PuertaCampoAbierta) {
					ConsoleXY(3, fila); fila++;
					cout << "¡UY! ¡Parece que el camino al campo está cerrado!" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "Necesito pedirle la llave a Manolo... :(" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "A estas horas estará en su puesto del marcado." << endl;
				}
				else {
					idSala = 14;
					ConsoleXY(3, fila); fila++;
					cout << "Caminando..." << endl;
				}
				break;
			case 1000002: //IR SUR
				idSala = 1;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 2006000: //USAR PUERTA
				if (!Mundo.PuertaCasaAbierta) {
					if (items[LlaveDeCasa].location == -1)
					{
						ConsoleXY(3, fila); fila++;
						cout << "La puerta se ha abierto. :)" << endl;
						Mundo.PuertaCasaAbierta = true;
					}
					else {
						ConsoleXY(3, fila); fila++;
						cout << "La puerta está cerrada..." << endl;
						ConsoleXY(3, fila); fila++;
						cout << "Necesito abrirla con la llave primero." << endl;
					}
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "Cerrando puerta..." << endl;
					Mundo.PuertaCasaAbierta = false;
				}
				break;
			case 1000003: //IR ESTE
				if (Mundo.PuertaCasaAbierta) {
					idSala = 3;
					ConsoleXY(3, fila); fila++;
					cout << "Caminando..." << endl;
				}
				else { //NECESITO QUE LA PUERTA ESTÉ ABIERTA PARA ENTRAR
					if (items[LlaveDeCasa].location == -1) { //SI YA TENGO LA LLAVE DOY UNA PISTA DE QUÉ DEBERÍA HACER PARA ENTRAR
						ConsoleXY(3, fila); fila++;
						cout << "Primero tendré que abrir la puerta con la llave, ¡Digo yo!" << endl;
					}
					else {
						ConsoleXY(3, fila); fila++;
						cout << "La puerta está cerrada :(" << endl;
						ConsoleXY(3, fila); fila++;
						cout << "¿Dónde habré dejado la llave de mi casa?" << endl;
					}
				}
				break;
			case 12006000: //ABRIR PUERTA
				if (Mundo.PuertaCasaAbierta) {
					ConsoleXY(3, fila); fila++;
					cout << "La puerta ya está abierta." << endl;
				}
				else {
					if (items[LlaveDeCasa].location == -1) {
						ConsoleXY(3, fila); fila++;
						cout << "La puerta se ha abierto. :)" << endl;
						Mundo.PuertaCasaAbierta = true;
					}
					else { //PISTA POR SI AUN NO TIENE LA LLAVE
						ConsoleXY(3, fila); fila++;
						cout << "La puerta está cerrada con llave." << endl;
						ConsoleXY(3, fila); fila++;
						cout << "Siempre pierdo las llaves o me olvido dónde las he dejado..." << endl;
						ConsoleXY(3, fila); fila++;
						cout << "Recuerdo que la dejé en algún sitio cercano para poderla recoger." << endl;
						ConsoleXY(3, fila); fila++;
						cout << "Ahora toca recordar dónde está ese sitio :(" << endl;
						ConsoleXY(3, fila); fila++;
						ConsoleSetColor(BLACK, BLACK);
						system("pause");
						ConsoleSetColor(WHITE, BLACK);
					}
				}
				break;
			case 13006000: //CERRAR PUERTA
				if (Mundo.PuertaCasaAbierta)
				{
					ConsoleXY(3, fila); fila++;
					cout << "Cerrando puerta..." << endl;
					Mundo.PuertaCasaAbierta = false;
				}
				break;
			}
			break;
			case 11006000: //TIRAR PUERTA
				ConsoleXY(3, fila); fila++;
				cout << "No voy a tirar la puerta de mi propia casa al suelo..." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Prefiero encontrar la llave primero." << endl;
				break;
		case 3: //SALON DE CASA
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 5;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000004: //IR OESTE
				idSala = 2;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 2008000: //USAR ESCALERAS
				idSala = 4;
				ConsoleXY(3, fila); fila++;
				cout << "Subiendo escaleras..." << endl;
				if (items[Gallina].location == idSala)
				{
					if (items[HuevoDeOro].location != -1)
					{
						Mundo.isEgg = true;
						items[HuevoDeOro].location = idSala;
					}
				}
				break;
			}
			break;
		case 4: //HABITACION
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 2008000: //USAR ESCALERAS
				ConsoleXY(3, fila); fila++;
				cout << "Bajando escaleras..." << endl;
				idSala = 3;
				break;
			case 3009000: //MIRAR VENTANA
				ConsoleXY(3, fila); fila++;
				cout << "Hacia el norte hay el campo de manolo." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Tiene trigo, vacas, obejas, y muy mala hostia." << endl;
				Mundo.VentanaHabiacion = true;
				break;
			case 18016000: //HACER CAMA
				ConsoleXY(3, fila); fila++;
				cout << "¡Sí claro! No he hecho la cama en todo el año..." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "¡No me pondré a hacerla ahora porque tú lo digas!" << endl;
				break;
			}
			break;
		case 5: //GARAJE
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 6;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				idSala = 3;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000003: //IR ESTE
				idSala = 69;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			}
			break;
		case 69: //CRUCE CIUDAD
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 10;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				idSala = 6;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000004: //IR OESTE
				idSala = 5;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 3017000: //MIRAR CARTEL
				ConsoleXY(3, fila); fila++;
				cout << "En el cartel hay escrito:" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "NORTE: PUEBLO" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "SUD: MERCADO PRINCIPAL" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "OESTE: MONTE PERDICIÓN" << endl;
				Mundo.ResetCruce = false;
				break;
			}
			break;
		case 6: //ENTRADA MERCADO - MANOLO
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 69;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				idSala = 7;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 7019000: //HABLAR MANOLO
				ConsoleXY(3, fila); fila++;
				cout << "MANOLO: Te dejo ir al campo sólo con la condicion" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "            de que vigiles a mis animales... Aquí tienes las llaves" << endl;
				items[LlavesDeCampo].location = 6;
				Mundo.LlavesManolo = true;
				break;
			case 15018000: //QUITAR LLAVES
				ConsoleXY(3, fila); fila++;
				cout << "MANOLO: ¡EH ESAS SON MIS LLAVES!" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "        Te dejo ir al campo sólo con la condicion" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "        de que vigiles a mis animales... Aquí tienes las llaves" << endl;
				items[LlavesDeCampo].location = 6;
				Mundo.LlavesManolo = true;
				break;
			}
			break;
		case 7:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 6;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				idSala = 8;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 7020000: //HABLAR PAQUITA
				if (Mundo.DialogPaquita)
				{
					ConsoleXY(3, fila); fila++;
					cout << "PAQUITA: ¡¡¡Hola Furgencio!!! Jovencito, necesito un favor..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "            ¿Podrías traerme un poco de trigo o pan para poder alimentar a mis gallinas?" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "            ¡Si me lo traes te daré una recompensa!" << endl;
					items[LlavesDeCampo].location = 6;
					Mundo.DialogPaquita = false;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "PAQUITA: Que tengas una tarde tranquila, ¡Jovenzuelo!" << endl;
				}
				break;
			case 6012000: //DAR TRIGO
				if (items[Trigo].location == -1 && !Mundo.DialogPaquita)
				{
					items[Trigo].location = 0;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "PAQUITA: ¡¡¡MUCHAS GRACIAS!!!" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         Como recompensa te daré una de mis gallinas," << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         Ésta es una de las más gordas y sanas." << endl;
					items[Gallina].location = -1;
					Mundo.GallinaPaquita = true;
				}
				else if (Mundo.DialogPaquita) {
					ConsoleXY(3, fila); fila++;
					cout << "¿Porque querría Paquita un poco de Trigo?..." << endl;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "No tengo Trigo para darle a Paquita." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "Supongo que no le imprtará si lo cojo del campo de Manolo, su marido..." << endl;
				}

				break;
			}
			break;
		case 8:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 7;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				idSala = 9;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 7021000: //HABLAR GUS

				if (Mundo.DialogGus)
				{
					ConsoleXY(3, fila); fila++;
					cout << "GUS: ¡Espero que no pierdas el Cupón! No te daré otro..." << endl;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "GUS: ¡Buenas tardes Furgencio! Esta noche tenemos un Ramen especial..." << endl;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "            Aunque como sigas igual de pobre no te lo voy a dejar probar >:(" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "            JAJAJAJAjajajaja ··· Bueno, si algún día me traes una moneda de oro," << endl;
					ConsoleXY(3, fila); fila++;
					cout << "            ¡Te daré Ramen gratis todo el año!" << endl;
					Mundo.DialogGus = true;
				}

				break;
			case 6015000: //DAR MONEDA DE ORO
				if (items[MonedaDeOro].location == -1 && Mundo.DialogGus)
				{
					items[MonedaDeOro].location = 0;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "GUS: ¡¡¡MUCHAS GRACIAS!!!" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         Nunca pensé que tendría una moneda de oro," << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         ¡Y encima tan bonita! No pensé que lo harías, lo decía en coña..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         Pero ahora me sabría mal no darte el Cupón... ¡Aquí lo tienes!" << endl;
					items[CuponDeRamen].location = -1;
					Mundo.GallinaPaquita = true;
				}
				else if (items[MonedaDeOro].location == -1 && !Mundo.DialogGus) {
					ConsoleXY(3, fila); fila++;
					cout << "¿Para que le daría yo una Moneda de Oro a Gus?" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "¡Un Ramen no vale tanto! Mejor me la quedo para mi..." << endl;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "No tengo ninguna Moneda de Plata..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "Y tampoco ideas de dónde encontrar una :( sólo me queda pedir un deseo en una fuente jajaja..." << endl;
				}
				break;
			}
			break;
		case 9:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 7;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				ConsoleXY(3, fila); fila++;
				cout << "No hay más tiendas hacia el sur..." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Parece que he llegado al final del marcado." << endl;
				break;
			case 3022000: //MIRAR BRAGAS
				ConsoleXY(3, fila); fila++; fila++;
				cout << "Oye, pues son bonitas..." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Si tubiera novia le regalaba unas, pero estoy mas solo que la una." << endl;
				ConsoleWait(3000);
				break;
			case 2022000: //USAR BRAGAS
				ConsoleXY(3, fila); fila++; fila++;
				cout << "¡Ni de coña me pruebo unas bragas!" << endl;
				ConsoleXY(3, fila); fila++; fila++;
				cout << "              ···" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Y menos ahora que me están mirando... ¬¬ Si no hubiera nadie a lo mejor sí..." << endl;
				ConsoleWait(3000);
				break;
			case 4022000: //COGER BRAGAS
				ConsoleXY(3, fila); fila++; fila++;
				cout << "¡QUE NO QUIERO UNAS BRAGAS!" << endl;
				ConsoleWait(3000);
				break;
			case 16000000: //PONER BRAGAS
				ConsoleXY(3, fila); fila++; fila++;
				cout << "¡Ni de coña me pongo unas bragas!" << endl;
				ConsoleXY(3, fila); fila++; fila++;
				cout << "              ···" << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Y menos ahora que me están mirando... ¬¬ Si no hubiera nadie a lo mejor sí..." << endl;
				ConsoleWait(3000);
				break;
			}
			break;
		case 10:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 12;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000002: //IR SUR
				idSala = 69;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 1000004: //IR OESTE
				idSala = 13;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 3023000: //MIRAR FUENTE
				if (!Mundo.MonedaEnFuente) {
					ConsoleXY(3, fila); fila++;
					cout << "En el fondo de la fuente veo..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "¡Veo una Moneda de Oro! ¡Y una Alcantarilla abierta!" << endl;
					Mundo.MonedaEnFuente = true;
					items[MonedaDeOro].location = idSala;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "Si sigo mirando la fuente me acabaré cayendo..." << endl;
				}
				break;
			case 2024000: //USAR ALCANTARILLA
				if (Mundo.MonedaEnFuente) {
					ConsoleXY(3, fila); fila++;
					cout << "La curiosidad me mata..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "¡Voy a entrar por ésa Alcantarilla!" << endl;
					idSala = 11;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "¿Qué Alcantarilla ni qué Alcantarilla? ..." << endl;
				}
				break;
			}
			break;
		case 11: //SECTA
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 2024000: //USAR ALCANTARILLA
				ConsoleXY(3, fila); fila++;
				cout << "Subiendo Alcantarilla..." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "¡Espero que nadie sepa que he entrado aquí!..." << endl;
				idSala = 10;
				break;
			case 14027000: //ENCENDER LUCES
				ConsoleXY(3, fila); fila++;
				cout << "Parece que no hay ningún interruptor..." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Tendré que apañarme con las velas encendidas que poco iluminan..." << endl;
			}
			break;
		case 12:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000002: //IR SUR
				idSala = 10;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 12026000: //ABRIR COFRE SAGRADO
				if (items[LlaveDeOro].location == -1 && Mundo.isChestOpen == false)
				{
					ConsoleXY(3, fila); fila++;
					cout << "El Cofre Sagrado se ha abierto..." << endl;
					items[LlaveDeOro].location = 0;
					items[MetalSagrado].location = idSala;
					Mundo.isChestOpen = true;
				}
				else if (Mundo.isChestOpen == false) {
					ConsoleXY(3, fila); fila++;
					cout << "El Cofre Sagrado ya está cerrado..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "No tengo la llave que lo abre..." << endl;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "El Cofre Sagrado ya está abierto..." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "Dentro tenía un trozo de Metal Sagrado..." << endl;
				}
				break;
			}
			break;
		case 13: //HERRERIA
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000003: //IR ESTE
				idSala = 10;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 7025000: //HABLAR HERRERO
				ConsoleXY(3, fila); fila++;
				cout << "HERRERO: Hola, joven. ¿Que puedo hacer por ti?" << endl;
				ConsoleXY(3, fila); fila++;
				ConsoleSetColor(CYAN, BLACK);
				cout << "         Contar Leyenda";
				ConsoleXY(3, fila); fila++;
				cout << "         Forjar Espada";
				if (Mundo.DialogLeyenda)
				{
					ConsoleXY(3, fila); fila++;
					cout << "         Forjar Llave De Oro";
				}
				ConsoleSetColor(BLACK, BLACK);
				system("pause");
				ConsoleSetColor(YELLOW, BLACK);
				break;
			case 19000000: //CONTAR LEYENDA
				Leyenda(idSala);
				break;
			case 20000000: //FORJAR ESPADA
				if (items[MetalSagrado].location == -1)
				{
					items[MetalSagrado].location = 0;
					items[EspadaSagrada].location = -1;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "HERRERO: ¡Vaya! Me ha salido una espada genial..." << endl;
					ConsoleXY(3, fila); fila++;
					ConsoleSetColor(YELLOW, BLACK);
					cout << "          HAS RECIBIDO UNA ESPADA SAGRADA" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "          Con esto seguro que puedo matar al Demonio Rafaz'el" << endl;
					ConsoleSetColor(WHITE, BLACK);
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "HERRERO: Para forjar una espada necesito materiales." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         Vuelve cuando los tengas." << endl;
				}
				break;
			case 21000000: //FORJAR LLAVE
				if (Mundo.DialogLeyenda && items[HuevoDeOro].location == -1)
				{
					items[HuevoDeOro].location = 0;
					items[LlaveDeOro].location = -1;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "HERRERO: ¡Vaya! Parece que la leyenda tiene parte de verdad..." << endl;
					ConsoleXY(3, fila); fila++;
					ConsoleSetColor(YELLOW, BLACK);
					cout << "          HAS RECIBIDO UNA LLAVE DE ORO" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "          Ahora te toca descubrir cuál es tu camino para salvar el mundo." << endl;
					ConsoleSetColor(WHITE, BLACK);
				}
				else if (!Mundo.DialogLeyenda) {
					ConsoleXY(3, fila); fila++;
					cout << "HERRERO: ¿Para que quieres tu una llave de oro?." << endl;
				}
				else {
					ConsoleXY(3, fila); fila++;
					cout << "HERRERO: Para forjar una llave dorada como la de la leyenda necesito mucho oro." << endl;
					ConsoleXY(3, fila); fila++;
					cout << "         Vuelve cuando lo tengas." << endl;
				}
				break;
			}
			break;
		case 14:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000001: //IR NORTE
				idSala = 15;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				PlaySound(TEXT("DevilTheme.wav"), NULL, SND_ASYNC | SND_LOOP);
				break;
			case 1000002: //IR SUR
				idSala = 2;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				break;
			case 3012000: //MIRAR TRIGO
				ConsoleXY(3, fila); fila++;
				cout << "Un bonito trigo... Con el trigo se hace pan. CREO." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "Aunque creo que las gallinas comen trigo sin cocinar." << endl;
				ConsoleXY(3, fila); fila++;
				cout << "No se, no soy granjero..." << endl;
				break;
			case 14012000: //ENCENDER TRIGO
				ConsoleXY(3, fila); fila++;
				cout << "¡ESTÁS LOCO! Manolo me cae mal, ¡Pero no le quemaría el campo!" << endl;
				break;
			}
			break;
		case 15:
			switch (numAction) {
			default:
				ConsoleXY(3, fila); fila++;
				cout << "No sé qué quieres hacer :(" << endl;
				break;
			case 1000002: //IR SUR
				idSala = 2;
				ConsoleXY(3, fila); fila++;
				cout << "Caminando..." << endl;
				PlaySound(TEXT("ost.wav"), NULL, SND_ASYNC | SND_LOOP);
				break;
			case 2005000: //USAR ESPADA SAGRADA
				if (items[EspadaSagrada].location == -1)
				{
					ConsoleXY(3, fila); fila++;
					cout << "ZAS... ZUS... ¡DEMONIO MALVADO! ¡MUERE!" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "¡...!" << endl;
					ConsoleWait(2000);
					DialogDemonioDeath();
					idSala = 0;
				}
				break;
			case 6011000: //DAR CUPON DE RAMEN
				DialogDemonioRamen();
				idSala = 0;
				break;
			case 9000000: //PEGAR
				if (items[EspadaSagrada].location == -1)
				{
					ConsoleXY(3, fila); fila++;
					cout << "ZAS... ZUS... ¡DEMONIO MALVADO! ¡MUERE!" << endl;
					ConsoleXY(3, fila); fila++;
					cout << "¡...!" << endl;
					ConsoleWait(2000);
					DialogDemonioDeath();
					idSala = 0;
				} else {
					ConsoleXY(3, fila); fila++;
					cout << "Sin espada, Furgencio decidió pegar a Rafaz'el" << endl;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "¡Con los puños!" << endl;
					ConsoleXY(3, fila); fila++; fila++;
					cout << "y evidentemente Furgenció fue comido por el Demonio." << endl;
					ConsoleXY(20, fila);
					cout << "         ..." << endl;
					ConsoleXY(3, fila); ConsoleSetColor(RED, BLACK);
					cout << "                       ..." << endl;
					ConsoleWait(5000);
					idSala = 0;
				}
				break;
			}
			break;
		}
	}
}
