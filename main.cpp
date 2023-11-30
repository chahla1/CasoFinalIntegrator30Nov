#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};
struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};
ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const string& filename, bool show_script = false){
    try {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo: " << filename << endl;
            return;
        }

    }

}


int main() {

}

