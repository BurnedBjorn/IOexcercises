// IOexcercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"
using namespace std;
void FToLower(string, string);

void FindWord(string filename, string word) {
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = tolower(word[i]); //bring all letters to lowercase
    }
    ifstream win{ filename };
    if (!win)
    {
        error("couldn't open file " + filename);
    }
    ofstream wout{ "WordFound.txt"};
    if (!wout)
    {
        error("couldn't open the output file");
    }
    //FToLower(filename, filename);
    for (int i = 0; win; i++) //do as long as lines are reading
    {
        string input;
        getline(win, input);
        string output = input; //save the input with cases
        for (int i = 0; i < input.size(); i++) //bring all input to lowercase
        {
            input[i] = tolower(input[i]);
        }
        if (input.find(word)!=input.npos) //find all lines in input, then output the lines with original case
        {
            wout <<i<<", " << output<<'\n';
            cout << i << " " << output << " " << word << '\n';
        }
    }
}
void FToLower(string finput, string foutput) {
    ifstream ist{ finput };
    if (!ist)
    {
        error("can't open file");
    }
    ofstream ost(foutput);
    if (!ost)
    {
        error("can't get output file");
    }
    char ch;
    while (ist.get(ch))
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
        }

        ost << ch;
    }
    cout << "done";
}



void disemvowel(string filename) {
    ifstream fin{ filename };
    
    if (!fin)
    {
        error("can't open file");
    }
    ofstream fout{ "output.txt" };
    vector<char> vowels{ 'a','e','i','o','u','y' };
    char input;
    
    while (fin.get(input))
    {
        char savedcase = input;
        input = tolower(input);
        if (find(vowels.begin(), vowels.end(), input)== vowels.end())
        {
            fout << savedcase;
            //cout << input;
        }
    }
}

void form_out(int number, int base) {
    
    const string conv = "converts to\t";
    const string d = "\tdecimal\t";
    const string o = "\toctal\t";
    const string h = "\thexadecimal\t";
      
    switch (base)
    {
    case 8:
        cout << oct << number <<  o  << conv << dec  << number <<d<< endl;
        break;
    case 10:
        cout << dec << number << d << conv << dec << number <<d<< endl;
        break;
    case 16:
        cout << hex << number << h << conv << dec <<  number << d<<endl;
        break;
    default:
        break;
    }
     
}

void multi_input() {
    cout << "Enter integers in octal, decimal or hexadecimal system\ntype ';' or 'quit' when done inputting\n>";
    string input;
    vector<int> numbers;
    vector<int> bases;
    while (cin>>input&&(input!=";"||input=="quit"))
    {
        int base = 10;
        if (input[0] == '0')
        {
            if (input[1]=='x')
            {
                base = 16;
            }
            else
            {
                base = 8;
            }
        }
        int num = -999;
        num = stoi(input, nullptr, base);
        numbers.push_back(num);
        bases.push_back(base);
        cout << '>';
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        form_out(numbers[i], bases[i]);
    }
}






int main()
{
    try {
        multi_input();
        

    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        
        return 2;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
