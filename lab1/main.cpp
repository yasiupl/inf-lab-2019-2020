#include <iostream>

using namespace std;

typedef struct {
    int songs;
    char name[32];
    float price;
    char genre;
} Album;

Album createAlbum() {
    Album album;

    cout << endl << "Type in album name:" << endl;
    cin >> album.name;

    cout << "Type in genre:" << endl;
    cin >> album.genre;

    cout << "Type in number of songs:" << endl;
    cin >> album.songs;

    cout << "Type in price:" << endl;
    cin >> album.price;

    return album;
}

void displayAlbum(Album album) {
    cout << "Album name:" << album.name << endl;
    cout << "Genre:" << album.genre << endl;
    cout << "n* of songs:" << album.songs << endl;
    cout << "List Price:" << album.price << endl;
}

void displayByPrice(Album albums[], int length) {
    Album tmp;
    int n = length;
    do {
        for(int i = 0; i < length - 1; ++i) {
            if((albums[i].price > albums[i+1].price)) {
                tmp = albums[i+1];
                albums[i+1] = albums[i];
                albums[i] = tmp;
            }
        }
        --n;
    } while (n > 1);

    cout << endl << "Albums cheapest to priciest: " << endl;
    for(int i = 0; i < length; ++i){
        displayAlbum(albums[i]);
    }
}

void displayPriceInterval(Album albums[], int length, float lower, float upper) {
    cout << endl << "Albums in given price interval: " << endl;
    for(int i = 0; i < length - 1; ++i) {
        if((albums[i].price >= lower && albums[i].price <= upper)) {
            displayAlbum(albums[i]);
        }
    }
}

int main()
{
    int albums = 5;
    Album albumList[5] = {{16, "King Of Pop 1", 69.99, 'P'},{16, "King Of Pop 2", 16.99, 'P'},{16, "King Of Pop 3", 10.99, 'P'},{16, "King Of Pop 4", 15.99, 'P'},{16, "King Of Pop 5", 100.99, 'P'}};
    //Zad. 1:
    //displayAlbum(albumList[0]);


    for(int i = 0; i < albums; ++i){
        // Zad. 2:
        //albumList[i] = createAlbum();
        displayAlbum(albumList[i]);
    }

    // Zad. 3
    displayPriceInterval(albumList, 5, 50.00, 80.00);

    // Zad. 4 bez zwracania tablicy.
    displayByPrice(albumList, 5);
    return 0;
}
