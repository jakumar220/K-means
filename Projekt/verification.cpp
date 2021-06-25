#include "verification.h"

bool ver_format(const char* filename, const char* extension) // do funkcji podane jest nazwa pliku i rozszerzenie .txt
{
	unsigned short file_len;		
	unsigned short exten_len =4;	// zmienna z dlugoscia rozszerzenia .txt
	file_len = strlen(filename);	//zmienna z dlugoscia nazwy pliku 

	if (!(exten_len <= file_len)) // sprawdzanie czy dlugosc pliku nie jest rowna lub mniejsza 4
	{
		return false;
	}
	if (!(strcmp(&filename[file_len-exten_len],extension))) //sprawdzenie, czy na ostatnich 4 znakach nazwy pliku jest .txt
	{
		return true;
	}
	else return false;
}
void help_arg()
{
	std::cout << "Dane wejsciowe: " << std::endl
		<< "-i : nazwa pliku z punktami  " << std::endl
		<< "-k; liczba centroidow " << std::endl;
}
bool ver_arg(int argc, char** argv, char*& filename, int& centroids_number)
{
	if (argc == 1)
	{
		std::cout << "Nie podany zostal zaden argument... Podaj -h, aby dowiedziec sie jakie sa wymagane argumenty." << std::endl;
		return false;
	}
	else {
		for (short i = 1; i < argc; i++)
		{
			if (strcmp(argv[i], "-h") == 0)
			{
				help_arg();
				return false;
			}
		}
		for (short i = 1; i < argc; i++)
		{
			if (strcmp(argv[i], "-i") == 0 and i + 1 < argc) {
				i++;
				filename = argv[i];
				if (!ver_format(filename, ".txt")) {				//sprawdzanie formatu pliku
					std::cout << "Podano zly plik wejsciowy: " << filename << std::endl;	//przekazanie dla uzytkownika ¿e podano b³êdny format
					return false;
				}
				
			}
			if (strcmp(argv[i], "-k") == 0 and i + 1 < argc) {
				++i;
				centroids_number = atoi(argv[i]);
			}
		}
	}
	
}



