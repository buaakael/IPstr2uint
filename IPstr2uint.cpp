#include <iostream>
#include <string>
using namespace std;

unsigned IPstr2uint(string IP)
{
    string temp;
    unsigned a[4];
    size_t pos;
    unsigned i = 3;
    while (1)
    {
        pos = IP.find(".");
        if (pos != string::npos)
        {
            temp = IP.substr(0, pos);
            a[i] = atoi(temp.c_str());
            i--;
            IP.erase(0, pos + 1);
        }
        else
        {
            temp = IP;
            a[i] = atoi(temp.c_str());
            break;
        }
    }
    unsigned result = (a[3] << 24) + (a[2] << 16) + (a[1] << 8) + a[0];
    return result;
}

int main(int argc, char* argv[])
{
    string IP;
    cin >> IP;
    cout << IPstr2uint(IP) << endl;
}

