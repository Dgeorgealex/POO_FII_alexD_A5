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


class MyException : public exception
{
protected:
    string exceptie;
    MyException(const string& s)
    {
        exceptie = s;
    }
public:
    virtual const char* what() const throw()
    {
        return exceptie.c_str();
    }
};

class OpenFileException : public MyException
{
public:
    OpenFileException(string s) : MyException(s)
    {
        exceptie = string("can't open file ") + s;
    }
};

class ReadFileException : public MyException
{
public:
    ReadFileException(string s) : MyException(s)
    {
        exceptie = string("can't read file ") + s;
    }
};

class WriteFileException : public MyException
{
public:
    WriteFileException(string s) : MyException(s)
    {
        exceptie = string("can't read file ") + s;
    }
};
class CommandManager
{
private:
    map<string, function<void(vector<string>)>> commands;
    function<void(vector<string>)> last = nullptr;

public:
    void add(string name, function<void(vector<string>)> fn);
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
            p = strtok(nullptr, " ");
        }

        if (commands[nume] == nullptr)
        {
            cout << "Nu exista comanda\n";
            continue;
        }
        try
        {
            commands[nume](parametrii);
        }
        catch (bad_alloc& e) {
            cerr << e.what();
        }
        catch (exception& e){
            cerr << e.what();
        }
    }
}

int main()
{
    CommandManager manager;

    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);


    auto count = [](vector<string> args) { cout << args.size() << '\n'; };
    manager.add("count", count);

    auto append = [](vector<string> args) {

        fstream file;
        file.open(args[0], ios_base::app | ios_base::in);
        if (!file.good())
            throw OpenFileException(args[0]);

        for (int i = 1; i < args.size(); i++)
        {
            file << args[i] << ' ';
            if (!file.good())
                throw WriteFileException(args[0]);
        }

    };
    manager.add("append", append);


    auto times = [con = 0](vector<string>args) mutable {
        con++;
        cout << con << '\n';
    };
    manager.add("times", times);


    auto copy = [](vector<string> args)
    {
        ifstream in_file(args[0], ios::binary);
        if (!in_file.good())
            throw OpenFileException(args[0]);

        ofstream out_file(args[1], ios::binary);
        if (!out_file.good())
            throw OpenFileException(args[1]);


        out_file << in_file.rdbuf();
        if (!in_file.good())
            throw ReadFileException(args[0]);
        if (!out_file.good())
            throw WriteFileException(args[1]);
    };
    manager.add("copy", copy);

    auto sort_size = [](vector<string> args) {
        sort(args.begin(), args.end(), [](string& s1, string& s2) {return s1.size() < s2.size(); });
        for_each(args.begin(), args.end(), [](string& s1) { cout << s1 << ' '; });
        cout << '\n';
    };
    manager.add("sort_size", sort_size);

    auto alocmemorie = [](vector<string> args) {
        long long value = strtol(args[0].c_str(), nullptr, 10);
        int* salut = new int[value];
        delete[] salut;
    };
    manager.add("alocmemorie", alocmemorie);
    manager.run();
}