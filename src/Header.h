#pragma once

enum inventario {
	LlaveDeCasa, LlaveDeOro, MetalSagrado, EspadaSagrada, MonedaDeOro, CuponDeRamen, Trigo, Gallina, HuevoDeOro, DiccionarioSatanico, LlavesDeCampo, _TOTAL}; //List of items

struct item
{
	int id;
	std::string name;
	int usable; //number of uses left
	int location; //if -1 = in inventory
};

struct events
{
	bool CuponRecibido;
	bool MonedaEnFuente;
	bool PiedraMedianaMovida;
	bool PuertaCasaAbierta;
	bool DialogCoche;
	bool PuertaCampoAbierta;
	bool ResetCruce;
	bool VentanaHabiacion;
	bool LlavesManolo;
	bool DialogManolo;
	bool DialogPaquita;
	bool GallinaPaquita;
	bool DialogGus;
	bool isDictionaryRead;
	bool isChestOpen;
	bool isEgg;
	bool DialogLeyenda;
}; //USO ESTO PARA CONTROLAR EVENTOS; SI HE RECOGIDO UN OBJETO YA, O SI YA HE ABIERTO UNA PUERTA...

extern events Mundo;
////�STAS VARIABLES SON EXTERNAS PARA QUE SEAN EDITABLES DESDE TODOS LOS CPP Y FUNCIONES. SE DECLARAN EN EL SOURCE.CPP
extern item items[_TOTAL];

//CONTROLLER

/**
 * Prints Items contained in the Room.
 *
 * @param idSala int id of the Room to check.
 * 
 */
void ListItemsSala(int idSala);

/**
 * Prints the text of the current Room.
 *
 * @param idSala int id of the Room to check.
 * @param &playing Pointer of the Playing State boolean.
 *
 */
void ReadSala(int idsala, bool &playing);

/**
 * Prints the text of the current Room.
 *
 * @param idSala int id of the Room to check.
 * @param &playing Pointer of the Playing State boolean.
 *
 */
int ParseAction(std::string &accion);
void PerformAction(int numAction, int &idSala);

//DRAW
void ReprintHUD(int idSala);
int menuPrincipal();
void DrawCastle();
void PresentarHistoria();
void HowToPlay();
void ShowHelp(int idSala);
void ReadDictionary(int idSala);
void Leyenda(int idSala);
void DialogDemonio();
void DialogDemonioDeath();
void DialogDemonioRamen();

//GAMEPLAY - SOURCE
void DefaultStart(bool& endGame, bool& playing, bool& howto, int& idSala);