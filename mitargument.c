#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int options;
    long itemNummer;
    char *endptr;
    while ((options = getopt(argc, argv, "hla:d:c:")) != -1)
    {

        switch (options)
        {
        case 'h':
            printf("Hilfe wurde abgerufen.\n");
            break;

        case 'l':
            printf("Liste wurde abgerufen.\n");
            break;

        case 'a':
            printf("Neue Aufgabe: %s\n", optarg);
             break;
        case 'd':
            itemNummer = strtol(optarg, &endptr, 10);
            if(endptr == optarg || *endptr != '\0' || itemNummer <= 0 ) {
            printf("Ungültige Item-Nummer !");
            break;
            }
            printf("Item zum Löschen: %ld\n", itemNummer);
            break;
        case 'c':
            itemNummer = strtol(optarg, &endptr, 10);
            if(endptr == optarg || *endptr != '\0' || itemNummer <= 0 ) {
            printf("Ungültige Item-Nummer !");
            break;
            }
            printf("Item zum Erledigen: %ld\n", itemNummer);
            break;
        }
    }

    return 0;
}