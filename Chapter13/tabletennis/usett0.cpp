#include <iostream>
#include "tabtenn0.h"

int main(void){
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Chunk", "Blizzard", true);
    RatedPlayer rplayer1(1140, "Tara", "Boomdea", false);
    rplayer1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
        
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;
    
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
        
    return 0;
}