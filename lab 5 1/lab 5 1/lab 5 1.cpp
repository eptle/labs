#include <iostream>

int main()
{
    char a[101], a_out[101];
    char vowels[7] = "aeiouy";
    gets_s(a, 101);
    int cnt = 0;
    for (int i = 0; i < strlen(a); i++) {
        bool isVowel = false;
        for (int j = 0; j < strlen(vowels); j++) {
            if (a[i] == vowels[j])
                isVowel = true;
        }
        if (isVowel == false) {
            a_out[cnt] = a[i];
            cnt++;
        }
    }
    a_out[cnt] = '\0';
    std::cout << a_out << std::endl;
}
