#include <iostream>
#include <cstdio>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include "ConsoleControl.h"
#include "Header.h"
#include <windows.h>
#include <algorithm>
#include <locale>
#include <string>

#pragma execution_character_set( "utf-8" ) //PODER ESCRIBIR EN LA CONSOLA CON CARACTERES ESPAÑOLES

using namespace std;

void ReprintHUD(int idSala) {

	ConsoleClear();

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleSetColor(GREEN, BLACK);

	//DIBUJAR CUADRADO EN LOS BORDES DE LAS VENTANAS
	for (int i = 0; i < windowColumns; i++) {
		ConsoleXY(i, 0);
		cout << "·";
	}

	for (int i = 0; i < windowRows; i++) {
		ConsoleXY(windowColumns - 1, i);
		cout << "·";
	}

	for (int i = 0; i < windowRows; i++) {
		ConsoleXY(0, i);
		cout << "·";
	}

	for (int i = 0; i < windowColumns - 1; i++) {
		ConsoleXY(i, windowRows - 1);
		cout << "·";
	}

	//DIBUJAR LINEA HORIZONTAL PARA SEPARAR EL ESPACIO DONDE ESCRIBES
	for (int i = 0; i < windowColumns - 1; i++) {
		ConsoleXY(i, windowRows - 3);
		cout << "·";
	}
	ConsoleSetColor(WHITE, BLACK);

	ConsoleXY(windowColumns - 11, 1);
	cout << "Sala: " << idSala;

}

int menuPrincipal() {

	int action = 0;
	int select = 1;

	do {
		//JUGAR -> action = 1
		//COMO JUGAR -> action = 2
		//SALIR -> action = 3

		//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
		//SUELO USARLO PARA CENTRAR TEXTOS
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int windowColumns, windowRows;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		//

		ConsoleClear();
		if (windowRows >= 26 && windowColumns >= 64) {
			//DIBUJAR TITULO
			ConsoleSetColor(GREEN, BLACK);
			int titleLine = 2;
			ConsoleXY((windowColumns / 2) - 32, titleLine); titleLine++;
			cout << "    ___           _ _ _                                         ";
			ConsoleXY((windowColumns / 2) - 32, titleLine); titleLine++;
			cout << "   /   \\_____   _(_) ( )__    /\\  /\\_   _ _ __   __ _  ___ _ __ ";
			ConsoleXY((windowColumns / 2) - 32, titleLine); titleLine++;
			cout << "  / /\\ / _ \\ \\ / / | |/ __|  / /_/ / | | | '_ \\ / _` |/ _ \\ '__|";
			ConsoleXY((windowColumns / 2) - 32, titleLine); titleLine++;
			cout << " / /_//  __/\\ V /| | |\\__ \\ / __  /| |_| | | | | (_| |  __/ |   ";
			ConsoleXY((windowColumns / 2) - 32, titleLine); titleLine++;
			cout << "/___,' \\___| \\_/ |_|_||___/ \\/ /_/  \\__,_|_| |_|\\__, |\\___|_|   ";
			ConsoleXY((windowColumns / 2) - 32, titleLine); titleLine++;
			cout << "                                                |___/           ";
			ConsoleSetColor(WHITE, BLACK);

			//
		}

		//DIBUJAR MENU CON RECUADRO
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) - 3);
		cout << "+--------------------------------+";
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) - 2);
		cout << "|                                |";
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) - 1);
		cout << "|               ";
		if (select == 1) {
			ConsoleSetColor(GREEN, BLACK);
			cout << "JUGAR";
			ConsoleSetColor(WHITE, BLACK);
		}
		else cout << "JUGAR";
		cout << "            |";
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2));
		cout << "|               ";
		if (select == 2) {
			ConsoleSetColor(GREEN, BLACK);
			cout << "COMO JUGAR";
			ConsoleSetColor(WHITE, BLACK);
		}
		else cout << "COMO JUGAR";
		cout << "       |";
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) + 1);
		cout << "|               ";
		if (select == 3) {
			ConsoleSetColor(GREEN, BLACK);
			cout << "SALIR";
			ConsoleSetColor(WHITE, BLACK);
		} else cout << "SALIR";
		cout << "            |";
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) + 2);
		cout << "|                                |";
		ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) + 3);
		cout << "+--------------------------------+";

		//

		switch (select) {
		case 1:
			ConsoleXY((windowColumns / 2) - 7, (windowRows / 2) - 1);
			ConsoleSetColor(GREEN, BLACK);
			cout << "--->";
			ConsoleSetColor(WHITE, BLACK);
			break;
		case 2:
			ConsoleXY((windowColumns / 2) - 7, (windowRows / 2));
			ConsoleSetColor(GREEN, BLACK);
			cout << "--->";
			ConsoleSetColor(WHITE, BLACK);
			break;
		case 3:
			ConsoleXY((windowColumns / 2) - 7, (windowRows / 2) + 1);
			ConsoleSetColor(GREEN, BLACK);
			cout << "--->";
			ConsoleSetColor(WHITE, BLACK);
			break;
		}

		//CAMBIAR SELECCION MEDIANTE TECLADO
		int tecla = 0;
		while (tecla != KB_DOWN && tecla != KB_UP && tecla != KB_ENTER && tecla != KB_ESCAPE)
		{
			tecla = ConsoleInKey();
		}

		if (tecla == KB_DOWN) {
			if (select < 3) select += 1;
			else select = 1;
		}
		else if (tecla == KB_UP) {
			if (select > 1) select -= 1;
			else select = 3;
		}
		else if (tecla == KB_ENTER) {
			action = select;
		}
		else if (tecla == KB_ESCAPE) return 3;

		//
	} while (action == 0);

	return action;
}

