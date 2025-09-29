#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Функция для вывода справки
void printHelp(const char* programName) {
    cout << "Использование: " << programName << " [ОПЦИИ]" << endl;
    cout << "Тригонометрический калькулятор" << endl;
    cout << endl;
    cout << "Обязательные опции:" << endl;
    cout << "  -o, --operation OPERATION  Задает операцию (sin или cos)" << endl;
    cout << "  -a, --angle ANGLE          Задает угол в градусах" << endl;
    cout << endl;
    cout << "Дополнительные опции:" << endl;
    cout << "  -h, --help                 Показать эту справку" << endl;
    cout << endl;
    cout << "Примеры:" << endl;
    cout << "  " << programName << " -o sin -a 30" << endl;
    cout << "  " << programName << " --operation cos --angle 45" << endl;
}

int main(int argc, char* argv[]) {
    string operation;
    double angle = 0.0;
    
    // Обработка коротких опций
    int opt;
    while ((opt = getopt(argc, argv, "o:a:h")) != -1) {
        switch (opt) {
            case 'o':
                operation = optarg;
                break;
            case 'a':
                try {
                    angle = stod(optarg);
                } catch (const exception& e) {
                    cerr << "Ошибка: неверный формат угла" << endl;
                    return 1;
                }
                break;
            case 'h':
                printHelp(argv[0]);
                return 0;
            case '?':
                cerr << "Используйте -h для справки" << endl;
                return 1;
        }
    }
    
    // Обработка длинных опций
    for (int i = optind; i < argc; i++) {
        string arg = argv[i];
        
        if (arg == "--operation" && i + 1 < argc) {
            operation = argv[++i];
        }
        else if (arg == "--angle" && i + 1 < argc) {
            try {
                angle = stod(argv[++i]);
            } catch (const exception& e) {
                cerr << "Ошибка: неверный формат угла" << endl;
                return 1;
            }
        }
        else if (arg == "--help") {
            printHelp(argv[0]);
            return 0;
        }
        else {
            cerr << "Ошибка: неизвестный параметр " << arg << endl;
            printHelp(argv[0]);
            return 1;
        }
    }
    
    // Проверка обязательных параметров
    if (operation.empty()) {
        cerr << "Ошибка: не указана операция" << endl;
        printHelp(argv[0]);
        return 1;
    }
    
    if (angle == 0.0 && operation != "sin" && operation != "cos") {
        cerr << "Ошибка: не указан угол" << endl;
        printHelp(argv[0]);
        return 1;
    }
    
    // Проверка корректности операции
    if (operation != "sin" && operation != "cos") {
        cerr << "Ошибка: неверная операция. Допустимые значения: sin, cos" << endl;
        return 1;
    }
    
    // Вычисление результата
    double radians = degreesToRadians(angle);
    double result;
    
    if (operation == "sin") {
        result = sin(radians);
    } else {
        result = cos(radians);
    }
    
    // Вывод результата
    cout << fixed << setprecision(6);
    if (operation == "sin") {
        cout << "sin(" << angle << "°) = " << result << endl;
    } else {
        cout << "cos(" << angle << "°) = " << result << endl;
    }
    
    return 0;
}
