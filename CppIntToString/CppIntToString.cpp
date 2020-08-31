#include <iostream>
#include <vector>

// Create a function that converts an int to a char
char IntToChar(int value) {
    // Check if the value is below 0 or above 9. if so, return 0
    if (value < 0 || value > 9) {
        return '0';
    }

    // i did some tests and found that the char '0'
    // is equal to 48 as an int. so technically, you just
    // need to offset the value when parsing as a char.

    return (char)(value + 48);
}

// A function to convert an int to a string
// (aka an array of chars)

const char* IntToString(int value) {
    // 10 is the maximum "string" length of an int32.
    // which is something like 2147000000
    // but the extra 1 i think is the "start address" for the array
    char buffer[11];
    // fill the buffer so it doesnt have random characters
    memset(&buffer, 0, sizeof(buffer));

    // create a list (vector), which is sort of an array of the int values
    std::vector<int> splitValue;

    while (true) {
        // This will insert a mod 10 of value. mod basically returns
        // the remainder when dividing ints. so 25 % 10 is 5, because
        // 25 / 10 is 2.5, but ints are whole numbers so it just returns
        // 2, the remainder being 5.
        splitValue.insert(splitValue.begin(), value % 10);

        // divide the value by 10 which will sort of remove the end of the value
        // aka, 25 / 10 is 2. so it sort of indirectly removes the 5
        value /= 10;

        // if the value is 0 then break the loop. cannot divide by 0 lol.
        // and if it's 0 then it means the number is empty
        if (value == 0)
            break;
    }

    // now to add every element in the list (vector) into the char buffer

    // i think it's size. or it might be container. but size worked for me
    // (idk much about vectors lol)
    for (int i = 0; i < splitValue.size(); i++) {
        // i think it's considered better practice to use
        // a vector's at function, but ill just do this as i understand it easier
        buffer[i] = IntToChar(splitValue[i]);
    }

    // i think the list might auto-clear by itself, but idk if it does
    // so i'll do it manually.
    splitValue.clear();

    return buffer;
}

#include <Windows.h>

int main()
{
    int value = 123789;

    const char* valueString = IntToString(value);

    // "123789"

    // idk why this is outputting random chars. in debugging it works
    // but fsr it doesn't output the numbers. might try and fix later
    MessageBoxA(NULL, valueString, "Message", MB_OK);

    std::cout << valueString << '\n';
}