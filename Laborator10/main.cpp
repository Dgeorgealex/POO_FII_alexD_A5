// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#define Nmax 1000

using namespace std;

class CommandManager 
{
private:
    map<string, function<void(vector<string>)>> commands;
    function<void(vector<string>)> last = nullptr;

public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) 
{
    commands[name] = fn;
}

void CommandManager::run()
{  
    while (1)
    {
        string nume;
        vector <string> parametrii;
        char c[Nmax];

        cin >> nume;
        if (nume == "stop")
            return;
        
        cin.getline(c, Nmax);
        char* p = strtok(c, " ");
        while (p != nullptr)
        {
            int n = strlen(p);
            string aux;
            for (int i = 0; i < n; i++)
                aux += p[i];
            parametrii.push_back(aux);
            p = strtok(nullptr , " ");
        }

        if (commands[nume] == nullptr)
        {
            cout << "Nu exista comanda\n";
            continue;
        }
        commands[nume](parametrii);
    }
}

int main()
{
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);


    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) { cout << args.size() << '\n'; };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args) {
        
        fstream file;
        file.open(args[0], ios_base::app | ios_base::in);
        if (file.is_open())
            for (int i=1;i<args.size();i++)
                file << args[i] << ' ';
        else number_of_errors++;
    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [con = 0](vector<string>args) mutable {
        con++;
        cout << con << '\n';
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [&number_of_errors](vector<string> args)
    {
        ifstream in_file(args[0]);
        ofstream out_file(args[1]);
        string chestii;
        if (in_file.is_open() && out_file.is_open())
            while (getline(in_file, chestii))
                out_file << chestii << '\n';    
        else
            number_of_errors++;
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](vector<string> args) {
        sort(args.begin(), args.end(), [](string& s1, string& s2) {return s1.size() < s2.size(); });
        for_each(args.begin(), args.end(), [](string& s1) {cout << s1 << ' '; });
        cout << '\n';
    };
    manager.add("sort_size", sort_size);


    // add one more command of anything you'd like 
    auto pisica = [&number_of_errors](vector<string> args) {
        ifstream in_file(args[0]);
        string chestii;
        if (in_file.is_open())
            while (getline(in_file, chestii))
                cout << chestii << '\n';
        else
            number_of_errors++;
    };
    manager.add("pisica", pisica);


    manager.run();
    printf("number of errors: %u\ndone!\n", number_of_errors);
}