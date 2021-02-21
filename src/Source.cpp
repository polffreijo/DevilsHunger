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
#include <tchar.h>

#pragma comment(lib, "winmm.lib")
#pragma execution_character_set( "UTF-8" ) //PODER ESCRIBIR EN LA CONSOLA CON CARACTERES ESPAÑOLES

using namespace std;

events Mundo;

item items[_TOTAL];

void DefaultStart(bool& endGame, bool& playing, bool& howto, int& idSala) {
	for (int i = 0; i < _TOTAL; i++)
	{
		items[i].id = i;
		items[i].location = 0;
		items[i].usable = 0; //Será usable una vez esté recogida; dejará de serlo cuando el contador de usos llegue a 0.
	}

	items[LlaveDeCasa].name = "Llave de Casa";
	items[LlaveDeOro].name = "Llave de Oro";
	items[MetalSagrado].name = "Metal Sagrado";
	items[EspadaSagrada].name = "Espada Sagrada";
	items[MonedaDeOro].name = "Moneda de Oro";
	items[CuponDeRamen].name = "Cupon de Ramen";
	items[Trigo].name = "Trigo";
	items[Gallina].name = "Gallina";
	items[HuevoDeOro].name = "Huevo de Oro";
	items[DiccionarioSatanico].name = "Diccionario Satanico";
	items[LlavesDeCampo].name = "Llaves de Campo";

	items[Trigo].location = 14;
	items[DiccionarioSatanico].location = 11;

	Mundo.CuponRecibido = false;
	Mundo.MonedaEnFuente = false;
	Mundo.PiedraMedianaMovida = false;
	Mundo.PuertaCasaAbierta = false;
	Mundo.DialogCoche = false;
	Mundo.PuertaCampoAbierta = false;
	Mundo.ResetCruce = false;
	Mundo.VentanaHabiacion = false;
	Mundo.LlavesManolo = false;
	Mundo.DialogManolo = true;
	Mundo.DialogPaquita = true;
	Mundo.GallinaPaquita = false;
	Mundo.DialogGus = false;
	Mundo.isDictionaryRead = false;
	Mundo.isChestOpen = false;
	Mundo.isEgg = false;
	Mundo.DialogLeyenda = false;

	endGame = false;  playing = false; howto = false; idSala = 1;
}

int main(void) {

	//VARIABLES
	bool endGame, playing, howto;
	
	////GAMEPLAY
	int idSala;
		
	DefaultStart(endGame, playing, howto, idSala);
	
	SetConsoleOutputCP(65001); //PARA PODER MOSTRAR CARACTERES ESPAÑOLES
	ConsoleSetColor(WHITE, BLACK);

	do {
		//MENU PRINCIPAL [JUGAR - COMO JUGAR - SALIR]
		int menuaction = menuPrincipal(); //RECIBO DE LA FUNCIÓN QUÉ OPCION HE ELEGIDO
		switch (menuaction) {
			case 1:
				playing = true;
				break;
			case 2:
				howto = true;
				break;
			case 3:
				endGame = true;
				break;
			default:
				break;
		}
		//

		//HOW TO PLAY
		if (howto) {
			HowToPlay();
			howto = false; //SÓLO SE MOSTRARÁ SI HE SELECCIONADO EN EL MENU LA OPCION DE COMO JUGAR
		}
		//
		
		bool showIntro = true; // Mostrar Introduccion (SI O NO)

		idSala = 1; //SALA INICIAL (PARA EL DEBUG PUEDO CAMBIARLA A LA QUE QUIERA, PERO LA INCIAL SERÁ 1 EN EL JUEGO FINAL)
		
		//PRESENTACION HISTORIA SI HEMOS EMPEZADO A JUGAR
		if (playing && showIntro) {
			PlaySound(TEXT("ost.wav"), NULL, SND_ASYNC | SND_LOOP);
			PresentarHistoria();
			ConsoleClear();
		}
		else if (playing) {
			PlaySound(TEXT("ost.wav"), NULL, SND_ASYNC | SND_LOOP);
		}
		//

		//GAMEPLAY ( SI SELECCIONAMOS JUGAR )
		while(playing) {

			//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
			//SUELO USARLO PARA CENTRAR TEXTOS
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			int windowColumns, windowRows;

			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
			windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

			//

			ReprintHUD(idSala); //PONGO EL CUADRO DE PUNTITOS PARA HACERLO MAS BONITO TODO

			ReadSala(idSala, playing); //DESCRIPCION DE LA SALA EN LA QUE ESTAMOS

			ConsoleXY(3, windowRows - 2); //EN LA PENULTIMA FILA ESCRIBIMOS LAS ORDENES
			ConsoleSetColor(YELLOW, BLACK);
			cout << "Qué quieres hacer?: ";
			ConsoleSetColor(WHITE, BLACK);
			string action = "";
			getline(cin, action);
			transform(action.begin(), action.end(), action.begin(), ::toupper); //PONE LA ACCION A MAYUSCULAS PARA NO TENER QUE PREOCUPARSE LUEGO AL COMPARAR LOS TEXTOS

			if (action != "") { //SI SE HA ESCRITO ALGO
				int numAction = 0;
				numAction = ParseAction(action); //RECIBIR NUMERO DEL PARSE (QUÉ ES LO QUE EL USUARO QUIERE HACER)
				if (numAction == 9999999) playing = false; //SI QUIERE SALIR PONEMOS EL BOOL DE CONTROL PARA NO SEGUIR JUGANDO

				if (playing) {
					PerformAction(numAction, idSala); //COMPRUEBA SI EL USUARIO PUEDE HACER LO QUE HA PEDIDO EN LA SALA EN LA QUE ESTÁ
					ConsoleWait(1500);
				}
			}

			if (!playing)
			{
				ConsoleXY(windowColumns / 2 - 11, windowRows / 2);
				cout << "RESTART GAME? (Y/N): ";
				char restartResponse;
				cin >> restartResponse;

				if (restartResponse == 'Y' || restartResponse == 'y')
				{
					DefaultStart(endGame, playing, howto, idSala);
				}
			}
		
		}
		//

	} while (!endGame);

	//
}