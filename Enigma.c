#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Example rotor wirings for the Enigma machine
char rotor1[26] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char rotor2[26] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char rotor3[26] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

// Example reflector wiring
char reflector[26] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

// Encrypt a character through one rotor, considering its offset
char encryptThroughRotor(char input, char* rotor, int offset) {
    int pos = (input - 'A' + offset) % 26; // Find the rotor position with the offset
    return rotor[pos]; // Return the corresponding encrypted character
}

// Reflect a character using the reflector
char reflect(char input) {
    return reflector[input - 'A']; // Reflect the character using the reflector wiring
}

// Find the position of a character in the rotor
int findIndexInRotor(char character, char* rotor) {
    int i;
    for (i = 0; i < 26; i++) {
        if (rotor[i] == character) {
            return i; // Return the index of the character
        }
    }
    return -1; // Should never happen in valid input
}

// Encrypt a single character through the entire Enigma machine
char encryptCharacter(char input, int* rotorPositions) {
    // Display the character and rotor positions before encryption
    printf("\nEncrypting character: %c\n", input);
    printf("Initial Rotor Positions: [%d, %d, %d]\n", rotorPositions[0], rotorPositions[1], rotorPositions[2]);

    // Pass through each rotor in sequence
    char step1 = encryptThroughRotor(input, rotor1, rotorPositions[0]);
    printf("After Rotor 1 (position %d): %c\n", rotorPositions[0], step1);
    
    char step2 = encryptThroughRotor(step1, rotor2, rotorPositions[1]);
    printf("After Rotor 2 (position %d): %c\n", rotorPositions[1], step2);
    
    char step3 = encryptThroughRotor(step2, rotor3, rotorPositions[2]);
    printf("After Rotor 3 (position %d): %c\n", rotorPositions[2], step3);

    // Reflect the character
    char reflected = reflect(step3);
    printf("After Reflector: %c\n", reflected);

    // Pass back through the rotors in reverse order
    int backStep3 = findIndexInRotor(reflected, rotor3);
    char backStep2 = 'A' + (backStep3 - rotorPositions[2] + 26) % 26;
    printf("Back through Rotor 3: %c\n", backStep2);

    int backStep2Index = findIndexInRotor(backStep2, rotor2);
    char backStep1 = 'A' + (backStep2Index - rotorPositions[1] + 26) % 26;
    printf("Back through Rotor 2: %c\n", backStep1);

    int backStep1Index = findIndexInRotor(backStep1, rotor1);
    char finalChar = 'A' + (backStep1Index - rotorPositions[0] + 26) % 26;
    printf("Back through Rotor 1: %c\n", finalChar);

    // Display the final encrypted character
    printf("Encrypted character: %c\n", finalChar);

    // Advance the rotors (basic stepping mechanism)
    rotorPositions[0] = (rotorPositions[0] + 1) % 26;
    if (rotorPositions[0] == 0) {
        rotorPositions[1] = (rotorPositions[1] + 1) % 26;
        if (rotorPositions[1] == 0) {
            rotorPositions[2] = (rotorPositions[2] + 1) % 26;
        }
    }

    // Display the new rotor positions after stepping
    printf("New Rotor Positions: [%d, %d, %d]\n", rotorPositions[0], rotorPositions[1], rotorPositions[2]);

    return finalChar;
}

// Decrypt a single character through the entire Enigma machine
char decryptCharacter(char input, int* rotorPositions) {
    // Decryption is the same as encryption with the same rotor settings
    return encryptCharacter(input, rotorPositions);
}

// Encrypt an entire message
void encryptMessage(char* message, char* encryptedMessage, int* rotorPositions) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') { // Encrypt only uppercase letters
            encryptedMessage[i] = encryptCharacter(message[i], rotorPositions);
        } else {
            encryptedMessage[i] = message[i]; // Keep non-uppercase characters unchanged
        }
    }
    encryptedMessage[len] = '\0'; // Null-terminate the encrypted message
}

// Decrypt an entire message
void decryptMessage(char* encryptedMessage, char* decryptedMessage, int* rotorPositions) {
    int len = strlen(encryptedMessage);
    int i;
    for (i = 0; i < len; i++) {
        if (encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z') { // Decrypt only uppercase letters
            decryptedMessage[i] = decryptCharacter(encryptedMessage[i], rotorPositions);
        } else {
            decryptedMessage[i] = encryptedMessage[i]; // Keep non-uppercase characters unchanged
        }
    }
    decryptedMessage[len] = '\0'; // Null-terminate the decrypted message
}

int main() {
    char message[100];
    char encryptedMessage[100];
    char decryptedMessage[100];
    int rotorPositions[] = {0, 0, 0}; // Starting positions for the rotors

    // Prompt user for input
    printf("Enter the message to encrypt (uppercase letters only): ");
    fgets(message, sizeof(message), stdin);
    
    // Remove newline character if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Convert message to uppercase
    for (int i = 0; message[i]; i++) {
        message[i] = toupper((unsigned char)message[i]);
    }

    printf("\n---Encryption Process---\n");
    encryptMessage(message, encryptedMessage, rotorPositions);

    // Reset rotor positions for decryption
    rotorPositions[0] = 0;
    rotorPositions[1] = 0;
    rotorPositions[2] = 0;

    printf("\n---Decryption Process---\n");
    decryptMessage(encryptedMessage, decryptedMessage, rotorPositions);

    // Print the results
    printf("\n---Summary---\n");
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}
