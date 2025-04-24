#include <iostream>
using namespace std;

char mat[5][5];
bool isKey[26];
int place[26];
void printMatrix() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

string toUpperString(string text) {
  for (int i = 0; i < text.length(); i++) {
    text[i] = toupper(text[i]);
    if (text[i] == 'J')
      text[i] = 'I';
  }
  return text;
}
string encryptor(string decodedText) {

  int i = 0;
  string enText = "";
  if (decodedText.length() % 2 == 1)
    decodedText += 'X';
  while (i < decodedText.length()) {

    int first_row = place[decodedText[i] - 65] / 5;
    int first_column = place[decodedText[i] - 65] % 5;
    i++;
    int second_row = place[decodedText[i] - 65] / 5;
    int second_column = place[decodedText[i] - 65] % 5;

    if (first_row == second_row) {
      enText += mat[first_row][(first_column + 1) % 5];
      enText += mat[first_row][(second_column + 1) % 5];

    } else if (first_column == second_column) {

      enText += mat[(first_row + 1) % 5][first_column];
      enText += mat[(second_row + 1) % 5][second_column];
    } else {
      enText += mat[first_row][second_column];
      enText += mat[second_row][first_column];
    }

    i++;
  }

  return enText;
}
string decryptor(string encodedText) {

  int i = 0;
  string deText = "";
  if (encodedText.length() % 2 == 1)
    encodedText += 'X';
  while (i < encodedText.length()) {

    int first_row = place[encodedText[i] - 65] / 5;
    int first_column = place[encodedText[i] - 65] % 5;
    i++;
    int second_row = place[encodedText[i] - 65] / 5;
    int second_column = place[encodedText[i] - 65] % 5;

    if (first_row == second_row) {
      deText += mat[first_row][(first_column + 4) % 5];
      deText += mat[first_row][(second_column + 4) % 5];

    } else if (first_column == second_column) {

      deText += mat[(first_row + 4) % 5][first_column];
      deText += mat[(second_row + 4) % 5][second_column];
    } else {
      deText += mat[first_row][second_column];
      deText += mat[second_row][first_column];
    }

    i++;
  }

  return deText;
}
int main() {
  string key;
  string plainText;
  cout << "Enter the key : ";
  cin >> key;
  for (int i = 0; i < 26; i++) {
    isKey[i] = false;
  }

  int keySize;
  keySize = key.length();

  for (int k = 0; k < key.length(); k++) {
    key[k] = toupper(key[k]);
    if (key[k] == 'J')
      key[k] = 'I';
    if (!isKey[(int)key[k] - 65]) {
      mat[k / 5][k % 5] = key[k];
      isKey[(int)key[k] - 65] = true;
      place[(int)key[k] - 65] = k;
    } else {
      keySize--;
    }
  }

  int alphabet = 65;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i * 5 + j < keySize) {
        continue;
      }
      while (isKey[alphabet - 65] == true) {
        alphabet++;
      }
      if (alphabet == 74) {
        alphabet++;
      }

      mat[i][j] = char(alphabet);
      place[alphabet - 65] = i * 5 + j;
      alphabet++;
    }
  }

  printMatrix();
  int choice;

  cout << "\n1. Encrypt\n2. Decrypt\nYour choice: ";
  cin >> choice;
  cin.ignore();
  string text;
  if (choice == 1) {
    cout << "Enter plaintext: ";
    getline(cin, text);
    text = toUpperString(text);
    cout << "ciphertext: " << encryptor(text) << endl;
  } else if (choice == 2) {
    cout << "Enter ciphertext: ";
    getline(cin, text);
    text = toUpperString(text);
    cout << "plaintext: " << decryptor(text) << endl;
  } else {
    cout << "Invalid option.\n";
  }
}
