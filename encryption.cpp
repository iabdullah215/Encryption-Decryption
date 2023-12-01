#include <iostream>
using namespace std;

int main ()
{
	string k;
	int i,num,shift;
	cout << "Number of words in your sentence: " << endl;
	cin >> num;
	cout << "For incryption of first word put last digit of reg. number as shift..." << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for ( i=1; i<=num; i++)
	{
		cout << "Enter shift: " << endl;
		cin >> shift;
		if ( shift <=26 )
		{
			cout << "Enter string to encrypt: " << endl;
			cin >> k;
			for ( int i=0; i<=k.size(); i++)
			{
				char ch=((k[i]-'a'+ shift)%26)+'a';
				k[i]=ch;
			}
			cout << "Encrypted text: " << endl;
			cout << k << endl;
			cout << "Now add 2 in the shift for encryption of the next word: " << endl;
			cout << "----------------------------------------------------------------------" << endl;
		}
		else if ( shift > 26)
		{
			cout << "You have reached the limit of encryption..." << endl;
			cout << "Enter zero to continue..." << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
	
	return 0;
}
