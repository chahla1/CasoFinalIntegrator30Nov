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
        string script((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);

    }
    catch (const exception& e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
    }

}
void load_script()
{
    string filename;
    cout << "Archivo: ";
    cin >> filename;
    load_script(filename, true);
}



int main() {
    return 0;


}