void DrawCastle() {

	//CONSOLE WIDTH AND HEIGHT
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleSetColor(DARKCYAN, BLACK);
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 9);
	cout << "                                       ,.=,,==. ,,_";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 8);
	cout << "                      _ ,====, _    |I|`` ||  `|I `|";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 7);
	cout << "                     |`I|    || `==,|``   ^^   ``  |";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 6);
	cout << "                     | ``    ^^    ||_,===TT`==,,_ |";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 5);
	cout << "                     |,==Y``Y==,,__| \L=_-`'   +J/`";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 4);
	cout << "                      \|=_  ' -=#J/..-|=_-     =|";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 3);
	cout << "                       |=_   -;-='`. .|=_-     =|----T--,";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 2);
	cout << "                       |=/\  -|=_-. . |=_-/^\  =||-|-|::|____";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) - 1);
	cout << "                       |=||  -|=_-. . |=_-| |  =|-|-||::\____";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2));
	cout << "                       |=LJ  -|=_-. . |=_-|_| =||-|-|:::::::";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 1);
	cout << "                       |=_   -|=_-_.  |=_-     =|-|-||:::::::";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 2);
	cout << "                       |=_   -|=//^\. |=_-     =||-|-|:::::::";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 3);
	cout << "                   ,   |/&_,_-|=||  | |=_-     =|-|-||:::::::";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 4);
	cout << "                ,--``8%,/    ',%||  | |=_-     =||-|-|%::::::";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 5);
	cout << "            ,---`_,888`  ,.'''''`-.,|,|/!,--,.&\|&\-,|&#:::::";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 6);
	cout << "           |;:;K`__,...;=\_____,=``           %%%&     %#,---";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 7);
	cout << "           |;::::::::::::|       `'.________+-------\   ``";
	ConsoleXY((windowColumns / 2) - 30, (windowRows / 2) + 8);
	cout << "          /8M%;:::;;:::::|                  |        `-------";
}

