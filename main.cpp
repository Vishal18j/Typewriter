#include<iostream>
#include<cstring>
#include<string.h>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include<sys/stat.h>
#include<dirent.h>
#include<direct.h>
#include<ctime>
#include<sys/stat.h>
using namespace std;
void Welcome();
void menu(int msg);
void listing();
int start();
int Statistics();
clock_t starting,ending;
double time_taken;
time_t nowtime;
char *date;
string uniuser,unipass;
string unidate;
string path;
string newstring;
string token1,token2,token3;

void Welcome()
{
    char welcome[500]="\
\n\n\n\n\n\
\t\t\t\t\t      TTTTTT YY  YY PPPPPP  EEEEEE  WW      WW  RRRRRR     11  TTTTTT EEEEEE  RRRRRR\n\r\
\t\t\t\t\t        TT    YYYY  PP   PP EE      WW  WW  WW  RR   RR  1111    TT   EE      RR   RR\n\r\
\t\t\t\t\t        TT     YY   PPPPPP  EEEEEE  WW WWWW WW  RRRRRR     11    TT   EEEEEE  RRRRRR\n\r\
\t\t\t\t\t        TT     YY   PP      EE      WWWW  WWWW  RR  RR     11    TT   EE      RR  RR\n\r\
\t\t\t\t\t        TT     YY   PP      EEEEEE  WW      WW  RR   RR  111111  TT   EEEEEE  RR   RR\n\r\
  \n\n\n\n\n\n\r";
    cout<<welcome;
}

void header(int msg)
{
    system("CLS");
	if(msg==0)
	{
	    cout<<"\n\n\n";
	    cout<<"-------------------------"<<endl;
	    cout<<"|                       |"<<endl;
		cout<<"| WELCOME TO TYPEWR1TER |"<<endl;
		cout<<"|                       |"<<endl;
		cout<<"-------------------------"<<endl;
	}
	if(msg==1)
	{
		cout<<"\n\n\n";
		cout<<"------------------------------------------"<<endl;
		cout<<"|                                        |"<<endl;
		cout<<"| THE FILE HAS BEEN CREATED SUCCESSFULLY |"<<endl;
		cout<<"|                                        |"<<endl;
		cout<<"------------------------------------------"<<endl;
	}
	if(msg==2)
	{
	    cout<<"\n\n\n";
	    cout<<"------------------------------------------"<<endl;
	    cout<<"|                                        |"<<endl;
		cout<<"| THE FILE HAS BEEN UPDATED SUCCESSFULLY |"<<endl;
		cout<<"|                                        |"<<endl;
		cout<<"------------------------------------------"<<endl;
	}
	if(msg==4)
	{
	    cout<<"\n\n\n";
	    cout<<"----------------------------------"<<endl;
	    cout<<"|                                |"<<endl;
		cout<<"| THE FILE IS RID OF ALL CONTENT |"<<endl;
		cout<<"|                                |"<<endl;
		cout<<"----------------------------------"<<endl;
	}
	if(msg==5)
	{
	    cout<<"\n\n\n";
	    cout<<"--------------------------------"<<endl;
	    cout<<"|                              |"<<endl;
		cout<<"| FILE IS DELETED SUCCESSFULLY |"<<endl;
		cout<<"|                              |"<<endl;
		cout<<"--------------------------------"<<endl;
	}
	if(msg==55)
	{
	    cout<<"\n\n\n";
	    cout<<"----------------------------"<<endl;
	    cout<<"|                          |"<<endl;
		cout<<"| FILE HAS NOT BEEN FOUND! |"<<endl;
		cout<<"|                          |"<<endl;
		cout<<"----------------------------"<<endl;
	}
	if(msg==6)
	{
	    cout<<"\n\n\n";
	    cout<<"-------------------------------------"<<endl;
	    cout<<"|                                   |"<<endl;
		cout<<"| FILE HAS BEEN COPIED SUCCESSFULLY |"<<endl;
		cout<<"|                                   |"<<endl;
		cout<<"-------------------------------------"<<endl;
	}
	if(msg==7)
	{
	    cout<<"\n\n\n";
	    cout<<"--------------------"<<endl;
	    cout<<"|                  |"<<endl;
		cout<<"| FILE OPERATIONS  |"<<endl;
		cout<<"|                  |"<<endl;
		cout<<"--------------------"<<endl;
	}
}

