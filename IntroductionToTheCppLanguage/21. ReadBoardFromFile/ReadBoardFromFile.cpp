#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string str) {
  istringstream stringStreamed(str);
  vector<int> vector;
  int elementVector;
  char c;
  while (stringStreamed >> elementVector >> c) {
    cout << elementVector << " " << c << "\n";
    vector.push_back(elementVector);
  }
  return vector;
}

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(string pathToBoardFile) {
  ifstream boardFile;
  boardFile.open(pathToBoardFile);
  if (boardFile) {
    string line;
    while (getline(boardFile, line)) {
      cout << line << "\n";
    }
  }
}

// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // TODO: Call the ReadBoardFile function here.
  // ReadBoardFile("1.board");
  // Leave the following line commented out.
  // PrintBoard(board);
  for (auto i : ParseLine("0,1,0,0,0,0,")) {
    cout << i << "\n";
  }
}