void PresentarHistoria() {
	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleClear();
	ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) - 2); //CENTRAR TEXTO ----> ((tamañoHorizontal/2)- mitad de los carácteres escritos, (tamañoVertiacal/2) - mitad de lineas usadas)
	cout << "Había una vez en una pequeña ciudad";
	ConsoleXY((windowColumns / 2) - 15, (windowRows / 2) - 1);
	cout << "donde nadie se metía con nadie";
	ConsoleXY((windowColumns / 2) - 14, (windowRows / 2));
	cout << "y todo el mundo vivía en paz";
	ConsoleXY((windowColumns / 2) - 15, (windowRows / 2) + 1);
	cout << "(menos Paco que era muy borde)";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleXY((windowColumns / 2) - 15, (windowRows / 2) - 1);
	cout << "En ésta ciudad vivía Furgencio,";
	ConsoleXY((windowColumns / 2) - 16, (windowRows / 2));
	cout << "un joven modesto pero travieso :)";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleXY((windowColumns / 2) - 21, (windowRows / 2) - 2);
	cout << "Furgencio tenía una vida normal y tranquila";
	ConsoleXY((windowColumns / 2) - 19, (windowRows / 2) - 1);
	cout << "hasta que un dia, estando de excursión";
	ConsoleXY((windowColumns / 2) - 22, (windowRows / 2));
	cout << "en un acantialado cercano, al sur de su casa,";
	ConsoleXY((windowColumns / 2) - 16, (windowRows / 2) + 1);
	cout << "pasó algo que le cambió la vida...";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 4, (windowRows / 2) - 1);
	cout << "'EH, TU!'";
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY((windowColumns / 2) - 14, (windowRows / 2));
	cout << "se escuchó una voz celestial";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 22, (windowRows / 2) - 1);
	cout << "'VALIENTE JOVEN, LA CIUDAD NECESITA TU AYUDA'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 19, (windowRows / 2) - 1);
	cout << "'EL DEMONIO RAFAZ'EL ESTA MUY ENFADADO'";
	ConsoleXY((windowColumns / 2) - 10, (windowRows / 2));
	cout << "'Y QUIERE DESTRUIRLA'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(DARKYELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 11, (windowRows / 2) - 1);
	cout << "'¿¡QUIEN ME HABLA?! :('";
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY((windowColumns / 2) - 13, (windowRows / 2));
	cout << "contestó el joven Furgencio";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleXY((windowColumns / 2) - 2, (windowRows / 2) - 1);
	cout << "'...'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 8, (windowRows / 2) - 1);
	cout << "'ME LLAMO AESIR'";
	ConsoleXY((windowColumns / 2) - 18, (windowRows / 2));
	cout << "'SOY LA DIOSA QUE CREÓ ESTE LUGAR'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 9, (windowRows / 2) - 2);
	cout << "'PERO AL NACER YO'";
	ConsoleXY((windowColumns / 2) - 13, (windowRows / 2) - 1);
	cout << "'RAFAZ'EL TAMBIEN APARECIÓ'";
	ConsoleXY((windowColumns / 2) - 17, (windowRows / 2));
	cout << "'SE PODRÍA DECIR QUE ES MI HERMANO'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 18, (windowRows / 2) - 1);
	cout << "'Y AUNQUE EN EL FONDO ES BONDADOSO,'";
	ConsoleXY((windowColumns / 2) - 20, (windowRows / 2));
	cout << "'CUANDO SE ENFADA PUEDE HACER LOCURAS...'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(DARKYELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 11, (windowRows / 2) - 1);
	cout << "'¿Y cómo puedo ayudar?'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 16, (windowRows / 2) - 2);
	cout << "'ESO TENDRÁS QUE DESCUBRIRLO TU'";
	ConsoleXY((windowColumns / 2) - 18, (windowRows / 2) - 1);
	cout << "'AHORA ERES EL HÉROE DE LA HISTORIA,'";
	ConsoleXY((windowColumns / 2) - 11, (windowRows / 2));
	cout << "'TÚ CREARÁS TU CAMINO'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 11, (windowRows / 2) - 1);
	cout << "'SÓLO NECESITAS SABER'";
	ConsoleXY((windowColumns / 2) - 15, (windowRows / 2));
	cout << "'DÓNDE SE ENCUENTRA EL DEMONIO'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 25, (windowRows / 2) - 12);
	cout << "'SE ENCUENTRA EN EL CASTILLO AL NORTE DE LA CIUDAD'";
	ConsoleXY((windowColumns / 2) - 20, (windowRows / 2) - 11);
	cout << "'SIGUIENDO EL CAMINO SECRETO DE TU CASA'";

	DrawCastle();

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleSetColor(MAGENTA, BLACK);
	ConsoleXY((windowColumns / 2) - 8, (windowRows / 2) - 1);
	cout << "'SUERTE, FURGENCIO'";
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY((windowColumns / 2) - 18, (windowRows / 2));
	cout << "Dijo Aesir justo antes de desaparecer";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ConsoleXY((windowColumns / 2) - 2, (windowRows / 2) - 1);
	cout << "'...'";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);
}

