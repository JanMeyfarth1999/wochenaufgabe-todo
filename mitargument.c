#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int options;
    long itemNummer;
    while ((options = getopt(argc, argv, "hla:d:")) != -1)
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
            itemNummer = atoi(optarg);
            printf("Item zum Löschen: %d\n", itemNummer);
            break;
        }
    }

    return 0;
}