#include <windows.h>
#include <stdio.h>

void appendTextAtPosition(HANDLE hStdout, COORD position, const char* text) {
    DWORD written;
    SetConsoleCursorPosition(hStdout, position);
    WriteConsoleOutputCharacter(hStdout, text, strlen(text), position, &written);
}

int main() {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // Print some initial text
    printf("Hello, this is a test message.");
    
    // Get the current console screen buffer info
    GetConsoleScreenBufferInfo(hStdout, &csbi);
    
    // Set the position where you want to append the new text
    position.X = 7;  // Column position (0-based index)
    position.Y = csbi.dwCursorPosition.Y - 1;  // Row position (adjusting for 0-based index)

    // Append the new text at the specified position
    appendTextAtPosition(hStdout, position, " inserted text");

    // Move the cursor to a new line after appending text
    SetConsoleCursorPosition(hStdout, csbi.dwCursorPosition);
    printf("\n");

    return 0;
}