void HowToPlay() {
	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//
	ConsoleClear();
	ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) - 2); //CENTRAR TEXTO ----> ((tamañoHorizontal/2)- mitad de los carácteres escritos, (tamañoVertiacal/2) - mitad de lineas usadas)
	cout << "Para jugar solo tienes que escribir";
	ConsoleXY((windowColumns / 2) - 19, (windowRows / 2) - 1);
	cout << "en consola que es lo que quieres hacer";
	ConsoleXY((windowColumns / 2) - 4, (windowRows / 2));
	cout << "EJEMPLOS:";
	ConsoleXY((windowColumns / 2) - 5, (windowRows / 2) + 1);
	cout << "IR al NORTE";
	ConsoleXY((windowColumns / 2) - 9, (windowRows / 2) + 2);
	cout << "COGER LLAVE DE CASA";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);
	ConsoleClear();

	ConsoleXY((windowColumns / 2) - 33, (windowRows / 2) - 1);
	cout << "Verás la descripción de la sala y qué hay en ella en todo momento.";
	ConsoleXY((windowColumns / 2) - 32, (windowRows / 2));
	cout << "Para ver qué objetos tienes en tu inventario tienes que escribir:";
	ConsoleXY((windowColumns / 2) - 5, (windowRows / 2) + 1);
	cout << "INVENTARIO";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);
	ConsoleClear();
	

	ConsoleXY((windowColumns / 2) - 21, (windowRows / 2) - 1);
	cout << "Para ver los vervos que se pueden utilizar:";
	ConsoleXY((windowColumns / 2) - 10, (windowRows / 2) + 1);
	cout << "Escribe AYUDA o HELP";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);
	ConsoleClear();


	ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) - 1);
	cout << "Para cerrar la partda y volver al menú principal:";
	ConsoleXY((windowColumns / 2) - 9, (windowRows / 2) + 1);
	cout << "Escribe EXIT o QUIT";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

}

void ReadDictionary(int idSala) {
	ConsoleClear();
	ReprintHUD(idSala);

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) - 4);
	cout << "~ DICCIONARIO SATANICO PARA GENTE NO MUY LISTA ~";
	ConsoleXY((windowColumns / 2) - 32, (windowRows / 2) - 1);
	cout << "ira ten’ rashwe! lle ista amin quella no’ amin sen amin utue ta.";
	ConsoleXY((windowColumns / 2) - 31, (windowRows / 2));
	cout << "Lema ed' templa bragol thalion nai uuvanimo turamin Narquelie.";
	ConsoleXY((windowColumns / 2) - 35, (windowRows / 2) + 1);
	cout << "Yala onna lle merna aut farien tenna’ san’ malia ten’ fion laure sereg?";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleXY((windowColumns / 2) - 29, (windowRows / 2) - 4);
	cout << "~ DICCIONARIO SATANICO PARA GENTE NO MUY LISTA | PAGINA 2 ~";
	ConsoleXY((windowColumns / 2) - 44, (windowRows / 2) - 1);
	cout << "Tyara harwar elea ie’ dome sina mani naa essa en lle? Ta naa nae seasamin templa pilini’";
	ConsoleXY((windowColumns / 2) - 27, (windowRows / 2));
	cout << "Ram en' ondo Cairbara lema ed' ando en' templa Yallume.";
	ConsoleXY((windowColumns / 2) - 40, (windowRows / 2) + 1);
	cout << "‘kshonna, wanya yala onna en’ naur. An lema Mith’quessir Isilya creoso a’baramin.";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleXY((windowColumns / 2) - 29, (windowRows / 2) - 4);
	cout << "~ DICCIONARIO SATANICO PARA GENTE NO MUY LISTA | PAGINA 3 ~";
	ConsoleXY((windowColumns / 2) - 19, (windowRows / 2) - 1);
	cout << "Neuma! hama sinome Nwalmaerea Lannerea.";
	ConsoleXY((windowColumns / 2) - 53, (windowRows / 2));
	cout << "Yala rauko quel marth llie n'vanima ar' lle atara lanneina lissenen ar' maska'lalaith tenna' lye omentuva.";
	ConsoleXY((windowColumns / 2) - 41, (windowRows / 2) + 1);
	cout << "Antolle ulua sulrim pelekta yassen i' handele n'ndengina ta ho parm templa tengwa.";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);

	Mundo.isDictionaryRead = true;
}

