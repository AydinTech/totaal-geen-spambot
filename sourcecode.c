#include <stdio.h>
#include <windows.h>

int hoevaak;
int teller;
char spam;
int enter;
int hoofdletter;
int langzaam;

int main() {
    printf("Hoe vaak moet ik spammen?\n"); //ff informatie opvragen hoor ik kan ook niet ruiken wat je wilt!
    scanf(" %i", &hoevaak);
    printf("Welke letter moet ik spammen?\n");
    scanf(" %c", &spam);
    printf("Moeten er lijnen omlaag/enters tussen zitten? 0 = nee, 1 = ja\n");
    scanf(" %i", &enter);
    printf("Moeten het hoofdletters zijn? (Dit zet caps lock aan!) 0 = kleine letters, 1 = hoofdletters\n");
    scanf(" %i", &hoofdletter);
    printf("Moet langzame modus aan staan? (1 seconde tussen de letters handig als er een anti spam is) 0 = nee, 1 = ja\n");
    scanf(" %i", &langzaam);

    printf("\nGa binnen 5 secondes naar het venster met het tekstbalk.\n"); //doe wat er staat anders werkt het niet

    Sleep(5000); //ff die 5 secondes tijd om naar dat venster te gaan

    if(hoofdletter == 1) keybd_event(VK_CAPITAL, 0x00, 0, 0); //voor het geval dat caps lock aan moest, dan wordt het hier geactiveerd

    for(teller = 0; teller < hoevaak; ++teller) { //ff een for loop maken zodat we de aangegeven hoeveelheid letters gaan spammen

        keybd_event( VkKeyScan(spam), 0x00, 0, 0); //nu gaan we die letter typen

        if(langzaam == 1) Sleep(1000); //voor als langzame modus aan staat

        if(enter == 1) keybd_event(VK_RETURN, 0x00, 0, 0); //voor het geval dat er enters moesten zijn, dan worden die erbij gezet
    }

    printf("\nKlaar, druk op een toets om het programma te sluiten.\n"); //dat was het dan alweer
    system("pause"); //gewoon zodat het programma niet zomaar sluit
    return 0; //anders gaat het nooit meer afsluiten
}
