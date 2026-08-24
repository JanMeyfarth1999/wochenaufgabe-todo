#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int istGueltigeNummer(char *text, long *ergebnis)
{
    char *endptr;
    *ergebnis = strtol(text ,&endptr, 10);
    if (endptr == text || *endptr != '\0' || *ergebnis <= 0)
    {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int options;
    long itemNummer;
    char *endptr;
    // Lässt nur meinen default als fehler auswerfen und lässt 
    // die Fehlermeldung von getopt() nicht mehr auswerfen:
    opterr = 0;
    while ((options = getopt(argc, argv, ":hla:d:c:")) != -1)
    {

        switch (options)
        {
            default:
            printf("Ungültiger Itembefehl\n");
            break;

        case ':':
            printf("Bekannte Option aber fehlendes Argument\n");
            break;

        case '?':
            printf("Unbekannte Option\n");
            break;    
            
        case 'h':
            printf("Hilfe wurde abgerufen.\n");
            break;

        case 'l':
            printf("Liste wurde abgerufen.\n");
            break;

        case 'a':
            FILE *datei;
            datei = fopen("todo.txt", "a");
            if(datei == NULL)
            { 
            printf("Datei konnte nicht geöffnet werden !");
            return 1;
            }
            fprintf(datei, "%s\n", optarg);
            fclose(datei);
            printf("Neue Aufgabe: %s", optarg);
            break;

        case 'd':
            if (istGueltigeNummer(optarg, &itemNummer) == 0)
            {
                printf("Ungültige Item-Nummer !\n");
                break;
            }
            printf("Item zum Löschen: %ld\n", itemNummer);
            break;

        case 'c':
            
            if (istGueltigeNummer(optarg, &itemNummer) == 0)
            {
                printf("Ungültige Item-Nummer !\n");
                break;
            }
            printf("Item zum Erledigen: %ld\n", itemNummer);
            break;
        }
    }

    return 0;
}