void ShowHelp(int idSala) {
	ConsoleClear();
	ReprintHUD(idSala);

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleXY((windowColumns / 2) - 15, (windowRows / 2) - 2);
	cout << "VERBOS QUE SE PUEDEN UTILIZAR:";
	ConsoleXY((windowColumns / 2) - 31, (windowRows / 2));
	cout << "USAR, COGER, SOLTAR, DAR, HABLAR, MOVER, PEGAR, EMPUJAR, TIRAR,";
	ConsoleXY((windowColumns / 2) - 31, (windowRows / 2) + 1);
	cout << "MIRAR, ABRIR, IR, CERRAR, ENCENDER, QUITAR, PONER, LEER, HACER.";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(WHITE, BLACK);
}

void Leyenda(int idSala) {
	ConsoleClear();
	ReprintHUD(idSala);

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 13, (windowRows / 2) - 1);
	cout << "LEYENDA DEL HUEVO DORADO:";
	ConsoleXY((windowColumns / 2) - 23, (windowRows / 2));
	cout << "Cuenta la Leyenda, que el mundo en que vivimos";
	ConsoleXY((windowColumns / 2) - 19, (windowRows / 2) + 1);
	cout << "Tiene mas mágia que la que conocemos...";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 10, (windowRows / 2) - 1);
	cout << "El aire tiene magia,";
	ConsoleXY((windowColumns / 2) - 11, (windowRows / 2));
	cout << "La tierra tiene magia,";
	ConsoleXY((windowColumns / 2) - 11, (windowRows / 2) + 1);
	cout << "El agua tiene magia...";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 14, (windowRows / 2) - 1);
	cout << "Todos los animales y personas";
	ConsoleXY((windowColumns / 2) - 18, (windowRows / 2));
	cout << "tienen magia, porque vivimos de ella.";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 27, (windowRows / 2) - 1);
	cout << "Y la magia, que siempre ayuda a los seres de este mundo";
	ConsoleXY((windowColumns / 2) - 15, (windowRows / 2));
	cout << "Algún dia, cuando sea necesario";
	ConsoleXY((windowColumns / 2) - 22, (windowRows / 2) + 1);
	cout << "Ayudará a un Joven y le dará un Huevo de Oro";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 10, (windowRows / 2) - 1);
	cout << "Que forjará una llave";
	ConsoleXY((windowColumns / 2) - 21, (windowRows / 2));
	cout << "para emprender un camino hacia la salvación";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	Mundo.DialogLeyenda = true;
}

