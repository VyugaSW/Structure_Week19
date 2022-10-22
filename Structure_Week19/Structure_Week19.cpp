
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
//Структура
int z; //Переменная принимающая нажатие клавиш пользователя (продолжение выполнения)
struct Book {
    char* name = new char[256]; //Имя
    char* author = new char[256]; //Автор
    char* publisher = new char[256]; //Издательство
    char* genre = new char[256]; //Жанр
};
//Заполнение массива структур
void FillBooks(Book* arr, const int size) {
    for (int i = 0; i < size; i++) {
        system("cls");
        cout << "Enter the name of book number " << i + 1 << " :\n";
        gets_s(arr[i].name, 256);
        cout << "Enter the Author of book number " << i + 1 << " :\n";
        gets_s(arr[i].author, 256);
        cout << "Enter the publisher of book number " << i + 1 << " :\n";
        gets_s(arr[i].publisher, 256);
        cout << "Enter the genre of book number " << i + 1 << " :\n";
        gets_s(arr[i].genre, 256);
    }
}
//Вывод всех книг
void PrintingBooks(Book* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "||Book Number|| - " << i+1 << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Author: " << arr[i].author << endl;
        cout << "Publisher: " << arr[i].publisher << endl;
        cout << "Genre: " << arr[i].genre << endl << endl;
    }
    cout << "Press any key to continue:\n";
    z = _getch();
}
//Поиск книги по автору
void SearchBookOnAuthor(Book* arr, const int size) {
    char* buff = new char[256]; // Строка пользователя
    cout << "Enter the author of searching book:\n";
    gets_s(buff, 256);
    cout << "All matches:\n\n ";
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].author, buff) == 0) {
            cout << "Book Number " << i << endl;
            cout << "Name: " << arr[i].name << endl;
            cout << "Author: " << arr[i].author << endl;
            cout << "Publisher: " << arr[i].publisher << endl;
            cout << "Genre: " << arr[i].genre << endl;
            cout << endl;
        }
    }
    delete[]buff; //Удаление массива
    cout << "Press any key to continue:\n";
    z = _getch();
}
//Поиск книги по названию
void SearchBookOnName(Book* arr, const int size) {
    char* buff = new char[256]; // Строка пользователя
    cout << "Enter the author of searching book:\n";
    gets_s(buff, 256);
    cout << "All matches:\n\n ";
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, buff) == 0) {
            cout << "Book Number " << i << endl;
            cout << "Name: " << arr[i].name << endl;
            cout << "Author: " << arr[i].author << endl;
            cout << "Publisher: " << arr[i].publisher << endl;
            cout << "Genre: " << arr[i].genre << endl;
            cout << endl;
        }
    }
    delete[] buff;
    cout << "Press any key to continue:\n";
    z = _getch();
}
//Сортировка книг по именам
void SortingBookOnName(Book* arr, const int size) {
    Book** newarr = new Book*[size]; //Массив указателей сортировки ради
    for (int i = 0; i < size; i++) {
        newarr[i] = &arr[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (strcmp(newarr[j]->name,newarr[j + 1]->name) > 0) {
                swap(newarr[j], newarr[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "||Book Number|| " << i+1 << endl;
        cout << "Name: " << newarr[i]->name << endl;
        cout << "Author: " << newarr[i]->author << endl;
        cout << "Publisher: " << newarr[i]->publisher << endl;
        cout << "Genre: " << newarr[i]->genre << endl;
        cout << endl;
    }
    cout << "Press any key to continue:\n";
    z = _getch();
}
//Сортировка книг по авторам
void SortingBookOnAuthor(Book* arr, const int size) {
    Book** newarr = new Book * [size];
    for (int i = 0; i < size; i++) {
        newarr[i] = &arr[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (strcmp(newarr[j]->author, newarr[j + 1]->author) > 0) {
                swap(newarr[j], newarr[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "||Book Number|| " << i + 1 << endl;
        cout << "Name: " << newarr[i]->name << endl;
        cout << "Author: " << newarr[i]->author << endl;
        cout << "Publisher: " << newarr[i]->publisher << endl;
        cout << "Genre: " << newarr[i]->genre << endl;
        cout << endl;
    }
    cout << "Press any key to continue:\n";
    z = _getch();
}
//Сортировка книг по издательствам
void SortingBookOnPublisher(Book* arr, const int size) {
    Book** newarr = new Book * [size];
    for (int i = 0; i < size; i++) {
        newarr[i] = &arr[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (strcmp(newarr[j]->publisher, newarr[j + 1]->publisher) > 0) {
                swap(newarr[j], newarr[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "||Book Number|| " << i + 1 << endl;
        cout << "Name: " << newarr[i]->name << endl;
        cout << "Author: " << newarr[i]->author << endl;
        cout << "Publisher: " << newarr[i]->publisher << endl;
        cout << "Genre: " << newarr[i]->genre << endl;
        cout << endl;
    }
    cout << "Press any key to continue:\n";
    z = _getch();
}
int main()
{
    const int size = 10; 
    Book arr[size];
    FillBooks(arr, size);
    int us_choice;
    while (true) {
        system("cls");
        cout << "Chooce a option:\n";
        cout << "1 - Print all books\n";
        cout << "2 - Search book on Name\n";
        cout << "3 - Searh book on author\n";
        cout << "4 - Sort book on author\n";
        cout << "5 - Sort book on name\n";
        cout << "6 - Sort book on Publisher\n";
        cout << "Enter option: ";
        us_choice = _getch(); //Считывает нажатие клавиш пользователя
        switch (us_choice) {
        case 49: //Код клавиши "1"
            system("cls");
            PrintingBooks(arr, size);
            break;
        case 50: //Код клавиши "2"
            system("cls");
            SearchBookOnAuthor(arr, size);
            break;
        case 51: //И дальше
            system("cls");
            SearchBookOnName(arr, size);
            break;
        case 52:
            system("cls");
            SortingBookOnAuthor(arr, size);
            break;
        case 53:
            system("cls");
            SortingBookOnName(arr, size);
            break;
        case 54:
            system("cls");
            SortingBookOnPublisher(arr, size);
            break;
        }



    }
}

