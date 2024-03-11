#include <iostream>
#include <string>
using namespace std;

void concatenate_string(string s, string s1)
{
	int i;
	int j = s.length();
	for (i = 0; s1[i] != '\0'; i++) {
		s[i + j] = s1[i];
	}
    s[i + j] = '\0';
    return ;
}

int main()
{

	char s[5000], s1[5000];
	cout<<"Enter the first string: ";
	cin>>s;
    cout << s;
	cout<<"Enter the second string: ";
	cin>>s1;
    cout << s1;
    concatenate_string(s, s1);
	cout<<"Concatenated String is:" << s;
	return 0;
}