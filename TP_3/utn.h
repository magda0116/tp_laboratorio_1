typedef struct {
    char ETitulo[31];
    char EGenero[31];
    int  EDuracion;
    char EDescripcion[101];
    int  EPuntaje;
    char ELImagen[81];
    int Eestado;
}EMovie;

void Menu();

int Val_Menu(int *opc,char mensaje[],char mensajeError[]);

void Agregar(EMovie *E_peli, FILE *pFile);

void Borrar(EMovie *E_peli, FILE *pFile);

void Modificar(EMovie *E_peli, FILE *pFile);

int Generar_PWeb(EMovie *E_peli, FILE *pFile);

int Val_Entero(int opc, int desde, int hasta);

void Val_Cadena(char opc[]);



