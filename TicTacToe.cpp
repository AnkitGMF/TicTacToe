#include <iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string>
#include<ctype.h>
#include<ctime>
#include<fstream>

using namespace std;
//Global Variables
char GameData[9],Clocation;
int Location,rdm=0;
char aipP,aipA;
//initialization of GameData
void initialize(){
    for(int i=0;i<9;i++)GameData[i]=' ';
}
void display(){
    cout<<GameData[0]<<'|'<<GameData[1]<<'|'<<GameData[2]
    <<endl<<"-----"<<endl;
     cout<<GameData[3]<<'|'<<GameData[4]<<'|'<<GameData[5]
    <<endl<<"-----"<<endl;
     cout<<GameData[6]<<'|'<<GameData[7]<<'|'<<GameData[8]
    <<endl<<endl;

    cout<<"_____"<<endl<<endl;

    cout<<1<<'|'<<2<<'|'<<3
    <<endl<<"-----"<<endl;
     cout<<4<<'|'<<5<<'|'<<6
    <<endl<<"-----"<<endl;
     cout<<7<<'|'<<8<<'|'<<9
    <<endl;
}
int GameChecker(){
    if(GameData[0]!=' '&& (GameData[0]==GameData[1]&&GameData[1]==GameData[2])){
        return 1;
    }
    else if(GameData[3]!=' '&& (GameData[3]==GameData[4]&&GameData[4]==GameData[5])){
        return 1;
    }
    else if(GameData[6]!=' '&& (GameData[6]==GameData[7]&&GameData[7]==GameData[8])){
        return 1;
    }
    else if(GameData[0]!=' '&& (GameData[0]==GameData[3]&&GameData[3]==GameData[6])){
        return 1;
    }
     else if(GameData[1]!=' '&& (GameData[1]==GameData[4]&&GameData[4]==GameData[7])){
        return 1;
    }
     else if(GameData[2]!=' '&& (GameData[2]==GameData[5]&&GameData[5]==GameData[8])){
        return 1;
    }
     else if(GameData[0]!=' '&& (GameData[0]==GameData[4]&&GameData[4]==GameData[8])){
        return 1;
    }
     else if(GameData[2]!=' '&& (GameData[2]==GameData[4]&&GameData[4]==GameData[6])){
        return 1;
    }
    else{
        return 0;
    }
}
//Data type Converter
int typeConverter(char a){
    if(a==48)return 0;
    if(a==49)return 1;
    if(a==50)return 2;
    if(a==51)return 3;
    if(a==52)return 4;
    if(a==53)return 5;
    if(a==54)return 6;
    if(a==55)return 7;
    if(a==56)return 8;
    if(a==57)return 9;
    return -1;
}
int spaceclac(){
int ct3=0;
for(int j=0;j<9;j++){
    if(GameData[j]==' '){
        ct3++;
    }
}
return ct3;
}
int largest(int x[]){
    int biggest,ct=-1,numBig;
    biggest=x[0];
    for(int j=0;j<6;j++){
        if(biggest<x[j]){
            biggest=x[j];
        }
    }
    for(int j=0;j<6;j++){
        if(x[j]==biggest)numBig++;
    }
    if(numBig==2)return 10;
    for(int j=0;j<6;j++)
        {ct++;
        if(x[j]==biggest)return ct;
    }


    return -1;
}
//A.I.
int AI(){

    int health[6]={10,10,10,10,10,10},a=0,LoseCond=0,radinput,smt=-1,ct2=-1,smt2;
    //Checks if the AI wins the match
    for(int j=0;j<9;j++){
        if(GameData[j]==' '){
            GameData[j]=aipA;
            if(GameChecker()){
                return j;
            }
            GameData[j]=' ';
        }
    }
    //Checks if AI looses the match
    for(int j=0;j<9;j++){
        if(GameData[j]==' '){
            GameData[j]=aipA;

            for(int k=0;k<9;k++){
                if(GameData[k]==' '){
                    GameData[k]=aipP;
                    if(GameChecker()){
                            health[a]=health[a]-1;
                            LoseCond=1;

                    }
GameData[k]=' ';}

            }
            a++;
GameData[j]=' '; }
    }
    //Re-simulating the Lose condition loop to get the value of i for max health
    if(LoseCond==1){

            smt2=largest(health);
            if(smt2==0){
                for(int j=0;j<9;j++){
                   if(GameData[j]==' '){
                    return j;
                   }
                }
            }
            else{
        for(int j=0;smt!=smt2;j++){
            if(GameData[j]==' '){smt++;}
            ct2++;

        }

        return ct2;
        }
    }
    else{
            anotherinput:
        srand(time(0));
        radinput=rand()%9;
        if(GameData[radinput]!=' '){
            goto anotherinput;
        }
        return radinput;
    }
    return -1;
}
//Scoreboard Structure
class scoreBoard{
    public:
    char name[41];
    int score;
};
//String to integer conversion
int main(){
    scoreBoard s[2];
    int i,m;
    char userInput,ha,disp[75];
    char vs[5]=" vs ",next='\n';
    ofstream scoreB("score.txt",ios::out|ios::app);
    ifstream scoreBD("score.txt",ios::in);
    choice:
    cout<<"To play against Human. Press H/To play against AI. Press A/To view previous scores press S: ";
    cin>>ha;
    if(ha=='s'||ha=='S'){
        while(scoreBD)
        {
            scoreBD.getline(disp,75);
            cout<<disp<<endl;
        }
        scoreBD.close();
        goto choice;
    }
    else if(ha=='A'||ha=='a'){
        goto AIPlayzone;
    }
    HPlayZone:
        m=0;
    s[0].score=0;
    s[1].score=0;
    cout<<"Please enter your name 1st Player: ";
    cin>>s[0].name;
    cout<<"Please enter your name 2nd Player: ";
    cin>>s[1].name;
    start:
    system("CLS");
    initialize();
    display();
    for(i=0;i<9;i++){
        if(i%2==0){
            cout<<endl<<s[0].name<<"'s Turn. Please select a cell: ";
        }
        else{
            cout<<endl<<s[1].name<<"'s Turn. Please select a cell: ";
        }
        wronglocation:
        Clocation = getch();
        if(!isdigit(Clocation)){
            system("CLS");
            display();
            cout<<"Please enter a number only!!: ";
             goto wronglocation;
        }
        else{
            Location= typeConverter(Clocation);
        }
        if(GameData[Location-1]==' '){
            if(i%2==0){
                GameData[Location-1]='X';
            }
            else{
                GameData[Location-1]='O';
            }
        }
        else{
                system("CLS");
                display();
            cout<<"This cell is already occupied. Please choose another cell: ";
            goto wronglocation;
        }
        system("CLS");
        display();
        if(GameChecker()){
            m=1;
            rdm=i;
            break;
        }
        }
    if(m==1){
        if(rdm%2==0){
            cout<<s[0].name<<" won the Game!!"<<endl;
            s[0].score++;
        }
        else{
            cout<<s[1].name<<" won the Game!!"<<endl;
            s[1].score++;
        }
    }
    else{
        cout<<"Its a tie"<<endl;
    }

    cout<<"If you want to play again press Y/If you want to quit Press N: ";
    options:
    cin>>userInput;
    if(userInput=='Y'||userInput=='y'){
        goto start;
    }
    else if(userInput=='N'||userInput=='n'){
            scoreB << s[0].name<<" vs "<<s[1].name
            <<endl<<s[0].score<<" vs "<<s[1].score<<endl<<endl;
            scoreB.close();

        return 0;
    }
    else{
        cout<<"Please Choose from the above options: ";
        goto options;
    }system("CLS");
        display();
    AIPlayzone:
        m=0;
        system("CLS");
        cout<<"Select X or O: ";
        cin>>aipP;

        if(aipP=='X'||aipP=='x'){
            aipA='O';
        }
        else if(aipP=='O'||aipP=='o'){
            aipA='X';
        }

        else{
            goto AIPlayzone;
        }
        system("CLS");
        initialize();
        display();
        for(int j=0;j<5;j++){
            cout<<"Please select a cell: ";
            wronglocation2:
            Clocation=getch();
            cout<<endl;
             if(!isdigit(Clocation)){
            system("CLS");
            display();
            cout<<"Please enter a number only!!: ";
             goto wronglocation2;
        }
        else{
            Location= typeConverter(Clocation);
        }
        if(GameData[Location-1]!=' '){
            system("CLS");
            display();
            cout<<"The cell is already occupied. Please select another cell: ";
            goto wronglocation2;
        }
        GameData[Location-1]=aipP;
        system("CLS");
        display();
        if(GameChecker()){
            m=1;
            break;
        }
        if(spaceclac()){
        Location=AI();
        GameData[Location]=aipA;
        system("CLS");
        display();
        if(GameChecker()){
            m=2;
            break;
        }
        }
        else{
            break;
        }
        }
        if(m==1){
            cout<<"You won the game";
        }else if(m==2){
            cout<<"A.I won the game";
        }else{
            cout<<"Its a tie";
        }

        cout<<endl<<"If you want to play again press Y.If you want to quit press N. If you want to play with a human press H: ";
        options2:
            cin>>userInput;
        if(userInput=='Y'||userInput=='y'){
            goto AIPlayzone;
        }
        else if(userInput=='N'||userInput=='n'){
            return 0;
        }else if(userInput=='H'||userInput=='h'){
            goto HPlayZone;
        }else{
        cout<<"Please enter a valid option: ";
        goto options2;
        }

}