void DialogDemonio() {
	int idSala = 15;
	ConsoleClear();
	ReprintHUD(idSala);

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	if (Mundo.isDictionaryRead)
	{
		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 7, (windowRows / 2) - 1);
		cout << "¿QUIÉN ERES TU?";
		ConsoleXY((windowColumns / 2) - 8, (windowRows / 2) + 1);
		cout << "¿QUE HACES AQUÍ?";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 10, (windowRows / 2) - 1);
		cout << "¿TE ENVIA MI HERMANA?";
		ConsoleXY((windowColumns / 2) - 3, (windowRows / 2) + 1);
		cout << "¿AESIR?";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 15, (windowRows / 2) - 1);
		cout << "PUES YA TE DIGO AHORA MISMO...";
		ConsoleXY((windowColumns / 2) - 28, (windowRows / 2));
		cout << "¡QUE NO PODRÁS IMPEDIR QUE ME COMA A TODOS LOS HABITANTES";
		ConsoleXY((windowColumns / 2) - 7, (windowRows / 2) + 1);
		cout << "DE ESTA CIUDAD!";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 12, (windowRows / 2) - 1);
		cout << "TENGO MUCHA MUCHA HAMBRE";
		ConsoleXY((windowColumns / 2) - 13, (windowRows / 2));
		cout << "¡Y ESTOY MUY MUY ENFADADO!";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);
	}
	else {
		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 25, (windowRows / 2) - 1);
		cout << "¿Sulime naur tinchor ostring Taraerea lle maa quel?";
		ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) + 1);
		cout << "¿Lanta kaima Tincokemen Viresse manka lle merna?";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 34, (windowRows / 2) - 1);
		cout << "¿Creoso a'baramin lle creoso amin naa tualle poika tuulo' 'kshapsae?";
		ConsoleXY((windowColumns / 2) - 3, (windowRows / 2) + 1);
		cout << "¿AESIR?";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 37, (windowRows / 2) - 1);
		cout << "Neuma! uuner uma, n'dela no'ta amin dele ten' ho he sen nae saian luume'...";
		ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) + 1);
		cout << "¡Ya ohtar en oionaaru caela ie'lle Mori'quessir!";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);
	}
}

void DialogDemonioDeath() {
	int idSala = 15;
	ConsoleClear();
	ReprintHUD(idSala);

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) - 1);
	cout << "Y ASÍ ES COMO EL JOVEN FURGENCIO MATÓ AL DEMONIO";
	ConsoleXY((windowColumns / 2) - 25, (windowRows / 2) + 1);
	cout << "Y SALVÓ LA CIUDAD DE SUS SUCIOS Y APESTOSO DIENTES";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 14, (windowRows / 2) - 1);
	cout << "AUNQUE NUNCA NINGUN CONOCIDO";
	ConsoleXY((windowColumns / 2) - 9, (windowRows / 2) + 1);
	cout << "LE DARÁ LAS GRACIAS";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);

	ConsoleClear();
	ReprintHUD(idSala);

	ConsoleSetColor(YELLOW, BLACK);
	ConsoleXY((windowColumns / 2) - 17, (windowRows / 2) - 1);
	cout << "A FURGENCIO SÓLO LE IMPORTABA AHORA";
	ConsoleXY((windowColumns / 2) - 29, (windowRows / 2) + 1);
	cout << "QUE AÚN TENÍA TIEMPO A VOLVER AL CAMPO Y DORMIR UNA SIESTA";

	ConsoleSetColor(BLACK, BLACK);
	system("pause");
	ConsoleSetColor(YELLOW, BLACK);
}

