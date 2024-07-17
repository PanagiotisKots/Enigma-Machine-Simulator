#include <stdio.h>
#include <string.h>

// Define rotor wiring (example wirings)
char rotor1[26] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char rotor2[26] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char rotor3[26] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

// Define reflector wiring (example wiring)
char reflector[26] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

// Function to encrypt a character through a single rotor
char encryptThroughRotor(char input, char* rotor, int offset) {
    int pos = (input - 'A' + offset) % 26; // Calculate the position considering the rotor offset
    return rotor[pos]; // Return the encrypted character
}

// Function to encrypt a character through the reflector
char reflect(char input) {
    return reflector[input - 'A']; // Reflect the character using the reflector wiring
}

// Function to find the index of a character in a rotor
int findIndexInRotor(char character, char* rotor) {
    int i;
    for (i = 0; i < 26; i++) {
        if (rotor[i] == character) {
            return i; // Return the index of the character in the rotor
        }
    }
    return -1; // Should never happen
}

// Function to encrypt a character through the entire Enigma machine
char encryptCharacter(char input, int* rotorPositions) {
    // Print the current state before encryption
    printf("\nEncrypting character: %c\n", input);
    printf("Initial Rotor Positions: [%d, %d, %d]\n", rotorPositions[0], rotorPositions[1], rotorPositions[2]);

    // Forward pass through rotors
    char step1 = encryptThroughRotor(input, rotor1, rotorPositions[0]);
    printf("After Rotor 1 (position %d): %c\n", rotorPositions[0], step1);
    
    char step2 = encryptThroughRotor(step1, rotor2, rotorPositions[1]);
    printf("After Rotor 2 (position %d): %c\n", rotorPositions[1], step2);
    
    char step3 = encryptThroughRotor(step2, rotor3, rotorPositions[2]);
    printf("After Rotor 3 (position %d): %c\n", rotorPositions[2], step3);

    // Reflect
    char reflected = reflect(step3);
    printf("After Reflector: %c\n", reflected);

    // Backward pass through rotors (reverse direction)
    int backStep3 = findIndexInRotor(reflected, rotor3);
    char backStep2 = 'A' + (backStep3 - rotorPositions[2] + 26) % 26;
    printf("Back through Rotor 3: %c\n", backStep2);

    int backStep2Index = findIndexInRotor(backStep2, rotor2);
    char backStep1 = 'A' + (backStep2Index - rotorPositions[1] + 26) % 26;
    printf("Back through Rotor 2: %c\n", backStep1);

    int backStep1Index = findIndexInRotor(backStep1, rotor1);
    char finalChar = 'A' + (backStep1Index - rotorPositions[0] + 26) % 26;
    printf("Back through Rotor 1: %c\n", finalChar);

    // Print the final encrypted character
    printf("Encrypted character: %c\n", finalChar);

    // Advance the rotors (simplified stepping mechanism)
    rotorPositions[0] = (rotorPositions[0] + 1) % 26;
    if (rotorPositions[0] == 0) {
        rotorPositions[1] = (rotorPositions[1] + 1) % 26;
        if (rotorPositions[1] == 0) {
            rotorPositions[2] = (rotorPositions[2] + 1) % 26;
        }
    }

    // Print the new rotor positions after stepping
    printf("New Rotor Positions: [%d, %d, %d]\n", rotorPositions[0], rotorPositions[1], rotorPositions[2]);

    return finalChar;
}

// Main function to encrypt a message
void encryptMessage(char* message, char* encryptedMessage, int* rotorPositions) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = encryptCharacter(message[i], rotorPositions);
        } else {
            encryptedMessage[i] = message[i]; // Non-alphabet characters remain unchanged
        }
    }
    encryptedMessage[len] = '\0'; // Null-terminate the encrypted message
}

int main() {
    char message[] = "HELLO ENIGMA";
    char encryptedMessage[100];
    int rotorPositions[] = {0, 0, 0}; // Initial rotor positions
    int i;

    printf("Original Message: %s\n", message);
    encryptMessage(message, encryptedMessage, rotorPositions);
    printf("Encrypted Message: %s\n", encryptedMessage);

    return 0;
}

