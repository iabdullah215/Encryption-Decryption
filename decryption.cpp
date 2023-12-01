#include<iostream>
#include<fstream>
using namespace std;

void decrypt(string d,int key);
int findkey(string d);
string key1(string d);
int main()
{
    string d;     
    cout << "ENTER A STRING TO DECRYPT: ";
	getline(cin,d);
	cout << "THE KEY USED FOR DECRYPTION IS: ";
	int key = findkey ( key1(d) );
	cout << key;
	cout << endl << endl;
	cout << "THE DECRYPTED STRING IS: ";
	decrypt ( d,key );
}

void decrypt(string d,int key)
{
	string decrypted_string="";

	decrypted_string="";
	int todecrement = key;
	for(int i=0; i<d.size(); i++)
	{
		if(d[i]==' ')
		{
		    todecrement -= 2;
	      	cout << " ";
	      	decrypted_string += " ";
		}
		else
		{
			int s=d[i];
				
			if(s>=65 && s<=90)
			{	
				s+=todecrement;
				if (s>90) { s%=90; s+=64; }
				else if (s<65) { s=91-(65%s); }	
			}
			else if((s>=97 && s<=122))
		    {
       			s+=todecrement;
				if(s>122) { s%=122; s+=96;}
				else if(s<97){ s=123-(97%s) ;}	
			}
				
			char out_char=s;	
			decrypted_string = decrypted_string + out_char;	
				
		}
	}
		
	cout << endl << decrypted_string << endl;
		
}

int findkey(string d)

{
	string decrypted_string="";
	int key=0;
	for(int i=-1;i>=-9;i--)
	{
		decrypted_string="";
		int todecrement=i;
		for(int i=0; i<d.size(); i++)
		{
		    if(d[i]==' ')
			{
			    todecrement -= 2;
		      	cout << " ";
		      	decrypted_string += " ";
			}
			else
			{
				int s=d[i];
				if(s>=65 && s<=90)
				{		
				    s += todecrement;
					if (s>90) { s%=90; s+=64; }
					else if (s<65) { s=91-(65%s) ;}			
				}
				else if((s>=97 && s<=122))
				{
					s += todecrement;
					if(s>122) { s%=122; s+=96;}
					else if(s<97){ s=123-(97%s) ;}		
				}
				
				char out_char=s;	
				decrypted_string = decrypted_string + out_char;	
			}
		}
		
			fstream fileX;
        	fileX.open("dictionary.txt",ios::in);
        	string word;
        	
		while( fileX >> word )
		{
			if(word == decrypted_string)
			{
				
				key = i;
				break;
			}		
		}	
   }
   
	return key;
	
}

string key1(string d)

{
	string j="";
	for(int i=0;i<d.size();i++)
	{
        if(d[i]==' ')
        break;
	    else j=j+d[i];	
	}
	
	return j;
	
}