void wipe()
{
    ofstream myfile;
    myfile.open((path).c_str());
    myfile<<"";
    myfile.close();
}

void menu()
{
	M:
    cout<<"\n\n\n";
	cout<<"MAIN MENU"<<endl;
	cout<<"\n";
	cout<<"-------------"<<endl;
	cout<<"\n\n";
	cout<<"1. NAME A NEW BLANK FILE(SINGLE WORD)"<<endl;
	cout<<"2. WRITE CONTENT(EITHER TO AN EXISTING FILE OR A NEW ONE)"<<endl;
	cout<<"3. MODIFY CONTENT(TO AN EXISTING FILE)"<<endl;
	cout<<"4. FILE OPERATIONS"<<endl;
	cout<<"5. LIST FILES AND FOLDERS IN CWD"<<endl;
	cout<<"6. DISPLAY STATISTICS OF A FILE"<<endl;
	cout<<"7. USER MANUAL"<<endl;
	cout<<"8. LOGOUT"<<endl;
	cout<<"9. EXIT APPLICATION"<<endl<<endl;
	cout<<"ENTER YOUR CHOICE\n"<<endl;

	int choice = 0;
	string filename;
	string text;

	cin>>choice;

	if(choice==1)
	{
		cout<<endl<<"ENTER NAME OF THE FILE: "<<endl;
		cin.ignore();
		getline(cin, filename);
		path="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+filename+".txt";
		ofstream myfile( (path).c_str() );
		myfile.close();
		header(1);
		menu();
		cin>>choice;
	}
	if(choice==2)
	{
		text="";
		cout<<endl<<"ENTER THE NAME OF AN EXISTING FILE: "<<endl;
		cin>>filename;
		path="C:/Users/visha/Desktop/File Structures Files/Username/"+uniuser+"/"+filename+".txt";
        cout<<endl<<"START TYPING YOUR CONTENT(TYPE '!END' TO SAVE THE WRITTEN CHANGES AND EXIT)"<<endl;
		ofstream myfile;
		myfile.open((path).c_str(),ios::app);
		string line;
		cin.ignore();	 // (Ignore the Buffer(Temporary contents)
        time_t start,finish;
        time(&start);
        ios_base::sync_with_stdio(false);
		while (getline(cin, line))
		{
			if(line.size()>=4)
			{
			    if (line.substr(line.size() - 4) == "!END") //Specifying that whenever !END is typed stop reading data eof//
			    {
			    	text += line.substr(0, line.size()-4);// 0 is position of 1st character ,line.size is the total length, 4 is size of !END//
			    	break;
				}
				else{
					text += line+"\n";
				}
			}
			else{
				text += line+"\n";
			}
		}
		time(&finish);
		time_taken=double(finish-start);
		myfile<<text;
		time_t nowtime=time(0);
        char *date=ctime(&nowtime);
        cout<<"\n\n"<<endl;
        cout<<"Date and Time is\n"<<endl;
        cout<<date<<endl;
        unidate=string(date);
        myfile<<date;
  		myfile.close();
  		fstream uniquevalue;
  		uniquevalue.open("UniqueValues.txt",ios::app);
  		uniquevalue<<unidate;
  		uniquevalue.close();
  		Sleep(5000);
  		header(2);
		menu();
		cin>>choice;

	}

	if(choice==3)
    {
        N:
        text="";
		cout<<endl<<"ENTER THE NAME OF THE FILE: "<<endl;
		cin>>filename;
		path="C:/Users/visha/Desktop/File Structures Files/Username/"+uniuser+"/"+filename+".txt";
		fstream myfile;
		myfile.open((path).c_str(),ios::in);
		while(getline(myfile, text))
        {
         cout<<text<<"\n";
      	}
      	fstream myfile4( (path).c_str() );
		string line;
		while(getline(myfile4, line))
		{
         text += line+"\n";
        }
        string beg="", finish="";
        int rep1, rep2, increment=0;
        cout<<"\nENTER THE WORD/LETTER FROM WHERE YOU WANT TO START MODIFYING\n";
        cin>>beg;
        cout<<"ENTER THE WORD/LETTER WHERE YOU WANT TO END MODIFYING\n";
        cin>>finish;
        cout<<"ENTER THE ITERATION OF THE WORD IF THERE IS REPETITION OF STARTING WORD\n";
        cin>>rep1;
        cout<<"ENTER THE ITERATION OF THE WORD IF THERE IS REPETITION OF ENDING WORD\n";
        cin>>rep2;
        cout<<"\n";
        int a,b;
        int length=text.size();
        int finishlength=finish.size();
        size_t pos = 0;
        int none=0;


       T:
        while(none<=rep1)
        {
            token1=text.substr(pos, length);

            if(none==rep1)
            {

                while (( pos = token1.find (beg)) != std::string::npos)
                {
                   none++;
                    {
                        a=pos;
                        cout<<a<<"\n";
                        //token1 = text.substr(0, pos);
                        goto P;// store the substring
                    }
                }
            }
            else
            {
                while (( pos = token1.find (beg)) != std::string::npos)
                {
                   none++;
                    {
                        a=pos;
                        goto T;
                    }
                }
            }
        }

        P:
        none=0;
        pos=0;
        S:
        while(none<=rep2)
        {
            token1=text.substr(pos, length);;

            if(none==rep2)
            {

                while (( pos = token1.find (finish)) != std::string::npos)
                {
                   none++;
                    {
                        b=pos;
                        cout<<b<<"\n";
                        //token1 = text.substr(0, pos);
                        goto Q;// store the substring
                    }
                }
            }
            else
            {
                while (( pos = token1.find (finish)) != std::string::npos)
                {
                   none++;
                    {
                        b=pos;
                        goto S;
                    }
                }
            }
        }

        Q:
        token1=text.substr(0,a);
        token3=text.substr((b),length);

        if(a>b)
        {
            cout<<"THE VALUES ENTERED ARE INCORRECT\n";
            cout<<endl<<"PRESS ANY KEY FOLLOWED BY ENTER TO RETURN TO MAIN MENU";
            char now;
            Sleep(3000);
            cin>>now;
            system("CLS");
            header(2);
            menu();
            goto N;
        }
        else
        {
            wipe();
            ofstream myfile4;
            myfile4.open((path).c_str(),ios::app);
            cin.ignore();
            cout<<"ENTER THE STRING YOU WANT TO ADD AND WHEN YOU ARE FINISHED TYPE !END AND PRESS ENTER:\n";
            string line2;
            while (getline(cin, line2))
                {
                    if(line2.size()>=4)
                    {
                        if (line2.substr(line2.size() - 4) == "!END") //Specifying that whenever !END is typed stop reading data eof//
                        {
                            token2 += line2.substr(0, line2.size()-4);// 0 is position of 1st character ,line.size is the total length, 4 is size of !END//
                            break;
                        }
                        else
                        {
                            token2 += line2+"\n";
                        }
                    }
                    else
                    {
                        token2 += line2+"\n";
                    }
                }
                newstring=token1+token2+token3;
                myfile4<<newstring;
                myfile4.close();

        }
        myfile.close();
        myfile4.close();

        cout<<"IF YOU WANT TO MODIFY AGAIN, THEN PRESS 1\n";
        int one;
        cin>>one;
        if(one==1)
        {
            goto N;
        }
        else
        {
            char now;
            cout<<endl<<"FILE HAS BEEN UPDATED. PRESS ANY KEY FOLLOWED BY ENTER TO RETURN TO MAIN MENU";
            Sleep(3000);
            cin>>now;
            header(2);
            menu();
            cin>>choice;
        }
    }


	if(choice==4)
    {
        int ch;
        system("CLS");
        header(7);
        cout<<"\n\n\n";
        cout<<"SUB MENU"<<endl;
        cout<<"\n";
        cout<<"-------------"<<endl;
        cout<<"\n\n";
        cout<<"1. READ CONTENT FROM A SAVED FILE"<<endl;
        cout<<"2. ERASE THE CONTENT ON A FILE"<<endl;
        cout<<"3. DELETE A FILE"<<endl;
        cout<<"4. COPY A FILE"<<endl;
        cout<<"5. GO BACK TO MAIN MENU"<<endl;
        cout<<"ENTER YOUR CHOICE\n"<<endl;
        cin>>ch;

        if(ch==1)
        {
        text="";
		cout<<endl<<"ENTER THE NAME OF THE FILE: "<<endl;
		cin>>filename;
		path="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+filename+".txt";
		fstream myfile;
		myfile.open((path).c_str(),ios::in);
		while(getline(myfile, text))
        {
         cout<<text<<"\n";
      	}
      	myfile.close();
      	char now;
		cout<<endl<<"END OF FILE. PRESS ANY KEY FOLLOWED BY ENTER TO RETURN TO MAIN MENU";
		Sleep(3000);
		cin>>now;
		header(2);
		menu();
		cin>>choice;
        }

        if(ch==2)
        {
        cout<<endl<<"ENTER THE NAME OF THE FILE: "<<endl;
		cin>>filename;
		path="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+filename+".txt";
		ofstream myfile;
		myfile.open((path).c_str());
		myfile<<"";
  		myfile.close();
		header(4);
		menu();
		cin>>choice;
        }

        if(ch==3)
        {
            cout<<endl<<"ENTER THE NAME OF THE FILE: "<<endl;
		cin>>filename;
		path="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+filename+".txt";
		if (remove((path).c_str())==0)
		{
			header(5);
            menu();;
		}
		else
		{
			header(55);
            menu();
		}
        }

        if(ch==4)
        {
            text="";
		cout<<endl<<"ENTER NAME OF THE FILE TO COPY FROM: "<<endl;
		cin.ignore();
		getline(cin, filename);
		path="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+filename+".txt";
		fstream myfile( (path).c_str() );
		string line;
		while(getline(myfile, line)){
         text += line+"\n";
      	}
		myfile.close();
		cout<<endl<<"ENTER THE NAME OF THE FILE TO COPY TO: "<<endl;
		string second;
		getline(cin, second);
		ofstream myfile2;
		string path2="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+second+".txt";
		myfile2.open((path2).c_str(),ios::app);
		myfile2<<text;
  		myfile2.close();
		header(6);
		menu();
		cin>>choice;
        }

        if(ch==5)
        {
            system("CLS");
            header(0);
            goto M;
        }
    }

	if(choice==5)
	{
		listing();
		Sleep(10000);
		header(7);
		menu();
		cin>>choice;
	}
	if(choice==6)
    {
        Statistics();
        char now;
		cout<<endl<<"END OF STATS. PRESS ANY KEY FOLLOWED BY ENTER TO RETURN TO MAIN MENU\n"<<endl;
		Sleep(3000);
		cin>>now;
		header(8);
		menu();
		cin>>choice;

    }
    if(choice==7)
    {
        system("CLS");
        string manual="";
        fstream userman;
        userman.open("Document.txt",ios::in);
        while(getline(userman,manual))
        {
            cout<<manual<<"\n";
        }
        userman.close();
        char now;
		cout<<endl<<"PRESS ANY KEY FOLLOWED BY ENTER TO RETURN TO MAIN MENU\n"<<endl;
		Sleep(1000);
		cin>>now;
        header(0);
        menu();
        cin>>choice;
    }
	if(choice==8)
    {
        start();

    }
    if(choice>=9)
    {
        exit(EXIT_SUCCESS);
    }
}