void DialogDemonioRamen() {
	int idSala = 15;
	ConsoleClear();
	ReprintHUD(idSala);

	//CONSOLE WIDTH AND HEIGHT //COPIAR Y PEGAR DONDE QUIERA USAR windowColums y windowRows PARA SABER EL TAMAÑO DE LA VENTANA
	//SUELO USARLO PARA CENTRAR TEXTOS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int windowColumns, windowRows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	windowColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	windowRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//
	if (true)
	{
		if (items[CuponDeRamen].location == -1)
		{
			ConsoleSetColor(RED, BLACK);
			ConsoleXY((windowColumns / 2) - 6, (windowRows / 2) - 1);
			cout << "¿QUE ES ESTO?";
			ConsoleXY((windowColumns / 2) - 13, (windowRows / 2) + 1);
			cout << "¿UN CUPON DEL RESTAURANTE?";

			ConsoleSetColor(BLACK, BLACK);
			system("pause");
			ConsoleSetColor(RED, BLACK);

			ConsoleClear();
			ReprintHUD(idSala);

			ConsoleSetColor(RED, BLACK);
			ConsoleXY((windowColumns / 2) - 20, (windowRows / 2) - 1);
			cout << "¡¿QUE TE CREES QUE CON UN PLATO DE RAMEN";
			ConsoleXY((windowColumns / 2) - 9, (windowRows / 2) + 1);
			cout << "ESTARÉ SATISFECHO?!";

			ConsoleSetColor(BLACK, BLACK);
			system("pause");
			ConsoleSetColor(RED, BLACK);

			ConsoleClear();
			ReprintHUD(idSala);

			ConsoleSetColor(RED, BLACK);
			ConsoleXY((windowColumns / 2) - 14, (windowRows / 2) - 1);
			cout << "AH, QUE ES DE POR VIDA???...";
			ConsoleXY((windowColumns / 2) - 9, (windowRows / 2));
			cout << "¡ENTONCES ME VALE!";
			ConsoleXY((windowColumns / 2) - 20, (windowRows / 2) + 1);
			cout << "¡CENAR RAMEN TODOS LOS DIAS ES MI SUEÑO!";

			ConsoleSetColor(BLACK, BLACK);
			system("pause");
			ConsoleSetColor(RED, BLACK);

			ConsoleClear();
			ReprintHUD(idSala);

			ConsoleSetColor(RED, BLACK);
			ConsoleXY((windowColumns / 2) - 12, (windowRows / 2) - 1);
			cout << "TENGO MUCHA MUCHA HAMBRE";
			ConsoleXY((windowColumns / 2) - 13, (windowRows / 2));
			cout << "¡Y ESTABA MUY MUY ENFADADO!";

			ConsoleSetColor(BLACK, BLACK);
			system("pause");
			ConsoleSetColor(RED, BLACK);

			ConsoleClear();
			ReprintHUD(idSala);

			ConsoleSetColor(RED, BLACK);
			ConsoleXY((windowColumns / 2) - 29, (windowRows / 2) - 1);
			cout << "PERO AHORA TU ME HAS DADO LA SOLUCION A TODOS MIS PROBLEMAS";
			ConsoleXY((windowColumns / 2) - 17, (windowRows / 2));
			cout << "Y TE ESTARÉ ETERNAMENTE AGRADECIDO";
			ConsoleXY((windowColumns / 2) - 14, (windowRows / 2) + 1);
			cout << "NO ME COMERÉ A LOS CIUDADANOS";

			ConsoleSetColor(BLACK, BLACK);
			system("pause");
			ConsoleSetColor(RED, BLACK);
		}
		else {
			ConsoleSetColor(YELLOW, BLACK);
			ConsoleXY((windowColumns / 2) - 6, (windowRows / 2) - 1);
			cout << "NO TIENES NINGUN CUPON DE RAMEN";
			ConsoleXY((windowColumns / 2) - 13, (windowRows / 2) + 1);
			cout << "ADEMAS, ES UN DEMONIO, ¿CREES QUE SERVIRIA DE ALGO?";
		}
	}
	else {
		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 25, (windowRows / 2) - 1);
		cout << "¿Sulime naur tinchor ostring Taraerea lle maa quel?";
		ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) + 1);
		cout << "¿Lanta kaima Tincokemen Viresse manka lle merna?";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 34, (windowRows / 2) - 1);
		cout << "¿Creoso a'baramin lle creoso amin naa tualle poika tuulo' 'kshapsae?";
		ConsoleXY((windowColumns / 2) - 3, (windowRows / 2) + 1);
		cout << "¿AESIR?";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);

		ConsoleClear();
		ReprintHUD(idSala);

		ConsoleSetColor(RED, BLACK);
		ConsoleXY((windowColumns / 2) - 37, (windowRows / 2) - 1);
		cout << "Neuma! uuner uma, n'dela no'ta amin dele ten' ho he sen nae saian luume'...";
		ConsoleXY((windowColumns / 2) - 24, (windowRows / 2) + 1);
		cout << "¡Ya ohtar en oionaaru caela ie'lle Mori'quessir!";

		ConsoleSetColor(BLACK, BLACK);
		system("pause");
		ConsoleSetColor(RED, BLACK);
	}
}