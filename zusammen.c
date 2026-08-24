#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int istGueltigeNummer(char *text, long *ergebnis)
{
    char *endptr;
    *ergebnis = strtol(text, &endptr, 10);
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
    char zeile[256];
    int zeilenNummer = 0;
    FILE *datei;
    FILE *tempDatei;
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
            datei = fopen("todo.txt", "r");
            if (datei == NULL)
            {
                printf("Es befinden sich aktuell keine Aufgaben im Ordner 'todo.txt' !");
                return 1;
            }
            while (fgets(zeile, 256, datei) != NULL)
            {
                zeilenNummer++;
                printf("%d: %s", zeilenNummer, zeile);
            }
            fclose(datei);
            break;

        case 'a':
            datei = fopen("todo.txt", "a");
            if (datei == NULL)
            {
                printf("Datei konnte nicht geöffnet werden !");
                return 1;
            }
            fprintf(datei, "%s\n", optarg);
            fclose(datei);
            printf("Neue Aufgabe: %s\n", optarg);
            break;

        case 'd':
            if (istGueltigeNummer(optarg, &itemNummer) == 0)
            {
                printf("Ungültige Item-Nummer !\n");
                break;
            }
            datei = fopen("todo.txt", "r");
            if (datei == NULL)
            {
                printf("Datei konnte nicht geöffnet werden !");
                return 1;
            }
            tempDatei = fopen("temp.txt", "w");
            if (tempDatei == NULL)
            {
                fclose(datei);                
                printf("Datei konnte nicht geöffnet werden !");
                return 1;
            }
            zeilenNummer = 0;
            int gefunden = 0;
            while (fgets(zeile, 256, datei) != NULL)
            {
                zeilenNummer++;
                if (zeilenNummer == itemNummer)
                {
                    gefunden = 1;
                }

                if (zeilenNummer != itemNummer)
                {

                    fprintf(tempDatei, "%s", zeile);
                }
            }
            fclose(datei);
            fclose(tempDatei);
            if (gefunden == 0)
            {
                remove("temp.txt");
                printf("Item %ld existiert nicht!\n", itemNummer);
                break;
            }

            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            printf("Item %ld wurde gelöscht!\n", itemNummer);
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