//DIRECTORY LISTING
void listing()
{
    cout<<"FILES AND FOLDERS OF THE CURRENT WORKING DIRECTORY:\n\n";
    struct dirent *d;
    struct stat dst;
    DIR *dr;
    string path3="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/";
    dr=opendir(path3.c_str());
    if(dr!=NULL)
    {
        for(d=readdir(dr);d!=NULL;d=readdir(dr))
        {
            string type=d->d_name;
            type=path+type;
            if(stat(type.c_str(), &dst)==0)
            {
                if(dst.st_mode & S_IFDIR)
                {
                    type="is a FOLDER";
                }
                else if(dst.st_mode & S_IFREG)
                {
                    type="is a FILE";
                }
            }
            cout<<d->d_name<<"\t"<<type<<endl;
        }
        closedir(dr);
    }
    else
    {
        cout<<"ERROR"<<endl;
    }
}

//STATISTICS SECTION
int Statistics()
{
    string filename;
    fstream file;
    cout<<"\nENTER NAME OF FILE:"<<endl;
    cin.ignore();
    getline(cin,filename);
    string path4="C:/Users/visha/Desktop/File Structures Files/Typewriter/"+uniuser+"/"+filename+".txt";
    file.open((path4),ios::in);
    char ch;
    int lines=0,words=0,chars=0;
    file.get(ch);
    while(file)
    {
        if(ch=='\n')
        {
            lines++;
            words++;
        }
        else if(ch==' ')
        {
            words++;
            chars++;
        }
        else
            chars++;
        file.get(ch);
    }
    file.close();
    cout<<unidate<<endl;
    cout<<"TIME TAKEN="<<time_taken<<"SECONDS"<<endl;
    cout<<"\n"<<endl;
    cout<<"NUMBER OF CHARACTERS="<<chars<<endl;
    cout<<"\n"<<endl;
    cout<<"NUMBER OF WORDS="<<words+1<<endl;
    cout<<"\n"<<endl;
    cout<<"NUMBER OF LINES="<<lines+1<<endl;
    cout<<"\n"<<endl;
    double wpm=double(words*60)/double(time_taken);
    cout<<"WORDS PER MINUTE(WPM)="<<wpm<<endl;
    return 0;
}

