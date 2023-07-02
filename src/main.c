#include <stdio.h> // Ein und Ausgabe
#include <string.h> // Verarbeitung von Stringketten

/* Funktionen bekannt machen */
/*
main.c:20:5: error: call to undeclared function 'werte_aendern_ueber_zeiger'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
    werte_aendern_ueber_zeiger(&preisZeiger);
    ^
main.c:33:6: error: conflicting types for 'werte_aendern_ueber_zeiger'
void werte_aendern_ueber_zeiger(double *preisZeiger)
     ^
main.c:20:5: note: previous implicit declaration is here
    werte_aendern_ueber_zeiger(&preisZeiger);
    ^
*/
void werte_aendern_ueber_zeiger(double *preisZeiger);
void ausgabeFeld(double *dfeld, int count);

void readtxt()
{
    FILE *fp;
    char zeile[100];
    int i = 0;

    fp = fopen("test.txt", "r");
    while (fgets(zeile, 100, fp) != NULL)
    {
        i++;
    }
    fclose(fp);
    
}
void writetxt()
{
    FILE *fp;
    char zeile[100];
    int i = 0;

    fp = fopen("test.txt", "w");
    if(fp!= NULL)
    {
        fprintf(fp, "%s", "Hallo \n");
    }
    fclose(fp);

}
void txt()
{
    writetxt();
}

struct artikel
{
    /* data */
    int id;
    char name[20];
    double preis;
};
void teststruct()
{
    struct artikel a , b;
    a.id = 1;
    strcpy(a.name, "Apple");
    a.preis = 2.50;

    b.id = 2;
    strcpy(b.name, "Birne");
    b.preis = 3.50;

    printf("ID: %d\n", a.id);
    printf("Name: %s\n", a.name);
    printf("Preis: %f\n", a.preis);
    printf("\n");
    printf("ID: %d\n", b.id);
    printf("Name: %s\n", b.name);
    printf("Preis: %f\n", b.preis);

    // Möglich ist auch 
    // struct artikel artikelFeld[20];
    // Beispiele, for schleife wäre ideal zum befüllen oder anzeigen
    // artikelFeld[0].id = 1;
    // strcpy(artikelFeld[0].name, "Apple");
    // artikelFeld[0].preis = 2.50;
    // artikelFeld[1].id = 2;
    // strcpy(artikelFeld[1].name, "Birne");
    // artikelFeld[1].preis = 3.50;
    // printf("ID: %d\n", artikelFeld[0].id);
    // printf("Name: %s\n", artikelFeld[0].name);
    // printf("Preis: %f\n", artikelFeld[0].preis);
    // printf("\n");
    // printf("ID: %d\n", artikelFeld[1].id);   
        
}


void zeiger()
{
    double preis = 1.45;
    double *preisZeiger = &preis;

    printf("preis = %f\n", preis);
    printf("&preis = %p\n", &preis);
    printf("preisZeiger = %p\n", preisZeiger);
    printf("*preisZeiger = %f\n", *preisZeiger);
    /*
    preis = 1.450000
    &preis = 0x16ee0b028
    preisZeiger = 0x16ee0b028
    *preisZeiger = 1.450000
    */

    printf("\n");
    werte_aendern_ueber_zeiger(preisZeiger);

    printf("preis = %f\n", preis);
    printf("&preis = %p\n", &preis);
    printf("preisZeiger = %p\n", preisZeiger);
    printf("*preisZeiger = %f\n", *preisZeiger);
    /*
    preis = 2.450000
    &preis = 0x16ee0b028
    preisZeiger = 0x16ee0b028
    *preisZeiger = 2.450000
    */

    printf("\n");
    double feld[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    ausgabeFeld(feld, sizeof(feld) / sizeof(double));   //Durch die Division von sizeof(feld) durch sizeof(double) erhältst du die Anzahl der double-Elemente im Array feld. 
}
void werte_aendern_ueber_zeiger(double *preisZeiger)
{
    *preisZeiger = 2.45;
}
void ausgabeFeld(double *dfeld, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("dfeld[%d] = %f\n", i, dfeld[i]);
    }
}

void teststring()
{
    char str_test[30];

    strcpy(str_test, "Hallo Maik"); // String kopieren
    printf("%s\n", str_test);

    char str_name[30] = {"Learn C"};
    printf("%s\n", str_name);
    printf("Buchstaben:  %lu\n", strlen(str_name));
    printf("erster Buchstabe:  %c\n", str_name[0]);
    printf("letzter Buchstabe:  %c\n", str_name[strlen(str_name)-1]);   // string Länge minus 1 (das \0 Endezeichen)

    printf("Name bitte eingeben:");
    scanf("%s", str_name);  // bis zum ersten Leerzeichen, mehr wird nicht eingelesen
    printf("Hallo %s\n", str_name);

    printf("%s Ende\n", str_name);
    printf("%15s Ende\n", str_name);    // rechtsbündig
    printf("%-15s Ende\n", str_name);   // linksbündig
    
}

void testarray()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    char array[10];
    printf("%s\n", "gebe bitte 10 mal einen Buchstaben an:");
    for (i = 0; i < 10; i++) {
        scanf("%c\n", &array[i]);
        
    }
    printf("%s\n", array);
}

int testloop()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    int num;
    for(num = 0; num < 10; num++)
    {
        printf("%d\n", num);
    }
    int flag = 0;
    do
    {
        printf("%d\n", flag);
        flag++;
    } while (flag == 5);
    
    while (flag < 1)
    {
        printf("%d\n", flag);
        flag--;
    }
    return 0;
}

int print_and_scan()
{
    /* Deklaration */
    int count;
    /* Zuweisung */
    count = 5;
    /* Ausgabe */
    // int = %d, %i ; double = %f (%.2f für 2 Nachkommastellen) 
    printf("%d\n", count);
    /* Eingabe */
    printf("Anzahl eingeben: ");
    scanf("%d", &count);//Dezimalpunkt statt Komma (%f nicht vergessen), Prüfung der eingabe wäre sehr wichtig 
    printf("Anzahl: %d\n", count);
    return 0;
}

int main(int argc, char *argv[]) 
{
    //print_and_scan();
    //testloop();
    //testarray();
    //teststring();
    //zeiger();
    //teststruct();
    txt();


    //printf("Hello, world!\n");
    return 0;
}