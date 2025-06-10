#include<iostream>
using namespace std;

struct Song{
    string songName;
    string artistName;
    string albumName;
    Song* next;
    Song* prev;

    Song(string name, string artist, string album){
        songName = name;
        artistName = artist;
        albumName = album;
        next = prev = nullptr;
    }
};

class Playlist{
    private:
        Song* head;
        Song* tail;
        Song* current;

    public:
        Playlist(){
            head = tail = current = nullptr;
        }    

        void addSong(string name, string artist, string album){
            Song* newSong = new Song(name, artist, album);

            if(!head){
                head = tail = newSong;
                current = head;
            } else{
                tail->next = newSong;
                newSong->prev = tail;
                tail = newSong;
            } tail->next = nullptr;
            cout<<"Song Added:\n[Song]:"<<name<<"\n[Artist]:"<<artist<<"\n[Album]:"<<album<<endl;
        }

        void playCurrent(){
            if(current){
                cout<<"Currently playing:\n[Song]:"<<current->songName<<"\n[Artist]:"<<current->artistName<<"\n[Album]:"<<current->albumName<<endl;
            } else{
                cout<<"Playlist is Empty!\n";
            }
        }

        void playNext(){
            if(current && current->next){
                current = current->next;
                playCurrent();
            } else{
                cout<<"No next song!\n";
            }
        }

        void playPrevious(){
            if(current && current->prev){
                current = current->prev;
                playCurrent();
            } else{
                cout<<"No previous song!\n";
            }
        }

        void showPlaylist(){
            Song* temp = head;

            cout<<"Playlist:\n";
            while(temp){
                cout<<"Song Name: "<<temp->songName<<endl;
                cout<<"Artist Name: "<<temp->artistName<<endl;
                cout<<"Album Name: "<<temp->albumName<<endl;
                cout<<endl;    
                if(temp == current){
                    cout<<"Currently playing:\n[Song]:"<<current->songName<<"\n[Artist]:"<<current->artistName<<"\n[Album]:"<<current->albumName<<endl;
                } 
                temp = temp->next;
            }
        }
};

int main(){
    Playlist myPlaylist;
    int choice;
    string songName, artistName, albumName;

    do{
        cout<<"Playlist Menu:\n";
        cout<<"Press 1 to Add Song\n";
        cout<<"Press 2 to Play Current Song\n";
        cout<<"Press 3 to Play Next Song\n";
        cout<<"Press 4 to Play Previous Song\n";
        cout<<"Press 5 to Show Playlist\n";
        cout<<"Press 0 to Exit\n";
        cout<<"Choose an option: ";
        cin>>choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout<<endl;
                cout << "Enter song name: ";
                getline(cin, songName);
                cout << "Enter artist name: ";
                getline(cin, artistName);
                cout << "Enter album name: ";
                getline(cin, albumName);
                myPlaylist.addSong(songName, artistName, albumName);
                cout<<endl;
                break;
            case 2:
                cout<<endl;
                myPlaylist.playCurrent();
                cout<<endl;
                break;
            case 3:
                cout<<endl;
                myPlaylist.playNext();
                cout<<endl;
                break;
            case 4:
                cout<<endl;
                myPlaylist.playPrevious();
                cout<<endl;
                break;
            case 5:
                cout<<endl;
                myPlaylist.showPlaylist();
                cout<<endl;
                break;
            case 0:
                cout<<endl;
                cout<<"Program Exited Successfully!\n";
                break;
            default:
                cout<<endl;
                cout<<"Invalid choice. Try again.\n";
        }
    }while(choice != 0);
}