bool IsLoggedIn()
{
string username, password, un, pw;

cout << "\nENTER USERNAME: "<<endl;
cin>> username;
uniuser=username;
cout << "\nENTER PASSWORD: "<<endl;
cin>> password;
unipass=password;


ifstream read("login\\" + username + ".txt");

getline(read, un);

getline(read, pw);

if(un == username && pw==password)
{
    return true;
}

else

{
    return false;
}
}

int start()

{
system("CLS");
Welcome();
Sleep(3000);

int choice;

cout << "1: REGISTER\n2: LOGIN\n\nYOUR CHOICE: "<<endl; cin>> choice;
if (choice == 1)

{
string username, password;

cout << "\nSELECT A USERNAME: "<<endl;
cin>> username;
uniuser=username;
cout << "\nSELECT A PASSWORD: "<<endl;
cin>> password;
unipass=password;

if(mkdir(username.c_str()) == -1)
        cerr << "" << endl;

    else
        cout << "";

ofstream file;

file.open("login\\" + username + ".txt");
file <<username << endl << password;
file.close();
system("CLS");
start();
}
else if (choice == 2)
{
bool status=IsLoggedIn();
if (!status)
{
    cout << "FALSE LOGIN!" << endl;
    system("PAUSE");
    return 0;
}
else
{
    header(0);
    menu();
    return 1;
}
}
}
int main()
{
    start();
}
